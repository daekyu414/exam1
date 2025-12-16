#! /bin/bash

file_wordcnt()
{
    if [ ! -e $1 ]; then
        echo "$1 파일이 존재하지 않습니다."
        return 1;
    fi
    WORDS=$(cat $1 | wc -w)
    echo "$1 파일의 단어는 $WORDS 개 입니다."
}

read -p "Enter a file name: " FILE
file_wordcnt $FILE
echo "file_wordcnt 함수의 종료 상태: $?"