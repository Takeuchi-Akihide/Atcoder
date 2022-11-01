#!/bin/bash

cd `dirname $0`

# 名前を分解してcommon.shに引数を渡す
name=$(basename $0 | sed 's/\.[^\.]*$//')
IFS=_ read -ra ARR <<< "${name}"
../Build/common.sh ${ARR[1]}
