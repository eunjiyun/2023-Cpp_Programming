/*
파일명: Swap.c
프로그램 내용: 두 변수에 저장된 값을 바꾸는 함수를 정의, 호출하여 값을 확인
작성자: 2019184020
        윤은지
*/


#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
void Swap(int* _fir, int* _sec);

int main()
{
    int fir = 0;
    int sec = 0;

    printf("두 정수 입력: ");
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
