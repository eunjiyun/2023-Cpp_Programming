//�а� : ���Ӱ��а�
//�й� : 2019184020
//�̸� : ������
//���� : �־��� Person Ŭ������ �����ڸ� �ߺ� �ۼ��ϰ�
//�־��� ���� ����� ������ �Ѵ�.

#include<iostream>
using namespace std;

class Person {
	int id;
	double weight;
	string name;
public:
	// �⺻ ������
	Person() : id(1), weight(20.5), name("Grace") {}

	// �Ű� ������ �ִ� ������
	Person(int _id, const string& _name) : id(_id), name(_name), weight(20.5) {}

	// �Ű� ������ �ִ� ������2
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