#include <iostream>
#include<fstream>
#include<vector>
#include<map>
#include<algorithm>
#include<string>
using namespace std;

//----------------------------------------------------------------------------
int main()
//----------------------------------------------------------------------------
{
	//---------------------------------------------------------------------------
	// 파일의 내용을 다음과 같이 단어(string) 단위로 vector v에 읽어 왔다.
	//
	// 이 문제에서 단어는 원본 파일에서 공백으로 분리된 문자집합을 말한다.
	//----------------------------------------------------------------------------
	ifstream ifs("80일간의 세계일주.txt");

	vector<string> v({ istream_iterator<string>(ifs), istream_iterator<string>() });
	ifs.close();

	cout << "---------------------" << endl;
	cout << "STL 기말시험입니다." << endl;
	cout << "---------------------" << endl;

	cout << endl;
	cout << "모두 " << v.size() << "개의 단어를 읽었습니다." << endl;

	// 여기까지 실행이 되는 지 확인한 후 문제를 시작하도록 하자.

	// 파일을 처음부터 다시 읽지 않도록 한다.
	// vector<string> v 를 이용하여 순서대로 문제를 해결하자.

	// [문제 1] 소설에 사용된 영문자의 출현 빈도를 세어 출력하는 프로그램을 작성하라.
	// 문제에서 영문자란 공백을 제외한 1byte 아스키 문자를 말한다.
	// 결과 화면을 참고하라.
	//
	// (도움말) 컨테이너 map을 사용한다.
	// 연관 배열로 사용할 수 있는 map의 기능을 이용한다.

	map<char, int> m;

	for (const auto& t : v)
	{
		for (const auto& c : t)
		{
			++m[c ];
		}
	}

	for (char c = 'A'; c <= 'Z'; ++c)
		cout << "[" << c << "] - " << m[c] << endl;
	for (char c = 'a'; c <= 'z'; ++c)
		cout << "[" << c << "] - " << m[c] << endl;


	// [문제 2] 문제 1의 결과를 출현 빈도가 높은 것부터 출력하라.
	// 결과 화면을 참고하라.
	// (도움말) 컨테이너를 하나 더 생성하라.
	// 결과 화면을 관찰하라.

	map<int, char, greater<int>> m2;

	for(const auto& d:m)
		m2.insert(pair<int,char>(d.second, d.first));

	cout << endl << endl;

	for (const auto& d : m2)
		if('A'<=d.second && 'Z'>=d.second
		|| 'a'<=d.second && 'z'>=d.second)
			cout << "[" << d.first << "] - " << d.second << endl;


	// [문제 3] 벡터 v를 단어의 길이가 긴 순서를 기준으로 정렬하라.
	// 길이가 가장 긴 단어가 제일 앞에 오도록 하라.
	// 결과 화면을 참고하라.
	// (도움말) lambda를 사용한다.

	sort(v.begin(), v.end(), [](const string& fir, const string& sec) {return fir.length() > sec.length(); });

	cout << endl << endl;

	for (int i{}; i < 20; ++i)
		cout << v[i] << endl;




	// [문제 4] 문제 3의 출력을 관찰한 결과 중복된 단어가 있음을 알았다.
	// 모든 단어가 한 번 씩만 존재하도록 벡터의 내용을 수정한 후
	// 문제 3과 같이 단어 길이 순으로 정렬 하라.
	// 결과 화면을 참고하라.
	// (도움말) 알고리즘 함수 unique를 사용한다.

	sort(v.begin(), v.end());

	v.erase(unique(v.begin(), v.end()), v.end());

	sort(v.begin(), v.end(), [](const string& a, const string& b) {
		return a.length() > b.length();
		});
	cout << endl << endl;

	for (int i{}; i < 20; ++i)
		cout << v[i] << endl;
	

	// [문제 5] 길이가 7인 단어가 몇 개나 있는 지 출력하라.

	int n{};

	for (const auto& t : v)
	{
		if (7 == t.length())
			++n;
	}

	cout << "길이기ㅏ 7인 단어 개수 : " << n << endl;
	

	// [문제 6] 길이가 7인 단어가 생각보다 많이 있다.
	// 길이가 7인 단어를 따로 떼어 vector<string> v2에 옮겨 담아라.
	// v에는 길이가 7인 단어가 존재하지 않아야 한다.
	// (도움말) partition_copy() 를 사용한다.

	vector<string> v2;
	v2.reserve(n);

	partition_copy(v.begin(), v.end(),back_inserter(v2), back_inserter(v), [](string s)->bool {return s.length() == 7; });
	
	cout << endl << endl;
	cout << "v2 size : " << v2.size() << endl;

	for (int i{}; i < 20; ++i)
		cout << v2[i] << endl;
}