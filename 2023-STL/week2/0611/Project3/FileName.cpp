#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include<map>	
#include<string>
using namespace std;


// [���α׷� ȯ��] Release, x64, ������Ʈ �Ӽ� C++ ���: �̸� ���� - �ֽ� C++ �ʾ��� ���(/std:c++latest)

//---------
int main()
//---------
{
	// ���� "����1.dat"�� "����2.dat"�� �� ������ �𸣴� int�� �����Ͽ���. 
	// int ���� operator<<�� ����Ͽ� text ���� ����Ͽ���.
	// (��)	int n = 123;
	//	    out << n << " ";

	ifstream in1{ "����1.dat" };
	ifstream in2{ "����2.dat" };

	vector<int> v1;			// "����1.dat"�� ���⿡ �����Ѵ�
	vector<int> v2;			// "����2.dat"�� ���⿡ �����Ѵ�


	// [���� 1] "����1.dat"�� "����2.dat"�� �о� v1�� v2�� �����ϰ�, v1�� v2�� size()�� ȭ�鿡 ����϶�.
	// �������� v1�� �����ϴ� �ڵ常 ���� ȭ�鿡 ��µ� size()���� ������ �ȴ�.		(15, 5)
	// (����) v1�� v2�� �̹� �����Ǿ��ִ�.

	int num{};

	while (in1 >> num)
		v1.push_back(num);
	while (in2 >> num)
		v2.push_back(num);

	cout << "v1 size : " << v1.size() << endl;
	cout << "v2 size : " << v2.size() << endl;
	cout << "v1 ũ�� : " << v1.size() * sizeof(int) << endl;
	cout << "v2 ũ�� : " << v2.size() * sizeof(int) << endl;



	// [���� 2]	v1�� ����� ���ҵ��� Ȧ���� ¦���� �и��� �� ���� �� ������ ����϶�.	
	// ����� Ȧ���� ������ ¦���� ������ ������� ���.							(15, 5)

	auto p = partition(v1.begin(), v1.end(), [](int n) {return n % 2; });

	int d = distance(v1.begin(), p);
	cout << "Ȧ�� : " << d << endl;
	d = distance(p, v1.end());
	cout << "¦�� : " << d << endl;


	// [���� 3] v1�� v2�� ���� ���Ҹ� ã�� v3�� �����϶�.		
	// v3�� ����� ���Ұ����� ����ϰ� �������� �����.								(25, 5)
	// (����) ���� ���Ҵ� set_intersection���� ã�� �� �ִ�.
	// ���� ���� ���� ���Ұ� ���� �� ���� ���� set_intersection�� ó������� ������.

	vector<int> v3;		// v1�� v2�� ���� ���Ҹ� ���⿡ �����Ѵ�.

	ranges::sort(v1);
	ranges::sort(v2);

	set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), back_inserter(v3));

	cout << "v3 size : " << v3.size() << endl;

	//v3.erase(unique(v3.begin(), v3.end()), v3.end());

	//cout << "v3 size : " << v3.size() << endl;


	// [���� 4] v3�� ����� int�� ȭ�鿡 ����ϸ� ���� ���´�.
	// int ���� [0,9] ���ڷ� ǥ���ȴ�.
	// v3�� ����� ��� int�� ���ڷ� ��Ÿ���� �� ������ ������ ȭ�鿡 ����϶�.
	// '9'�� ������ �������� ���.													(35, 5)
	// (����) to_string()���� int�� string���� ��ȯ�� �� �ִ�.	
	// (��) 1231511   31233122 
	// �� �� int���� 
	// [1] - 6
	// [2] - 4
	// [3] - 4
	// [4] - 0
	// [5] - 1
	// ���� ����

	map<char, int> m;

	for (const auto& v : v3)
	{
		string s = to_string(v);

		for (const auto& t : s)
		{
			int n = t - '0';
			++m[n];
		}
	}

	for (int i{}; i < 10; ++i)
		cout << "[" << i << "] - " << m[i] << endl;

}