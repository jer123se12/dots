#!/bin/bash

volume=$(pactl get-sink-volume @DEFAULT_SINK@ | awk '{print $5}')

mute=$(pactl get-sink-mute @DEFAULT_SINK@ | awk '{print $2}')

if [ "$mute" = "yes" ]; then
    echo "$volume X"
    echo "$volume X"
    echo "#FF8000"
else
    echo "$volume"
    echo "$volume"
fi
