//�а� : ���Ӱ��а�
//�й� : 2019184020
//�̸� : ������
//���� : �߻� Ŭ���� ����

#include<iostream>
using namespace std;

class AbstractGate {//�߻� Ŭ����
protected:
	bool x, y;
public:
	void set(bool x, bool y) { this->x = x; this->y = y; }
	virtual bool operation() = 0;
};

class ANDGate : public AbstractGate {
public:
	bool operation()
	{
		if (x and y)
			return true;
		else
			return false;
	}
};
class ORGate : public AbstractGate {
public:
	bool operation()
	{
		if (x or y)
			return true;
		else
			return false;
	}

};
class XORGate : public AbstractGate {
public:
	bool operation()
	{
		if (x xor y)
			return true;
		else
			return false;
	}
};

int main()
{
	ANDGate andGate;
	ORGate orGate;
	XORGate xorGate;

	andGate.set(true, false);
	orGate.set(true, false);
	xorGate.set(true, false);

	cout.setf(ios::boolalpha);
	cout << andGate.operation() << endl;
	cout << orGate.operation() << endl;
	cout << xorGate.operation() << endl;
}