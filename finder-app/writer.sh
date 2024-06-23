#!/bin/sh
writefile=$1
writestr=$2

if [ $# -ne 2 ]; then
    echo "Illegal number of parameters" && exit 1
fi
    DIR="$(dirname "${writefile}")"
if ! [ -d "$DIR" ]; then
    mkdir -p $DIR
fi
echo "$writestr" > $writefile