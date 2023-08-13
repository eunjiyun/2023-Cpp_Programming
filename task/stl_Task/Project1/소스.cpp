#include <iostream>
#include <fstream>
#include <format>
#include <algorithm>
#include <numeric>
#include <vector>


using namespace std;
#define SIZE 2000000 

class Player {
	string name; // �̸�, ����[3, 15]
	int score; // ����
	size_t id; // ���̵�, ��ġ�� ���̵� ���� �� ����
	size_t num; // free store�� Ȯ���� ����Ʈ ��
	char* p; // free store�� Ȯ���� �޸��� ���۹���

public:
	void write(ostream& os);
	bool read(istream& is);

	friend ostream& operator<<(ostream& os, const Player& p) {
		os << format("�̸�:{:<15} , ���̵�:{:<8} , ����:{:<10} , �ڿ���:{:<5} ", p.name, p.id, p.score, p.num) << endl;
		os << format("����ȱ���:{:<10}", p.p) << endl;
		return os;
	}

	// char ������������ p�� �����ϴ� �Լ�
	void sortP() {
		vector<char> temp(p, p + num);
		sort(temp.begin(), temp.end());
		copy(temp.begin(), temp.end(), p);
	}

	// ID�� ���� �� ������ ����
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

	//1. ������ �о� ���� ������ ��ü�� ������ ������ ���� �������� ����϶�.
	//[����] �̸�:ftexe, ���̵� : 697265, ���� : -38293887, �ڿ��� : 122
		//����ȱ��� : idquvhfhdszwhjouiolrxgybqdmpbxpinvxnrpbtpffxxkfixlvqrbvu
		//khnlquvelenyftlrkuhmpmtyjdstzvyafwmrplojliyuufqonxugynhdmxqggqrwbk

	string pname{ "2023 STL ���� ����" };
	ifstream in{ pname,ios::binary };

	vector<Player> players(SIZE);

	for (int i{}; i < SIZE; ++i) {

		if (!players[i].read(in)) break;

	}

	cout << players[players.size() - 1] << endl << endl;


	//2. ������ ���� ū Player�� ã�� ȭ�鿡 ����϶�.
	//��� Player�� ��� ������ ����Ͽ� ȭ�鿡 ����϶�.

	 // ������ ���� �÷��̾� ����
	sort(players.begin(), players.end(), compareByScore);

	// ���� ū ������ ���� �÷��̾� ���
	if (!players.empty()) {
		cout << players[0] << endl;
	}

	long double  sum{ 0 };

	sum = accumulate(players.begin(), players.end(), 0LL, [](long double  acc, const Player& p) {
		return p.getScore() + acc;
		});


	cout << fixed;
	cout.precision(5);
	cout << "��� : " << sum / players.size() << endl << endl;


	//3. id�� ���� ���� ��ü�� ã�� "�������̵�.txt"�� ����϶�.
	//id�� ���� ��ü�� ��� �� ������ ȭ�鿡 ����϶�.
		//- ���Ͽ��� Player ���� �̸��� ���̵� �� �ٿ� ����Ѵ�.

	 // id�� ���� ��ü���� ���Ͽ� ����ϰ� ������ ���
	recordSameIdPlayers(players);


	//4. p�� �о�� �޸𸮸� char ������������ �����϶�.
	//'a'�� 10���� �̻��� Player�� ������ ȭ�鿡 ����϶�.

	 // 'p' ����� char ������������ ����
	for (int i{}; i < SIZE; ++i) {
		players[i].sortP();
	}

	// 'a'�� 10���� �̻��� Player�� ������ ����
	int count = 0;
	for (const auto& player : players) {
		string pString(player.getP());
		if (std::count(pString.begin(), pString.end(), 'a') >= 10) {
			count++;
		}
	}

	// ��� ���
	cout << "a�� 10���� �̻��� Player�� ����: " << count << endl << endl;


	//5. id�� �Է¹޾� �����ϴ� id��� ���� ������ �� ���� ȭ�� ����϶�

	/*5-1. Player�� id ������������ �����Ͽ��� ��
		�ش� id ���� �հ� �� Player�� ������ ����Ѵ�.
		id�� ���� Player�� �� �̻��̸� �̵��� ������ ��� ����Ͽ��� �Ѵ�.*/

		//5-2. Player�� name ������������ �����Ͽ��� �� �ش� id ���� �հ� �� Player�� ������ ����Ѵ�.

		//5-3. Player�� score ������������ �����Ͽ��� �� �ش� id ���� �հ� �� Player�� ������ ����Ѵ�.



	while (true) {
		int choose = 0;
		cout << "1. id �������� ����" << endl;
		cout << "2. name �������� ����" << endl;
		cout << "3. score �������� ����" << endl;
		cout << "choose : ";
		cin >> choose;

		size_t targetId;
		cout << "ã�� ID�� �Է��ϼ���: ";
		cin >> targetId;

		if (cin.fail()) {
			cout << "�߸��� �Է��Դϴ�. �ٽ� �õ��ϼ���." << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			continue;
		}

		switch (choose) {
		case 1:
			// players ���͸� id ������������ ����
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


		// targetId�� ã�� ���� ���� Ž��
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
				cout << "�� Player ����:" << endl;
				for (const auto& tmp : preV)
					cout << tmp << endl;

				cout << "��ġ�ϴ� Player ����:" << endl;
				for (const auto& tmp : tp)
					cout << tmp << endl;

				cout << "�� Player ����:" << endl;
				for (const auto& tmp : nexV)
					cout << tmp << endl;
			}
			else {
				for (int i{}; i < tp.size(); ++i) {
					cout << "�� Player ����:" << endl;
					cout << preV[i] << endl;

					cout << "��ġ�ϴ� Player ����:" << endl;
					cout << tp[i] << endl;

					cout << "�� Player ����:" << endl;
					cout << nexV[i] << endl;

				}
			}
		}
		else {
			// targetId�� ã�� ����
			cout << "�ش� ID�� ���� Player�� ã�� �� �����ϴ�." << endl;
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
	ofstream outFile("�������̵�.txt");
	if (!outFile) {
		cerr << "������ �� �� �����ϴ�." << endl;
		return;
	}

	vector<Player> sortedPlayers = players; // ������ ���� ���ο� ���Ϳ� ����
	sort(sortedPlayers.begin(), sortedPlayers.end());

	vector<Player> sameIdPlayers;
	int n = 0;


	for (size_t i = 0; i < sortedPlayers.size(); ++i) {
		size_t id = sortedPlayers[i].getId();

		if (i > 0 && sortedPlayers[i - 1].getId() == id) {
			// �̹� �ش� id�� ���� ��ü�� ���Ͽ� ��������� �ǳʶٱ�
			continue;
		}

		sameIdPlayers.clear();

		// ���� Ž������ ���� id�� ���� �÷��̾� ã��
		auto it = lower_bound(sortedPlayers.begin(), sortedPlayers.end(), id,
			[](const Player& player, size_t id) {
				return player.getId() < id;
			});
		while (it != sortedPlayers.end() && it->getId() == id) {
			sameIdPlayers.push_back(*it);
			++it;
		}

		// ���� id�� ���� ��ü���� ���Ͽ� ���
		for (int i{}; i < sameIdPlayers.size(); ++i) {
			if (1 == sameIdPlayers.size())
				continue;

			outFile << sameIdPlayers[i].getName() << ' ' << sameIdPlayers[i].getId() << '\n';

			++n;
		}
	}

	cout << "id�� ���� ��ü�� ����: " << n << endl << endl;

	outFile.close();
}