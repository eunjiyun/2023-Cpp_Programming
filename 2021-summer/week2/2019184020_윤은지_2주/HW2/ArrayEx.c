/*
���ϸ�: AarrayEx.c
���α׷� ����: �迭�� ���� 5���� �Է� �޾� �ִ밪�� ���ϱ�
�ۼ���: 2019184020
		������
*/


#define _CRT_SECURE_NO_WARNINGS
#define MAX 5
#include<stdio.h>

int main(void)
{
	int arry[MAX] = { 0 };
	int i = 0;
	int max = 0;

	printf("%d���� ���� �Է�: ", MAX);
	for (i = 0; i < MAX; ++i)
		scanf("%d", &arry[i]);

	max = arry[0];
	for (i = 0; i < MAX; ++i)
		if (max < arry[i])
			max = arry[i];

	printf("max: %d", max);

	return 0;
}