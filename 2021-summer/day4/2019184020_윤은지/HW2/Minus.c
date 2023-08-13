/*
파일명: Minus.c
프로그램 내용: 두 정수를 입력 받아 큰 수에서 작은 수를 빼고 그 값을 출력
작성자: 2019184020
		윤은지
*/


#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int fir = 0;
	int sec = 0;
	int max = 0;
	int min = 0;

	printf("두 정수를 입력하세요: ");
	scanf("%d %d", &fir,&sec);

	max = fir >= sec ? fir : sec;
	min= fir < sec ? fir : sec;

	printf("%d", max - min);

	return 0;
}