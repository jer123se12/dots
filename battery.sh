#!/bin/bash

# Get raw data from acpi (first line only to avoid multi-battery confusion)
BAT_INFO=$(acpi -b | head -n 1)

# Extract percentage - safer regex
PERCENT=$(echo "$BAT_INFO" | grep -oP '\d+(?=%)')

# Extract Status - using a case statement for better readability
if echo "$BAT_INFO" | grep -q "Charging"; then
    STAT="C"
elif echo "$BAT_INFO" | grep -q "Full"; then
    STAT="F"
else
    STAT="D"
fi

# Toggle logic:
# When you click, i3blocks sets $BLOCK_BUTTON.
# Note: This only shows the time WHILE the button is pressed/clicked.
if [ "$BLOCK_BUTTON" -eq 1 ]; then
    TIME=$(echo "$BAT_INFO" | grep -oP '\d{2}:\d{2}:\d{2}')
    # If time is available, show it; otherwise fallback to percent
    if [ -n "$TIME" ]; then
        echo "B ${TIME}${STAT}"
    else
        echo "B ${PERCENT}%${STAT}"
    fi
else
    echo "B ${PERCENT}%${STAT}"
fi
