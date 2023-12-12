#include<stdio.h>

int main(void)
{
	unsigned int result = 0;
	unsigned int tmp;
	char input;

	for (int i = 0; i < 4; ++i)
	{
		printf("%d번째 문자를 입력: ", i + 1);
		scanf_s(" %c", &input);
		tmp = input;

		if (1 == i)
			tmp <<= 8;
		else if (2 == i)
			tmp <<= 16;
		else if (3 == i)
			tmp <<= 24;

		if (i != 0)
			result |= tmp;
		else
			result = tmp;
	}
	printf("결과값: %#x", result);

	return 0;
}