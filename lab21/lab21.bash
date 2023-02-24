#!/bin/bash

# Check if user has provided a directory as an argument
if [ $# != 1 ]; then
    echo "Use: $0 <directory>"
    exit 1
fi;

# Check if directory exists
if [ ! -d "$1" ]; then
    echo "Err: $1 is not a directory"
    exit 1
fi;

# Traverse directory and output subdirectories
find "$1" -type d | sort
