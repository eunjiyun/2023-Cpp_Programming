//------------ 주 의 ------------
// namespace std를 사용하였다.
// include 문장을 답지에 적을 필요없다.
// 실행되지 않는 코드를 적으면 감점한다
// 답이 맞더라도 효율 낮은 코드나 알고리즘을 사용하지 않은 코드는 감점한다.
// 프로그램 환경 - Release/x64, 프로젝트 속성 - 미리 보기 - 최신 C++ 초안의 기능(/std:c++latest)

// e-class에서 시험.zip을 다운 받은 후 시작한다.

// 각 문제를 해결하는데 필요한 코드( 멤버함수 포함 )를 답지에 적는다.
// 화면 출력을 적으라는 문제는 출력된 내용을 답지에 적는다.

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
    ifstream in{ "기말단어.txt" };
    if (not in)
        return 0;

    vector<string> v;

    // [문제 1] 파일 "기말단어.txt"에 있는 모든 단어를 읽어 컨테이너 v에 저장하라.
    // 모두 몇 개의 단어를 읽었는지 화면에 출력하고 출력결과를 답지에도 적어라.   (코드:15, 결과:5)                             
    // (참고) 파일은 텍스트 모드로 기록되었으며 텍스트 편집기로 읽을 수 있다.
    // (주의) v는 이미 생성되어있다.

    string s;
    while (in >> s)
        v.push_back(s);

    cout << "v size : " << v.size() << endl;

    // [문제 2] v에 저장된 단어의 평균 길이를 소수점 둘째자리까지 출력하고 답지에도 적어라. (코드:15, 출력값:5)
    // (참고) {:2.2f}

    float sum{};
    float aver{};

    for (const auto& t : v)
        sum += t.length();

    aver = sum / v.size();

    cout << "평균 길이 : " << aver << endl;
    cout << "평균 길이: " << fixed << setprecision(2) << aver << endl;


    // [문제 3]  v에 저장된 단어 중에서 "stl"이라는 연속된 문자가 들어간 단어를 찾아라. 
    // "stl"이 들어간 단어 모두와 단어의 개수를 화면에 출력하고 답지에 출력된 개수도 적어라.   (코드:20, 개수:5)
    // (예) jnziastlizef - 이 단어에는 stl이 들어있다.

    int count{};
    for (const auto& word : v) {
        if (word.find("stl") != std::string::npos) {
            std::cout << word << " - 이 단어에는 stl이 들어있다." << std::endl;
            ++count;
        }
    }

    std::cout << "stl이 들어간 단어의 개수: " << count << std::endl;


    // [문제 4] v를 사전으로 만든 후 사전의 단어 수를 출력하고 답지에도 적어라. (코드:10, 단어개수:5)
    // (주의) 사전은 오름차순으로 정렬되어 있으며 중복된 단어가 없다.

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    stable_sort(v.begin(), v.end(), [](const string& fir, const string& sec) {return fir.length() < sec.length(); });

    cout << "만든 사전의 단어 수 : " << v.size() << endl;

  /*  cout << endl << endl;

    for (int i=100; i < 1000; ++i)
        cout << v[i] << endl;*/

    // 다음 코드는 "단어들.txt"를 읽어 words에 저장한다.
    // (참고) words는 오름차순 정렬되어 있으며 중복된 단어가 없다.

    ifstream in2{ "단어들.txt" };
    if (not in2)
        return 0;

    vector<string> words{ istream_iterator<string>{in2}, {} };
    cout << "단어들.txt - " << words.size() << endl;

    // (출력) 단어들.txt - 369882


    vector<string> v2;              // v의 단어가 "단어들.txt"에 있는 단어라면 여기에 저장한다.


    // [문제 5] v에 있는 단어 중에서 "단어들.txt"에 있는 단어를 찾아 v2에 저장하라.              
    // v2에 모두 몇 단어가 있는지 출력하고 답지에도 써라.                      (코드:15, 개수:5)
    // (참고) 공통 단어는 set_intersection으로 찾을 수 있다.

    ranges::sort(v);
    ranges::sort(words);

    set_intersection(v.begin(), v.end(), words.begin(), words.end(), back_inserter(v2));

    cout << "v2 원소의 개수 : " << v2.size() << endl;


    // [문제 6] 다음과 같이 표준 알고리즘함수 copy를 호출하면 v의 모든 단어가 역순으로 바뀐다.
    // 필요한 코딩을 추가하라.                                                (관련코드:40)
    // (예) 다음은 v의 단어 4개를 역순으로 바꾼 것이다 
    // v의 처음 4 단어  - a aaat aacdkuopsavjiornyb aadksxwzjdfkovafbdyckguegepyx
    // 역순으로 바꾼 후 - a taaa bynroijvaspoukdcaa xypegeugkcydbfavokfdjzwxskdaa

    // 다음 주석문을 제거하고 실행할 것
     ///std::copy( v.begin( ), v.end( ), REVERSE( v.begin( ) ) );

    ////copy(v2.begin(), v2.end(), REV(v2.begin()));//리버스
    //REVERSE<decltype(v.begin())> revIter(v.end());
    //std::copy(v.begin(), v.end(), revIter);

   

    //// v2 벡터의 내용 확인
    //for (const std::string& word : v) {
    //    std::cout << word << " ";
    //}
    //std::cout << std::endl;

    for (auto& word : v) {
        std::reverse(word.begin(), word.end());
    }

    std::cout << "// 각 단어를 역순으로 바꾼 후 - ";
    for (const auto& word : v) {
        std::cout << word << " ";
    }
    std::cout << std::endl;
}
