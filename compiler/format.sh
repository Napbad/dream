#!/bin/bash

DIR="./"

if ! command -v clang-format &> /dev/null
then
    echo "clang-format could not be found. Please install it first."
    exit 1
fi

find $DIR -type f \( -name "*.cpp" -o -name "*.h" \) | while read file; do
    echo "Formatting $file"
    clang-format -i "$file"
done

echo "All files in $DIR have been formatted."
