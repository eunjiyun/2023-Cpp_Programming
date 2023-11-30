//-----------------------------------------------------------------------------------------------------------------------------------------------------------
// 2023.2학기 c++ 11.30 (13주 2일)
// 12 13 기말 시험
// 12 14 종강, 한학기정리 12 18성적 게시e315
//-----------------------------------------------------------------------------------------------------------------------------------------------------------
// 상속과 다형성
// ----------------------------------------------------------------------------------------------------------------------------------------------------------
// 과제 - 나만의 자료형을 만들어 반복연습
//-----------------------------------------------------------------------------------------------------------------------------------------------------------

#include <iostream>
#include <random>

#include "STRING.h"
#include "save.h"
using namespace std;

// Animal, Dog, Bird를 상속으로 표현하고 다형성을 알아본다
// 다형성을 구현하기 위해 메모리를 더 사용한다. (포인터 크기만큼)
// C++에서 다형성을 구현하기 위한 핵심 키워드 - virtual

class Animal {
 public:
  virtual void move() const {  // virtual로 다형성이 된다.
    cout << "동물 - 움직인다" << endl;
  }
};

class Dog : public Animal {
 public:
  void move() const {  // 멤버함수 override : 재정의 하였다.
    cout << "개 - 달린다" << endl;
  }
};

class Bird : public Animal {
 public:
  void move() const { cout << "새 - 난다" << endl; }
};

//[문제] 동물 여러 마리를 관리하는 코드를 작성한다.
// 몇 마리인지는 사용자 입력에 따른다.
// 주사위를 던져 홀수이면 Dog를 만들고 짝수이면 Bird를 만들어라.
// 동물 중에서 Dog만 골라 move를 호출하라.

default_random_engine dre;
uniform_int_distribution uid{0, 1};

//---------
int main()
//---------
{
  while (true) {
    cout << "몇 마리를 만들까요? ";
    int num;
    cin >> num;

    Animal** animals = new Animal*[num];

    // for (Animals* p:animals)//이건 안됨.

    for (int i{}; i < 10; ++i) {
      if (uid(dre))
        animals[i] = new Dog;
      else
        animals[i] = new Bird;
    }

    //// 다형성이 구현됨을 확인
    //for (int i{}; i < num; ++i) animals[i]->move();

    //dog인 경우만 move를 호출한다
    for (int i{}; i < num; ++i)
        //포인터말고 레퍼런스로 한다.
      //if (dynamic_cast<Dog*>(animals[i])==nullptr) animals[i]->move();
      // 근데또 모든 다형성 코드는 레퍼런스 말고 포인터로 한대
      if (dynamic_cast<Dog*>(animals[i])) animals[i]->move();

    for (int i{}; i < num; ++i) delete animals[i];
    delete[] animals;
  }

  save("소스.cpp");
}
