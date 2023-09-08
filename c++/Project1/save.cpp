//----------------------------------------------------------------------------------------------------------------------------------
//save.cpp 한 학기 강의를 저장한다
// 
// 2023. 9. 7
//----------------------------------------------------------------------------------------------------------------------------------

//#include "save.h"
#include<string>
#include<fstream>
#include<chrono>
using namespace std;

//------------------------------------
void save(const std::string& fileName)
//------------------------------------
{
	ifstream in{ fileName};//읽을 파일을 연다. -RAII C++의 자원 관리 기법이 있어서 닫을 필요가 없다.
	ofstream out{ "2023-2 cpp.txt" ,ios::app };//두 번째 인자에 1을 넣어도 되지만 의미를 알 수 없는 숫자를 쓰는 것은 지양해야 한다.

	auto now = chrono::system_clock::now();//epock 1초에 숫자가 하나씩 늘어난다. 숫자를 리턴 받을 수 있다. //현재 time_point를 얻는다.
	auto utc = chrono::system_clock::to_time_t(now);//UTC시간으로 변경

	//localtime은 인자로 메모리 블럭을 받는데 시작 번지만 받아온다. 해킹의 온상이 되는 코드 -sdl 검사 아니요
	auto lt = localtime(&utc);//지역 달력시간으로 변경

	auto old = out.imbue(locale("ko_KR"));//로켈이라고 읽는데 출력스트림을 대한민국으로

	out << '\n' << '\n';
	out << "=====================================================" << '\n';
	out << "저장한 시간 : " << put_time(lt, "%x %A %X") << endl;
	out << "=====================================================" << '\n';
	out << '\n';
	out.imbue(old);

	char c;

	in >> noskipws;//white space도 읽어야 - space, enter, tab
	while (in >> c)
		out << c;
}