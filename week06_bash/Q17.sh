#! /bin/bash

file_wordcnt()
{
    files=$(find . -name '*.txt')
    for n in $files; do
        wordcnt=$(cat $n | wc -w)
        echo "$n 파일의 단어는 $wordcnt 개 입니다."
    done
}

file_wordcnt