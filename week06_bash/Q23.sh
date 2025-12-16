#! /bin/bash

factorial()
{
    result=1
    for n in $(seq 1 $1); do
        result=$(( $result * $n ))
    done
    echo "Factorial of $1 is $result"
}

read -p "Enter a number: " NUM
factorial $NUM