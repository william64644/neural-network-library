#!/bin/bash

clear

touch previous_hash # Create a file to store the previous hash if it doesn't exist
touch compiled # Create a file to store the compiled code if it doesn't exist
chmod +x compiled # Make the file executable

current_hash=`sha1sum main.cpp`

previous_hash=`cat previous_hash`

if [[ "$current_hash" == "$previous_hash" ]]; then # Detect if the file has been changed
    ./compiled
else # If the file has been changed, recompile and run the program
    g++ main.cpp -pedantic -Wall -Wextra -Wcast-align -Wcast-qual -Wctor-dtor-privacy -Wdisabled-optimization -Wformat=2 -Winit-self -Wlogical-op -Wmissing-declarations -Wmissing-include-dirs -Wnoexcept -Wold-style-cast -Woverloaded-virtual -Wredundant-decls -Wshadow -Wsign-conversion -Wsign-promo -Wstrict-null-sentinel -Wstrict-overflow=5 -Wswitch-default -Wundef -Wno-unused -o compiled
    
    echo "$current_hash" > previous_hash
fi