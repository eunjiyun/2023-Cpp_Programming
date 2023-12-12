//학과 : 게임공학과
//학번 : 2019184020
//이름 : 윤은지
//설명 : 세 개의 == 연산자 함수를 가진 Book 클래스의 작성
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
		cout << title << ' ' << price << "원 " << pages << " 페이지" << endl;
	}
	string getTitle() { return title; }

	// 첫 번째 == 연산자 함수: 가격(price)만 비교
	bool operator==(int otherPrice) const {
		return price == otherPrice;
	}

	// 두 번째 == 연산자 함수: 제목(title)만 비교
	bool operator==(const string& otherTitle) const {
		return title == otherTitle;
	}

	// 세 번째 == 연산자 함수: 모든 멤버(제목, 가격, 페이지) 비교
	bool operator==(const Book& other) const {
		return title == other.title && price == other.price && pages == other.pages;
	}
};

int main() 
{
    //Book 객체를 활용하는 사례이다.
    Book a("명품 C++", 30000, 500), b("고품 C++", 30000, 500);
    if (a == 30000)cout << "정가 30000원" << endl;//price 비교
    if (a == "명품 C++")cout << "명품 C++입니다." << endl;//책 title 비교
    if (a == b)cout << "두 책이 같은 책입니다." << endl;//title, price, pages 모두 비교

    //출력:
    //정가 30000원
    //명품 C++입니다.
}