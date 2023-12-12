/*
파일명: Circle.c
프로그램 내용: 원의 반지름을 입력 받아 원주를 출력한다.
작성자: 2019184020
        윤은지
*/


#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
    double rad;//반지름 저장
    double circleCircumference;//원의 넓이 결과 저장

    printf("반지름 입력: ");
    scanf("%lf", &rad);

    circleCircumference = rad *2  * 3.1415;

    printf("원의 둘레 = %f\n", circleCircumference);

    return 0;
}