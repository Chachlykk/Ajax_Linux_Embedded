#/!bin/bash

if [[ ! -f "$1/.clang-format" ]]; then
	echo "No dir or file .clang-format"
	exit 1
fi

echo -e "====CLANG-FORMAT 17 VERSION====\nрезультати перевірки версією 17"
echo "==============================="

clang-format-17 --dry-run --Werror "$1"/src/*.c "$1"/include/*.h

echo "==============================="


echo -e "====CLANG-FORMAT 22 VERSION====\nрезультати перевірки версією 17"
echo "==============================="

clang-format-22 --dry-run --Werror "$1"/src/*.c "$1"/include/*.h

echo "==============================="
