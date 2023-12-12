//학과 : 게임공학과
//학번 : 2019184020
//이름 : 윤은지
//설명 : 클래스의 상속 공부 : Point 클래스를 상속받는 ColorPoint 클래스 만들기

#include<iostream>
#include<string>
#include"obj.h"
using namespace std;

//생성자 호출 관계 및 실행 순서
//=>시험에 나온다.
//부모 클래스가 먼저 소멸되는지 생성되는지 그런 순서들
//1. 첫번째 부모 생성자 실행
//2. 두번째 부모 생성자 실행
//3. 마지막 생성자 실행
//4. 마지막 소멸자 실행
//5. 두번째 부모 소멸자 실행
//6. 첫번째 부모 소멸자 실행

int main()
{
	Point p;
	p.set(2, 3);
	//p.x = 5;
	//p.y = 5;
	p.showPoint();

	ColorPoint cp;
	//cp.x = 10;
	//cp.y = 10;
	cp.set(3, 4);
	cp.setColor("Red");
	cp.showColorPoint();

	ColorPoint cp2;
	cp2.set(3, 4);
	cp2.setColor("Red");

	cout << (cp.equals(cp2) ? "true" : "false");
}
