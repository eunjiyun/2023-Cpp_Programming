/*
���ϸ�: flFunc.c
���α׷� ����: �Ǽ����� ���ڷ� ���� �޾� ���밪�� ���ϴ� �Լ��� ���� �� ȣ��
�ۼ���: 2019184020
        ������
*/


#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

double GetAbs(double);

int main()
{
    double num = 0.0;

    printf("�Ǽ��� �Է�: ");
    scanf("%lf", &num);

    num = GetAbs(num);

    printf("���밪: %f", num);

    return 0;
}

double GetAbs(double _num)
{
    if (_num < 0)
        _num = -_num;

    return _num;
}