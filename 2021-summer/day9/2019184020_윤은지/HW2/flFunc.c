/*
파일명: flFunc.c
프로그램 내용: 실수값을 인자로 전달 받아 절대값을 구하는 함수를 정의 후 호출
작성자: 2019184020
        윤은지
*/


#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

double GetAbs(double);

int main()
{
    double num = 0.0;

    printf("실수값 입력: ");
    scanf("%lf", &num);

    num = GetAbs(num);

    printf("절대값: %f", num);

    return 0;
}

double GetAbs(double _num)
{
    if (_num < 0)
        _num = -_num;

    return _num;
}