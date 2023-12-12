/*
파일명: hw1.c
프로그램 내용: 정수 하나를 입력 받아 그 정수까지의 합을 구하기
작성자: 2019184020
        윤은지
*/


#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>   

int main()
{
    int num = 0;
    int i = 0;
    int sum = 0;
    
    printf("정수 하나를 입력하세요: ");
    scanf("%d", &num);

    for (i = 1; i <= num ; ++i)
        sum += i;

    printf("%d", sum);

    return 0;
}