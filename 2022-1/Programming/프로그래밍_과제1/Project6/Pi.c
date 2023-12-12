//반복문을 사용하여
// 문자 A(Area) 입력하면 반지름(r)을 입력 받아
//PI* r* r 을 계산하여 그 값을 표준 출력장치에 출력하시오.
// 문자 C(Circumference) 입력하면 반지름(r) 을 입력 받아
//2 * PI * r 을 계산하여 출력하시오.
// 문자 Q를 입력하면 실행을 끝내시오.



#include<stdio.h>
#define PI 3.141592//PI를 3.141592로 정의

int main(void)
{
	char choose = '0';//초기값을 문자 0으로 한다.
	float r;

	while (choose != 'Q')//choose가 문자 Q일 때 종료
	{
		if(choose!='\n')
			printf("A: Area\nC: Circumference\nQ: 종료\n");//메뉴를 출력하여 사용자가 선택할 수 있게 한다.
		scanf_s("%c", &choose,1);//메뉴중 하나를 선택한다.

		if(choose=='A')//choose가 A일 때
		{
			printf("반지름 r을 입력: ");
			scanf_s("%f", &r);//반지름 값 입력
			printf("Area: %f\n\n\n", PI * r * r);//반지름 값 출력
		}
		else if(choose=='C')//choose가 C일 때
		{
			printf("반지름 r을 입력: ");
			scanf_s("%f", &r);//반지름 값 입력
			printf("Circumference: %f\n\n\n", 2 * PI * r);//반지름 값 출력
		}
	}

	return 0;
}
