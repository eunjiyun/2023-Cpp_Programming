/*
���ϸ�: length.c
���α׷� ����: �� ���� ��ǥ ������ ǥ���ϴ� ����ü, ������ ǥ���ϴ� ����ü, ������ ���̸� ���ϴ� �Լ��� �����Ͽ� ������ ���� ���
�ۼ���: 2019184020
		������
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

	printf("�������� ������ ��ǥ �Է�(startX, startY, endX, endY): ");
	scanf("%d %d %d %d", &link.start.x, &link.start.y, &link.end.x, &link.end.y);

	distance = GetLength(link);
	printf("������ ����: %f", distance);

	return 0;
}

double GetLength(LINE _link)
{
	double _distance = sqrt((_link.end.x - _link.start.x) * (_link.end.x - _link.start.x) +
		(_link.end.y - _link.start.y) * (_link.end.y - _link.start.y));

	return _distance;
}