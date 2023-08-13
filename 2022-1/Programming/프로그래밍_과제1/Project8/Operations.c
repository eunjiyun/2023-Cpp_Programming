// 사칙연산을 하는 계산기 프로그램을 switch 문을 사용하
//여 작성하시오.
// 무한히 반복적으로 실행
// 실행 예,
//#+ - * / 를 선택하시오: +
//#두 값을 입력하시오 : 10 20
//#10 + 20 = 30



#include<stdio.h>

int main(void)
{
	char ope='0';//ope의 초기값은 문자 0
	float fir, sec,result;

	while (1)//무한루프
	{
		printf("+ - * / 를 선택하시오: ");
		if(ope!='0')
		getchar();
		scanf_s("%c", &ope,1);//연산자 입력
		
		printf("두 값을 입력하시오: ");
		scanf_s("%f %f", &fir,&sec);//값 입력

		switch (ope)
		{
		case '+'://덧셈
			result = fir + sec;
			break;
		case '-'://뺄셈
			result = fir - sec;
			break;
		case '*'://곱셈
			result = fir *sec;
			break;
		case '/'://나눗셉
			result = fir /sec;
			break;
		default:
			printf("잘못된 입력입니다.\n");//잘못된 입력 처리
			break;
		}
		printf("%f %c %f = %f\n\n\n", fir, ope, sec, result);//출력
	}
	
	return 0;
}