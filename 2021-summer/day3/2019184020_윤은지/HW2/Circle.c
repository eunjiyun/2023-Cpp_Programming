/*
���ϸ�: Circle.c
���α׷� ����: ���� �������� �Է� �޾� ���ָ� ����Ѵ�.
�ۼ���: 2019184020
        ������
*/


#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
    double rad;//������ ����
    double circleCircumference;//���� ���� ��� ����

    printf("������ �Է�: ");
    scanf("%lf", &rad);

    circleCircumference = rad *2  * 3.1415;

    printf("���� �ѷ� = %f\n", circleCircumference);

    return 0;
}