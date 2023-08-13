/*
파일명: pointer.c
프로그램 내용: 포인터 4번 문제
작성자: 2019184020
		윤은지
*/


#include<stdio.h>

int main()
{
	char ch;
	int n;
	double d;
	int arr[5];
	int i;

	char* pc = &ch;
	int* pi = &n;
	double* pd = &d;

	for (i = 0; i < 3; ++i)
		printf("pc + %d = %p\n", i, pc + i);

	for (i = 0; i < 3; ++i)
		printf("pi + %d = %p\n", i, pi + i);

	for (i = 0; i < 3; ++i)
		printf("pd + %d = %p\n", i, pd + i);

	for (i = 0; i < 5; ++i)
		printf("&arr[%d] - &arr[%d] = %d\n", i, 0, &arr[i] - &arr[0]);

	return 0;
}