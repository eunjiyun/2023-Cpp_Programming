/*
���ϸ�: hw1.c
���α׷� ����: ���� �ϳ��� �Է� �޾� �� ���������� ���� ���ϱ�
�ۼ���: 2019184020
        ������
*/


#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>   

int main()
{
    int num = 0;
    int i = 0;
    int sum = 0;
    
    printf("���� �ϳ��� �Է��ϼ���: ");
    scanf("%d", &num);

    for (i = 1; i <= num ; ++i)
        sum += i;

    printf("%d", sum);

    return 0;
}