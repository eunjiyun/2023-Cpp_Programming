#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

// [���α׷� ȯ��] Release, x64, ������Ʈ �Ӽ� C++ ���: �̸� ���� - �ֽ� C++ �ʾ��� ���(/std:c++latest)

//---------
int main()
//---------
{
    ifstream in{ "�̻��� ������ �ٸ���.txt" };

    vector<string> v;

    // [���� 1] ���� "�̻��� ������ �ٸ���.txt"�� �ִ� ��� �ܾ �о� �����̳� v�� �����϶�.
    // ��� �� ���� �ܾ �о����� ȭ�鿡 ����ϰ� ��°���� �������� �����.   (15, 5)                             
    // (����) v�� �̹� �����Ǿ��ִ�.

    string s;
    while (in >> s)
        v.push_back(s);

    cout << "v size : " << v.size() << endl;
    cout << "v ũ�� : " << v.size() * sizeof(string) << endl;


    // [���� 2]  v���� "rabbit" �̶�� �ܾ�� ��� �� ���ΰ�? 
    // �� ������ ȭ�鿡 ����ϰ� ������ ��µ� ������ �����.                    (20, 5)
    // (����) rabbit�� ��ҹ��ڸ� �������� �ʴ´� 
    // (��) rabbit Rabbit RABBIT Rabbit-Hole - ���⿡�� rabbit�� 3���̴�.

    int n{};

    for (const auto& t : v)
    {
        string temp = t;

        transform(temp.begin(), temp.end(), temp.begin(), ::tolower);

        if (temp =="rabbit")
            ++n;
    }

    cout << "rabbit ���� : " << n << endl;


    // ������ ���� v�� �ܾ�������� �������.

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    cout << "�������� ���� v�� �ܾ� �� - " << v.size() << endl;
    // (���) �������� ���� v�� �ܾ� �� - 5295


    // [���� 3] ������ �ܾ��� ���� ���� ������������ �����϶�.
    // ������ ù �ܾ�� ������ �ܾ ȭ�鿡 ����ϰ� ��������� �����. 	(15, 5)				
    // (����) ���̰� ���� �ܾ�� ������ ������������ ���ĵǾ�� �Ѵ�.
    // (����) ������ ������ �ذ��� �� 2001��° ���� 10�� �ܾ ����� ���̴�.
    // '--you 'After 'Begin 'Boots 'Bring 'Can't 'Come, 'DRINK 'Dear, 'Don't

    stable_sort(v.begin(), v.end(), [](const string& fir, const string& sec) {return fir.length() < sec.length(); });

    cout << "ù �ܾ� : " << v.front() << endl;
    cout << "�� �ܾ� : " << v.back() << endl;

    for (int i=2000; i < 2010; ++i)
        cout << v[i] << endl;


    // "�ܾ��.txt"�� words�� �����Ѵ�.
    ifstream in2{ "�ܾ��.txt" };
    vector<string> words{ istream_iterator<string>{in2}, {} };
    cout << "�ܾ��.txt - " << words.size() << endl;
    // (���) �ܾ��.txt - 369882

    vector<string> v2;              // v�� �ܾ "�ܾ��.txt"�� �ִ� �ܾ��� ���⿡ �����Ѵ�.

    // [���� 4] v�� �ִ� �ܾ� �߿��� "�ܾ��.txt"�� �ִ� �ܾ ã�� v2�� �����϶�.              
    // v2�� ��� �� �ܾ �ִ��� ����ϰ� �������� ���.  (20, 5)

    for (const auto& t : words)
    {
        if (find(v.begin(), v.end(), t) != v.end())
            v2.push_back(t);
    }
    cout << "v2 size : " << v2.size() << endl;


    // [���� 5] ������ ǥ�� �˰����Լ� copy�� ȣ���ϸ� v2�� ��� �ܾ �������� �ٲ��.
    // �ʿ��� �ڵ��� �߰��϶�.                                                (40)
    // (��) v2�� �ܾ ������ ���ٰ� ����.    Alice was beginning to 
    // copy ȣ�� �Ŀ��� ������ ���� �ٲ��.    ecilA saw gninnigeb ot

    //copy(v2.begin(), v2.end(), REV(v2.begin()));
}
