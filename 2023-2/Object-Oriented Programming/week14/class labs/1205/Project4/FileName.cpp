//학과 : 게임공학과
//학번 : 2019184020
//이름 : 윤은지
//설명 : 템플릿 작성

#include<iostream>
using namespace std;

template <class T>
T add(T a[], int size)
{
	T sum{};
	for (int i{}; i < size; ++i)
		sum += a[i];

	return sum;
}

int main()
{
	int x[]{ 1,2,3,4,5 };
	double y[]{ 1.2,2.3,3.4,4.5,5.6,6.7 };

	cout << "sum of x[] = " << add(x, 5) << endl;
	cout << "sum of y[] = " << add(y, 6) << endl;
}