/*
���ϸ�: count.c
���α׷� ����: ������ �Է� �޾� ���, ����, 0�� ������ ���
�ۼ���: 2019184020
		������
*/


#define _CRT_SECURE_NO_WARNINGS
#define MAX 10
#include<stdio.h>

int main()
{
	int arr[MAX] = { 0 };
	int i = 0;
	int zero = 0;
	int posi = 0;
	int nega = 0;

	printf("���� %d�� �Է�: ",MAX);
	for (i = 0; i <MAX; ++i)
		scanf("%d", &arr[i]);

	for (i = 0; i < MAX; ++i)
	{
		if (arr[i] == 0)
			++zero;
		else if (arr[i] > 0)
			++posi;
		else
			++nega;
	}

	printf("���: %d\n", posi);
	printf("����: %d\n", nega);
	printf("0: %d\n", zero);

	return 0;
}