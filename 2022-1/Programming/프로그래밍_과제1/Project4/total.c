//1. 정수 n을 입력 받아 1부터 n까지 정수 중 짝수의 합과 홀수
//의 합을 구하시오.
//① for 반복문을 사용하시오
//② while 반복문을 사용하시오



#include<stdio.h>

int main(void)
{
	int n,choose;//n 문제에서 요구한 정수 n, choose는 for와 while중 사용할 것을 선택하기 위한 변수
	int evenSum = 0;//짝수일 때의 합으로 초기값을 0으로 한다.
	int oddSum = 0;//홀수 일때의 합으로 초기값을 0으로 한다.

	printf("정수 n을 입력: ");
	scanf_s("%d", &n);//정수 n을 입력
	printf("1.for으로 계산\n2.while으로 계산\n");
	scanf_s("%d", &choose);//for와 while중에 선택

	if (choose == 1)//for을 이용
	{
		for (int i = 2; i <= n; i += 2)//i는 2부터 n까지 2씩 증가 
			evenSum += i;//i를 for문이 종료될 때까지 evenSum에 더한다.

		for (int i = 1; i <= n; i += 2)//i는 1부터 n까지 2씩 증가 
			oddSum += i;
	}
	else if (choose == 2)//while을 이용
	{
		int i = 2;//i의 초기값은 2
		while (i <= n)//i는 n이 될 때까지, i가 n을 초과하면 while문을 빠져나간다. 
		{
			evenSum += i;
			i += 2;//i는 2씩 증가
		}

		 i = 1;
		while (i <= n)
		{
			oddSum += i;
			i += 2;
		}
	}
	printf("짝수의 합: %d\n", evenSum);//출력
	printf("홀수의 합: %d\n", oddSum);

	return 0;
};