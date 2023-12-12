/*
파일명: length.c
프로그램 내용: 한 점의 좌표 정보를 표현하는 구조체, 직선을 표현하는 구조체, 직선의 길이를 구하는 함수를 정의하여 직선의 길이 출력
작성자: 2019184020
		윤은지
*/


#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>   
#include<math.h>
typedef struct point
{
	int x;
	int y;
}POINT;
typedef struct line
{
	POINT start;
	POINT end;
}LINE;
double GetLength(LINE);

int main(void)
{
	LINE link;
	double distance = 0;

	printf("시작점과 끝점의 좌표 입력(startX, startY, endX, endY): ");
	scanf("%d %d %d %d", &link.start.x, &link.start.y, &link.end.x, &link.end.y);

	distance = GetLength(link);
	printf("직선의 길이: %f", distance);

	return 0;
}

double GetLength(LINE _link)
{
	double _distance = sqrt((_link.end.x - _link.start.x) * (_link.end.x - _link.start.x) +
		(_link.end.y - _link.start.y) * (_link.end.y - _link.start.y));

	return _distance;
}