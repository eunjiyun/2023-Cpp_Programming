//�а� : ���Ӱ��а�
//�й� : 2019184020
//�̸� : ������
//���� : �־��� Person Ŭ������ ����Ʈ �Ű������� ���� �ϳ��� �����ڸ� �ۼ��ϰ�
//�־��� ���� ����� ������ �Ѵ�.

#include<iostream>
using namespace std;

class Person {
	int id;
	double weight;
	string name;
public:
	// �Ű� ������ �ִ� ������
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