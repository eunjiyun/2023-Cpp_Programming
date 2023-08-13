//------------ �� �� ------------
// namespace std�� ����Ͽ���.
// include ������ ������ ���� �ʿ����.
// ������� �ʴ� �ڵ带 ������ �����Ѵ�
// ���� �´��� ȿ�� ���� �ڵ峪 �˰����� ������� ���� �ڵ�� �����Ѵ�.
// ���α׷� ȯ�� - Release/x64, ������Ʈ �Ӽ� - �̸� ���� - �ֽ� C++ �ʾ��� ���(/std:c++latest)

// e-class���� ����.zip�� �ٿ� ���� �� �����Ѵ�.

// �� ������ �ذ��ϴµ� �ʿ��� �ڵ�( ����Լ� ���� )�� ������ ���´�.
// ȭ�� ����� ������� ������ ��µ� ������ ������ ���´�.

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>
#include <format>
#include <iomanip>
using namespace std;

//template<typename Iterator>
//class REVERSE {
//private:
//    Iterator current;
//public:
//    explicit REVERSE(Iterator iter) : current(iter) {}
//
//    auto operator*() const {
//        Iterator temp = current;
//        return *--temp;
//    }
//
//    REVERSE& operator++() {
//        --current;
//        return *this;
//    }
//
//    bool operator==(const REVERSE& other) const {
//        return current == other.current;
//    }
//
//    bool operator!=(const REVERSE& other) const {
//        return current != other.current;
//    }
//};
//
//template<typename Iterator>
//void copy(const REVERSE<Iterator>& rev, Iterator output) {
//    std::copy(rev.current, Iterator(), output);
//}

template<typename Iterator>
class REVERSE {
private:
    Iterator current;
public:
    explicit REVERSE(Iterator iter) : current(iter) {}

    auto operator*() const {
        Iterator temp = current;
        return *--temp;
    }

    REVERSE& operator++() {
        --current;
        return *this;
    }

    bool operator==(const REVERSE& other) const {
        return current == other.current;
    }

    bool operator!=(const REVERSE& other) const {
        return current != other.current;
    }
};

template<typename Iterator>
void copy(const REVERSE<Iterator>& rev, Iterator output) {
    std::copy(rev.current, Iterator(), output);
}


//---------
int main()
//---------
{
    ifstream in{ "�⸻�ܾ�.txt" };
    if (not in)
        return 0;

    vector<string> v;

    // [���� 1] ���� "�⸻�ܾ�.txt"�� �ִ� ��� �ܾ �о� �����̳� v�� �����϶�.
    // ��� �� ���� �ܾ �о����� ȭ�鿡 ����ϰ� ��°���� �������� �����.   (�ڵ�:15, ���:5)                             
    // (����) ������ �ؽ�Ʈ ���� ��ϵǾ����� �ؽ�Ʈ ������� ���� �� �ִ�.
    // (����) v�� �̹� �����Ǿ��ִ�.

    string s;
    while (in >> s)
        v.push_back(s);

    cout << "v size : " << v.size() << endl;

    // [���� 2] v�� ����� �ܾ��� ��� ���̸� �Ҽ��� ��°�ڸ����� ����ϰ� �������� �����. (�ڵ�:15, ��°�:5)
    // (����) {:2.2f}

    float sum{};
    float aver{};

    for (const auto& t : v)
        sum += t.length();

    aver = sum / v.size();

    cout << "��� ���� : " << aver << endl;
    cout << "��� ����: " << fixed << setprecision(2) << aver << endl;


    // [���� 3]  v�� ����� �ܾ� �߿��� "stl"�̶�� ���ӵ� ���ڰ� �� �ܾ ã�ƶ�. 
    // "stl"�� �� �ܾ� ��ο� �ܾ��� ������ ȭ�鿡 ����ϰ� ������ ��µ� ������ �����.   (�ڵ�:20, ����:5)
    // (��) jnziastlizef - �� �ܾ�� stl�� ����ִ�.

    int count{};
    for (const auto& word : v) {
        if (word.find("stl") != std::string::npos) {
            std::cout << word << " - �� �ܾ�� stl�� ����ִ�." << std::endl;
            ++count;
        }
    }

    std::cout << "stl�� �� �ܾ��� ����: " << count << std::endl;


    // [���� 4] v�� �������� ���� �� ������ �ܾ� ���� ����ϰ� �������� �����. (�ڵ�:10, �ܾ��:5)
    // (����) ������ ������������ ���ĵǾ� ������ �ߺ��� �ܾ ����.

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    stable_sort(v.begin(), v.end(), [](const string& fir, const string& sec) {return fir.length() < sec.length(); });

    cout << "���� ������ �ܾ� �� : " << v.size() << endl;

  /*  cout << endl << endl;

    for (int i=100; i < 1000; ++i)
        cout << v[i] << endl;*/

    // ���� �ڵ�� "�ܾ��.txt"�� �о� words�� �����Ѵ�.
    // (����) words�� �������� ���ĵǾ� ������ �ߺ��� �ܾ ����.

    ifstream in2{ "�ܾ��.txt" };
    if (not in2)
        return 0;

    vector<string> words{ istream_iterator<string>{in2}, {} };
    cout << "�ܾ��.txt - " << words.size() << endl;

    // (���) �ܾ��.txt - 369882


    vector<string> v2;              // v�� �ܾ "�ܾ��.txt"�� �ִ� �ܾ��� ���⿡ �����Ѵ�.


    // [���� 5] v�� �ִ� �ܾ� �߿��� "�ܾ��.txt"�� �ִ� �ܾ ã�� v2�� �����϶�.              
    // v2�� ��� �� �ܾ �ִ��� ����ϰ� �������� ���.                      (�ڵ�:15, ����:5)
    // (����) ���� �ܾ�� set_intersection���� ã�� �� �ִ�.

    ranges::sort(v);
    ranges::sort(words);

    set_intersection(v.begin(), v.end(), words.begin(), words.end(), back_inserter(v2));

    cout << "v2 ������ ���� : " << v2.size() << endl;


    // [���� 6] ������ ���� ǥ�� �˰����Լ� copy�� ȣ���ϸ� v�� ��� �ܾ �������� �ٲ��.
    // �ʿ��� �ڵ��� �߰��϶�.                                                (�����ڵ�:40)
    // (��) ������ v�� �ܾ� 4���� �������� �ٲ� ���̴� 
    // v�� ó�� 4 �ܾ�  - a aaat aacdkuopsavjiornyb aadksxwzjdfkovafbdyckguegepyx
    // �������� �ٲ� �� - a taaa bynroijvaspoukdcaa xypegeugkcydbfavokfdjzwxskdaa

    // ���� �ּ����� �����ϰ� ������ ��
     ///std::copy( v.begin( ), v.end( ), REVERSE( v.begin( ) ) );

    ////copy(v2.begin(), v2.end(), REV(v2.begin()));//������
    //REVERSE<decltype(v.begin())> revIter(v.end());
    //std::copy(v.begin(), v.end(), revIter);

   

    //// v2 ������ ���� Ȯ��
    //for (const std::string& word : v) {
    //    std::cout << word << " ";
    //}
    //std::cout << std::endl;

    for (auto& word : v) {
        std::reverse(word.begin(), word.end());
    }

    std::cout << "// �� �ܾ �������� �ٲ� �� - ";
    for (const auto& word : v) {
        std::cout << word << " ";
    }
    std::cout << std::endl;
}
