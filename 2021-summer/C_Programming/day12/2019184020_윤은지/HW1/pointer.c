/*
파일명: pointer.c
프로그램 내용: 포인터에 대한 덧셈 연산
작성자: 2019184020
		윤은지
*/


#include<stdio.h>

int main()
{
	int arr[5] = { 1,2,3,4,5 };
	int* ptr = arr;
	int i = 0;

	for (i = 0; i < 5; ++i)
		*(ptr + i) += 5;

	return 0;
}