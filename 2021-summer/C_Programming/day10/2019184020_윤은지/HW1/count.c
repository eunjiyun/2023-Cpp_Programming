/*
파일명: count.c
프로그램 내용: 정수를 입력 받아 양수, 음수, 0의 개수를 출력
작성자: 2019184020
		윤은지
*/


#define _CRT_SECURE_NO_WARNINGS
#define MAX 10
#include<stdio.h>

int main()
{
	int arr[MAX] = { 0 };
	int i = 0;
	int zero = 0;
	int posi = 0;
	int nega = 0;

	printf("정수 %d개 입력: ",MAX);
	for (i = 0; i <MAX; ++i)
		scanf("%d", &arr[i]);

	for (i = 0; i < MAX; ++i)
	{
		if (arr[i] == 0)
			++zero;
		else if (arr[i] > 0)
			++posi;
		else
			++nega;
	}

	printf("양수: %d\n", posi);
	printf("음수: %d\n", nega);
	printf("0: %d\n", zero);

	return 0;
}