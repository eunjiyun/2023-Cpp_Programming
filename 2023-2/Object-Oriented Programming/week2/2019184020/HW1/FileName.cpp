//�й� : 2019184020
//�а� : ���Ӱ��а�
//�̸� : ������
//���� : cin�� ����Ͽ� �� ���� ������ �о� 
//		if������ ū ���� �Ǻ��ϰ� 
//		ȭ�鿡 cout���� ����ϴ� ���α׷� �Դϴ�.

#include<iostream>
using namespace std;

int main()
{
	int fir, sec;

	cout << "�� ���� �Է��϶�>>";
	cin >> fir >> sec;

	if (fir > sec)
		cout << "ū �� = " << fir << endl;
	else if (fir == sec)
		cout << "�� ���� �����ϴ�." << endl;
	else
		cout << "ū �� = " << sec << endl;
}