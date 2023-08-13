#include <iostream>
#include <fstream>
#include <string>
#include <array>
#include <vector>
#include <list>
#include <algorithm>
#include <format>
using namespace std;


class Test {
	int id;								// 일련번호
	string word;						// 단어

public:
	Test() = default;

	int getId() const {
		return id;
	}

	string getWord() const {
		return word;
	}

	void show() const {
		cout << format("id:{:>5d} 단어: {}", id, word) << endl;
		// cout << "id:" << id << " 단어:" << word << endl;
	}

	void write(ostream& os) const {
		os << id << " " << word << " ";
	}

	void read(istream& is) {
		is >> id >> word;
	}



	/*void read(istream& is) {
		is >> id;
		int len;
		is >> len;
		char buf[1024];
		is.read(buf, len);
		word = string(buf, len);
	}*/
	//void read(istream& is) {
	//	is.read(reinterpret_cast<char*>(&id), sizeof(id));
	//	int len;
	//	is.read(reinterpret_cast<char*>(&len), sizeof(len));
	//	char buf[1024];
	//	is.read(buf, len);
	//	buf[len] = '\0';    // null 문자 추가
	//	word = string(buf);
	//}
};


// 몇 개인지 모르는 Test 객체가 "시험자료.txt" 파일에 text 모드로 기록되어 있다.
// Test 객체는 write() 멤버함수로 자신을 기록한다.

//---------
int main()
//---------
{
	ifstream in{ "시험자료.txt" };

	// [문제 1] Test 객체를 모두 읽어 컨테이너에 저장하라.
	// 모두 몇 객체가 있는지 출력하고 답지에 출력된 갯수도 적어라.	          
	// Test 객체를 읽기 위해 필요한 멤버함수를 추가할 수 있다.
	// 답지에 관련 코드를 모두 적어라.

	string fileName{ "시험자료.txt" };
	struct stat s;
	size_t fileSize;
	vector<Test> v;
	Test t;

	if (0 == stat(fileName.c_str(), &s))
		fileSize = s.st_size;

	/*while (in.read(reinterpret_cast<char*>(&t), sizeof(t)))
		v.push_back(t);
	in.close();*/

	while (in && !in.eof()) {
		t.read(in);
		v.push_back(t);
	}
	in.close();

	for (const auto& temp : v)
	{
		cout << "id : " << temp.getId() << endl;
		cout << "word : " << temp.getWord() << endl;
	}



	// [문제 2] 컨테이너의 Test 객체 중 word의 길이가 가장 긴 객체를 화면에 출력하라.		
	// 출력된 결과를 답지에도 적어라.								
	// 출력은 멤버함수 show()를 사용하라.
	Test longest;

	for (const auto t : v)
	{
		if (t.getWord().size() > longest.getWord().size())
			longest = t;
	}
	longest.show();




	// [문제 3] 컨테이너를 Test 객체 id 기준 오름차순으로 정렬하라.
	// 제일 마지막 객체를 show()로 출력하고 답지에도 적어라.		

	// id를 기준으로 정렬
	sort(v.begin(), v.end(), [](const Test& a, const Test& b) {
		return a.getId() < b.getId();
		});

	for (const auto& vec : v)
		cout << "id: " << vec.getId() << endl;




	// [문제 4] 단어를 입력받아 같은 단어가 있는 Test 객체를 검색하는 코드를 작성하라.
	// word가 같은 객체가 몇 개인지 세서 출력하고,					
	// 찾는 객체가 있다면 모두 화면에 출력하도록 하라.				
	// (주의) 이 코드는 계속 실행되어야 한다.				
	// (실행화면의 화면 출력을 참고하라)


	cout << "단어를 검색합니다" << endl;
	while (true) {
		string word;
		cout << "찾으려는 단어를 입력하세요: ";
		cin >> word;


		// 여기 들어갈 코드를 작성하면 된다.
		vector<Test> temp;


		//int count = count_if(v.begin(), v.end(), [word](const Test& t) {return t.getWord() == word; });
		//auto it = count_if(v.begin(), v.end(), []() {})
		auto find = copy_if(v.begin(), v.end(), back_inserter(temp), [word](Test& t) {return t.getWord() == word; });
		cout << word << "의 개수 - " << temp.size() << endl;

		for (const auto& vec : temp)
		{
			cout << "id : " << vec.getId() << endl;
			cout << "word : " << vec.getWord() << endl;
		}
	}
}
