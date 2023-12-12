//학과 : 게임공학과
//학번 : 2019184020
//이름 : 윤은지
//설명 : 가상 함수 구현

#include<iostream>
using namespace std;

class Calculator {
public:
	virtual int add(int a, int b) = 0;
	virtual int subtract(int a, int b) = 0;
	virtual double average(int a[], int size) = 0;
};

class GoodCalc :public Calculator {
public:

	virtual int add(int a, int b) { return a + b; };
	virtual int subtract(int a, int b) { return a - b; };
	virtual double average(int a[], int size) 
	{
		double sum{};
		for (int i{}; i < size; ++i)
			sum += a[i];
		return sum / size;
	};
};

int main()
{
	int a[] = { 1,2,3,4,5 };
	Calculator* p = new GoodCalc();//업캐스팅

	cout << p->add(2, 3) << endl;
	cout << p->subtract(3, 5) << endl;
	cout << p->average(a, 5) << endl;

	delete p;
}