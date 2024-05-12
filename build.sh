#!/bin/bash

cmake .
make clean
make

mkdir -p output
mv *.out ./output
