//학번 : 2019184020
//학과 : 게임공학과
//이름 : 윤은지
//설명 : C++에서 string 클래스를 사용하기 위해 #include<string>를 선언하고
//		string 변수 두 개를 선언한 후 cin으로 string 변수를 입력 받고 
//		if문으로 두 변수가 같은지 검사한 후 결과를 cout으로 출력합니다.

#include<iostream>
#include<string>
using namespace std;

int main()
{
	string fir, sec;

	cout << "새 암호를 입력하세요. ";
	cin >> fir;

	cout << "새 암호를 다시 한번 입력하세요. ";
	cin >> sec;

	if (fir == sec)
		cout << "같습니다." << endl;
	else
		cout << "다릅니다." << endl;
}