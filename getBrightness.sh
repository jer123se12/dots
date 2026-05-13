#!/bin/bash
brightness=$(brightnessctl -m | awk -F, '{print $4}')
echo "L $brightness"
echo "L $brightness"
