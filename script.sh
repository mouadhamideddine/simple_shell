#!/bin/bash

# List of source files
source_files="_strdup.c _strncmp.c execute.c get_path.c strcpy_path.c tokenize.c _strcpy.c _strlen.c exec_cmd.c free_array.c is_path.c read.c shellbeta.c strdup_path.c tokenize_path.c"

# Compilation command with stderr redirected to terminal
gcc -o myshell $source_files 2>&1

# Check if compilation was successful
if [ $? -eq 0 ]; then
    echo "Compilation successful"
else
    echo "Compilation failed"
fi
