/*
���ϸ�: Area.c
���α׷� ����: �������� �Է� �޾� ���� ���̸� ���
�ۼ���: 2019184020
        ������
*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main(void)
{
    int radius = 0;
    float area = 0;
    const float pie = 3.141592;

    printf("������: ");
    scanf("%d", &radius);

    area = pie * radius * radius;
    printf("���� ����: %15.2f", area);

    return 0;
}