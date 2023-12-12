#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include <filesystem>
using namespace std;

class Person
{
public:
	string name;
	int id;

public:
	void write(ostream& os)
	{
		os.write((char*)this, sizeof(Person));
	}
};



int main()
{
	string fileName{ "�߰�����.dat"s };

	ifstream in{ fileName,ios::binary };
	if (!in)
	{
		cout << fileName << "������ �� �� �����ϴ�" << endl;
		exit(0);
	}


	//1
	struct stat s;
	size_t fileSize;

	if (0 == stat(fileName.c_str(), &s))
		fileSize = s.st_size;

	cout << fileName << "�� ũ�� - " << fileSize << " ����Ʈ" << endl;


	//2
	Person p;
	vector<Person> v;

	while (in.read(reinterpret_cast<char*>(&p), sizeof(p)))
	{
		v.push_back(p);
	}
	in.close();

	// ���Ͽ��� ���� �����͸� ����غ���
	for (const auto& data : v) {
		std::cout << "ID: " << data.id << ", Name: " << data.name << '\n';
	}


	//3
	auto it = find_if(v.begin(), v.end(), [](const Person& p) {return p.name == "standardlibrary"; });
	if (it != v.end())
	{
		cout << "found at index : " << distance(v.begin(), it) << endl;
		cout << "id : " << v[distance(v.begin(), it)].id << endl;
		cout << "name : " << v[distance(v.begin(), it)].name << endl;
	}
	else
		cout << "not found" << endl;


	//4
	for (;;)
	{
		int inputId;
		vector<Person> temp;

		cout << "id �Է� : ";
		cin >> inputId;

		auto findP = copy_if(v.begin(), v.end(), back_inserter(temp), [inputId](const Person& per) {return per.id == inputId; });

		cout << "size : " << temp.size() << endl;
		for (const auto& t : temp)
		{
			cout << "id : " << t.id << endl;
			cout << "name : " << t.name << endl;
		}
	}
}