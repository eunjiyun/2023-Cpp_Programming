/*
파일명: EngNum.c
프로그램 내용: 1-5까지의 정수를 입력 받아 영문으로 출력
작성자: 2019184020
        윤은지
*/


#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
    int num = 0;

    printf("1부터 5까지의 정수를 입력하세요: ");
    scanf("%d", &num);

    switch (num)
    {
    case 1:
        printf("ONE");
        break;
    case 2:
        printf("TWO");
        break;
    case 3:
        printf("THREE");
        break;
    case 4:
        printf("FOUR");
        break;
    case 5:
        printf("FIVE");
        break;
    default:
        printf("I don't know.");
        break;
    }

    return 0;
}