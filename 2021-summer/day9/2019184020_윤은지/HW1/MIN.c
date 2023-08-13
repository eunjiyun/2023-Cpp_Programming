/*
파일명: MIN.c
프로그램 내용: 세 정수를 인자로 전달 받아 함수의 리턴값을 이용하여 
최소값을 구하기
작성자: 2019184020
        윤은지
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

    printf("세 정수를 입력:  ");
    scanf("%d %d %d", &fir, &sec, &thi);

    min=GetMin(fir, sec, thi);

    printf("최소값: %d", min);

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