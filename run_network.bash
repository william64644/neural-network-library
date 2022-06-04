#!/bin/bash

clear

touch previous_hash
touch compiled
chmod +x compiled

current_hash=`sha1sum main.cpp`

previous_hash=`cat previous_hash`

if [[ "$current_hash" == "$previous_hash" ]]; then
    ./compiled
else
    g++ -c main.cpp 

    g++ main.o -o compiled -lsfml-graphics -lsfml-window -lsfml-system
    
    echo "$current_hash" > previous_hash
fi
