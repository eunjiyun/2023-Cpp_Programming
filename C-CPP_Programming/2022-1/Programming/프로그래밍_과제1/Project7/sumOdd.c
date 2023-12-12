//임의의 수 n을 입력 받아 0부터 첫 n개의 짝수의 합과 첫
//n개의 홀수의 합을 계산하는 프로그램을 다음에 따라 3
//가지로 작성하시오.
//1. 아래에 주어진 문장을 사용하여 프로그램을 작성하시오.
//2. for 반복문의 실행문에 콤마 연산자를 사용하지 말고 작성하시
//오.
//3. while문만 사용하시오.
//수식:
//for (cnt = 0, i = 1, j = 2; cnt < n; ++cnt, i += 2, j += 2)
//	sum_odd += i, sum_even += j;



#include<stdio.h>

int main(void)
{
	int n, choose, cnt,i,j;
	int sum_odd = 0;//합계의 초기값은 0
	int sum_even = 0;

	printf("정수 n을 입력: ");
	scanf_s("%d", &n);//정수 n입력
	printf("1.주어진 문장\n2.for\n3.while\n");//메뉴 출력
	scanf_s("%d", &choose);//메뉴 선택

	if (choose == 1)//주어진 문장을 이용
	{
		//cnt의 초기값은 0, i의 초기값은 1, j의 초기값은 0이고 cnt가 n보다 작을때까지 cnt는 1씩,i와 j는 2씩 증가시킨다.
		for (cnt = 0, i = 1, j = 0; cnt < n; ++cnt, i += 2, j += 2)
			sum_odd += i, sum_even += j;//i는 sum_odd에 더하고, j는 sum_even에 더한다.
	}
	else if (choose == 2)//for
	{
		for (int i = 0; i <=( n-1) * 2; i += 2)//i는 0부터 2n-2까지 i를 2씩 증가
			sum_even += i;

		for (int i = 1; i <= n * 2; i += 2)
			sum_odd += i;
	}
	else if (choose == 3)//while
	{
		int i = 0;
		while (i <= (n - 1) * 2)
		{
			sum_even += i;
			i += 2;
		}

		i = 1;
		while (i <= n * 2)
		{
			sum_odd += i;
			i += 2;
		}
	}
	printf("첫 n개의 짝수의 합: %d\n", sum_even);//출력
	printf("첫 n개의 홀수의 합: %d\n", sum_odd);

	return 0;
}