/*
���ϸ�: StructScore.c
���α׷� ����: ����ü�� �����ϰ� ����ü�� ��� ������ ����, �����Ͽ� ���� ���
�ۼ���: 2019184020
        ������
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

    printf("����, ����, ������ ������ �Է�: ");
    scanf("%d %d %d", &person.kor, &person.eng, &person.mat);

    person.ave = (double)(person.kor + person.eng + person.mat) / 3;

    printf("name: %s\nkor: %d\neng: %d\nmat: %d\nave: %f",
        person.name,person.kor, person.eng, person.mat, person.ave);

    return 0;
}

