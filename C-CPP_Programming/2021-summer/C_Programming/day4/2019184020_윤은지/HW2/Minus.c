/*
���ϸ�: Minus.c
���α׷� ����: �� ������ �Է� �޾� ū ������ ���� ���� ���� �� ���� ���
�ۼ���: 2019184020
		������
*/


#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int fir = 0;
	int sec = 0;
	int max = 0;
	int min = 0;

	printf("�� ������ �Է��ϼ���: ");
	scanf("%d %d", &fir,&sec);

	max = fir >= sec ? fir : sec;
	min= fir < sec ? fir : sec;

	printf("%d", max - min);

	return 0;
}