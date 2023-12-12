/*
파일명: hw2.c
프로그램 내용: 정수 하나를 입력 받아 그 수 만큼 3의 배수를 출력
작성자: 2019184020
        윤은지
*/


#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>   

int main()
{
    int num = 0;

    printf("정수를 입력하세요: ");
    scanf("%d", &num);

    for (int i = 1; i <= num; ++i)
        printf("%d ", i* 3);

    return 0;
}