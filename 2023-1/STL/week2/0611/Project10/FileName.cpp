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
	// ������ ������ ������ ���� �ܾ�(string) ������ vector v�� �о� �Դ�.
	//
	// �� �������� �ܾ�� ���� ���Ͽ��� �������� �и��� ���������� ���Ѵ�.
	//----------------------------------------------------------------------------
	ifstream ifs("80�ϰ��� ��������.txt");

	vector<string> v({ istream_iterator<string>(ifs), istream_iterator<string>() });
	ifs.close();

	cout << "---------------------" << endl;
	cout << "STL �⸻�����Դϴ�." << endl;
	cout << "---------------------" << endl;

	cout << endl;
	cout << "��� " << v.size() << "���� �ܾ �о����ϴ�." << endl;

	// ������� ������ �Ǵ� �� Ȯ���� �� ������ �����ϵ��� ����.

	// ������ ó������ �ٽ� ���� �ʵ��� �Ѵ�.
	// vector<string> v �� �̿��Ͽ� ������� ������ �ذ�����.

	// [���� 1] �Ҽ��� ���� �������� ���� �󵵸� ���� ����ϴ� ���α׷��� �ۼ��϶�.
	// �������� �����ڶ� ������ ������ 1byte �ƽ�Ű ���ڸ� ���Ѵ�.
	// ��� ȭ���� �����϶�.
	//
	// (����) �����̳� map�� ����Ѵ�.
	// ���� �迭�� ����� �� �ִ� map�� ����� �̿��Ѵ�.

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


	// [���� 2] ���� 1�� ����� ���� �󵵰� ���� �ͺ��� ����϶�.
	// ��� ȭ���� �����϶�.
	// (����) �����̳ʸ� �ϳ� �� �����϶�.
	// ��� ȭ���� �����϶�.

	map<int, char, greater<int>> m2;

	for(const auto& d:m)
		m2.insert(pair<int,char>(d.second, d.first));

	cout << endl << endl;

	for (const auto& d : m2)
		if('A'<=d.second && 'Z'>=d.second
		|| 'a'<=d.second && 'z'>=d.second)
			cout << "[" << d.first << "] - " << d.second << endl;


	// [���� 3] ���� v�� �ܾ��� ���̰� �� ������ �������� �����϶�.
	// ���̰� ���� �� �ܾ ���� �տ� ������ �϶�.
	// ��� ȭ���� �����϶�.
	// (����) lambda�� ����Ѵ�.

	sort(v.begin(), v.end(), [](const string& fir, const string& sec) {return fir.length() > sec.length(); });

	cout << endl << endl;

	for (int i{}; i < 20; ++i)
		cout << v[i] << endl;




	// [���� 4] ���� 3�� ����� ������ ��� �ߺ��� �ܾ ������ �˾Ҵ�.
	// ��� �ܾ �� �� ���� �����ϵ��� ������ ������ ������ ��
	// ���� 3�� ���� �ܾ� ���� ������ ���� �϶�.
	// ��� ȭ���� �����϶�.
	// (����) �˰��� �Լ� unique�� ����Ѵ�.

	sort(v.begin(), v.end());

	v.erase(unique(v.begin(), v.end()), v.end());

	sort(v.begin(), v.end(), [](const string& a, const string& b) {
		return a.length() > b.length();
		});
	cout << endl << endl;

	for (int i{}; i < 20; ++i)
		cout << v[i] << endl;
	

	// [���� 5] ���̰� 7�� �ܾ �� ���� �ִ� �� ����϶�.

	int n{};

	for (const auto& t : v)
	{
		if (7 == t.length())
			++n;
	}

	cout << "���̱⤿ 7�� �ܾ� ���� : " << n << endl;
	

	// [���� 6] ���̰� 7�� �ܾ �������� ���� �ִ�.
	// ���̰� 7�� �ܾ ���� ���� vector<string> v2�� �Ű� ��ƶ�.
	// v���� ���̰� 7�� �ܾ �������� �ʾƾ� �Ѵ�.
	// (����) partition_copy() �� ����Ѵ�.

	vector<string> v2;
	v2.reserve(n);

	partition_copy(v.begin(), v.end(),back_inserter(v2), back_inserter(v), [](string s)->bool {return s.length() == 7; });
	
	cout << endl << endl;
	cout << "v2 size : " << v2.size() << endl;

	for (int i{}; i < 20; ++i)
		cout << v2[i] << endl;
}