//�а� : ���Ӱ��а�
//�й� : 2019184020
//�̸� : ������
//���� : HouseŬ������ ����� �־��� ���� ����� 
//�������� �Ѵ�.

#include <iostream>
using namespace std;

class House 
{
private:
	int width;//��� ����
	int num;

public:
	House() : House(20, 2) {}//������
	House(int w, int h)
	{
		width = w;
		num = h;
	}

	void show()//����ϴ� �Լ�
	{
		cout << "��ũ��� " << width << "���̰�, ���� ������ " << num <<"���Դϴ�."<<endl;
	}
};

int main() 
{
	House h1;
	House h2(30, 3);

	h1.show();
	h2.show();
}