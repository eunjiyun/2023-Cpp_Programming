//학과 : 게임공학과
//학번 : 2019184020
//이름 : 윤은지
//설명 : 제네릭 클래스 작성

#include<iostream>
using namespace std;

template <class T>
class MyStack {
	int tos;
	T data[100];

public:
	MyStack();
	void push(T element);
	T pop();
};

template <class T>
MyStack<T>::MyStack()
{
	tos = -1;
}
template <class T>
void MyStack<T>::push(T element)
{
	if (99 == tos) {
		cout << "stack full";
		return;
	}
	++tos;
	data[tos] = element;
}
template <class T>
T MyStack<T>::pop()
{
	T retData;
	if (-1 == tos) {
		cout << "stack empty";
		return 0;
	}
	retData = data[tos];
	--tos;
	return retData;
}

int main()
{
	MyStack<int> iStack;
	iStack.push(3);
	cout << iStack.pop() << endl;

	MyStack<double> dStack;
	dStack.push(3.5);
	cout << dStack.pop() << endl;

	MyStack<char>* p = new MyStack<char>();
	p->push('a');
	cout << p->pop() << endl;
	delete p;
}