// 임의의 수 n을 입력 받아 1부터 n까지의 합을 구하여 출력
//하는 프로그램을 작성하시오.
// 단, 임의의 양수 n을 입력 받아 그 합을 출력한 후 다시 양수 n의
//값을 입력 받는 방식으로 무한히 프로그램이 실행
//1. 프로그램을 for 반복문을 사용하여 구현하시오.
//2. while 반복문을 사용하여 수행하도록 수정하시오.



#include<stdio.h>

int main(void)
{
	int n, total, choose;

	printf("1.for문으로 계산\n2.while문으로 계산\n");//메뉴를 출력하여 어떤 반복문을 사용할건지 선택
	scanf_s("%d", &choose);//사용자의 선택을 scanf_s함수로 입력 받는다.

	if (choose == 1)//사용자의 선택이 1일 때
	{
		for(;;)//무한루프
		{
			printf("임의의 양수 n을 입력: ");
			scanf_s("%d", &n);//n에 임의의 양수값 입력
			total = 0;//초기값은 0으로 설정해야 총 합계를 구할 때 문제가 없다

			for (int i = 1; i <= n; ++i)
				total += i;//i가 1일때부터 n일때 까지 i값을 1씩 증가시키며 total변수에 더한다.

			printf("1부터 %d까지의 합: %d\n", n, total);
		}
	}
	else if(choose==2)//사용자의 선택이 2일 때
	{
		while (1)
		{
			printf("임의의 양수 n을 입력: ");
			scanf_s("%d", &n);
			total = 0;

			int i = 1;
			while (i <= n)
			{
				total += i;
				++i;
			}

			printf("1부터 %d까지의 합: %d\n", n, total);
		}
	}
	
	return 0;
}