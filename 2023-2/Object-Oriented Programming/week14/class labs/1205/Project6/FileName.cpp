//�а� : ���Ӱ��а�
//�й� : 2019184020
//�̸� : ������
//���� : ���ø� �ۼ�

#include<iostream>
using namespace std;

template <class T>
void print(T a[],int n)
{
	for (int i{}; i < n; ++i)
		cout << a[i] << " ";
	cout << endl;
}

void print(char a[], int n)
{
	for (int i{}; i < n; ++i)
		cout << (int)a[i] << " ";
	cout << endl;
}
int main()
{
	int x[]{ 1,2,3,4,5 };
	double d[5]{ 1.1,2.2,3.3,4.4,5.5 };

	print(x, 5);
	print(d, 5);

	char c[5]{97,2,3,4,5 };
	print(c, 5);
}