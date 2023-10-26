//학과 : 게임공학과
//학번 : 2019184020
//이름 : 윤은지
//설명 : House클래스를 만들고 주어진 실행 결과가 
//나오도록 한다.

#include <iostream>
using namespace std;

class House 
{
private:
	int width;//멤버 변수
	int num;

public:
	House() : House(20, 2) {}//생성자
	House(int w, int h)
	{
		width = w;
		num = h;
	}

	void show()//출력하는 함수
	{
		cout << "집크기는 " << width << "평이고, 방의 개수는 " << num <<"개입니다."<<endl;
	}
};

int main() 
{
	House h1;
	House h2(30, 3);

	h1.show();
	h2.show();
}