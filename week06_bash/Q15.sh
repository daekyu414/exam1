#! /bin/bash

file_wordcnt()
{
    WORDS=$(cat $1 | wc -w)
    echo "$1 파일의 단어는 $WORDS 개 입니다."
}

read -p "Enter a file name: " FILE
file_wordcnt $FILE