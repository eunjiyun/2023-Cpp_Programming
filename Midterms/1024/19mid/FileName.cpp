#include<iostream>
#include<thread>
#include<algorithm>
#include<random>
#include<fstream>
using namespace std;

int big(int arr[], int size);
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

	/*주어진 프로그램은 무한 루프를 실행하며 매 반복마다 크기가 10, 000, 000 인트(int) 배열을 동적으로 할당합니다.
	이 배열은 힙(heap) 메모리에 저장됩니다.
	그런 다음 this_thread::sleep_for(500ms) 함수를 사용하여 500 밀리초(0.5 초) 동안 프로그램을 일시 정지시킵니다.
	메모리 관점에서 이 프로그램을 설명하면 다음과 같습니다 :

	
	    1.프로그램이 실행되면 처음에는 p 포인터가 어떤 주소도 가리키지 않고(쓰레기 값이 들어 있음) while 루프로 진입합니다.

		2.루프의 각 반복에서 new int[10'000'000]를 호출하여 10, 000, 000 개의 int 요소를 포함하는 배열을 동적으로 할당합니다.이 배열은 힙 메모리에 저장됩니다.

		3.각 배열은 메모리를 차지하고, 힙 메모리는 점차 소진됩니다.

		4.this_thread::sleep_for(500ms)를 호출하여 반복마다 0.5초 동안 프로그램이 대기 상태에 들어갑니다.이 동안에는 할당된 메모리가 해제되지 않습니다.

		5.이 과정이 반복되면서 계속해서 새로운 배열이 할당되고, 메모리 소비량이 계속해서 증가합니다.

		6.힙 메모리가 계속 증가하면 결국 더 이상 사용 가능한 메모리가 없어질 것입니다.

		7.메모리가 더 이상 할당되지 못하면, 동적 메모리 할당이 실패하고 프로그램은 "new" 연산자가 실패한 것을 감지하고 오류를 발생시킬 것입니다.

		프로그램은 이러한 루프를 통해 메모리 부족으로 인해 결국 실패할 것입니다.
		프로그램을 실행한 환경(Visual Studio 버전 및 컴퓨터 메모리 용량)에 따라 
		정확한 실패 시점 및 메모리 소비량이 다를 수 있습니다.
		Visual Studio 버전은 문제의 디버그 도구와 관련이 있으며, 
		여기서 제공된 정보에 따라 디버그 모드 및 x86 모드로 실행되었음을 기반으로 설명을 제공했습니다.*/

	//3. sort 함수를 사용하여 text를 대소문자 관계없이
	//오름차순으로 정렬하라.
	//(참고) char c를 소문자로 변환하려면 tolower(c)를
	//호출하면 된다.

	//전체 namespace를 사용하지 않고 접미사 s를 사용하려면
	
	//using namespace std::string_literals;

	string text{ "The Quick Brown Fox Jumps Over The Lazy Dog"s };

	////여기에 들어갈 코드를 답지에 적어라.
	sort(text.begin(), text.end(), [](char& fir,char& sec) {
		return tolower(fir) < tolower(sec);
		});

	cout << text << endl;//aBcDeeeFghhiJkLmnooOopQrrsTTuuvwxyz (출력결과)

	//4. 이 프로그램은 정수 50개를 파일에 기록한다.
	//파일에 있는 모든 정수의 평균값을 계산하여 출력하는 
	//코드를 작성하라. (주의) 출력된 값도 답지에 써라.

	makeData();

	//여기에서 파일을 읽어 평균값을 계산하는 코드를 작성하면 되겠다.
	ifstream in{ fileName };
	int temp;
	double sum{};
	int ave;
	if (not in)
		return 0;
	while (in >> temp)
		sum += temp;

	ave = sum / 50;
	cout << "평균 : " << ave<< endl;
}

int big(int arr[], int size)
{
	int max = arr[0];

	for (int i{ 1 }; i < size; ++i)
		if (max < arr[i])
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