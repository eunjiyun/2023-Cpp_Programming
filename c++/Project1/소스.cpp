//-----------------------------------------------------------------------------------------------------------------------------------------------------------
//2023.2�б� c++ 11.02 (9�� 2��)
// 
//-----------------------------------------------------------------------------------------------------------------------------------------------------------
// ����� ���� �ڷ��� - user-defined data type
// ----------------------------------------------------------------------------------------------------------------------------------------------------------
// ���� - ������ �ڷ����� ����� �ݺ�����
//-----------------------------------------------------------------------------------------------------------------------------------------------------------

#include<iostream>
#include<random>
#include "save.h"
using namespace std;

//[����] ���� MemoryMonster��. ���� ���� �ÿ� int ���� ���޹޾� �� ����ŭ int �޸𸮸� �����Ѵ�.
//������ �޸𸮿� ���� �����ϰ� ����Ѵ�.
//���� �ڵ��� ��.
//���� �ڵ尡 �������� ����Ǹ� ���ھ�.

default_random_engine dre;
uniform_int_distribution uid(1, 9999);

class MemoryMonster {
	//size_t size;//unsigned int �̷��� �ᵵ ��. ǥ��c++�� ��� �������� ����x ������ �� ���ؼ�
	int size;
	int* ptr;

public:
	MemoryMonster(int s) :size{ s } {//�Ұ�ȣ�� �ʱ�ȭ�ϸ� ������ �� ���� ����x
		//int�� ������ ���� �� �־ ������ ����.
		ptr = new int[s];

		for (int i{}; i < s; ++i)
			ptr[i] = uid(dre);

		cout << "����(int) - " << size << ", [0] - " << ptr[0] << endl;
	}
	//���� ������
	//const�� �ջ� ����, �б� ����   &�� ���������ʰ� ���������ϰڴٴ� �ǹ�
	MemoryMonster(const MemoryMonster& other) :size{ other.size } {
		ptr = new int[size];

		for (int i{}; i < size; ++i)
			ptr[i] = other.ptr[i];

		cout << "������� - " << size << ", [0] - " << ptr[0] << endl;
	}
	~MemoryMonster() {
		cout << "�Ҹ����� - " << size << ", [0] - " << ptr[0] << endl;
		//if(nullptr!=ptr)// null�� �ƴ� ���� ���� �ڵ尡 ���ư��⿡ �̰� �������.
		delete[] ptr;
	}

	//�������̽� �Լ�
	void show()	const {//const�� �� �Լ��� �����͸� �б⸸ �ϰ� ���� ������ ��Ÿ��.
		//size = 300; const������ �б⸸ �ϱ⿡ �ȵ�.
		cout << "���� �����ϴ� int�� �� - " << size << ", [0] - " << ptr[0] << endl;
	}
};

//---------
int main()
//---------
{
	//DMA
	MemoryMonster a[]{ 1,3,5,7,9,2,4,6,8,10 };
	//[����] qsort�� ����Ͽ� a�� size���� ������������ �����ϰ� show()�� ȣ���϶�.

	void* �Ǵ��Լ�(void*,void*);

	qsort(a, sizeof(a) / sizeof(a[0]), sizeof(MemoryMonster),�Ǵ��Լ�);

	for (const MemoryMonster& m : a)
		m.show();

	save("�ҽ�.cpp");
}

MemoryMonster* �Ǵ��Լ�(MemoryMonster* fir, MemoryMonster* sec) {
	return fir;
}