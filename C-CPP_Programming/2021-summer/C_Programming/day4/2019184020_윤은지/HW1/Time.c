/*
���ϸ�: Time.c
���α׷� ����: ������, ������ ������ �̿��Ͽ� �ʸ� �ð�, ��, �� ������ �ٲٱ�
�ۼ���: 2019184020
		������
*/


#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int second = 0;
	int min = 0;
	int hour = 0;

	printf("�ʸ� �Է��ϼ���: ");
	scanf("%d", &second);

	hour = second / 3600;
	min = second % 3600 / 60;
	second = second % 3600 % 60;

	printf("%d�ð� %d�� %d��", hour, min, second);

	return 0;
}