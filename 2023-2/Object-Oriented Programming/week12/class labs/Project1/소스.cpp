//�а� : ���Ӱ��а�
//�й� : 2019184020
//�̸� : ������
//���� : Ŭ������ ��� ���� : Point Ŭ������ ��ӹ޴� ColorPoint Ŭ���� �����

#include<iostream>
#include<string>
#include"obj.h"
using namespace std;

//������ ȣ�� ���� �� ���� ����
//=>���迡 ���´�.
//�θ� Ŭ������ ���� �Ҹ�Ǵ��� �����Ǵ��� �׷� ������
//1. ù��° �θ� ������ ����
//2. �ι�° �θ� ������ ����
//3. ������ ������ ����
//4. ������ �Ҹ��� ����
//5. �ι�° �θ� �Ҹ��� ����
//6. ù��° �θ� �Ҹ��� ����

int main()
{
	Point p;
	p.set(2, 3);
	//p.x = 5;
	//p.y = 5;
	p.showPoint();

	ColorPoint cp;
	//cp.x = 10;
	//cp.y = 10;
	cp.set(3, 4);
	cp.setColor("Red");
	cp.showColorPoint();

	ColorPoint cp2;
	cp2.set(3, 4);
	cp2.setColor("Red");

	cout << (cp.equals(cp2) ? "true" : "false");
}
