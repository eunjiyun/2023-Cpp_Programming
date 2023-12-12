#include <iostream>
#include <fstream>
#include <format>
#include <algorithm>
#include <numeric>
#include <vector>


using namespace std;
#define SIZE 2000000 

class Player {
	string name; // 이름, 길이[3, 15]
	int score; // 점수
	size_t id; // 아이디, 겹치는 아이디 있을 수 있음
	size_t num; // free store에 확보한 바이트 수
	char* p; // free store에 확보한 메모리의 시작번지

public:
	void write(ostream& os);
	bool read(istream& is);

	friend ostream& operator<<(ostream& os, const Player& p) {
		os << format("이름:{:<15} , 아이디:{:<8} , 점수:{:<10} , 자원수:{:<5} ", p.name, p.id, p.score, p.num) << endl;
		os << format("저장된글자:{:<10}", p.p) << endl;
		return os;
	}

	// char 오름차순으로 p를 정렬하는 함수
	void sortP() {
		vector<char> temp(p, p + num);
		sort(temp.begin(), temp.end());
		copy(temp.begin(), temp.end(), p);
	}

	// ID에 대한 비교 연산자 정의
	bool operator<(const Player& other) const {
		return id < other.id;
	}

	string getName() const {
		return name;
	}

	int getScore() const {
		return score;
	}

	size_t getId() const {
		return id;
	}

	size_t getNum() const {
		return num;
	}

	const char* getP() const {
		return p;
	}
};


bool compareByScore(const Player&, const Player&);
void recordSameIdPlayers(const vector<Player>&);

int main()
{

	//1. 파일을 읽어 제일 마지막 객체의 정보를 다음과 같은 형식으로 출력하라.
	//[보기] 이름:ftexe, 아이디 : 697265, 점수 : -38293887, 자원수 : 122
		//저장된글자 : idquvhfhdszwhjouiolrxgybqdmpbxpinvxnrpbtpffxxkfixlvqrbvu
		//khnlquvelenyftlrkuhmpmtyjdstzvyafwmrplojliyuufqonxugynhdmxqggqrwbk

	string pname{ "2023 STL 과제 파일" };
	ifstream in{ pname,ios::binary };

	vector<Player> players(SIZE);

	for (int i{}; i < SIZE; ++i) {

		if (!players[i].read(in)) break;

	}

	cout << players[players.size() - 1] << endl << endl;


	//2. 점수가 가장 큰 Player를 찾아 화면에 출력하라.
	//모든 Player의 평균 점수를 계산하여 화면에 출력하라.

	 // 점수에 따라 플레이어 정렬
	sort(players.begin(), players.end(), compareByScore);

	// 가장 큰 점수를 가진 플레이어 출력
	if (!players.empty()) {
		cout << players[0] << endl;
	}

	long double  sum{ 0 };

	sum = accumulate(players.begin(), players.end(), 0LL, [](long double  acc, const Player& p) {
		return p.getScore() + acc;
		});


	cout << fixed;
	cout.precision(5);
	cout << "평균 : " << sum / players.size() << endl << endl;


	//3. id가 서로 같은 객체를 찾아 "같은아이디.txt"에 기록하라.
	//id가 같은 객체는 모두 몇 개인지 화면에 출력하라.
		//- 파일에는 Player 마다 이름과 아이디만 한 줄에 기록한다.

	 // id가 같은 객체들을 파일에 기록하고 개수를 출력
	recordSameIdPlayers(players);


	//4. p에 읽어온 메모리를 char 오름차순으로 정렬하라.
	//'a'가 10글자 이상인 Player의 개수를 화면에 출력하라.

	 // 'p' 멤버를 char 오름차순으로 정렬
	for (int i{}; i < SIZE; ++i) {
		players[i].sortP();
	}

	// 'a'가 10글자 이상인 Player의 개수를 세기
	int count = 0;
	for (const auto& player : players) {
		string pString(player.getP());
		if (std::count(pString.begin(), pString.end(), 'a') >= 10) {
			count++;
		}
	}

	// 결과 출력
	cout << "a가 10글자 이상인 Player의 개수: " << count << endl << endl;


	//5. id를 입력받아 존재하는 id라면 다음 내용을 한 번에 화면 출력하라

	/*5-1. Player를 id 오름차순으로 정렬하였을 때
		해당 id 포함 앞과 뒤 Player의 정보를 출력한다.
		id가 같은 Player가 둘 이상이면 이들의 정보를 모두 출력하여야 한다.*/

		//5-2. Player를 name 오름차순으로 정렬하였을 때 해당 id 포함 앞과 뒤 Player의 정보를 출력한다.

		//5-3. Player를 score 오름차순으로 정렬하였을 때 해당 id 포함 앞과 뒤 Player의 정보를 출력한다.



	while (true) {
		int choose = 0;
		cout << "1. id 오름차순 정렬" << endl;
		cout << "2. name 오름차순 정렬" << endl;
		cout << "3. score 오름차순 정렬" << endl;
		cout << "choose : ";
		cin >> choose;

		size_t targetId;
		cout << "찾을 ID를 입력하세요: ";
		cin >> targetId;

		if (cin.fail()) {
			cout << "잘못된 입력입니다. 다시 시도하세요." << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			continue;
		}

		switch (choose) {
		case 1:
			// players 벡터를 id 오름차순으로 정렬
			sort(players.begin(), players.end());
			break;
		case 2:
			sort(players.begin(), players.end(), [](const Player& a, const Player& b) {
				return a.getName() < b.getName();
				});
			break;
		case 3:
			sort(players.begin(), players.end(), [](const Player& a, const Player& b) {
				return a.getScore() < b.getScore();
				});
		}


		// targetId를 찾기 위해 이진 탐색
		vector<Player> tp;
		bool check = false;
		size_t pre;
		size_t nex;
		vector<Player> preV;
		vector<Player> nexV;

		if (1 == choose) {
			for (auto it = players.begin(); it != players.end(); ++it) {
				if (it->getId() == targetId) {
					tp.push_back(*it);
					check = true;
				}
				else if (true == check)
					break;
			}
		}
		else {
			for (auto it = players.begin(); it != players.end(); ++it) {
				if (it->getId() == targetId) {
					tp.push_back(*it);
				}
			}
		}

		if (!tp.empty()) {

			for (int i{}; i < players.size(); ++i) {
				if (1 == choose) {
					if (tp[0].getId() == players[i].getId()) {
						pre = players[i - 1].getId();

						for (;;) {
							if (tp[0].getId() != players[++i].getId()) {
								nex = players[i].getId();
								break;
							}
						}
						break;
					}
				}
				else {
					if (tp[0].getId() == players[i].getId()) {
						preV.push_back(players[i - 1]);
						nexV.push_back(players[i + 1]);
					}
				}
			}


			if (1 == choose) {
				check = false;

				for (auto it = players.begin(); it != players.end(); ++it) {
					if (it->getId() == pre) {
						preV.push_back(*it);
						check = true;
					}
					else if (true == check)
						break;
				}


				check = false;

				for (auto it = players.begin(); it != players.end(); ++it) {
					if (it->getId() == nex) {
						nexV.push_back(*it);
						check = true;
					}
					else if (true == check)
						break;
				}
			}

			if (1 == choose) {
				cout << "앞 Player 정보:" << endl;
				for (const auto& tmp : preV)
					cout << tmp << endl;

				cout << "일치하는 Player 정보:" << endl;
				for (const auto& tmp : tp)
					cout << tmp << endl;

				cout << "뒤 Player 정보:" << endl;
				for (const auto& tmp : nexV)
					cout << tmp << endl;
			}
			else {
				for (int i{}; i < tp.size(); ++i) {
					cout << "앞 Player 정보:" << endl;
					cout << preV[i] << endl;

					cout << "일치하는 Player 정보:" << endl;
					cout << tp[i] << endl;

					cout << "뒤 Player 정보:" << endl;
					cout << nexV[i] << endl;

				}
			}
		}
		else {
			// targetId를 찾지 못함
			cout << "해당 ID를 가진 Player를 찾을 수 없습니다." << endl;
			continue;
		}
	}
}

void Player::write(ostream& os) {
	os.write((char*)this, sizeof(Player));
	os.write((char*)p, num);
}

bool Player::read(istream& is) {

	is.read((char*)this, sizeof(Player));
	p = new char[num];
	is.read((char*)p, num);

	return (bool)is;
}

bool compareByScore(const Player& p1, const Player& p2) {
	return p1.getScore() > p2.getScore();
}

void recordSameIdPlayers(const vector<Player>& players) {
	ofstream outFile("같은아이디.txt");
	if (!outFile) {
		cerr << "파일을 열 수 없습니다." << endl;
		return;
	}

	vector<Player> sortedPlayers = players; // 정렬을 위해 새로운 벡터에 복사
	sort(sortedPlayers.begin(), sortedPlayers.end());

	vector<Player> sameIdPlayers;
	int n = 0;


	for (size_t i = 0; i < sortedPlayers.size(); ++i) {
		size_t id = sortedPlayers[i].getId();

		if (i > 0 && sortedPlayers[i - 1].getId() == id) {
			// 이미 해당 id를 가진 객체를 파일에 기록했으면 건너뛰기
			continue;
		}

		sameIdPlayers.clear();

		// 이진 탐색으로 같은 id를 가진 플레이어 찾기
		auto it = lower_bound(sortedPlayers.begin(), sortedPlayers.end(), id,
			[](const Player& player, size_t id) {
				return player.getId() < id;
			});
		while (it != sortedPlayers.end() && it->getId() == id) {
			sameIdPlayers.push_back(*it);
			++it;
		}

		// 같은 id를 가진 객체들을 파일에 기록
		for (int i{}; i < sameIdPlayers.size(); ++i) {
			if (1 == sameIdPlayers.size())
				continue;

			outFile << sameIdPlayers[i].getName() << ' ' << sameIdPlayers[i].getId() << '\n';

			++n;
		}
	}

	cout << "id가 같은 객체의 개수: " << n << endl << endl;

	outFile.close();
}