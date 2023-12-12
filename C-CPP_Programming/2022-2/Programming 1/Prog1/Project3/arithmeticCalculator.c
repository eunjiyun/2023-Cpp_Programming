#include<stdio.h>

int main(void)
{
	char input = 'i';//Q가 아닌 값으로 초기화
	float fir = 0;//연산을 할 것이기 때문에 0으로 초기화
	float sec = 0;//연산을 할 것이기 때문에 0으로 초기화
	
	printf("************************************\n");//메뉴 출력
	printf("A---- Add\n");
	printf("S---- Subtract\n");
	printf("M---- Multiply\n");
	printf("D---- Divide\n");
	printf("Q---- Quit\n");
	printf("************************************\n");

	printf("연산을 선택하시오: ");
	scanf_s("%c", &input);//연산 기호 입력, scanf 함수 경고 때문에 scanf_s 사용

	while (input != 'Q')//Q가 입력되면 종료
	{
		if (input == 'A' || input == 'S' || input == 'M' || input == 'D')//다음 연산 기호가 아니면 메뉴를 다시 출력
		{
			printf("두 수를 공백으로 분리하여 입력하시오: ");
			scanf_s("%f %f", &fir, &sec);//연산할 수를 입력

			if (input == 'A')
				printf("%.f %c %.f = %.f\n", fir, '+', sec, fir + sec);//%.f를 사용해서 수의 소수점을 표시하지 않고 덧셈
			else if (input == 'S')
				printf("%.f %c %.f = %.f\n", fir, '-', sec, fir - sec);//뺄셈
			else if (input == 'M')
				printf("%.f %c %.f = %.f\n", fir, '*', sec, fir * sec);//곱셈
			else if (input == 'D')
			{
				if (sec != 0)//나누는 수가 0이 아닐 때에 나눗셈
					printf("%.f %c %.f = %f\n", fir, '/', sec, fir / sec);//입력 받은 두 수의 소수점은 표시하지 않고 결과값은 소수점 6째자리까지 표시
				else//나누는 수가 0일때 에러 메시지 출력
					printf("0으로 나눌 수 없습니다.\n");
			}
		}

		printf("************************************\n");//메뉴 출력
		printf("A---- Add\n");
		printf("S---- Subtract\n");
		printf("M---- Multiply\n");
		printf("D---- Divide\n");
		printf("Q---- Quit\n");
		printf("************************************\n");

		printf("연산을 선택하시오: ");//연산 기호 입력, 버퍼에 엔터가 들어가서 메뉴가 두 번 출력되는 문제 때문에 %c 앞에 한 칸을 띄움
		scanf_s(" %c", &input);
	}

	printf("프로그램을 종료합니다.");//종료 메시지 출력

	return 0;
}