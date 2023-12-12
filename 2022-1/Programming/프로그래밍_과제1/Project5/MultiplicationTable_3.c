//이중 반복문을 사용하여 구구단 2단에서 9단까지 계산하
//는 프로그램을 작성하시오.
// 파일 이름을 MultiplicationTable_3.c 하시오.
//1. for 반복문을 사용하시오.
//2. while 반복문을 사용하시오.



#include<stdio.h>

int main(void)
{
	int choose;
	printf("1.for으로 계산\n2.while으로 계산\n");
	scanf_s("%d", &choose);//for로 할지 while로 할지 선택

	if (choose == 1)//for문 이용
	{
		for (int i = 2; i <= 9; ++i)//2단 부터 9단까지를 의미
			for (int j = 1; j <= 9; ++j)//1부터 9까지를 곱한다는 의미
				printf("%d * %d = %d\n",i,j,i*j);
	}
	else if (choose == 2)//while문 이용
	{
		int i = 2;
		while (i <= 9)
		{
			int j = 1;
			while ( j <= 9 )
			{
				printf("%d * %d = %d\n", i, j, i * j);
				++j;
			}
			++i;
		}
	}

	return 0;
};
