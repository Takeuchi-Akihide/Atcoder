#!/bin/bash

cd `dirname $0`

g++ $1 -std=c++14 -Wall -I ./Sample/ac_library
