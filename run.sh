#!/bin/sh

if ./build.sh = 0; then
	./build/ConsoleTeste
else
	echo "not running"
fi
