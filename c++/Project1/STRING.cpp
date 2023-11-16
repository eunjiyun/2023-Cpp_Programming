//---------------------------------------------------------------------------------
//STRING.cpp
// 
// 2023.11.09 ���Ϻи���
//---------------------------------------------------------------------------------
#include<iostream>
#include "STRING.h"


bool STRING::����{ false };//�����Ϸ��� �ƹ������� true�� �ٲ��ּ���

STRING::STRING(const char* s)
	:num{ strlen(s) }
{
	p = new char[num];
	memcpy(p, s, num);

	if(����)
		std::cout << "������(const char*) - " << num << ", �޸�: " << (void*)p << std::endl;
}

STRING::~STRING() 
{
	
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
STRING& STRING::operator=(const STRING& other) 
{
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

//2023. 11. 15 ������ �����ε�
STRING STRING::operator+(const char* str)const
{
	STRING temp;//default ctor�� ����� �Լ�, ����Ʈ �����ڸ� �����ؼ� ���� ���� ������� �ߴ�.

	temp.num = num + strlen(str);
	temp.p=new char[temp.num];

	memcpy(temp.p, p, num);
	memcpy(temp.p + num, str, strlen(str));

	return temp;//���⼭ ���� �����ڰ� ȣ��Ǿ�� ������ RVO�� �۵��ȴ�.
	//RVO(Return Value Optimization) - ��ȯ�� ����ȭ
}
STRING STRING::operator+(const STRING& s)const
{
	STRING temp;//default ctor�� ����� �Լ�, ����Ʈ �����ڸ� �����ؼ� ���� ���� ������� �ߴ�.

	temp.num = num + s.num;
	temp.p = new char[temp.num];

	memcpy(temp.p, p, num);
	memcpy(temp.p + num, s.p, s.num);

	return temp;//���⼭ ���� �����ڰ� ȣ��Ǿ�� ������ RVO�� �۵��ȴ�.
	//RVO(Return Value Optimization) - ��ȯ�� ����ȭ
}

//2023.11.16 free function
STRING operator+(const char* p, const STRING& s)
{
	STRING temp;
	temp.num = strlen(p) + s.num;
	temp.p=new char[temp.num];

	memcpy(temp.p, p, strlen(p));
	memcpy(temp.p + strlen(p), s.p, s.num);

	return temp;
}

//2023.11.16
char STRING::operator[](int idx)const
{
	return p[idx];
}

char& STRING::operator[](int idx)
{
	return p[idx];
}


size_t STRING::size() const 
{
	return num;
}

void STRING::show() const 
{
	for (int i{}; i < num; ++i)
		std::cout << p[i];
	std::cout << std::endl;
}

//2023.11.16
std::ostream& operator<<(std::ostream& os, const STRING& s)
{
	for (int i{}; i < s.num; ++i)
		os << s.p[i];
	return os;
}


