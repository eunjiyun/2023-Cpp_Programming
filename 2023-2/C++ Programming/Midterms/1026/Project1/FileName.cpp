#include<iostream>
#include<fstream>
using namespace std;

int num[123'456]{ 1 };

void setData(int*&, int);
void change(char&, char&);

int main()
{
	//1.
	{
		int n[10]{ 84,101,115,116 };

		for (char number : n)
			cout << number << ' ';
		cout << '\n';
	}
	//char number�� �ƽ�Ű�ڵ� ���� �迭 n�� ���ҿ� ���Ƽ�

	//2.
	
	cout << "���� ��" << '\n';
	cout << num[3] << '\n';
	//1.23mb 

	//3.

	int* p;
	int num = 333;

	setData(p, num);

	for (int i = 0; i < num; ++i)
		cout << p[i] << '\t';
	cout << endl;

	delete[] p;

	//4.

	char a = 'K';
	char b = 'O';

	change(a, b);

	printf("%c%c!", a, b);
	cout << endl;


	//5.

	int arr[]{ 1,2,3,4,5,6,7,8,9,10 };

	//���⿡ �� �ڵ带 �ۼ��϶�.
	//qsort�� �����ؾ� �Ѵ�.

	qsort(arr, sizeof(arr) / sizeof(arr[0]), sizeof(int), [](const void* fir, const void* sec) {
		return *(int*)fir % 3 - *(int*)sec % 3;
		});

	for (int n : arr)
		cout << n << ' ';
	cout << endl;

	//6.

	ifstream in{ "�ڷ�3.txt" };

	if (not in)
		return 0;


	string s;
	int n[10]{};
	while (in >> s) {
		for (char c : s)
			++n[c - '0'];
	}

	for (int i{}; i < sizeof(n) / sizeof(n[0]); ++i)
		cout << i << "�� ���� - " << n[i] << endl;

	int max{ n[0] };
	int name{};

	for (int i{ 1 }; i < sizeof(n) / sizeof(n[0]); ++i)
	{
		if (n[i] > max)
		{
			max = n[i];
			name = i;
		}
	}
	cout << "name : " << name << endl;
	cout << "max : " << max << endl;
}

void setData(int*& ptr, int n)
{
	ptr = new int[n];

	for (int i{}; i < n; ++i)
		ptr[i] = n;
}
void change(char& fir, char& sec)
{
	char temp = fir;
	fir = sec;
	sec = temp;
}