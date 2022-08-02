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
    g++ main.cpp -O2 -o compiled
    
    echo "$current_hash" > /tmp/previous_hash
fi