/*
���ϸ�: Integer.c
���α׷� ����: 16������ �Է� �޾� 10������ ��ȯ�ϰ� ���
�ۼ���: 2019184020
        ������
*/


#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
    int input = 0;
    
    printf("16������ ������ �Է��ϼ���: ");
    scanf("%x", &input);

    printf("%x�� 10������ %d�Դϴ�.\n",input,input);

    return 0;
}