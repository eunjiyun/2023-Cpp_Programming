//학과 : 게임공학과
//학번 : 2019184020
//이름 : 윤은지
//설명 : 세 개의 == 연산자 함수를 friend 함수로 구현

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
		cout << title << ' ' << price << "원 " << pages << " 페이지" << endl;
	}
	string getTitle() { return title; }

	// 프렌드 함수 선언
	friend bool operator==(const Book& , int);
	friend bool operator==(const Book& , const string& );
	friend bool operator==(const Book& , const Book& );
};

int main()
{
	Book a("명품 C++", 30000, 500), b("고품 C++", 30000, 500);

	if (a == 30000)cout << "정가 30000원" << endl;//price 비교
	if (a == "명품 C++")cout << "명품 C++ 입니다." << endl;//책 title 비교
	if (a == b)cout << "두 책이 같은 책입니다." << endl;//title, price, pages 모두 비교
}

// 프렌드 함수 정의
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



