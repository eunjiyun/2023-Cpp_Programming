/*
파일명: StructScore.c
프로그램 내용: 구조체를 정의하고 구조체의 멤버 변수에 접근, 연산하여 값을 출력
작성자: 2019184020
        윤은지
*/


struct student
{
    char name[10];
    int kor;
    int eng;
    int mat;
    double ave;
};
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
    struct student person = { "Yoon" };

    printf("국어, 영어, 수학의 점수를 입력: ");
    scanf("%d %d %d", &person.kor, &person.eng, &person.mat);

    person.ave = (double)(person.kor + person.eng + person.mat) / 3;

    printf("name: %s\nkor: %d\neng: %d\nmat: %d\nave: %f",
        person.name,person.kor, person.eng, person.mat, person.ave);

    return 0;
}

