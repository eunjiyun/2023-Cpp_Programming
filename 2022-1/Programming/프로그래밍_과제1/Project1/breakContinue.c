// 다음 코드를 break나 continue문을 사용치 않도록 수정하시오.
//#include<stdio.h>
//
//int main(void)
//{
//	int cnt = 0, digit_cnt = 0, i, total = 0;
//	char c;
//
//	while (c = getchar()) 
//	{
//		if (c == 'q') break;
//		++cnt;
//		if (c >= '0' && c <= 'g') ++digit_cnt;
//		i = 1;
//		while (i++ <= c) {
//			if (c == 'B') continue;
//			total += 1;
//			printf("input = % c and total = % d\n", c, total);
//		}
//	}
//
//	return 0;
//}



#include<stdio.h>

int main(void)
{
	int cnt = 0, digit_cnt = 0, i, total = 0;
	char c;

	while (c = getchar()) 
	{
		if (c == 'q')
			goto OUT;//break문은 가장 안 쪽의 반복문을 탈출
		++cnt;

		if (c >= '0' && c <= 'g')
			++digit_cnt;
		i = 1;

		while (i++ <= c)
		{
			if (c == 'B')
				goto IN;// continue문은 반복문 안의 continue다음을 건너뛰고 다음 반복을 실행
			total += 1;
			printf("input = % c and total = % d\n", c, total);
		IN:
			printf("");
		}
	}
	OUT:

	return 0;
}