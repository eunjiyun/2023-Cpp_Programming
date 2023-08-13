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
	int id;								// �Ϸù�ȣ
	string word;						// �ܾ�

public:
	Test() = default;

	int getId() const {
		return id;
	}

	string getWord() const {
		return word;
	}

	void show() const {
		cout << format("id:{:>5d} �ܾ�: {}", id, word) << endl;
		// cout << "id:" << id << " �ܾ�:" << word << endl;
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
	//	buf[len] = '\0';    // null ���� �߰�
	//	word = string(buf);
	//}
};


// �� ������ �𸣴� Test ��ü�� "�����ڷ�.txt" ���Ͽ� text ���� ��ϵǾ� �ִ�.
// Test ��ü�� write() ����Լ��� �ڽ��� ����Ѵ�.

//---------
int main()
//---------
{
	ifstream in{ "�����ڷ�.txt" };

	// [���� 1] Test ��ü�� ��� �о� �����̳ʿ� �����϶�.
	// ��� �� ��ü�� �ִ��� ����ϰ� ������ ��µ� ������ �����.	          
	// Test ��ü�� �б� ���� �ʿ��� ����Լ��� �߰��� �� �ִ�.
	// ������ ���� �ڵ带 ��� �����.

	string fileName{ "�����ڷ�.txt" };
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



	// [���� 2] �����̳��� Test ��ü �� word�� ���̰� ���� �� ��ü�� ȭ�鿡 ����϶�.		
	// ��µ� ����� �������� �����.								
	// ����� ����Լ� show()�� ����϶�.
	Test longest;

	for (const auto t : v)
	{
		if (t.getWord().size() > longest.getWord().size())
			longest = t;
	}
	longest.show();




	// [���� 3] �����̳ʸ� Test ��ü id ���� ������������ �����϶�.
	// ���� ������ ��ü�� show()�� ����ϰ� �������� �����.		

	// id�� �������� ����
	sort(v.begin(), v.end(), [](const Test& a, const Test& b) {
		return a.getId() < b.getId();
		});

	for (const auto& vec : v)
		cout << "id: " << vec.getId() << endl;




	// [���� 4] �ܾ �Է¹޾� ���� �ܾ �ִ� Test ��ü�� �˻��ϴ� �ڵ带 �ۼ��϶�.
	// word�� ���� ��ü�� �� ������ ���� ����ϰ�,					
	// ã�� ��ü�� �ִٸ� ��� ȭ�鿡 ����ϵ��� �϶�.				
	// (����) �� �ڵ�� ��� ����Ǿ�� �Ѵ�.				
	// (����ȭ���� ȭ�� ����� �����϶�)


	cout << "�ܾ �˻��մϴ�" << endl;
	while (true) {
		string word;
		cout << "ã������ �ܾ �Է��ϼ���: ";
		cin >> word;


		// ���� �� �ڵ带 �ۼ��ϸ� �ȴ�.
		vector<Test> temp;


		//int count = count_if(v.begin(), v.end(), [word](const Test& t) {return t.getWord() == word; });
		//auto it = count_if(v.begin(), v.end(), []() {})
		auto find = copy_if(v.begin(), v.end(), back_inserter(temp), [word](Test& t) {return t.getWord() == word; });
		cout << word << "�� ���� - " << temp.size() << endl;

		for (const auto& vec : temp)
		{
			cout << "id : " << vec.getId() << endl;
			cout << "word : " << vec.getWord() << endl;
		}
	}
}
