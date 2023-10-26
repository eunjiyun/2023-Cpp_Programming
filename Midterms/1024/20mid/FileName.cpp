#include <iostream>
using namespace std;

int main()
{
	// [문제1] 프로그램의 출력을 확인하고 이유를 설명하라 (15)

	char c = 'A' + 'a';

	cout << static_cast<int>(c) << '\n';
	// -94를 출력

	// cout << c 하면
	// 자료형에 맞게 char(c)를 출력

	// cout << (int)((unsigined char)c) 하면
	// c = 65 + 97 = 162
	// 162를 출력

	// c = 0x41 + 0x61 = 0xa2 = 0b1010'0010
	// 맨 앞자리 1은 음수를 나타냄 (2의 보수)
	// 0b0101'1110
	// -94


	// 오버플로우 x, 1바이트만 받음
	// char c = 0x12345678; 는
	// char c = 0x78;		와 같음

	// [문제2] 다음 main() 함수가 문제없이 실행되는 C언어 프로그램의 일부라고 하자
	// 프로그램 실행 시 출력될 내용을 쓰고 (10) 그렇게 되는 이유를 설명하라 (10)

	char a{ 'O' };
	char z{ 'K' };

	//change(a, z);

	cout << a << z << '!' << endl;
	// OK! 를 출력

	// C 프로그램의 경우 change 함수에서 원격조작할 수 있는 방법이 없다
	// void change(char*, char*) 이면 호출 시 change(&a, &z) 여야 한다


	// C++ 프로그램의 경우 void change(char&, char&) 가 가능하지만
	// change 함수의 내용을 모르기 때문에 출력될 내용을 알 수 없다


	// [문제3] 아래의 결과가 출력되도록 함수 makeUpper를 선언하고 (10) 정의하라 (15)

	void makeUpper(char&);		// 선언

	char str[]{ "C++ is a general-purpose programming language" };

	for (char& c : str) {
		makeUpper(c);
	}

	cout << str << endl;
	// 결과: C++ IS A GENERAL-PURPOSE PROGRAMMING LANGUAGE


	// [문제4] 정수(int)를 1부터 n까지 계속 더해나간다 (1 + 2 + 3 + ... + n)
	// 정수(int)의 최댓값 한계를 초과하지 않는 n의 값을 찾아서 화면에 출력하라 (40)

	int max = numeric_limits<int>::max();

	// int sum = 0;
	long long sum = 0;
	int i;

	for (i = 1; sum <= max; ++i) {
		sum += i;
		//cout << i << endl;
	}

	cout << "합계: " << sum << endl;
	cout << "n의 값은 " << i - 2 << endl;


	// 다른 방법

	int n = 1;
	sum = 0;

	while (true) {
		sum += n;
		if (max < sum) {
			break;
		}
		++n;
	}

	cout << "n의 값은 " << n - 1 << endl;


	// 검산

	int sum_c{};
	for (int i = 1; i <= 65535 + 1; ++i) {
		sum_c += i;
	}
	cout << sum_c << endl;

	// 65535
}

void makeUpper(char& c) {	// 정의
	if ('a' <= c && c <= 'z') {
		c -= 0x20;
	}
}





