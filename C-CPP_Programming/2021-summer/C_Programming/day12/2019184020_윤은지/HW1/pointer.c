/*
���ϸ�: pointer.c
���α׷� ����: �����Ϳ� ���� ���� ����
�ۼ���: 2019184020
		������
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