/*
파일명: Point.c
프로그램 내용: 2차원 평면에 있는 점의 좌표를 입력 받고 어느 사분면의 점인지 출력
작성자: 2019184020
        윤은지
*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main(void)
{
    int xPos = 0;
    int yPos = 0;

    printf("점의 좌표(x,y)? ");
    scanf("%d %d", &xPos, &yPos);

    if (xPos == 0 || yPos == 0)
        printf("어느 사분면에도 있지 않습니다.");
    else
    {
        if (xPos > 0 && yPos > 0)
            printf("1사분면에 있습니다.");
        else  if (xPos <0 && yPos > 0)
            printf("2사분면에 있습니다.");
        else  if (xPos <0 && yPos < 0)
            printf("3사분면에 있습니다.");
        else  if (xPos > 0 && yPos <0)
            printf("4사분면에 있습니다.");
    }

    return 0;
}