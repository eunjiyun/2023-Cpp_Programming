/*
���ϸ�: ArraySum.c
���α׷� ����: int�� �迭�� �հ踦 ���ϴ� �Լ� ����, ȣ�� �� �迭�� �հ� ���
�ۼ���: 2019184020
        ������
*/


#include<stdio.h>
int GetSumOfArray(int*, int);

int main()
{
    int arr[5] = { 10,20,30,40,50 };

    printf("�迭�� �հ� = %d",GetSumOfArray(arr, 5));

    return 0;
}

int GetSumOfArray(int* _arr,int size )
{
    int total = 0;
    int i = 0;

    for (i = 0; i < size; ++i)
        total += *(_arr + i);

    return total;
}
