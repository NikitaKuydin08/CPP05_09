#!/bin/bash

COUNT="${1:-3000}"
MAX="${2:-100000}"

if [ "$COUNT" -gt "$MAX" ]; then
    echo "Error: cannot generate $COUNT unique numbers from 1-$MAX"
    exit 1
fi

generate_unique()
{
    awk -v count="$1" -v max="$2" '
    BEGIN {
        srand()

        n = 0

        while (n < count) {
            number = int(rand() * max) + 1

            if (!(number in seen)) {
                seen[number] = 1
                print number
                n++
            }
        }
    }'
}

numbers=($(generate_unique "$COUNT" "$MAX"))

echo "Testing ${#numbers[@]} unique numbers..."
./PmergeMe "${numbers[@]}"