#include <stdio.h>

int main(void)
{
	int num = 0;

	for (int a = 1; a <= 100; a++)
		for (int b = 1; b <= 100; b++)
			for (int c = 1; c <= 100; c++)
				if ((a * a + b * b) == c * c)
					if (a < b)//3 4 5, 4 3 5 �� ���� ���� �ﰢ���� �� �� ��µǹǷ� a�� b���� �۴ٴ� ������ �߰����ָ� �� ���� ��µȴ�. c�� �׻� a�� b���ٴ� ũ�Ƿ� ����
					{
						printf("%d %d %d\n", a, b, c);
						++num;//���� �ﰢ���� ����
					}

	printf("���� �ﰢ���� ���� : %d��\n", num);

	return 0;
}