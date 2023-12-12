//학번 : 2019184020
//학과 : 게임공학과
//이름 : 윤은지
//설명 : 원의 면적을 계산하는 함수와 반지름을 입력 받는
//함수, 반지름의 정보를 담고 있는 class를 사용하여 
//세 원이 100보다 면적이 큰지 검사하는 소스코드 입니다.

#include <iostream>
using namespace std;

class Circle {
    int radius;
public:
    void setRadius(int r);//반지름 설정
    double getArea();//면적 리턴
};

int main() {
    Circle circles[3];
    int numCircles = 3; // 3개의 원을 생성

   
    for (int i{}; i < numCircles; ++i) {
        double radius;
        cout << "원 " << i + 1 << "의 반지름>>";
        cin >> radius;
        circles[i].setRadius(radius);
    }

    int count = 0; // 면적이 100보다 큰 원의 개수

    // 각 원의 면적을 계산하고, 100보다 큰지 확인
    for (int i{}; i < numCircles;++i) {
        if (circles[i].getArea() > 100) {
            ++count;
        }
    }

    cout << "면적이 100보다 큰 원의 개수: " << count << endl;
}
void Circle::setRadius(int r) {
    radius = r;
}
double Circle::getArea() {
    return 3.14159 * radius * radius;
}