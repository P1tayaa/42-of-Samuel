#!/bin/bash
FILE="$1"
LINES=$(cat $FILE)
i=0
while read line; do
    ARG="${line}"; ./push_swap $ARG | wc -l
    # ARG="${line}"; ./push_swap $ARG | ./checker_Mac $ARG
    #echo line: $i
    #((i=i+1))
    echo parameter: $line
    ./push_swap $line
done < "${FILE}"