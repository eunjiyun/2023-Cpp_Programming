//학번 : 2019184020
//학과 : 게임공학과
//이름 : 윤은지
//설명 : cin을 사용하여 두 개의 정수를 읽어 
//		if문으로 큰 수를 판별하고 
//		화면에 cout으로 출력하는 프로그램 입니다.

#include<iostream>
using namespace std;

int main()
{
	int fir, sec;

	cout << "두 수를 입력하라>>";
	cin >> fir >> sec;

	if (fir > sec)
		cout << "큰 수 = " << fir << endl;
	else if (fir == sec)
		cout << "두 수는 같습니다." << endl;
	else
		cout << "큰 수 = " << sec << endl;
}