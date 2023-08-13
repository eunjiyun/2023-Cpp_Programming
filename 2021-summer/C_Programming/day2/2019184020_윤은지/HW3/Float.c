/*
파일명: Float.c
작성일: 2021/07/13
프로그램 내용: 입력 받은 실수에 100을 곱하고 그 값을 출력
작성자: 2019184020
        윤은지
*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
    float num;
    float result;
    printf("실수를 입력하세요: ");
    scanf("%f", &num);
    result = num * 100;
    printf("result = %f", result);
    return 0;
}