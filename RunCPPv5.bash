#!/bin/bash

#  ______            _____ ____________       _____ 
#  | ___ \          /  __ \| ___ \ ___ \     |  ___|
#  | |_/ /   _ _ __ | /  \/| |_/ / |_/ /_   _|___ \ 
#  |    / | | | '_ \| |    |  __/|  __/\ \ / /   \ \
#  | |\ \ |_| | | | | \__/\| |   | |    \ V //\__/ /
#  \_| \_\__,_|_| |_|\____/\_|   \_|     \_/ \____/ 
#                                                                                                 


############ USAGE ############

# ./RunCPPv5.bash dev = compile with all compiler warnings
# ./RunCPPv5.bash deb = compile with support for debuggers and profilers (gprof, gdb, valgrind, etc.)
# ./RunCPPv5.bash rel = compile for best performance
# ./RunCPPv5.bash     = standart compilation

# "rec" can be added to recompile even without any detected changes

######## CONFIGURATION ########

mainFile="main.cpp"
executableName="compiled"
checksumFilePath="/tmp/"
directRunAfterRecompilation=true

###############################

clear

projectFolder=`basename "$PWD"`
outputChecksumName="${projectFolder}Checksum"

currentCodeChecksum=`find "./" -type f -not -name ${executableName} -print0 | xargs -0 sha1sum | sha1sum`

touch ${checksumFilePath}${outputChecksumName}
previousCodeChecksum=`cat ${checksumFilePath}${outputChecksumName}`

touch ${executableName}
chmod +x ${executableName}

if [[ "$currentCodeChecksum" == "$previousCodeChecksum" && $2 != "rec" && $1 != "rec" ]]; then
    ./${executableName}
else

    # development build
    if [[ $1 == "dev" ]]; then
    
    g++ ${mainFile} -pedantic -Wall -Wextra -Wcast-align -Wcast-qual -Wctor-dtor-privacy -Wdisabled-optimization -Wformat=2 -Winit-self -Wlogical-op -Wmissing-declarations -Wmissing-include-dirs -Wnoexcept -Wold-style-cast -Woverloaded-virtual -Wredundant-decls -Wshadow -Wsign-conversion -Wsign-promo -Wstrict-null-sentinel -Wstrict-overflow=5 -Wswitch-default -Wundef -Wno-unused -o ${executableName}

    # debug build
    elif [[ $1 == "deb" ]]; then
    
    g++ ${mainFile} -pg -o ${executableName}

    # release build
    elif [[ $1 == "rel" ]] then
    
    g++ ${mainFile} -O3 -o ${executableName}

    # standart build
    else
    g++ ${mainFile} -o ${executableName}
    fi

    echo "$currentCodeChecksum" > ${checksumFilePath}${outputChecksumName}

    if [ "${directRunAfterRecompilation}" == true ]; then
        ./${executableName}
    fi
fi