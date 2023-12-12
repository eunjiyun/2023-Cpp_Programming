#include <iostream>
#include <fstream>
#include <format>
#include <filesystem>
#include <string>
#include <algorithm>
using namespace std;


//------------ �� �� ------------
// namespace std�� ����Ͽ���.
// include ������ ������ ���� �ʿ����.
// ������� �ʴ� �ڵ带 ������ �����Ѵ�
// ���� �´��� ȿ�� ���� �ڵ峪 �˰����� ������� ���� �ڵ�� �����Ѵ�.
// ���α׷� ȯ�� - Release/x64, ������Ʈ �Ӽ� - �̸� ���� - �ֽ� C++ �ʾ��� ���(/std:c++latest)

// e-class���� ����.zip�� �ٿ� ���� �� �����Ѵ�.

// �� ������ �ذ��ϴµ� �ʿ��� �ڵ�( ����Լ� ���� )�� ������ ���´�.
// ȭ�� ����� ������� ������ ��µ� ������ ������ ���´�.


//----------------------------------------------------------------------------
// class Test
//----------------------------------------------------------------------------
class Test {
	size_t id{};						// ���� ����
	string word{};						// ������, ������ ������ �ִ� 15����

public:
	Test() = default;

	// num�� p�� ����� int ���� ȭ�鿡 ǥ���Ѵ�
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
	// "TEST ��ü" ����(���̳ʸ� ���)�� Test ��ü�� write() ����Լ��� ����Ͽ���.  
	// ���Ͽ��� �� ������ �𸣴� Test ��ü�� ����Ǿ� �ִ�.

	string fileName{ "Test ��ü"s };

	ifstream in{ fileName, ios::binary };
	if (!in) {
		cout << fileName << " ������ �� �� �����ϴ�" << endl;
		exit(0);
	}

	size_t fileSize = filesystem::file_size(fileName);
	cout << "���� \"" << fileName << "\"�� ũ�� - " << fileSize << " ����Ʈ" << endl;





	// [���� 1] ��µ� ���� ũ�⸦ ���� ����� ��ü�� ���� �� �� �ִ����� 
	// "��/�ƴϿ�"�� ���ϰ� �׷��� ���� ������ �����϶�.						(10)

	//�� ���̳ʸ� ��忡���� �˼� ����
	cout << "��ü�� �� : " << fileSize / sizeof(Test) << endl;
	cout << sizeof(Test) << endl;



	// [���� 2] ������ �о� ��ü�� �����̳ʿ� �����϶�.							
	// ���� ��ü�� ������ ����ϰ�, ������ ��ü�� show()�� ȣ���϶�.
	// ȭ�鿡 ��µ� ������ �������� �����.									(30)(��������ڵ�:20, ����ڵ�� ���: 10) 

	// (Ȯ��) ó���� ���� �� ü�� show()�� ȣ���� ����� ������ ����.
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

	cout << "��ü�� ���� : " << v.size() << endl;
	v.back().show();

	/*for (const auto& vec : v)
	{
		vec.show();
	}*/


	// [���� 3] �Լ� deleteZ()�� [���� 2]���� ����� �����̳ʸ� ���ڷ� �޾�
	// �����̳ʿ� ����� Test ��ü�� word�� ���� �� �ҹ��� 'z'�� �����ϴ� �Լ��̴�.
	// �� �Լ��� �����ϰ� ������ �� ȣ���϶�.									(35)(����:5, �Լ����ǿ� ���� �ڵ�:30)

	// (����) string�� begin()�� end()�� �����ϸ� ���ڴ� contiguous memory�� ����ȴ�

	// (����) �����̳� �̸��� x��� deleteZ(x); �� ���� ȣ���Ѵ�.

	// (Ȯ��) 'z'�� ������ �� ó���� ���� ��ü�� show()�� ȣ���� ����� ������ ����.
	// id:  511803   word : vrkmetlqhublq
	// id :  18649   word : ohjdt

	deleteZ(v);
	v[0].show();
	v[1].show();
	

	// [���� 4] �����̳ʿ� ������ Test ��ü�� word ������������ �����ϰ�  
	// ���� ������ ��ü�� show()�� ȣ���϶�.
	// ȭ�鿡 ��µ� ����� ������ �����.										(20)(�ڵ�:15, ���:5)
	
	sort(v.begin(), v.end(), [](Test& lhs, Test& rhs) {
		return lhs.getWord() < rhs.getWord();
		});
	v.back().show();

	/*for (const auto& vec : v)
		vec.show();*/



	// [���� 5] �����̳ʿ� ����� Test ��ü �� id ���� ���� ��ü�� �ϳ� �� ����� �� �����϶�.
	// ���� �� �����̳ʿ� ���� Test ��ü�� ���� ����ϰ� ����� ������ �����.	(25)(���� �ڵ�:20, ���:5)

	deleteSameId(v);
	cout << "���� ��ü�� ��: " << v.size() << endl;

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