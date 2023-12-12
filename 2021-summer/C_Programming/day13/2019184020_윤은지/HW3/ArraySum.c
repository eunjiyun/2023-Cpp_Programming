/*
파일명: ArraySum.c
프로그램 내용: int형 배열의 합계를 구하는 함수 정의, 호출 후 배열의 합계 출력
작성자: 2019184020
        윤은지
*/


#include<stdio.h>
int GetSumOfArray(int*, int);

int main()
{
    int arr[5] = { 10,20,30,40,50 };

    printf("배열의 합계 = %d",GetSumOfArray(arr, 5));

    return 0;
}

int GetSumOfArray(int* _arr,int size )
{
    int total = 0;
    int i = 0;

    for (i = 0; i < size; ++i)
        total += *(_arr + i);

    return total;
}
