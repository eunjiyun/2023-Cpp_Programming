//�й� : 2019184020
//�а� : ���Ӱ��а�
//�̸� : ������
//���� : C++���� string Ŭ������ ����ϱ� ���� #include<string>�� �����ϰ�
//		string ���� �� ���� ������ �� cin���� string ������ �Է� �ް� 
//		if������ �� ������ ������ �˻��� �� ����� cout���� ����մϴ�.

#include<iostream>
#include<string>
using namespace std;

int main()
{
	string fir, sec;

	cout << "�� ��ȣ�� �Է��ϼ���. ";
	cin >> fir;

	cout << "�� ��ȣ�� �ٽ� �ѹ� �Է��ϼ���. ";
	cin >> sec;

	if (fir == sec)
		cout << "�����ϴ�." << endl;
	else
		cout << "�ٸ��ϴ�." << endl;
}