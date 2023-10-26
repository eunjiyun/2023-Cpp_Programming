#include<iostream>
#include<thread>
#include<algorithm>
#include<random>
#include<fstream>
using namespace std;

int big(int[], int);

void makeData();

string fileName{ "정수몇개.txt" };

int main()
{
	//1. 정수 배열과 원소 수를 인자로 받아 
	//배열의 원소 중 가장 큰 값을 찾아
	//되돌려 주는 함수 big을 선언하고 정의하라.

	int a[5]{ 1,2,3,4,5 };
	int b[10]{ 1,2,3,4,5,6,7,8,9,10 };

	cout << "a에서 제일 큰 값 " << big(a, 5) << endl;//5
	cout << "b에서 제일 큰 값 " << big(b, 10) << endl;//10

	//2. 다음 프로그램을 (Debug 모드, x86)에서 컴파일하고
	//실행하였다.
	//실행 결과가 왜 그렇게 되는지를 메모리 관점에서 설명하라.
	//(주의) 사용한 비주얼 스튜디오의 버전(메뉴 - 도움말 -정보)
	//를 답지에 적어라. (예: 버전 16.2.3)

	/*int* p;

	while (true) {
		p = new int[10'000'000];
		this_thread::sleep_for(500ms);
	}*/

	//0.5초에 한 번씩 int 10'000'000개의 크기를 heap영역에 할당하기 때문에 
	//pc가 감당할 수 없을 만큼 메모리를 사용하게 되면 오류가 뜨고 프로그램이 종료됩니다.
	

		//3. sort 함수를 사용하여 text를 대소문자 관계없이
		//오름차순으로 정렬하라.
		//(참고) char c를 소문자로 변환하려면 tolower(c)를
		//호출하면 된다.

		//전체 namespace를 사용하지 않고 접미사 s를 사용하려면

		//using namespace std::string_literals;

		string text{ "The Quick Brown Fox Jumps Over The Lazy Dog"s };

		//여기에 들어갈 코드를 답지에 적어라.
	
		sort(text.begin(), text.end(), [](char fir,char sec) {
			return tolower(fir) < tolower(sec);
			});
		

		cout << text << endl;//aBcDeeeFghhiJkLmnooOopQrrsTTuuvwxyz (출력결과)

		//4. 이 프로그램은 정수 50개를 파일에 기록한다.
		//파일에 있는 모든 정수의 평균값을 계산하여 출력하는 
		//코드를 작성하라. (주의) 출력된 값도 답지에 써라.

	makeData();

	//여기에서 파일을 읽어 평균값을 계산하는 코드를 작성하면 되겠다.
	ifstream in{ fileName };

	if (not in)
		return 1;

	int temp;
	double sum{};
	int ave;
	while (in >> temp)
		sum += temp;
	ave = sum / 50;

	cout << "평균 : " << ave<< endl;//1273778304   1273778420  1.27378e+09
	
}

int big(int arr[], int size)
{
	int max = arr[0];

	for (int i{ 1 }; i < size; ++i)
		if (arr[i] > max)
			max = arr[i];

	return max;
}


void makeData()
{
	default_random_engine dre;
	uniform_int_distribution<int> uid;

	ofstream out{ fileName };

	for (int i{}; i < 50; ++i)
		out << uid(dre) << endl;
}