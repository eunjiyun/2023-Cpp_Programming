/*
���ϸ�: Float.c
�ۼ���: 2021/07/13
���α׷� ����: �Է� ���� �Ǽ��� 100�� ���ϰ� �� ���� ���
�ۼ���: 2019184020
        ������
*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
    float num;
    float result;
    printf("�Ǽ��� �Է��ϼ���: ");
    scanf("%f", &num);
    result = num * 100;
    printf("result = %f", result);
    return 0;
}