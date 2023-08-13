/*
파일명: Time.c
프로그램 내용: 나눗셈, 나머지 연산을 이용하여 초를 시간, 분, 초 단위로 바꾸기
작성자: 2019184020
		윤은지
*/


#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int second = 0;
	int min = 0;
	int hour = 0;

	printf("초를 입력하세요: ");
	scanf("%d", &second);

	hour = second / 3600;
	min = second % 3600 / 60;
	second = second % 3600 % 60;

	printf("%d시간 %d분 %d초", hour, min, second);

	return 0;
}