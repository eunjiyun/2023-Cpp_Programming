#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include<string>
#include<map>
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
	while (in1>>num)
		v1.push_back(num);
	while (in2 >> num)
		v2.push_back(num);

	cout << "v1 size : " << v1.size() << endl;//10220610
	cout << "v2 size : " << v2.size() << endl;//10220615

	//40882440
	cout << "v1 byte : " << v1.size() * sizeof(int) << endl;
	//40882460
	cout << "v2 byte : " << v2.size() * sizeof(int) << endl;


	// [���� 2]	v1�� ����� ���ҵ��� Ȧ���� ¦���� �и��� �� ���� �� ������ ����϶�.	
	// ����� Ȧ���� ������ ¦���� ������ ������� ���.							(15, 5)

	vector<int> fir, sec;

	partition_copy(v1.begin(), v1.end(), back_inserter(fir), back_inserter(sec), [](int& n) {return n % 2; });

	cout << "Ȧ�� : " << fir.size() << endl;//5111014
	cout << "¦�� : " << sec.size() << endl;//5109596


	// [���� 3] v1�� v2�� ���� ���Ҹ� ã�� v3�� �����϶�.		
	// v3�� ����� ���Ұ����� ����ϰ� �������� �����.								(25, 5)
	// (����) ���� ���Ҵ� set_intersection���� ã�� �� �ִ�.
	// ���� ���� ���� ���Ұ� ���� �� ���� ���� set_intersection�� ó������� ������.

	vector<int> v3;		// v1�� v2�� ���� ���Ҹ� ���⿡ �����Ѵ�.

	ranges::sort(v1);
	ranges::sort(v2);

	set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(),back_inserter(v3));

	cout << "v3 size : " << v3.size() << endl;

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

	////[0] - 91447
	////[1] - 104838
	////[2] - 104970
	////[3] - 104585
	////[4] - 104362
	////[5] - 104030
	////[6] - 104415
	////[7] - 105005
	////[8] - 104767
	////[9] - 104520

	map<char, int> m;

	for (const auto t : v3)
	{
		auto i = to_string(t);
		
		for (const auto t2 : i)
			++m[t2];
	}

	for (const auto t : m)
		cout << "[" << t.first << "] - " << t.second << endl;
}