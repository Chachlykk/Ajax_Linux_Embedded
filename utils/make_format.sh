#!/bin/bash

if [[ ! -n $2 ]]; then
	echo -e "Not enough parameters:\nUsage:\n\t$0 <directory> <clang-format version>"
	exit 1
fi

if [[ ! -f "$1/.clang-format" ]]; then
	echo "No dir or file .clang-format"
	exit 2
fi

echo -e "====CLANG-FORMAT $2 VERSION====\n"
echo "==============================="

find "$1" -type f \( -name "*.c" -o -name "*.h" \) -exec clang-format-"$2" -i {} + 
