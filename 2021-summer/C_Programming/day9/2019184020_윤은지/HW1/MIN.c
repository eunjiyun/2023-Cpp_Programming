/*
���ϸ�: MIN.c
���α׷� ����: �� ������ ���ڷ� ���� �޾� �Լ��� ���ϰ��� �̿��Ͽ� 
�ּҰ��� ���ϱ�
�ۼ���: 2019184020
        ������
*/


#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int GetMin(int,int,int);

int main()
{
    int fir = 0;
    int sec = 0;
    int thi = 0;
    int min= 0;

    printf("�� ������ �Է�:  ");
    scanf("%d %d %d", &fir, &sec, &thi);

    min=GetMin(fir, sec, thi);

    printf("�ּҰ�: %d", min);

    return 0;
}

int GetMin(int _fir, int _sec, int _thi)
{
    int firstM = 0;
    int _min = 0;

    firstM = _fir < _sec ? _fir : _sec;
    _min = firstM < _thi ? firstM : _thi;

    return _min;
}