/*
���ϸ�: Gugu.c
���α׷� ����: �Է� ���� �� ���� �������� ���
�ۼ���: 2019184020
        ������
*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main(void)
{
    int choose = 0;

    printf("�� ���� ����Ͻðڽ��ϱ�? ");
    scanf("%d", &choose);

    if (choose < 1)
        printf("�߸��� �Է��Դϴ�.");
    else
    {
        printf("%d*%d=%2d\n", choose, 9, choose * 9);
        printf("%d*%d=%2d\n", choose, 8, choose * 8);
        printf("%d*%d=%2d\n", choose, 7, choose * 7);
        printf("%d*%d=%2d\n", choose, 6, choose * 6);
        printf("%d*%d=%2d\n", choose, 5, choose * 5);
        printf("%d*%d=%2d\n", choose, 4, choose * 4);
        printf("%d*%d=%2d\n", choose, 3, choose * 3);
        printf("%d*%d=%2d\n", choose, 2, choose * 2);
        printf("%d*%d=%2d\n", choose, 1, choose * 1);
    }

    return 0;
}