/*
���ϸ�: pointerMinus.c
���α׷� ����: �����Ϳ� ���� ���ҿ����� ���
�ۼ���: 2019184020
		������
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