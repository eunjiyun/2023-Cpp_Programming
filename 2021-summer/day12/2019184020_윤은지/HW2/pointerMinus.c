/*
파일명: pointerMinus.c
프로그램 내용: 포인터에 대한 감소연산자 사용
작성자: 2019184020
		윤은지
*/


#include<stdio.h>   

int main()
{
	int arr[5] = { 1,2,3,4,5 };
	int* ptr = &arr[4];
	int sum = 0;
	int i = 0;

	for (i = 0; i < 5; ++i)
		sum += *ptr--;
	
	printf("sum: %d", sum);

	return 0;
}