#include<iostream>
#include<random>
#include<fstream>
#include<array>
#include <iterator>
using namespace std;

class NUM
{
	int val;

public:
	NUM(int n) :val(n) { }

	bool operator!=(const NUM& other)
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


//�ݺ��� ������ ���ڷ� �޾� ���� ����ϴ� �Լ��̴�.
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
	//���ڵ� ���Ͽ��� �� ������ �𸣴� ���ĺ� �ҹ��ڿ� ���� ���ڰ� ��ϵǾ� �ִ�.

	ifstream in{ "���ڵ�.txt" };

	vector<char> v;

	//1. ���ڵ�.txt�� ����� ���� �߿��� �ҹ��ڸ��� ��� �о� ���� v�� �����϶�.
	//v�� ����� ������ ���� ȭ�鿡 ����ϰ� �������� �����.
	//(����) v�� �̹� �����Ǿ��ִ�.

	char c;
	while (in>>c)
	{
		if (islower(c))
			v.push_back(c);
	}

	cout << "v size : " << v.size() << endl;
	cout << "v ũ�� : " << v.size() * sizeof(char) << endl;


	//2. ���� v�� ����Ǿ� �ִ� ���ڵ鿡�� ���� 's' 't' 'l'�� ���ӵ� ���� ��� �� ���ΰ� ����ϰ� �������� �����.

	int num{};
	for (int i{}; i < v.size(); ++i)
	{
		if ('s' == v[i] && 't' == v[i + 1] && 'l' == v[i + 2])
		{
			++num;
			i += 3;
		}
	}

	cout << "stl�� �� " << num << "��" << endl;

	
	//3. 
	sort(v.begin(), v.end());//v�� ������������ �����Ͽ���.
	array<int, 26> a;
	//������������ ���ĵ� ���� v���� �� ���ĺ��� ������ array<int, 26> a�� �����϶�.
	//a[0]���� 'a', a[1]���� 'b' ... , a[25]���� 'z'�� ������ ����ǵ��� �϶�.
	//�� ���ĺ��� ������ ȭ�鿡 ����ϰ� 'C'�� ������ ��������� �����.
	//(����) O(n) �˰����� ����ϸ� ������. ���ĵǾ� �ִٴ� ���� Ȱ���� ��
	//=>for���� ���x=>O(n)


	// ���ĺ� 'b'���� 'z'���� ���۵Ǵ� �ε��� ��ȣ�� ã�´�.
	int n[26];
	n[0] = 0;

	for (char c = 'b'; c <= 'z'; ++c)
	{
		auto it=lower_bound(v.begin(), v.end(), c);

		if (it != v.end() && c == *it)
			n[c - 'a'] = distance(v.begin(), it);
	}

	for (int i{}; i < 26; ++i)
	{
		if (25 != i)
			a[i] = n[i + 1] - n[i];
		else
			a[25] = v.size() - n[25];

		cout << "[" << char(i + 'a') << "] - " << a[i] << endl;
	}


	shuffle(v.begin(), v.end(), dre);      // ���ĵ� ���͸� ���´�

	print(v.begin(), v.begin() + 10, " - ");        // 10���� ����� ����
	cout << endl;

	// print ���� ��� (����)
	// a - p - t - v - e - k - k - v - k - i -

	// [���� 4] ���� ������ �����ϸ� ȭ�鿡 [1, 11)���� ���ڰ� ��µǵ��� �ʿ��� �ڵ��� �϶�.   (40)
	// (����) main() ���� �ڵ带 �������� �ʰ� �ذ��Ͽ��� �Ѵ�.  

	print(NUM(1), NUM(11), " ");        // ��� 1 2 3 4 5 6 7 8 9 10  
}