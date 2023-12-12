//�а� : ���Ӱ��а�
//�й� : 2019184020
//�̸� : ������
//���� : �� ���� == ������ �Լ��� friend �Լ��� ����

#include<iostream>
using namespace std;

class Book {
	string title;
	int price, pages;

public:
	Book(string title = "", int price = 0, int pages = 0) 
	{
		this->title = title; this->price = price; this->pages = pages;
	}
	void show() 
	{
		cout << title << ' ' << price << "�� " << pages << " ������" << endl;
	}
	string getTitle() { return title; }

	// ������ �Լ� ����
	friend bool operator==(const Book& , int);
	friend bool operator==(const Book& , const string& );
	friend bool operator==(const Book& , const Book& );
};

int main()
{
	Book a("��ǰ C++", 30000, 500), b("��ǰ C++", 30000, 500);

	if (a == 30000)cout << "���� 30000��" << endl;//price ��
	if (a == "��ǰ C++")cout << "��ǰ C++ �Դϴ�." << endl;//å title ��
	if (a == b)cout << "�� å�� ���� å�Դϴ�." << endl;//title, price, pages ��� ��
}

// ������ �Լ� ����
bool operator==(const Book& a, int price) 
{
	return a.price == price;
}

bool operator==(const Book& a, const string& title) 
{
	return a.title == title;
}

bool operator==(const Book& a, const Book& b) 
{
	return (a.title == b.title) && (a.price == b.price) && (a.pages == b.pages);
}



