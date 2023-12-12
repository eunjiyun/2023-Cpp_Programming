#include<iostream>
#include<fstream>
#include <iomanip>  // <iomanip> 헤더 포함
using namespace std;

int cnt{};

void f();

int main()
{
	//1. X만큼 메모리를 STACK에 주시오. 나는 Y라는 메모리를 access 하고싶다.
	// X Y;
	// 답
	//cout << sizeof(Y) << '\n';

	//2. 다음은 C++ 프로그램의 일부분이다. 실행 후 출력값을
	//살펴보고 왜 그런 값이 출력되는지 설명하라. (설명 10)
	int n[10];

	cout << "시험 중..." << '\n';
	for (int number : n)
		cout << number << '\n';

	//3. 재귀호출은 STACK을 넘치게 한다. 다음 코드는 f()를
	//재귀호출한다. 이 코드를 실행하면 호출횟수가 출력될
	//것이다. 호출 횟수 11이 출력되기 전에 STACK이 넘치도록
	//함수 f에 필요한 코드를 추가하라. (코드 20)

	/*cout << "시험 중" << '\n';
	f();*/

	//4. 배열 a를 qsort를 사용하여 값기준 오름차순으로 정렬하였다. 
	//qsort가 비교함수를 몇 번 호출하였는지 출력하는 코드를 추가하고,
	//어디에 어떤 코드를 추가하였는지 답지에 적어라. 출력된 호출횟수를
	//살펴보고 알려진 qsort의 호출횟수와 비교설명하라. 

	int a[1000];

	qsort(a, 1000, 4, [](const void* a, const void* b) {
		++cnt;
		return *(int*)a - *(int*)b;
		});

	for (int n : a)
		cout << n << ' ';
	cout << endl;

	cout << cnt << endl;

	//5. 다음 동작을 수행하는 코드를 작성하라.
	//입력한 학번 개수만큼 int를 저장할 메모리를 동적으로 확보하라.
	//(예: 입력한 학번이 180000 이라면 int 180000개를 저장할 메모리를 확보한다)
	//확보한 메모리를 1부터 시작하는 int값으로 채워라.(1 2 3 ... num)
	//1부터 num까지의 합계와 평균을 출력하라. 평균은 소수점 2자리까지 출력하라.
	//이 프로그램은 언제까지라도 문제없이 실행되어야 한다. (코드 20)

	while (true) {
		int num;
		cout << "본인 학번 중 뒷자리 6자리만 입력하세요: ";
		cin >> num;

		//여기에 들어갈 코드를 답지에 써라

		int* p = new int [num];
		double sum{};
		for (int i{}; i < num; ++i)
		{
			p[i] = i + 1;
			sum += p[i];
		}

		cout << "sum : " << sum << endl;
		cout << "ave : " <<fixed<<setprecision(2)<< sum / num << endl;

		delete[]p;
	}

	//6. e-class에서 파일 "int만개.mp4"를 가져온다. 이 파일에는 몇 개인지
	//모르는 int값이 기록되어 있다. 파일을 한 번만 읽어 모두 몇 개의
	//int값이 있는가와 끝자리가 1인 int는 몇 개인가를 세서 화면에 출력하라.
	//화면에 출력된 값을 답지에도 써라. (코드 15) (출력된 값 5)

	ifstream in{ "int만개.mp4" };
	if (not in)
		return 0;

	//여기에 들어갈 코드를 답지에 써라

	int i;
	int cnt{};
	int num1{};
	while (in >> i)
	{
		++cnt;
		if (1 == i % 10)
			++num1;
	}
	cout << "cnt : " << cnt << endl;
	cout << "num1 : " << num1 << endl;
}

void f()
{
	cout << ++cnt << '\n';

	//여기에 추가 코딩하라.
	char a[1999999999]{ 1,2,3,4 };



	f();
}