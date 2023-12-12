//학과 : 게임공학과
//학번 : 2019184020
//이름 : 윤은지
//설명 : 주어진 Person 클래스의 생성자를 중복 작성하고
//주어진 실행 결과가 나오게 한다.

#include<iostream>
using namespace std;

class Person {
	int id;
	double weight;
	string name;
public:
	// 기본 생성자
	Person() : id(1), weight(20.5), name("Grace") {}

	// 매개 변수가 있는 생성자
	Person(int _id, const string& _name) : id(_id), name(_name), weight(20.5) {}

	// 매개 변수가 있는 생성자2
	Person(int _id, const string& _name,double _weight) : id(_id), name(_name), weight(_weight) {}

	void show() { cout << id << ' ' << weight << ' ' << name << endl; }
};

int main()
{
	Person grace, ashley(2, "Ashley"), helen(3, "Helen", 32.5);
	grace.show();
	ashley.show();
	helen.show();
}