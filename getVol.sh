#!/bin/bash

volume=$(pactl get-sink-volume @DEFAULT_SINK@ | awk '{print $5}')
mute=""
if [[ $(pactl get-sink-mute @DEFAULT_SINK@ | awk '{print $2}') == "yes" ]]; then
    echo "X$volume"
    echo "X$volume"
    echo "#FF8000"
else 
    echo " $volume"
    echo " $volume"
fi
