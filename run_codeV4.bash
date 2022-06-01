#!/bin/bash

clear

sudo touch previous_hash
sudo touch compiled

current_hash=`sha1sum main.cpp`

previous_hash=`cat previous_hash`

if [[ "$current_hash" == "$previous_hash" ]]; then
    sudo ./compiled
else
    sudo g++ main.cpp -pedantic -Wall -Wextra -Wcast-align -Wcast-qual -Wctor-dtor-privacy -Wdisabled-optimization -Wformat=2 -Winit-self -Wlogical-op -Wmissing-declarations -Wmissing-include-dirs -Wnoexcept -Wold-style-cast -Woverloaded-virtual -Wredundant-decls -Wshadow -Wsign-conversion -Wsign-promo -Wstrict-null-sentinel -Wstrict-overflow=5 -Wswitch-default -Wundef -Wno-unused -o compiled
    
    echo "$current_hash" > previous_hash
fi
