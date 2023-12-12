#include <iostream>
#include <random>
#include <fstream>
#include <array>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

// ch�� num�� ȭ�鿡 ����ϴ� character monster
class CharMon {
	char ch;							// ['a','z] ���� �� �� ����
	int num;							// [1, 1000] ���� �� ����

public:
	CharMon() = default;

	// ȭ�鿡 ch�� num�� ���
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
	ifstream in{ "CharMon ����.txt", ios::binary };

	// ���蹮������ CharMon ��ü�� ���� ������� �ʴ´�.
	// ������ �ڵ尡 �� ����





	// [���� 1] ���� �������� CharMon.txt�� ũ�⸦ Ȯ���϶�. 
	// ���� ũ�⸦ ���� ����� ��ü�� ���� �� �� �ִ��� "��/�ƴϿ�"�� ���ϰ� 
	// �׷��� ���� ������ �����϶�.	
	string fileName{ "CharMon ����.txt" };
	struct stat s;
	size_t fileSize;

	if (0 == stat(fileName.c_str(), &s))
		fileSize = s.st_size;

	cout << "file size : " << fileSize / 1024 << "kb" << endl;



	// [���� 2] ������ �о� ����� ��� CharMon ��ü�� �����̳ʿ� �����϶�.	
	// ���� ������ ��ü�� attack()�� ȣ���϶�.	
	// ��°���� ���� ������ ��ü�� ch�� num�� ������ �����. (��: a - 333��)  

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
	cout << "���� : " << v.size() << endl;

	v[v.size() - 1].attack();




	// [���� 3] �����Լ� Upper�� [���� 2]���� ����� �����̳ʸ� ���ڷ� �޴´�.
	// Upper�� �����̳ʿ� ����� CharMon�� ���ڸ� �빮�ڷ� �ٲ۴�.
	// Upper�� �����ϰ� �����϶�.										
	// (����) ����� ���Ǹ� �����Ͽ� ���� ��.		

	Upper(&v);
	//for (const auto& temp : v)
	//{
	//	cout << "ch : " << temp.getCh() << endl;
	//	cout << "num : " << temp.getNum() << endl;
	//}





	// [���� 4] �����̳ʿ� ����� CharMon���� � ���ڸ� ���� �ִ���  
	// ������ ���� �������� ����϶�.
	// 
	// ch�� [A]�� ������ �� - 2022
	// ch�� [B]�� ������ �� - 4
	// 
	//  �߰� ����
	// 
	// ch�� [Z]�� ������ �� - 20
	//  
	// ���� �ڵ带 ������ ���� ch�� [C]�� ������ ���� �������� �����. 

	//char inputCh;
	//vector<CharMon> temp;

	/*cout << "�Է� : ";
	cin >> inputCh;*/


	int num = 0;
	for (char ch = 'A'; ch <= 'Z'; ++ch)
	{
		int count = count_if(v.begin(), v.end(), [ch](const CharMon& c) {return c.getCh() == ch; });
		cout << ch << " ���� : " << count << endl;
		num += count;
	}
	cout << "�� ���� : " << num << endl;
	cout << "v ������ : " << v.size() << endl;


	/*for (const auto& t : temp)
	{
		cout << "ch : " << t.getCh() << endl;
		cout << "num : " << t.getNum() << endl;
	}*/


	// [���� 5] num�� 777�� CharMon ��ü�� ���� ȭ�鿡 ����϶�.		
	// ��µ� ��ü�� ���� �������� �����.							

	/*int inputNum;
	cout << "num �Է� : ";
	cin >> inputNum;*/
	vector<CharMon> temp;

	auto find = copy_if(v.begin(), v.end(), back_inserter(temp), [](CharMon& c) {return c.getNum() == 777; });

	/*for (const auto& t : temp)
	{
		cout << "num : " << t.getNum() << endl;
		cout << "ch : " << t.getCh() << endl;
	}*/
	cout << "777 ���� : " << temp.size() << endl;



	// [���� 6] ������ �ذ��ϱ� ���� ����� �����̳ʸ� ������ ������ �����϶�. (10)
}

void Upper(vector<CharMon>* vec)
{
	transform(vec->begin(), vec->end(), vec->begin(), [](CharMon& c) {c.setCh(toupper(c.getCh())); return c; });
}



