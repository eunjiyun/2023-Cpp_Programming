//임의의 양의 정수를 입력받아 팩토리얼을 구하시오.
// 파일 이름을 factorial.c 로 작성
// for loop을 while loop로 변경하여 작성



#include<stdio.h>

int main(void)
{
	int n, choose;
	int nfact = 1;//초기값이 0이면 값을 곱해도 0이되므로 초기값은 1

	printf("정수 n을 입력: ");
	scanf_s("%d", &n);//정수 n을 입력
	printf("1.for으로 계산\n2.while으로 계산\n");
	scanf_s("%d", &choose);//for를 사용하리 while을 사용할지 입력

	if (choose == 1)//for을 사용
	{
		for (int i = n; i >= 1; --i)//i가 n일 때부터 i가 1이 될 때까지 1씩 i를 감소시킨다.
			nfact *= i;//nfact에 i를 곱하고 그 값을 nfact에 대입한다.
	}
	else if (choose == 2)//while을 사용
	{
		int i = n;
		while (i >= 1 )
		{
			nfact *= i;
			--i;
		}
	}

	printf("%d팩토리얼은 %d\n", n, nfact);//출력

	return 0;
};