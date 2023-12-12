/*
파일명: SwitchBreak.c
프로그램 내용: switch문을 이용하여 입력한 문자로 시작하는 단어 출력
작성자: 2019184020
        윤은지
*/


#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
    char word;

    printf("문자를 입력하세요: ");
    scanf("%c", &word);

    switch (word)
    {
    case 'M':case'm':
        printf("Morning");
        break;
    case 'A':case'a':
        printf("Afternoon");
        break;
    case 'E':case'e':
        printf("Evening");
        break;
    default:
        printf("잘못된 입력입니다.");
        break;
    }

    return 0;
}