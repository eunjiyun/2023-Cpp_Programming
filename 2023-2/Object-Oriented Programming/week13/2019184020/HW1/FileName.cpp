//학과 : 게임공학과
//학번 : 2019184020
//이름 : 윤은지
//설명 : Point 클래스를 상속받은 ColorPoint 클래스를
//작성하고, 주어진 실행 결과가 나오도록 전체 프로그램을 완성하기

#include<iostream>
using namespace std;

class Point {
	int x, y;
public:
	Point(int x, int y) { this->x = x;  this->y = y; }
	int getX() { return x; }
	int getY() { return y; }
protected:
	void move(int x, int y) { this->x = x, this->y = y; }
};

class ColorPoint : public Point {
	string color;
public:
	ColorPoint(int x, int y, const string& color) : Point(x, y), color{color}{}
    void setPoint(int x, int y) { move(x, y); }
    void setColor(const string& color)  { this->color = color; }
    void show() 
	{
        cout << color << "색으로 (" << getX() << ", " << getY() << ")에 위치한 점입니다." << endl;
    }
};

int main()
{
	ColorPoint cp(5, 5, "RED");
	cp.setPoint(10, 20);
	cp.setColor("BLUE");
	cp.show();
}