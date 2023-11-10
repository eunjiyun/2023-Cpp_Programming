//---------------------------------------------------------------------------------
//STRING.cpp
// 
// 2023.11.09 ���Ϻи���
//---------------------------------------------------------------------------------
#include<iostream>
#include "STRING.h"

STRING::STRING(const char* s)
	:num{ strlen(s) }
{
	p = new char[num];
	memcpy(p, s, num);

	if(����)
		std::cout << "������(const char*) - " << num << ", �޸�: " << (void*)p << std::endl;
}

STRING::~STRING() {
	
	if(����)
		std::cout << "�Ҹ��� - " << num << " , �޸�: " << (void*)p << std::endl;
	delete[] p;
}

//2023. 11. 09 ���� ������(����� �Լ�)
STRING::STRING(const STRING& other) :num{ other.num } {
	p = new char[num];
	//deep-copy
	memcpy(p, other.p, num);//DMA

	if(����)
		std::cout << "���� ������ - " << num << ", �޸�: " << (void*)p << std::endl;
}
//2023. 11. 09 ���� �����ڸ� ������ٸ� �̿� ¦�� �Ǵ� copy assignment operator�� 
//�ݵ�� �ڵ��ؾ� �Ѵ�.
STRING& STRING::operator=(const STRING& other) {
	//���� ���� �� ���� �ڱ� �ڽ��� �Ҵ����� �ʵ��� �ؾ� �Ѵ�.
	if (this == &other)
		return *this;

	delete[] p;

	num = other.num;
	p = new char[num];
	memcpy(p, other.p, num);

	if(����)
		std::cout << "copy assignment ������ - " << num << ", �޸�: " << (void*)p << std::endl;

	return *this;
}

STRING::STRING(STRING&& other) 
	:num{other.num},p{other.p}
{//const�� ���� �� �����. �����͸� �����ٵ�
	//other�� �ʱ�ȭ�Ѵ�.
	other.num = 0;
	other.p = nullptr;
}

size_t STRING::size() const {
	return num;
}

void STRING::show() const {
	for (int i{}; i < num; ++i)
		std::cout << p[i];
	std::cout << std::endl;
}

bool STRING::����{ false };

