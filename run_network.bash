#!/bin/bash

clear

touch /tmp/previous_hash
touch compiled
chmod +x compiled

current_hash=`sha1sum main.cpp`

previous_hash=`cat /tmp/previous_hash`

if [[ "$current_hash" == "$previous_hash" ]]; then
    ./compiled
else
    g++ main.cpp -lopencv_core -lopencv_videoio -lopencv_highgui -Os `pkg-config --cflags gtk+-2.0 --libs opencv4 gtk+-2.0` -o compiled
    
    echo "$current_hash" > /tmp/previous_hash
fi