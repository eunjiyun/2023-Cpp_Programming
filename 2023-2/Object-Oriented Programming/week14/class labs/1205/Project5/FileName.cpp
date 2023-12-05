//학과 : 게임공학과
//학번 : 2019184020
//이름 : 윤은지
//설명 : 템플릿 작성

#include<iostream>
using namespace std;

template <class T1, class T2>
void mcopy(T1 src[], T2 dest[], int n)
{
	for (int i{}; i < n; ++i)
		dest[i] = (T2)src[i];
}

int main()
{
	int x[]{ 1,2,3,4,5 };
	double y[5];

	char c[5]{ 'H','e','l','l','o' };
	char e[5];

	mcopy(x, y, 5);
	mcopy(c, e, 5);

	for (int i{}; i < 5; ++i)
		cout << y[i] << ' ';
	cout << endl;

	for (int i{}; i < 5; ++i)
		cout << e[i] << ' ';
	cout << endl;
}