/*
���ϸ�: Point.c
���α׷� ����: 2���� ��鿡 �ִ� ���� ��ǥ�� �Է� �ް� ��� ��и��� ������ ���
�ۼ���: 2019184020
        ������
*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main(void)
{
    int xPos = 0;
    int yPos = 0;

    printf("���� ��ǥ(x,y)? ");
    scanf("%d %d", &xPos, &yPos);

    if (xPos == 0 || yPos == 0)
        printf("��� ��и鿡�� ���� �ʽ��ϴ�.");
    else
    {
        if (xPos > 0 && yPos > 0)
            printf("1��и鿡 �ֽ��ϴ�.");
        else  if (xPos <0 && yPos > 0)
            printf("2��и鿡 �ֽ��ϴ�.");
        else  if (xPos <0 && yPos < 0)
            printf("3��и鿡 �ֽ��ϴ�.");
        else  if (xPos > 0 && yPos <0)
            printf("4��и鿡 �ֽ��ϴ�.");
    }

    return 0;
}