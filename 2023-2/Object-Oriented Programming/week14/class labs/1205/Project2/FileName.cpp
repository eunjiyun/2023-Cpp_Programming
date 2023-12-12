//학과 : 게임공학과
//학번 : 2019184020
//이름 : 윤은지
//설명 : 정수 두 개를 입력하여 계산기 클래스를 사용하여 계산하기

#include<iostream>
using namespace std;

class Calculator {
	void input() {
		cout << "정수 2개 입력: ";
		cin >> a >> b;
	}
protected:
	int a, b;
	virtual int calc(int a, int b) = 0;
public:
	void run() {
		input();
		cout << "계산된 값은 " << calc(a, b) << endl;
	}
};
class Adder :public Calculator {
public:
	int calc(int a, int b) {
		return a + b;
	}
};
class Subtractor :public Calculator {
	int calc(int a, int b) {
		return a - b;
	}
};

int main()
{
	Adder adder;
	Subtractor subtractor;
	adder.run();
	subtractor.run();

}