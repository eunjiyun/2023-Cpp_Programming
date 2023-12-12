/*
파일명: TwoInt.c
작성일: 2021/07/13
프로그램 내용: 두 변수를 입력받고 합과 차를 구한 후 출력
작성자: 2019184020
        윤은지
*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
    int fir;
    int sec;
    int sum;
    int difference;
    printf("두 변수를 입력하시오. (fir/sec) : ");
    scanf("%d %d", &fir, &sec);
    sum = fir + sec;
    difference = fir - sec;
    printf("합 = %d\n", sum);
    printf("차 = %d\n", difference);
    return 0;
}