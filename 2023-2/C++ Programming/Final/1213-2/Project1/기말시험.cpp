//-------------
// 기말시험.cpp 
//-------------

//910
#include <iostream>
#include <random>
#include "Shape.h"
#include "Triangle.h"
#include "Circle.h"
using namespace std;


// 시험에 사용한 랜덤 엔진과 분포
default_random_engine dre{ 202312 };
uniform_int_distribution<> uid{ 0, 1 };					// 홀수와 짝수
uniform_int_distribution<> uidRad{ 1, 100 };			// 원의 반지름		

int findMaxRad(Shape**, int);

int countCircles(Shape** shapes, int nShapes) {
	int nCircle = 0;
	for (int i = 0; i < nShapes; ++i) {
		const Circle* circle = dynamic_cast<const Circle*>(shapes[i]);
		if (circle != nullptr) {
			// 현재 도형이 Circle 클래스의 인스턴스인 경우
			++nCircle;
		}
	}
	return nCircle;
}
void copyCircles(Shape** shapes, int nShapes, Circle** circles, int nCircle) {
	int circleIndex = 0;
	for (int i = 0; i < nShapes; ++i) {
		const Circle* circle = dynamic_cast<const Circle*>(shapes[i]);
		if (circle != nullptr) {
			// 현재 도형이 Circle 클래스의 인스턴스인 경우
			circles[circleIndex++] = new Circle(*circle);
		}
	}
}
// 반지름 비교 함수
//bool compareByRadius(const Circle* a, const Circle* b) {
//	return a->getRad() < b->getRad();
//}

//--------
int main()
//--------
{
	//---------------------------------------------------
	// 시험준비가 제대로 되었는지 프로그램을 실행해 보자.
	//---------------------------------------------------
	Triangle aTriangle;
	Circle aCircle{ Point{}, uidRad( dre )};	// 중심점은 그대로 두고 반지름은 랜덤으로 초기화
			
	aTriangle.draw();							// [  1] - 삼각형
	aCircle.draw();								// [  2] - 원, 중심점( 0, 0 ), 반지름 - 60

	cout << '\n';
	cout << "출력결과는 \"시험출력예시.txt\"를 참고하라" << '\n';
	cout << '\n';


	//--------------------------------------------------------
	// 지금부터 순서대로 문제를 해결하고 답을 답안지에 적는다.
	//--------------------------------------------------------

	//-----------------------------------------------------------------------------------
	// [문제 1] Triangel 객체 한 개의 크기가 몇 byte인지 화면에 출력하고 답지에도 적어라. 
	// 객체의 크기가 왜 그렇게 출력되는지 이유를 상세하게 설명하라.					 (20) 
	//-----------------------------------------------------------------------------------

		// 여기에 들어갈 코드와 출력된 결과(byte 수)를 답지에 적는다.	(코드 10)
		// 출력된 이유를 답지에 적는다.									(이유 10)

	Triangle t;
	cout << "size : " << sizeof(t) << endl;




	//--------------------------------------------
	// 다음은 도형을 관리하는데 필요한 변수들이다.
	//--------------------------------------------

	int nShape = 100;					// 현재 관리하는 도형의 개수를 여기에 저장한다
										// 모두 100개의 도형을 만들어 관리한다

	Shape** shapes;						// shapes는 Shape* 주소를 저장할 수 있다
	Shape* pShapes[100];				// pShapes는 Shape* 100개 배열이다

	shapes = pShapes;					// 이제 shapes는 Shape* 100개가 저장된 배열을 가리킨다	


	//----------------------------------------
	// 다형성이 구현됨을 확인해 보는 문제이다.
	//----------------------------------------

	//--------------------------------------------------------------------
	// [문제 2] 위에서 num 개의 도형을 관리할 수 있는 shapes를 생성하였다.
	// 관리하는 도형은 Circle과 Triangle 2가지 종류만 있다.
	// 
	// 랜덤엔진 dre와 랜덤분포 uid를 사용하여 값이 홀수이면 Triangle을, 
	// 짝수라면 Circle을 i번째 도형으로 생성하여
	// 100개의 도형을 shapes가 관리할 수 있도록 하라.				  (20)
	//
	// 생성 방식은 처음의 준비과정에서와 같이 
	// Triangle은 default 생성	
	// Circle은   { Point{}, uidRad( dre ) }을 인자로 생성하라.
	//-------------------------------------------------------------------- 	

	for (int i = 0; i < nShape; ++i) {
		int sel = uid( dre );

		// 랜덤 값 sel 에 따라 i번째 도형을 생성한다.
		// 여기에 들어갈 코드를 적으면 된다.			(코드 20)

		if (0 != sel % 2)
			shapes[i] = new Triangle;
		else
			shapes[i] = new Circle(Point{}, uidRad(dre));
	
	
	
	}


	//-----------------------------------------------------
	// [문제 3] 관리하는 모든 도형의 draw() 멤버를 호출하여 
	// 다형성이 구현됨을 보여라.	                   (10)
	//-----------------------------------------------------

	cout << '\n';
	cout << "---------------------------------------------------" << '\n';
	cout << "[문제 3] 관리하는 100개 도형의 draw()를 호출한 결과" << '\n';
	cout << "---------------------------------------------------" << '\n';

	// 여기에 들어갈 코드를 답지에 적는다.			(코드 10)


	for (int i{}; i < nShape; ++i)
		shapes[i]->draw();


	//------------------------------------------------------------------------------
	// [문제 4] 함수 findMaxRad()는 shapes와 nShape을 인자로 받아
	// shapes 중에서 가장 반지름 값이 큰 Circle을 찾은 후 그 Circle의 id를 리턴한다.
	// findMaxRad를 아래와 같이 호출하였다.
	// 함수 findMaxRad를 선언하고 정의하라. 					   (선언 5, 정의 15)
	//------------------------------------------------------------------------------

	cout << '\n';
	cout << "--------------------------------" << '\n';
	cout << "[문제 4] 반지름이 가장 큰 Circle" << '\n';
	cout << "--------------------------------" << '\n';

	
	// 이 부분의 주석을 풀고 진행하자
	
	/*int id = findMaxRad( shapes, nShape );
	cout << "반지름이 가장 큰 Circle => "; 
	shapes[id]->draw( );*/
	


	//-----------------------------------------------------------------
	// [문제 5] 관리하는 도형의 id값을 기준으로 홀수와 짝수로 분리하라.
	// 홀수가 앞에 오고 짝수는 홀수 뒤에 나온다.
	// qdsort를 사용하여 분리하라.							  (코드 20)
	//-----------------------------------------------------------------

		// 여기에 들어갈 코드를 답지에 적는다.			(20)	
	
	
	qsort(shapes, sizeof(shapes) / sizeof(Shape), sizeof(Shape),
		[](const void* a, const void* b) {
			int idA = ((const Shape*)a)->getId();
			int idB = ((const Shape*)b)->getId();

			// ID 값에 따라 정렬하고, 홀수는 짝수보다 앞으로 오도록 함
			if (idA % 2 != idB % 2) {
				// 홀수와 짝수의 경우, 홀수를 우선하여 정렬
				return idA % 2 - idB % 2;
			}
			else {
				// ID 값이 같은 경우, 일반적으로 정렬
				return idA - idB;
			}
		});

	cout << '\n';
	cout << "-------------------------------------------------------------------" << '\n';
	cout << "[문제 5] 홀수와 짝수로 분리 후 관리하는 도형의 draw()를 호출한 결과" << '\n';
	cout << "-------------------------------------------------------------------" << '\n';

	// draw 코드는 의도에 따라 감추었다.  

	for (int i{}; i < nShape; ++i)
		shapes[i]->draw();


	//--------------------=-===-------------------------------------------------------- 
	// [문제 6 설명] 현재 shapes는 100개 도형의 주소를 저장하고 있는 메모리를 가리킨다.
	// 100개 도형 중에서 Circle만 골라 다른 메모리에 저장하려고 한다.
	// Circle만 따로 저장할 메모리에는 Circle을 복사하지 않고 
	// Circle이 저장된 주소만 복사해도, 원하는 문제를 해결하기에 충분하다고 생각한다.
	//-------------------------=====-----=--------------------------------------------- 

	//----------------------------------------------------------------------------------
	// [문제 6] 다음 순서에 따라 코딩하라.											(60)
	// 
	// (6-1) 100개 도형 중에서 Circle은 모두 몇 개인지 세어라. 
	//										-> Circle의 개수를 nCircle에 저장하라.	(10)
	

	//
	// (6-2) Circle* 형식의 자료 Circle개를 저장할 수 있는 메모리를 확보하라. 
	//										-> 이 메모리를 circles로 명명하라.		(10)
	
	

	// (6-3) shapes 중에서 nCircle개의 Circle*를 circles에 복사하라.				(10)	
	 // circles 배열로 Circle 포인터 복사
	
	
	// (6-4) circles를 반지름 기준 오름차순으로 정렬하라. (qsort 사용)				(10)	
	// 
	// (6-5) [문제 1]에서 [문제 6]까지 해결하면서 사용한 메모리를 모두 반환하라.	(20)
	// 
	// (주의) 답지에 (6-1)~(6-5)답을 구분해서 적을 것	
	// (주의) 문제와 관련하여 선언한 변수나 객체를 잊지말고 적을 것
	//----------------------------------------------------------------------------------


	cout << '\n';
	cout << "-----------------------------------------------------------------" << '\n';
	cout << "[문제 6] shapes중에서 nCircle개의 Circle 만 따로 관리하는 circles" << '\n';
	cout << "-----------------------------------------------------------------" << '\n';



	cout << '\n';
	cout << "(6-1) nShape 중에서 Circle의 수 - " << '\n';


	// Circle 개수 세기
	int nCircle = countCircles(shapes, nShape);
	cout << "n : " << nCircle << endl;

	Circle** circles = new Circle * [nCircle];

	cout << '\n';
	cout << "(6-3) circles의 draw 호출" << '\n';

	copyCircles(shapes, nCircle, circles, nCircle);

	/*for (int i{}; i < nCircle; ++i)
		circles[i]->draw();*/



	cout << '\n';
	cout << "(6-4) 반지름 기준 오름차순으로 정렬한 이후 circles의 draw 호출" << '\n';

	// 반지름 기준으로 circles 배열 정렬
	//std::sort(circles, circles + nCircle, compareByRadius);


	// 메모리 해제
	for (int i{}; i < nShape; ++i)
		delete shapes[i];
	//delete[] shapes;

	/*for (int i{}; i < nCircle; ++i)
		delete circles[i];*/
	//delete[]circles;
}

//int findMaxRad(Shape** s, int n)
//{
//	//if (nShape <= 0 || shapes == nullptr) {
//	//	// 예외 처리: 유효하지 않은 입력
//	//	std::cerr << "Invalid input: shapes is nullptr or nShape is non-positive." << std::endl;
//	//	return -1; // 특별한 값으로 오류를 나타냄
//	//}
//
//	int maxId = 0; // 초기값은 배열의 첫 번째 원소로 설정
//	double maxRadius = s[0]->getRad();
//
//	for (int i = 1; i < n; ++i) {
//		double currentRadius = s[i]->getRad();
//		if (currentRadius > maxRadius) {
//			// 현재 원소의 반지름이 최대값보다 크면 최대값 및 인덱스 갱신
//			maxRadius = currentRadius;
//			maxId = i;
//		}
//	}
//
//	return maxId;
//}