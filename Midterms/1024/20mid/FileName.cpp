#include <iostream>
using namespace std;

int main()
{
	// [����1] ���α׷��� ����� Ȯ���ϰ� ������ �����϶� (15)

	char c = 'A' + 'a';

	cout << static_cast<int>(c) << '\n';
	// -94�� ���

	// cout << c �ϸ�
	// �ڷ����� �°� char(c)�� ���

	// cout << (int)((unsigined char)c) �ϸ�
	// c = 65 + 97 = 162
	// 162�� ���

	// c = 0x41 + 0x61 = 0xa2 = 0b1010'0010
	// �� ���ڸ� 1�� ������ ��Ÿ�� (2�� ����)
	// 0b0101'1110
	// -94


	// �����÷ο� x, 1����Ʈ�� ����
	// char c = 0x12345678; ��
	// char c = 0x78;		�� ����

	// [����2] ���� main() �Լ��� �������� ����Ǵ� C��� ���α׷��� �Ϻζ�� ����
	// ���α׷� ���� �� ��µ� ������ ���� (10) �׷��� �Ǵ� ������ �����϶� (10)

	char a{ 'O' };
	char z{ 'K' };

	//change(a, z);

	cout << a << z << '!' << endl;
	// OK! �� ���

	// C ���α׷��� ��� change �Լ����� ���������� �� �ִ� ����� ����
	// void change(char*, char*) �̸� ȣ�� �� change(&a, &z) ���� �Ѵ�


	// C++ ���α׷��� ��� void change(char&, char&) �� ����������
	// change �Լ��� ������ �𸣱� ������ ��µ� ������ �� �� ����


	// [����3] �Ʒ��� ����� ��µǵ��� �Լ� makeUpper�� �����ϰ� (10) �����϶� (15)

	void makeUpper(char&);		// ����

	char str[]{ "C++ is a general-purpose programming language" };

	for (char& c : str) {
		makeUpper(c);
	}

	cout << str << endl;
	// ���: C++ IS A GENERAL-PURPOSE PROGRAMMING LANGUAGE


	// [����4] ����(int)�� 1���� n���� ��� ���س����� (1 + 2 + 3 + ... + n)
	// ����(int)�� �ִ� �Ѱ踦 �ʰ����� �ʴ� n�� ���� ã�Ƽ� ȭ�鿡 ����϶� (40)

	int max = numeric_limits<int>::max();

	// int sum = 0;
	long long sum = 0;
	int i;

	for (i = 1; sum <= max; ++i) {
		sum += i;
		//cout << i << endl;
	}

	cout << "�հ�: " << sum << endl;
	cout << "n�� ���� " << i - 2 << endl;


	// �ٸ� ���

	int n = 1;
	sum = 0;

	while (true) {
		sum += n;
		if (max < sum) {
			break;
		}
		++n;
	}

	cout << "n�� ���� " << n - 1 << endl;


	// �˻�

	int sum_c{};
	for (int i = 1; i <= 65535 + 1; ++i) {
		sum_c += i;
	}
	cout << sum_c << endl;

	// 65535
}

void makeUpper(char& c) {	// ����
	if ('a' <= c && c <= 'z') {
		c -= 0x20;
	}
}





