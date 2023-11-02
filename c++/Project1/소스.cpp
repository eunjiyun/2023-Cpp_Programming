//-----------------------------------------------------------------------------------------------------------------------------------------------------------
//2023.2학기 c++ 11.02 (9주 2일)
// 
//-----------------------------------------------------------------------------------------------------------------------------------------------------------
// 사용자 정의 자료형 - user-defined data type
// ----------------------------------------------------------------------------------------------------------------------------------------------------------
// 과제 - 나만의 자료형을 만들어 반복연습
//-----------------------------------------------------------------------------------------------------------------------------------------------------------

#include<iostream>
#include<random>
#include "save.h"
using namespace std;

//[문제] 나는 MemoryMonster다. 나는 생성 시에 int 값을 전달받아 그 수만큼 int 메모리를 생성한다.
//생성한 메모리에 값을 랜덤하게 기록한다.
//나를 코딩해 줘.
//다음 코드가 문제없이 실행되면 좋겠어.

default_random_engine dre;
uniform_int_distribution uid(1, 9999);

class MemoryMonster {
	//size_t size;//unsigned int 이렇게 써도 됨. 표준c++은 멤버 변수부터 쓰지x 강의할 때 편해서
	int size;
	int* ptr;

public:
	MemoryMonster(int s) :size{ s } {//소괄호로 초기화하면 오류가 안 떠서 쓰지x
		//int가 음수가 있을 수 있어서 오류가 난다.
		ptr = new int[s];

		for (int i{}; i < s; ++i)
			ptr[i] = uid(dre);

		cout << "생성(int) - " << size << ", [0] - " << ptr[0] << endl;
	}
	//복사 생성자
	//const는 손상 방지, 읽기 전용   &은 복사하지않고 원격조작하겠다는 의미
	MemoryMonster(const MemoryMonster& other) :size{ other.size } {
		ptr = new int[size];

		for (int i{}; i < size; ++i)
			ptr[i] = other.ptr[i];

		cout << "복사생성 - " << size << ", [0] - " << ptr[0] << endl;
	}
	~MemoryMonster() {
		cout << "소멸직전 - " << size << ", [0] - " << ptr[0] << endl;
		//if(nullptr!=ptr)// null이 아닐 때만 밑의 코드가 돌아가기에 이건 쓸모없다.
		delete[] ptr;
	}

	//인터페이스 함수
	void show()	const {//const는 이 함수가 데이터를 읽기만 하고 쓰지 않음을 나타냄.
		//size = 300; const때문에 읽기만 하기에 안됨.
		cout << "내가 관리하는 int의 수 - " << size << ", [0] - " << ptr[0] << endl;
	}
};

//---------
int main()
//---------
{
	//DMA
	MemoryMonster a[]{ 1,3,5,7,9,2,4,6,8,10 };
	//[문제] qsort를 사용하여 a를 size기준 오름차순으로 정렬하고 show()를 호출하라.

	void* 판단함수(void*,void*);

	qsort(a, sizeof(a) / sizeof(a[0]), sizeof(MemoryMonster),판단함수);

	for (const MemoryMonster& m : a)
		m.show();

	save("소스.cpp");
}

MemoryMonster* 판단함수(MemoryMonster* fir, MemoryMonster* sec) {
	return fir;
}