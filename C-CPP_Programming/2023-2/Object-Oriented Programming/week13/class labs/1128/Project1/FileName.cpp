#include<iostream>
using namespace std;

class Base {
public:
	void f() {
		cout << "Base::f() called" << endl;
	}
};

class Derived :public Base {
public:
	virtual void f() {
		cout << "Derived::f() called" << endl;
	}
};

int main()
{
	Derived d, * pDer;
	pDer = &d;
	pDer->f();

	Base* pBase;
	pBase = pDer;//업캐스팅: 기본클래스가 파생클래스를 가리키게 하는 것
	pBase->f();
}