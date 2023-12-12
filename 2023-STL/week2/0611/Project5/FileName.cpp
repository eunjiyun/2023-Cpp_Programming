#include<iostream>
#include<random>
#include<fstream>
#include<array>
using namespace std;

class NUM
{
	int val;
	
public:
	NUM(int n):val(n){}

	bool operator!=(NUM other)
	{
		return (other.val != val);
	}
	int operator*()
	{
		return val;
	}
	NUM operator++()
	{
		++val;
		return *this;
	}
};


//반복자 구간을 인자로 받아 값을 출력하는 함수이다.
template <class Iter, class Seperator>
void print(Iter b, Iter e, Seperator s)
{
	while (b != e)
	{
		cout << *b << s;
		++b;
	}
	cout << endl;
}

default_random_engine dre;

int main()
{
	//글자들 파일에는 몇 개인지 모르는 알파벳 소문자와 공백 문자가 기록되어 있다.

	ifstream in{ "글자들.txt" };

	vector<char> v;

	//1. 글자들.txt에 저장된 문자 중에서 소문자만을 모두 읽어 벡터 v에 저장하라.
	//v에 저장된 원소의 수를 화면에 출력하고 답지에도 적어라.
	//(주의) v는 이미 생성되어있다.

	char c;
	while (in >> c)
	{
		if (islower(c))
			v.push_back(c);
	}
	
	cout << "v size : " << v.size() << endl;
	cout << "v 크기 : " << v.size() * sizeof(char) << endl;

	//2. 벡터 v에 저장되어 있는 글자들에서 글자 's' 't' 'l'이 연속된 경우는 모두 몇 번인가 출력하고 답지에도 적어라.

	int n{};
	for (int i{}; i < v.size(); ++i)
	{
		if ('s' == v[i] && 't' == v[i + 1] && 'l' == v[i + 2])
		{
			++n;
			i += 2;
		}
	}

	cout << "stl은 총 " << n << "번" << endl;
	
	//3. 
	sort(v.begin(), v.end());//v를 오름차순으로 정렬하였다.
	array<int, 26> a;
	//오름차순으로 정렬된 벡터 v에서 각 알파벳의 개수를 array<int, 26> a에 저장하라.
	//a[0]에는 'a', a[1]에는 'b' ... , a[25]에는 'z'의 개수가 저장되도록 하라.
	//각 알파벳의 개수를 화면에 출력하고 'C'의 개수는 답안지에도 적어라.
	//(주의) O(n) 알고리즘을 사용하면 감점함. 정렬되어 있다는 점을 활용할 것
	//=>for루프 사용x=>O(n)

	int num[26];
	num[0] = 0;

	for (char ch = 'b'; ch <= 'z'; ++ch)
	{
		auto it = lower_bound(v.begin(), v.end(), ch);
		num[ch - 'a'] = distance(v.begin(), it);
	}

	for (int i{}; i < 26; ++i)
	{
		if (25 != i)
			a[i] = num[i + 1] - num[i];
		else
			a[25] = v.size() - num[25];

		cout << "[" << char(i + 'a') << "] - " << a[i] << endl;
	}
	
	

	shuffle(v.begin(), v.end(), dre);      // 정렬된 벡터를 섞는다

	print(v.begin(), v.begin() + 10, " - ");        // 10개를 출력해 본다
	cout << endl;

	// print 실행 결과 (예시)
	// a - p - t - v - e - k - k - v - k - i -

	// [문제 4] 다음 문장을 실행하면 화면에 [1, 11)까지 숫자가 출력되도록 필요한 코딩을 하라.   (40)
	// (주의) main() 안의 코드를 수정하지 않고 해결하여야 한다.  

	print(NUM(1), NUM(11), " ");        // 출력 1 2 3 4 5 6 7 8 9 10  
}