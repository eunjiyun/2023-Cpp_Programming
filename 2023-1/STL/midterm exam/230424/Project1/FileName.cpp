#include <iostream>
#include <fstream>
#include <format>
#include <filesystem>
#include <string>
#include <algorithm>
using namespace std;


//------------ 주 의 ------------
// namespace std를 사용하였다.
// include 문장을 답지에 적을 필요없다.
// 실행되지 않는 코드를 적으면 감점한다
// 답이 맞더라도 효율 낮은 코드나 알고리즘을 사용하지 않은 코드는 감점한다.
// 프로그램 환경 - Release/x64, 프로젝트 속성 - 미리 보기 - 최신 C++ 초안의 기능(/std:c++latest)

// e-class에서 시험.zip을 다운 받은 후 시작한다.

// 각 문제를 해결하는데 필요한 코드( 멤버함수 포함 )를 답지에 적는다.
// 화면 출력을 적으라는 문제는 출력된 내용을 답지에 적는다.


//----------------------------------------------------------------------------
// class Test
//----------------------------------------------------------------------------
class Test {
	size_t id{};						// 랜덤 숫자
	string word{};						// 영문자, 공백이 없으며 최대 15글자

public:
	Test() = default;

	// num과 p에 저장된 int 값을 화면에 표시한다
	void show() const {
		cout << format("id:{:8}   word:{:15}", id, word) << endl;
	}

	void write(ostream& os) const {
		os.write((char*)this, sizeof(Test));
	}

	

	size_t getId() {
		return id;
	}
	string getWord() {
		return word;
	}

	void setWord(const string& newWord) {
		word = newWord;
	}

	
};

void deleteZ(vector<Test>&); 
void deleteSameId(vector<Test>&);

//---------
int main()
//---------
{
	// "TEST 객체" 파일(바이너리 모드)에 Test 객체를 write() 멤버함수로 기록하였다.  
	// 파일에는 몇 개인지 모르는 Test 객체가 저장되어 있다.

	string fileName{ "Test 객체"s };

	ifstream in{ fileName, ios::binary };
	if (!in) {
		cout << fileName << " 파일을 열 수 없습니다" << endl;
		exit(0);
	}

	size_t fileSize = filesystem::file_size(fileName);
	cout << "파일 \"" << fileName << "\"의 크기 - " << fileSize << " 바이트" << endl;





	// [문제 1] 출력된 파일 크기를 보고 저장된 객체의 수를 알 수 있는지를 
	// "예/아니오"로 답하고 그렇게 답한 이유를 설명하라.						(10)

	//예 바이너리 모드에서는 알수 있음
	cout << "객체의 수 : " << fileSize / sizeof(Test) << endl;
	cout << sizeof(Test) << endl;



	// [문제 2] 파일을 읽어 객체를 컨테이너에 저장하라.							
	// 읽은 객체의 개수를 출력하고, 마지막 객체의 show()를 호출하라.
	// 화면에 출력된 내용을 답지에도 적어라.									(30)(저장관련코드:20, 출력코드와 출력: 10) 

	// (확인) 처음과 다음 객 체의 show()를 호출한 결과는 다음과 같다.
	// id:  511803   word : zvrkmetlqhubzlq
	// id:   18649   word : ohjdt

	vector<Test> v;
	Test t;
	
	/*while (in && !in.eof())
	{
		t.read(in);
		v.push_back(t);
	}*/

	while(in.read(reinterpret_cast <char*>(&t), sizeof(t)))
		v.push_back(t);
	in.close();

	cout << "객체의 개수 : " << v.size() << endl;
	v.back().show();

	/*for (const auto& vec : v)
	{
		vec.show();
	}*/


	// [문제 3] 함수 deleteZ()는 [문제 2]에서 사용한 컨테이너를 인자로 받아
	// 컨테이너에 저장된 Test 객체의 word의 문자 중 소문자 'z'를 삭제하는 함수이다.
	// 이 함수를 선언하고 정의한 후 호출하라.									(35)(선언:5, 함수정의와 관련 코드:30)

	// (참고) string은 begin()과 end()를 제공하며 글자는 contiguous memory에 저장된다

	// (참고) 컨테이너 이름이 x라면 deleteZ(x); 와 같이 호출한다.

	// (확인) 'z'를 삭제한 후 처음과 다음 객체의 show()를 호출한 결과는 다음과 같다.
	// id:  511803   word : vrkmetlqhublq
	// id :  18649   word : ohjdt

	deleteZ(v);
	v[0].show();
	v[1].show();
	

	// [문제 4] 컨테이너에 저장한 Test 객체를 word 오름차순으로 정렬하고  
	// 제일 마지막 객체의 show()를 호출하라.
	// 화면에 출력된 결과를 답지에 적어라.										(20)(코드:15, 출력:5)
	
	sort(v.begin(), v.end(), [](Test& lhs, Test& rhs) {
		return lhs.getWord() < rhs.getWord();
		});
	v.back().show();

	/*for (const auto& vec : v)
		vec.show();*/



	// [문제 5] 컨테이너에 저장된 Test 객체 중 id 값이 같은 객체는 하나 만 남기고 다 삭제하라.
	// 삭제 후 컨테이너에 남은 Test 객체의 수를 출력하고 결과를 답지에 적어라.	(25)(관련 코드:20, 출력:5)

	deleteSameId(v);
	cout << "남은 객체의 수: " << v.size() << endl;

	/*for (const auto& vec : v)
		vec.show();*/

}

void deleteZ(vector<Test>& v) {
	for (auto& t : v) {
		auto word = t.getWord();
		word.erase(std::remove_if(word.begin(), word.end(), [](char c) { return c == 'z'; }), word.end());
		t.setWord(word);
	}
}
void deleteSameId(vector<Test>& v) {
	sort(v.begin(), v.end(), []( Test& a, Test& b) {
		return a.getId() < b.getId();
		});

	auto it = unique(v.begin(), v.end(), []( Test& a,  Test& b) {
		return a.getId() == b.getId();
		});

	v.erase(it, v.end());
}