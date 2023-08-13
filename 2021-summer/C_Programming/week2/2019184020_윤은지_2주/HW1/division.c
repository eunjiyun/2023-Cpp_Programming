/*
파일명: division.c
프로그램 내용: 함수를 이용하여 약수와 약수 개수 구하기
작성자: 2019184020
		윤은지
*/


#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

void divide(int);

int main(void)
{
	int num = 1;

	while (num != 0)
	{
		printf("양의 정수?(0입력시 종료): ");
		scanf("%d", &num);

		divide(num);
	}

	return 0;
}

void divide(int _num)
{
	int i = 0;
	int count = 0;

	if (_num < 0)
	{
		printf("잘못된 값입니다.\n");
		return;
	}

	if (_num != 0)
		printf("  %d의 약수: ", _num);
	for (i = 1; i <= _num; ++i)
	{
		if (_num % i == 0)
		{
			printf("%d ", i);
			++count;
		}
	}
	if (_num != 0)
		printf("=> 총 %d개\n", count);
}