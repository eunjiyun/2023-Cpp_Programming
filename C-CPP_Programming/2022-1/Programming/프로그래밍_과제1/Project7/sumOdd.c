//������ �� n�� �Է� �޾� 0���� ù n���� ¦���� �հ� ù
//n���� Ȧ���� ���� ����ϴ� ���α׷��� ������ ���� 3
//������ �ۼ��Ͻÿ�.
//1. �Ʒ��� �־��� ������ ����Ͽ� ���α׷��� �ۼ��Ͻÿ�.
//2. for �ݺ����� ���๮�� �޸� �����ڸ� ������� ���� �ۼ��Ͻ�
//��.
//3. while���� ����Ͻÿ�.
//����:
//for (cnt = 0, i = 1, j = 2; cnt < n; ++cnt, i += 2, j += 2)
//	sum_odd += i, sum_even += j;



#include<stdio.h>

int main(void)
{
	int n, choose, cnt,i,j;
	int sum_odd = 0;//�հ��� �ʱⰪ�� 0
	int sum_even = 0;

	printf("���� n�� �Է�: ");
	scanf_s("%d", &n);//���� n�Է�
	printf("1.�־��� ����\n2.for\n3.while\n");//�޴� ���
	scanf_s("%d", &choose);//�޴� ����

	if (choose == 1)//�־��� ������ �̿�
	{
		//cnt�� �ʱⰪ�� 0, i�� �ʱⰪ�� 1, j�� �ʱⰪ�� 0�̰� cnt�� n���� ���������� cnt�� 1��,i�� j�� 2�� ������Ų��.
		for (cnt = 0, i = 1, j = 0; cnt < n; ++cnt, i += 2, j += 2)
			sum_odd += i, sum_even += j;//i�� sum_odd�� ���ϰ�, j�� sum_even�� ���Ѵ�.
	}
	else if (choose == 2)//for
	{
		for (int i = 0; i <=( n-1) * 2; i += 2)//i�� 0���� 2n-2���� i�� 2�� ����
			sum_even += i;

		for (int i = 1; i <= n * 2; i += 2)
			sum_odd += i;
	}
	else if (choose == 3)//while
	{
		int i = 0;
		while (i <= (n - 1) * 2)
		{
			sum_even += i;
			i += 2;
		}

		i = 1;
		while (i <= n * 2)
		{
			sum_odd += i;
			i += 2;
		}
	}
	printf("ù n���� ¦���� ��: %d\n", sum_even);//���
	printf("ù n���� Ȧ���� ��: %d\n", sum_odd);

	return 0;
}