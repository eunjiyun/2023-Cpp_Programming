#include<iostream>
#include<thread>
#include<algorithm>
#include<random>
#include<fstream>
using namespace std;

int big(int[], int);

void makeData();

string fileName{ "�����.txt" };

int main()
{
	//1. ���� �迭�� ���� ���� ���ڷ� �޾� 
	//�迭�� ���� �� ���� ū ���� ã��
	//�ǵ��� �ִ� �Լ� big�� �����ϰ� �����϶�.

	int a[5]{ 1,2,3,4,5 };
	int b[10]{ 1,2,3,4,5,6,7,8,9,10 };

	cout << "a���� ���� ū �� " << big(a, 5) << endl;//5
	cout << "b���� ���� ū �� " << big(b, 10) << endl;//10

	//2. ���� ���α׷��� (Debug ���, x86)���� �������ϰ�
	//�����Ͽ���.
	//���� ����� �� �׷��� �Ǵ����� �޸� �������� �����϶�.
	//(����) ����� ���־� ��Ʃ����� ����(�޴� - ���� -����)
	//�� ������ �����. (��: ���� 16.2.3)

	/*int* p;

	while (true) {
		p = new int[10'000'000];
		this_thread::sleep_for(500ms);
	}*/

	//0.5�ʿ� �� ���� int 10'000'000���� ũ�⸦ heap������ �Ҵ��ϱ� ������ 
	//pc�� ������ �� ���� ��ŭ �޸𸮸� ����ϰ� �Ǹ� ������ �߰� ���α׷��� ����˴ϴ�.
	

		//3. sort �Լ��� ����Ͽ� text�� ��ҹ��� �������
		//������������ �����϶�.
		//(����) char c�� �ҹ��ڷ� ��ȯ�Ϸ��� tolower(c)��
		//ȣ���ϸ� �ȴ�.

		//��ü namespace�� ������� �ʰ� ���̻� s�� ����Ϸ���

		//using namespace std::string_literals;

		string text{ "The Quick Brown Fox Jumps Over The Lazy Dog"s };

		//���⿡ �� �ڵ带 ������ �����.
	
		sort(text.begin(), text.end(), [](char fir,char sec) {
			return tolower(fir) < tolower(sec);
			});
		

		cout << text << endl;//aBcDeeeFghhiJkLmnooOopQrrsTTuuvwxyz (��°��)

		//4. �� ���α׷��� ���� 50���� ���Ͽ� ����Ѵ�.
		//���Ͽ� �ִ� ��� ������ ��հ��� ����Ͽ� ����ϴ� 
		//�ڵ带 �ۼ��϶�. (����) ��µ� ���� ������ ���.

	makeData();

	//���⿡�� ������ �о� ��հ��� ����ϴ� �ڵ带 �ۼ��ϸ� �ǰڴ�.
	ifstream in{ fileName };

	if (not in)
		return 1;

	int temp;
	double sum{};
	int ave;
	while (in >> temp)
		sum += temp;
	ave = sum / 50;

	cout << "��� : " << ave<< endl;//1273778304   1273778420  1.27378e+09
	
}

int big(int arr[], int size)
{
	int max = arr[0];

	for (int i{ 1 }; i < size; ++i)
		if (arr[i] > max)
			max = arr[i];

	return max;
}


void makeData()
{
	default_random_engine dre;
	uniform_int_distribution<int> uid;

	ofstream out{ fileName };

	for (int i{}; i < 50; ++i)
		out << uid(dre) << endl;
}