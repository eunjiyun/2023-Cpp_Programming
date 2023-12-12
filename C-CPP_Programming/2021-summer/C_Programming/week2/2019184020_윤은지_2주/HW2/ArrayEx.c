/*
파일명: AarrayEx.c
프로그램 내용: 배열에 정수 5개를 입력 받아 최대값을 구하기
작성자: 2019184020
		윤은지
*/


#define _CRT_SECURE_NO_WARNINGS
#define MAX 5
#include<stdio.h>

int main(void)
{
	int arry[MAX] = { 0 };
	int i = 0;
	int max = 0;

	printf("%d개의 정수 입력: ", MAX);
	for (i = 0; i < MAX; ++i)
		scanf("%d", &arry[i]);

	max = arry[0];
	for (i = 0; i < MAX; ++i)
		if (max < arry[i])
			max = arry[i];

	printf("max: %d", max);

	return 0;
}