#!/bin/bash

BUILD_TYPE="debug"
COMPILE_TYPE="dynamic"
PROJECT_NAME="$(basename "$PWD")"

help(){
	if [[ $# -eq 0 ]]; then
		TEXT_TO_ADD=""
	else 
		TEXT_TO_ADD="\n\n$1"
	fi

       	echo -e "Usage:\n"$0" <build_type> <compile_type>"$TEXT_TO_ADD""
}

get_cflags(){
	if [[ "$BUILD_TYPE" == "debug" ]]; then
		CFLAGS="-Wall -Wextra -g -O0"
	elif [[ "$BUILD_TYPE" == "release" ]]; then
		CFLAGS="-Wall -Wextra -O2"
	else
		echo "Unknown build type: "$BUILD_TYPE""
		exit 1
	fi

	if [[ "$COMPILE_TYPE" == "static" ]]; then
		CFLAGS="$CFLAGS -static"
	elif [[ "$COMPILE_TYPE" != "dynamic" ]]; then
		echo "Unknown compile type: "$COMPILE_TYPE""
		exit 1
	fi
}


if [[ $# -eq 0 ]]; then
	help "Used default parameters: BUILD TYPE = debug, COMPILE TYPE = dynamic" 
elif [[ $# -eq 1 ]]; then
	BUILD_TYPE="$1"
elif [[ $# -eq 2 ]]; then
	BUILD_TYPE="$1"
	COMPILE_TYPE="$2"
else
	help "Too many parameters"
	exit 1
fi

get_cflags

gcc $CFLAGS -Iinclude src/*c -o "$PROJECT_NAME"	

