//2. 구구단을 출력하는 프로그램을 작성하시오.몇 단을 출력할
//지는 입력 받은 수, n, 으로 가정한다.
// 파일 이름을 MultiplicationTable_2.c 로 하라.
//① for 반복문을 사용하시오
//② while 반복문을 사용하시오



#include<stdio.h>

int main(void)
{
	int n, choose;
	
	printf("몇 단을 출력할까요: ");
	scanf_s("%d", &n);//몇단을 출력할지 scanf_s 함수에 입력
	printf("1.for으로 계산\n2.while으로 계산\n");//메뉴를 출력하여 어떤 반복문을 사용할지 사용자가 선택하게 한다
	scanf_s("%d", &choose);//어떤 반복문을 사용할지 choose에 입력

	if (choose == 1)//for문 이용
	{
		for (int i = 1; i <= 9; ++i)
			printf("%d * %d = %d\n", n, i, n * i);//i가 1부터 9까지 i를 1씩 증가시키며 그 i값을  n에 곱하여 구구단 n단을 출력한다.
	}
	else if (choose == 2)//while문 이용
	{
		int i = 1;//i의 초기값은 1
		while (i <= 9 )//i가 9가 될 때까지
		{
			printf("%d * %d = %d\n", n, i, n * i);//출력
			++i;//i를 1씩 증가
		}
	}

	return 0;
};