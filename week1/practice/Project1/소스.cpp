#include <iostream>
#include <random>
#include <fstream>
#include <array>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

// ch를 num개 화면에 출력하는 character monster
class CharMon {
	char ch;							// ['a','z] 구간 중 한 문자
	int num;							// [1, 1000] 구간 중 정수

public:
	CharMon() = default;

	// 화면에 ch를 num개 출력
	void attack() const {
		int n = num;
		if (75 < n)
			n = 74;

		for (int i = 0; i < n; ++i)
			cout << ch;
		cout << ' ' << num << endl;
	}

	char getCh() const {
		return ch;
	}

	void setCh(char newChar) {
		ch = newChar;
	}

	int getNum() const {
		return num;
	}

	void write(ostream& os) const {
		os.write((char*)this, sizeof(CharMon));
	}


};

void Upper(vector<CharMon>*);

//---------
int main()
//---------
{
	ifstream in{ "CharMon 만개.txt", ios::binary };

	// 시험문제에서 CharMon 객체의 수는 변경되지 않는다.
	// 간결한 코드가 더 낫다





	// [문제 1] 파일 폴더에서 CharMon.txt의 크기를 확인하라. 
	// 파일 크기를 보고 저장된 객체의 수를 알 수 있는지 "예/아니오"로 답하고 
	// 그렇게 답한 이유를 설명하라.	
	string fileName{ "CharMon 만개.txt" };
	struct stat s;
	size_t fileSize;

	if (0 == stat(fileName.c_str(), &s))
		fileSize = s.st_size;

	cout << "file size : " << fileSize / 1024 << "kb" << endl;



	// [문제 2] 파일을 읽어 저장된 모든 CharMon 객체를 컨테이너에 저장하라.	
	// 제일 마지막 객체의 attack()을 호출하라.	
	// 출력결과를 보고 마지막 객체의 ch와 num을 답지에 적어라. (예: a - 333개)  

	CharMon mon;
	vector<CharMon> v;

	while (in.read(reinterpret_cast<char*>(&mon), sizeof(mon)))
		v.push_back(mon);
	in.close();

	for (const auto& temp : v)
	{
		cout << "ch : " << temp.getCh() << endl;
		cout << "num : " << temp.getNum() << endl;
	}
	cout << "개수 : " << v.size() << endl;

	v[v.size() - 1].attack();




	// [문제 3] 전역함수 Upper는 [문제 2]에서 사용한 컨테이너를 인자로 받는다.
	// Upper는 컨테이너에 저장된 CharMon의 문자를 대문자로 바꾼다.
	// Upper를 선언하고 정의하라.										
	// (주의) 선언과 정의를 구분하여 적을 것.		

	Upper(&v);
	//for (const auto& temp : v)
	//{
	//	cout << "ch : " << temp.getCh() << endl;
	//	cout << "num : " << temp.getNum() << endl;
	//}





	// [문제 4] 컨테이너에 저장된 CharMon들이 어떤 문자를 갖고 있는지  
	// 다음과 같은 형식으로 출력하라.
	// 
	// ch가 [A]인 몬스터의 수 - 2022
	// ch가 [B]인 몬스터의 수 - 4
	// 
	//  중간 생략
	// 
	// ch가 [Z]인 몬스터의 수 - 20
	//  
	// 관련 코드를 답지에 적고 ch가 [C]인 몬스터의 수는 답지에도 적어라. 

	//char inputCh;
	//vector<CharMon> temp;

	/*cout << "입력 : ";
	cin >> inputCh;*/


	int num = 0;
	for (char ch = 'A'; ch <= 'Z'; ++ch)
	{
		int count = count_if(v.begin(), v.end(), [ch](const CharMon& c) {return c.getCh() == ch; });
		cout << ch << " 개수 : " << count << endl;
		num += count;
	}
	cout << "총 개수 : " << num << endl;
	cout << "v 사이즈 : " << v.size() << endl;


	/*for (const auto& t : temp)
	{
		cout << "ch : " << t.getCh() << endl;
		cout << "num : " << t.getNum() << endl;
	}*/


	// [문제 5] num이 777인 CharMon 객체의 수를 화면에 출력하라.		
	// 출력된 객체의 수를 답지에도 적어라.							

	/*int inputNum;
	cout << "num 입력 : ";
	cin >> inputNum;*/
	vector<CharMon> temp;

	auto find = copy_if(v.begin(), v.end(), back_inserter(temp), [](CharMon& c) {return c.getNum() == 777; });

	/*for (const auto& t : temp)
	{
		cout << "num : " << t.getNum() << endl;
		cout << "ch : " << t.getCh() << endl;
	}*/
	cout << "777 개수 : " << temp.size() << endl;



	// [문제 6] 문제를 해결하기 위해 사용한 컨테이너를 선택한 이유를 설명하라. (10)
}

void Upper(vector<CharMon>* vec)
{
	transform(vec->begin(), vec->end(), vec->begin(), [](CharMon& c) {c.setCh(toupper(c.getCh())); return c; });
}



