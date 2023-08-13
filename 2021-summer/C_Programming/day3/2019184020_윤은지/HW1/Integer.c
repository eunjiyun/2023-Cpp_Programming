/*
파일명: Integer.c
프로그램 내용: 16진수를 입력 받아 10진수로 변환하고 출력
작성자: 2019184020
        윤은지
*/


#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
    int input = 0;
    
    printf("16진수로 정수를 입력하세요: ");
    scanf("%x", &input);

    printf("%x는 10진수로 %d입니다.\n",input,input);

    return 0;
}