/*
���ϸ�: Swap.c
���α׷� ����: �� ������ ����� ���� �ٲٴ� �Լ��� ����, ȣ���Ͽ� ���� Ȯ��
�ۼ���: 2019184020
        ������
*/


#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
void Swap(int* _fir, int* _sec);

int main()
{
    int fir = 0;
    int sec = 0;

    printf("�� ���� �Է�: ");
    scanf("%d %d", &fir, &sec);

    Swap(&fir, &sec);

    printf("fir = %d\nsec = %d", fir, sec);

    return 0;
}

void Swap(int* _fir, int* _sec)
{
    int temp = 0;

    temp = *_fir;
    *_fir = *_sec;
    *_sec = temp;
}
