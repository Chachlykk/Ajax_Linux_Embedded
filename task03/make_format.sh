#!/bin/bash

if [[ ! -n $2 ]]; then
	echo -e "Not enough parameters:\nUsage:\n\t$0 <directory> <clang-format version>"
	exit 1
fi

if [[ ! -f "$1/.clang-format" ]]; then
	echo "No dir or file .clang-format"
	exit 2
fi

echo -e "====CLANG-FORMAT $2 VERSION====\n результати перевірки версією $2"
echo "==============================="

clang-format-"$2" -i "$1"/src/*.c "$1"/include/*.h
