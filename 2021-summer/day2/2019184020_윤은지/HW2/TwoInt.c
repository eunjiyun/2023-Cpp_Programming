/*
���ϸ�: TwoInt.c
�ۼ���: 2021/07/13
���α׷� ����: �� ������ �Է¹ް� �հ� ���� ���� �� ���
�ۼ���: 2019184020
        ������
*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
    int fir;
    int sec;
    int sum;
    int difference;
    printf("�� ������ �Է��Ͻÿ�. (fir/sec) : ");
    scanf("%d %d", &fir, &sec);
    sum = fir + sec;
    difference = fir - sec;
    printf("�� = %d\n", sum);
    printf("�� = %d\n", difference);
    return 0;
}