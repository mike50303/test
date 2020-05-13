#!/bin/bash

if [ -d out ]; then
	rm -rf out
fi

mkdir out

cd out

cmake ..

make

cd ..
