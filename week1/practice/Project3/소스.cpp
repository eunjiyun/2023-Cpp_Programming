#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include <format>
#include <array>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

default_random_engine dre;
uniform_int_distribution uid{ 1, 10 };

class Dog {
	double speed{ 3.0 };				// �޸��� �ӷ�,  1�ʿ� �̵��� �Ÿ�(m/s)
	double distance{};					// �޸��Ÿ�
	string name{ "�̸��� �����ּ���" };	// �̸� 

public:
	Dog() = default;

	void show() const {
		cout << format("{:12}, �ü�: {:>5.2f}km,    �޸��Ÿ�: {:>7.2f}m", name, speed * 3.6, distance) << endl;
		// ����ȵǸ� 
		// printf( "%s, �ü�: %5.2fkm, �޸��Ÿ� %7.2fm\n", name, speed * 3.6, distance );
	}

	void run() {	// �޸��Ÿ� ����
		distance += speed * uid(dre) * 0.5;
	}

	void resetDistance() {
		distance = 0;
	}

	string getName() const {
		return name;
	}

	double getSpeed() const {
		return speed;
	}

	double getDistance() const {
		return distance;
	}

	void write(ostream& os) const {
		os << name << "\t" << speed << "\t" << distance << endl;
	}

	void read(istream& is) {
		is >> name >> speed >> distance;
	}
};


//---------
int main()
//---------
{
	// ���蹮������ Dog ��ü�� ���� ������� �ʴ´�.
	// ������ �ڵ尡 �� ����

	cout << "�ҽ��� �� ����ǳ� Ȯ���մϴ�" << endl;
	Dog dog;
	dog.show();

	for (int i = 0; i < 10; ++i)
		dog.run();
	cout << "run() 10�� ȣ�� ��" << endl;
	dog.show();

	ifstream in{ "Dog 10000.txt" };

	// [���� 1] ���Ͽ� �ִ� Dog ��ü�� �о� �����̳ʿ� �����϶�. 
	// ����� �����̳ʿ� �б� ���� �߰��� �ڵ带 �������� ������ �����.      
	// Dog�� ����Լ��� �߰��� �� �ִ�.

	vector<Dog> v;
	/*while (in.read(reinterpret_cast<char*>(&dog),sizeof(dog)))
		v.push_back(dog);
	in.close();*/

	while (in && !in.eof())
	{
		dog.read(in);
		v.push_back(dog);
	}

	for (const auto& d : v)
	{
		cout << "speed : " << d.getSpeed() << endl;
		cout << "distance : " << d.getDistance() << endl;
		cout << "name : " << d.getName() << endl;
	}





	// [���� 2] ��� Dog ��ü�� speed ��հ��� ���ϰ� ȭ�鿡 ����϶�.
	// ������ ��°���� �����.											





	// [���� 3] ��� Dog ��ü �� speed�� ���� ���� ��ü�� ã�� ȭ�鿡 ����϶�.
	// ������ ��°���� �����.											





	// [���� 4] �����Լ� play�� [���� 1]���� ����� �����̳ʸ� ���ڷ� �޴´�.
	// play�� �����̳ʿ� �ִ� ��� Dog ��ü�� run( )�� 200���� ȣ���Ѵ�.
	// �Լ� play�� �����ϰ� �����϶�.										
	// ���� - ������ �Լ��� ����� ���Ǹ� �����Ͽ� ���� ��





	// [���� 5] [���� 4]�� play()�� ȣ���Ͽ� run()�� 200�� �����Ͽ��ٰ� ����. 
	// ���� �ָ� �޸�(distance���� ���� ū) ��ü�� ã�� ȭ�鿡 ����϶�.
	// ������ ��°���� �����.											





	// [���� 6] �� ������ �ذ��ϱ� ���� ����� �����̳ʸ� ������ ������ �����϶�. 
}