/*
���ϸ�: hw2.c
���α׷� ����: ���� �ϳ��� �Է� �޾� �� �� ��ŭ 3�� ����� ���
�ۼ���: 2019184020
        ������
*/


#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>   

int main()
{
    int num = 0;

    printf("������ �Է��ϼ���: ");
    scanf("%d", &num);

    for (int i = 1; i <= num; ++i)
        printf("%d ", i* 3);

    return 0;
}