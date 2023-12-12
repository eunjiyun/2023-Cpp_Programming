//학과 : 게임공학과
//학번 : 2019184020
//이름 : 윤은지
//설명 : 주어진 Person 클래스의 디폴트 매개변수를 가진 하나의 생성자를 작성하고
//주어진 실행 결과가 나오게 한다.

#include<iostream>
using namespace std;

class Person {
	int id;
	double weight;
	string name;
public:
	// 매개 변수가 있는 생성자
	Person(int _id=1, const string& _name="Grace", double _weight = 20.5) : id(_id), name(_name), weight(_weight) {}

	void show() { cout << id << ' ' << weight << ' ' << name << endl; }
};

int main()
{
	Person grace, ashley(2, "Ashley"), helen(3, "Helen", 32.5);
	grace.show();
	ashley.show();
	helen.show();
}