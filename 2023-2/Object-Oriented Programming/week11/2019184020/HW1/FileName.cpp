//�а� : ���Ӱ��а�
//�й� : 2019184020
//�̸� : ������
//���� : �� ���� == ������ �Լ��� ���� Book Ŭ������ �ۼ�
#include<iostream>
using namespace std;

class Book {
	string title;
	int price, pages;
public:
	Book(string title = "", int price = 0, int pages = 0) {
		this->title = title; this->price = price; this->pages = pages;
	}
	void show() {
		cout << title << ' ' << price << "�� " << pages << " ������" << endl;
	}
	string getTitle() { return title; }

	// ù ��° == ������ �Լ�: ����(price)�� ��
	bool operator==(int otherPrice) const {
		return price == otherPrice;
	}

	// �� ��° == ������ �Լ�: ����(title)�� ��
	bool operator==(const string& otherTitle) const {
		return title == otherTitle;
	}

	// �� ��° == ������ �Լ�: ��� ���(����, ����, ������) ��
	bool operator==(const Book& other) const {
		return title == other.title && price == other.price && pages == other.pages;
	}
};

int main() 
{
    //Book ��ü�� Ȱ���ϴ� ����̴�.
    Book a("��ǰ C++", 30000, 500), b("��ǰ C++", 30000, 500);
    if (a == 30000)cout << "���� 30000��" << endl;//price ��
    if (a == "��ǰ C++")cout << "��ǰ C++�Դϴ�." << endl;//å title ��
    if (a == b)cout << "�� å�� ���� å�Դϴ�." << endl;//title, price, pages ��� ��

    //���:
    //���� 30000��
    //��ǰ C++�Դϴ�.
}