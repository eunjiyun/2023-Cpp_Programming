/*
���ϸ�: division.c
���α׷� ����: �Լ��� �̿��Ͽ� ����� ��� ���� ���ϱ�
�ۼ���: 2019184020
		������
*/


#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

void divide(int);

int main(void)
{
	int num = 1;

	while (num != 0)
	{
		printf("���� ����?(0�Է½� ����): ");
		scanf("%d", &num);

		divide(num);
	}

	return 0;
}

void divide(int _num)
{
	int i = 0;
	int count = 0;

	if (_num < 0)
	{
		printf("�߸��� ���Դϴ�.\n");
		return;
	}

	if (_num != 0)
		printf("  %d�� ���: ", _num);
	for (i = 1; i <= _num; ++i)
	{
		if (_num % i == 0)
		{
			printf("%d ", i);
			++count;
		}
	}
	if (_num != 0)
		printf("=> �� %d��\n", count);
}