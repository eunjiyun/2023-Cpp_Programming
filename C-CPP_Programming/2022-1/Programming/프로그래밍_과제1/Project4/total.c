//1. ���� n�� �Է� �޾� 1���� n���� ���� �� ¦���� �հ� Ȧ��
//�� ���� ���Ͻÿ�.
//�� for �ݺ����� ����Ͻÿ�
//�� while �ݺ����� ����Ͻÿ�



#include<stdio.h>

int main(void)
{
	int n,choose;//n �������� �䱸�� ���� n, choose�� for�� while�� ����� ���� �����ϱ� ���� ����
	int evenSum = 0;//¦���� ���� ������ �ʱⰪ�� 0���� �Ѵ�.
	int oddSum = 0;//Ȧ�� �϶��� ������ �ʱⰪ�� 0���� �Ѵ�.

	printf("���� n�� �Է�: ");
	scanf_s("%d", &n);//���� n�� �Է�
	printf("1.for���� ���\n2.while���� ���\n");
	scanf_s("%d", &choose);//for�� while�߿� ����

	if (choose == 1)//for�� �̿�
	{
		for (int i = 2; i <= n; i += 2)//i�� 2���� n���� 2�� ���� 
			evenSum += i;//i�� for���� ����� ������ evenSum�� ���Ѵ�.

		for (int i = 1; i <= n; i += 2)//i�� 1���� n���� 2�� ���� 
			oddSum += i;
	}
	else if (choose == 2)//while�� �̿�
	{
		int i = 2;//i�� �ʱⰪ�� 2
		while (i <= n)//i�� n�� �� ������, i�� n�� �ʰ��ϸ� while���� ����������. 
		{
			evenSum += i;
			i += 2;//i�� 2�� ����
		}

		 i = 1;
		while (i <= n)
		{
			oddSum += i;
			i += 2;
		}
	}
	printf("¦���� ��: %d\n", evenSum);//���
	printf("Ȧ���� ��: %d\n", oddSum);

	return 0;
};