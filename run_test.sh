#!/bin/bash

if [$# -eq 0]; then
    echo "❗️./run_test.sh <주차> <문제번호> <예제번호>"
    echo "ex: ./run_test.sh 1 2 2"
    exit 1
fi

FILE_NAME="W0${1}_P${2}_${3}"

SRC=/Users/gyuyeonjo/CLionProjects/dataStructures/main.cpp
EXE=main
INPUT=/Users/(whoami)/Desktop/data-structure/ans/$FILE_NAME.in
EXPECTED=/Users/(whoami)/Desktop/data-structure/ans/$FILE_NAME.ans
OUTPUT=output.txt


g++ -std=c++11 "$SRC" -o "$EXE"
if [$? -ne 0]; then
    echo "fail to compile"
    exit 1
fi

./"$EXE" < "$INPUT" > "$OUTPUT"

echo "comparing with expected output"
if diff -q "$OUTPUT" "$EXPECTED" > /dev/null; then
    echo "correct"
else
    echo "not correct"
    diff "$OUTPUT" "$EXPECTED"
fi
