#!/bin/sh

rm -r ./build
mkdir ./build

cmake -S ./ -B ./build/
cd ./build/

if not "make"; then
	echo "compilation error"
	exit -1
fi

