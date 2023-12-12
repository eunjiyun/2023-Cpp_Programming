/*
파일명: Area.c
프로그램 내용: 반지름을 입력 받아 원의 넓이를 출력
작성자: 2019184020
        윤은지
*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main(void)
{
    int radius = 0;
    float area = 0;
    const float pie = 3.141592;

    printf("반지름: ");
    scanf("%d", &radius);

    area = pie * radius * radius;
    printf("원의 넓이: %15.2f", area);

    return 0;
}