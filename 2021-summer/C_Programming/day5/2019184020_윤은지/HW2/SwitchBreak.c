/*
���ϸ�: SwitchBreak.c
���α׷� ����: switch���� �̿��Ͽ� �Է��� ���ڷ� �����ϴ� �ܾ� ���
�ۼ���: 2019184020
        ������
*/


#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
    char word;

    printf("���ڸ� �Է��ϼ���: ");
    scanf("%c", &word);

    switch (word)
    {
    case 'M':case'm':
        printf("Morning");
        break;
    case 'A':case'a':
        printf("Afternoon");
        break;
    case 'E':case'e':
        printf("Evening");
        break;
    default:
        printf("�߸��� �Է��Դϴ�.");
        break;
    }

    return 0;
}