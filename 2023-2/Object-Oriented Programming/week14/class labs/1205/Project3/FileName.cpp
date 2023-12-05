//학과 : 게임공학과
//학번 : 2019184020
//이름 : 윤은지
//설명 : 템플릿 작성

#include<iostream>
using namespace std;

template<class T>
T bigger(T a,T b) {
	if (a > b)
		return a;
	else
		return b;
}

int main()
{
	int a{ 20 }, b{ 50 };
	char c{ 'a' }, d{ 'z' };

	cout <<"bigger(20, 50)의 결과는 "<< bigger(a, b) << endl;
	cout << "bigger('a', 'b')의 결과는 " << bigger(c, d) << endl;


}