#include<stdio.h>

int main(void)
{
	char input = 'i';//Q�� �ƴ� ������ �ʱ�ȭ
	float fir = 0;//������ �� ���̱� ������ 0���� �ʱ�ȭ
	float sec = 0;//������ �� ���̱� ������ 0���� �ʱ�ȭ
	
	printf("************************************\n");//�޴� ���
	printf("A---- Add\n");
	printf("S---- Subtract\n");
	printf("M---- Multiply\n");
	printf("D---- Divide\n");
	printf("Q---- Quit\n");
	printf("************************************\n");

	printf("������ �����Ͻÿ�: ");
	scanf_s("%c", &input);//���� ��ȣ �Է�, scanf �Լ� ��� ������ scanf_s ���

	while (input != 'Q')//Q�� �ԷµǸ� ����
	{
		if (input == 'A' || input == 'S' || input == 'M' || input == 'D')//���� ���� ��ȣ�� �ƴϸ� �޴��� �ٽ� ���
		{
			printf("�� ���� �������� �и��Ͽ� �Է��Ͻÿ�: ");
			scanf_s("%f %f", &fir, &sec);//������ ���� �Է�

			if (input == 'A')
				printf("%.f %c %.f = %.f\n", fir, '+', sec, fir + sec);//%.f�� ����ؼ� ���� �Ҽ����� ǥ������ �ʰ� ����
			else if (input == 'S')
				printf("%.f %c %.f = %.f\n", fir, '-', sec, fir - sec);//����
			else if (input == 'M')
				printf("%.f %c %.f = %.f\n", fir, '*', sec, fir * sec);//����
			else if (input == 'D')
			{
				if (sec != 0)//������ ���� 0�� �ƴ� ���� ������
					printf("%.f %c %.f = %f\n", fir, '/', sec, fir / sec);//�Է� ���� �� ���� �Ҽ����� ǥ������ �ʰ� ������� �Ҽ��� 6°�ڸ����� ǥ��
				else//������ ���� 0�϶� ���� �޽��� ���
					printf("0���� ���� �� �����ϴ�.\n");
			}
		}

		printf("************************************\n");//�޴� ���
		printf("A---- Add\n");
		printf("S---- Subtract\n");
		printf("M---- Multiply\n");
		printf("D---- Divide\n");
		printf("Q---- Quit\n");
		printf("************************************\n");

		printf("������ �����Ͻÿ�: ");//���� ��ȣ �Է�, ���ۿ� ���Ͱ� ���� �޴��� �� �� ��µǴ� ���� ������ %c �տ� �� ĭ�� ���
		scanf_s(" %c", &input);
	}

	printf("���α׷��� �����մϴ�.");//���� �޽��� ���

	return 0;
}