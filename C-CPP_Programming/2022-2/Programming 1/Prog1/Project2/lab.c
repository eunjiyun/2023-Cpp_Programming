#include <stdio.h>

int main(void)
{
	int num = 0;

	for (int a = 1; a <= 100; a++)
		for (int b = 1; b <= 100; b++)
			for (int c = 1; c <= 100; c++)
				if ((a * a + b * b) == c * c)
					if (a < b)//3 4 5, 4 3 5 와 같이 같은 삼각형이 두 번 출력되므로 a가 b보다 작다는 조건을 추가해주면 한 번만 출력된다. c는 항상 a나 b보다는 크므로 제외
					{
						printf("%d %d %d\n", a, b, c);
						++num;//직각 삼각형의 개수
					}

	printf("직각 삼각형의 개수 : %d개\n", num);

	return 0;
}