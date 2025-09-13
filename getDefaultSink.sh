#!/bin/bash
sink=$(pactl get-default-sink)
output=""
if [[ "$sink" == "alsa_output.pci-0000_03_00.1.hdmi-stereo-extra2" ]]; then
    output="D"
elif [[ "$sink" == "alsa_output.usb-Blue_Microphones_Yeti_Nano_2323SG000KN8_888-000504041006-00.analog-stereo" ]]; then
    output="H"
else
    output="N"
fi

volume=$(pactl get-sink-volume @DEFAULT_SINK@ | awk '{print $5}')
mute=""
if [[ $(pactl get-sink-mute @DEFAULT_SINK@ | awk '{print $2}') == "yes" ]]; then
    echo "$volume$output"
    echo "$volume$output"
    echo "#FF8000"
else 
    echo "$volume$output"
    echo "$volume$output"
fi
