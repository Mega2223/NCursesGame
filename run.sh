#!/bin/sh

if ./build.sh = 0; then
	if ./build/ConsoleTeste = 0; then
		echo ""
		echo "exiting"
	else
		echo "runtime error"
	fi
else
	echo "not running"
fi
