//학과 : 게임공학과
//학번 : 2019184020
//이름 : 윤은지
//설명 : Tower클래스를 만들고 주어진 실행 결과가 
//나오도록 한다.

#include<iostream>
using namespace std;

class Tower
{
private:
    int height;//멤버 변수

public:
    Tower(int h = 1)//생성자
    {
        height = h;
    }

    int getHeight()//멤버 함수
    {
        return height;
    }
};

int main()
{
    Tower myTower;
    Tower seoulTower(100);

    cout << "높이는 " << myTower.getHeight() << "미터" << endl;
    cout << "높이는 " << seoulTower.getHeight() << "미터" << endl;
}