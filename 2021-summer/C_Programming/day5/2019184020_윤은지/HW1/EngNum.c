/*
���ϸ�: EngNum.c
���α׷� ����: 1-5������ ������ �Է� �޾� �������� ���
�ۼ���: 2019184020
        ������
*/


#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
    int num = 0;

    printf("1���� 5������ ������ �Է��ϼ���: ");
    scanf("%d", &num);

    switch (num)
    {
    case 1:
        printf("ONE");
        break;
    case 2:
        printf("TWO");
        break;
    case 3:
        printf("THREE");
        break;
    case 4:
        printf("FOUR");
        break;
    case 5:
        printf("FIVE");
        break;
    default:
        printf("I don't know.");
        break;
    }

    return 0;
}