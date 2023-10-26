#include<iostream>
#include<fstream>
using namespace std;

int num[123'456]{ 1 };

int main()
{
	//1. ������ C++ ���α׷��� �Ϻκ��̴�. ���� �� ��°��� ���캸�� 
	// �� �׷� ���� �������� �����϶�. (���� 10)

	{
		char c[10]{ 'T','e','s','t' };

		for (int number : c)
			cout << number << '\n';
	}
	//int�� �о��� ������

	//2. �������� num�� ������ ���� ����Ͽ���. �������� ũ�⿡ ��ġ��
	//������ �����϶�. (���� 10)

	cout << "���� ��" << '\n';

	//�̸�ŭ�� �޸𸮸� ���� �ִٸ� ���������� ũ�Ⱑ 5mb�� �ȴٴ� ��
	//�޸��� ����� �����س��� ���� �������� �ۿ� ���� ����

	//3. �Լ� change�� ���ڿ� str ���� ������ �Ѱ� ������ ���� ��°����
	//���Դ�. (��°��) THE-QUICK-BROWN-FOX-JUMPS-OVER-THE-LAZY-DOG

	//�Լ� change�� �����ϰ� ������ �� ȣ���϶�. �� �׸��� �����ؼ�
	//������ �����. (���� 5) (���� 10) (ȣ�� 5)

	char str[]{ "The quick brown fox jumps over the lazy dog" };

	//���⿡�� �Լ� change�� ȣ���Ѵ�
	//���⿡ �� �ڵ带 �ۼ��϶�.

	void change(char[]);

	change(str);

	cout << str << '\n';
	//THE-QUICK-BROWN-FOX-JUMPS-OVER-THE-LAZY-DOG;

	//4. ������ ����Ǵ� C++��� �ڵ��� �Ϻκ��̴�. �� �ڵ带 ������ ��
	//� ��°���� ������ ���� �׷��� ������ ������ �����϶�.
	//(����) change �Լ��� ȭ�鿡 � �͵� ������� �ʴ´�. (���� 10)

	char a = 'K';
	char b = 'O';

	void change(char& , char& );

	change(a, b);

	cout << a << b << '!' << '\n';

	//5. �迭 a�� qsort �Լ��� ����Ͽ� �����϶�. ���ı����� Ȧ���� ¦���̴�.
	//������ (��� ��)�� ���� ���� Ȧ��, ������ ¦���� �;� �Ѵ�.
	//������ �ذ��ϱ� ���� �߰��� ��� �ڵ带 ������ �����.
	//(�ڵ� 20)

	int arr[]{ 1,2,3,4,5,6,7,8,9,10 };

	//���⿡ �� �ڵ带 �ۼ��϶�.
	//qsort�� �����ؾ� �Ѵ�.

	qsort(arr, sizeof(arr) / sizeof(arr[0]), sizeof(int), [](const void* fir, const void* sec) {
		return *(int*)sec % 2 - *(int*)fir % 2;
		});


	for (int n : arr)
		cout << n << ' ';
	cout << endl;

	//(��� ��) 9 3 7 5 1 10 4 8 2 6
	//�̿� ���� Ȧ���� ¦���� �и��Ǿ�� �Ѵ�

	//6. e-class���� ���� "�ڷ�2.txt"�� �����´�. "�ڷ�2.txt" ���Ͽ���
	//���ĺ� �ҹ��ڿ� ���鹮�ڸ� �Ǿ� �ִ�. ������ �� ���� �о

	//6-1) �� ���Ͽ� �ִ� ���ĺ��� ��� �� ���ΰ� ����϶�. 
	// ȭ�鿡 ��µ� ������ �������� ���.
	//(���� �а� ���� ���� �ڵ� 5, ���ĺ� ���� 5)

	//6-2) 'a'���� 'z'���� ���ĺ� �߿��� ���� ������ ���� ���ĺ��� 
	//�� ������ ����϶�. ȭ�鿡 ����� ���� �������� ���. (�ڵ� 15)
	//(ȭ�鿡 ����� ���� ������ ���� ���ĺ��� �� ���� 5)

	ifstream in{ "�ڷ�2.txt" };

	if (not in)
		return 0;

	string s;
	int cnt{};
	int al[26]{};
	while (in >> s) {
		for(char c:s)
			if (islower(c))
			{
				++cnt;
				++al[c - 'a'];
			}

		
	}

	int max{ al[0] };
	char name{ 'a' };
	for (int i{ 1 }; i < sizeof(al) / sizeof(al[0]); ++i) {
		if (max < al[i])
		{
			max = al[i];
			name = static_cast<char>(i + 'a');
		}
	}

	cout << "cnt : " << cnt << endl;
	cout << "al : " << name << endl;
	cout << "max : " << max << endl;
}

void change(char s[])
{
	for (int i{}; i < strlen(s); ++i)
	{
		if (islower(s[i])||isupper(s[i]))
			s[i]=toupper(s[i]);
		else
			s[i] = '-';
	}
}

void change(char& fir, char& sec)
{
	char temp = fir;
	fir = sec;
	sec = temp;
}