#include<iostream>
#include<fstream>
using namespace std;

int num[123'456]{ 1 };

int main()
{
	//1. 다음은 C++ 프로그램의 일부분이다. 실행 후 출력값을 살펴보고 
	// 왜 그런 값이 나오는지 설명하라. (설명 10)

	{
		char c[10]{ 'T','e','s','t' };

		for (int number : c)
			cout << number << '\n';
	}
	//int로 읽었기 때문에

	//2. 전역변수 num을 다음과 같이 사용하였다. 실행파일 크기에 미치는
	//영향을 설명하라. (설명 10)

	cout << "시험 중" << '\n';

	//이만큼의 메모리를 쓰고 있다면 실행파일의 크기가 5mb가 된다는 뜻
	//메모리의 모양을 저장해놓는 곳은 실행파일 밖에 없기 때문

	//3. 함수 change에 문자열 str 관련 정보를 넘겨 다음과 같은 출력결과가
	//나왔다. (출력결과) THE-QUICK-BROWN-FOX-JUMPS-OVER-THE-LAZY-DOG

	//함수 change를 선언하고 정의한 후 호출하라. 각 항목을 구분해서
	//답지에 적어라. (선언 5) (정의 10) (호출 5)

	char str[]{ "The quick brown fox jumps over the lazy dog" };

	//여기에서 함수 change를 호출한다
	//여기에 들어갈 코드를 작성하라.

	void change(char[]);

	change(str);

	cout << str << '\n';
	//THE-QUICK-BROWN-FOX-JUMPS-OVER-THE-LAZY-DOG;

	//4. 다음은 실행되는 C++언어 코드의 일부분이다. 이 코드를 실행할 때
	//어떤 출력결과가 나올지 쓰고 그렇게 생각한 이유를 설명하라.
	//(주의) change 함수는 화면에 어떤 것도 출력하지 않는다. (설명 10)

	char a = 'K';
	char b = 'O';

	void change(char& , char& );

	change(a, b);

	cout << a << b << '!' << '\n';

	//5. 배열 a를 qsort 함수를 사용하여 정렬하라. 정렬기준은 홀수와 짝수이다.
	//문제의 (출력 예)와 같이 왼편에 홀수, 오른편에 짝수가 와야 한다.
	//문제를 해결하기 위해 추가한 모든 코드를 답지에 적어라.
	//(코드 20)

	int arr[]{ 1,2,3,4,5,6,7,8,9,10 };

	//여기에 들어갈 코드를 작성하라.
	//qsort로 정렬해야 한다.

	qsort(arr, sizeof(arr) / sizeof(arr[0]), sizeof(int), [](const void* fir, const void* sec) {
		return *(int*)sec % 2 - *(int*)fir % 2;
		});


	for (int n : arr)
		cout << n << ' ';
	cout << endl;

	//(출력 예) 9 3 7 5 1 10 4 8 2 6
	//이와 같이 홀수와 짝수가 분리되어야 한다

	//6. e-class에서 파일 "자료2.txt"를 가져온다. "자료2.txt" 파일에는
	//알파벳 소문자와 공백문자만 되어 있다. 파일을 한 번만 읽어서

	//6-1) 이 파일에 있는 알파벳은 모두 몇 개인가 출력하라. 
	// 화면에 출력된 개수를 답지에도 써라.
	//(파일 읽고 개수 세는 코드 5, 알파벳 개수 5)

	//6-2) 'a'부터 'z'까지 알파벳 중에서 가장 개수가 많은 알파벳과 
	//그 개수를 출력하라. 화면에 출력한 것을 답지에도 써라. (코드 15)
	//(화면에 출력한 가장 개수가 많은 알파벳과 그 개수 5)

	ifstream in{ "자료2.txt" };

	if (not in)
		return 0;

	string s;
	int cnt{};
	int al[26]{};
	while (in >> s) {
		for(char c:s)
			if (islower(c))
			{
				++cnt;
				++al[c - 'a'];
			}

		
	}

	int max{ al[0] };
	char name{ 'a' };
	for (int i{ 1 }; i < sizeof(al) / sizeof(al[0]); ++i) {
		if (max < al[i])
		{
			max = al[i];
			name = static_cast<char>(i + 'a');
		}
	}

	cout << "cnt : " << cnt << endl;
	cout << "al : " << name << endl;
	cout << "max : " << max << endl;
}

void change(char s[])
{
	for (int i{}; i < strlen(s); ++i)
	{
		if (islower(s[i])||isupper(s[i]))
			s[i]=toupper(s[i]);
		else
			s[i] = '-';
	}
}

void change(char& fir, char& sec)
{
	char temp = fir;
	fir = sec;
	sec = temp;
}