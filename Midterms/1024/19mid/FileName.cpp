#include<iostream>
#include<thread>
#include<algorithm>
#include<random>
#include<fstream>
using namespace std;

int big(int arr[], int size);
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

	/*�־��� ���α׷��� ���� ������ �����ϸ� �� �ݺ����� ũ�Ⱑ 10, 000, 000 ��Ʈ(int) �迭�� �������� �Ҵ��մϴ�.
	�� �迭�� ��(heap) �޸𸮿� ����˴ϴ�.
	�׷� ���� this_thread::sleep_for(500ms) �Լ��� ����Ͽ� 500 �и���(0.5 ��) ���� ���α׷��� �Ͻ� ������ŵ�ϴ�.
	�޸� �������� �� ���α׷��� �����ϸ� ������ �����ϴ� :

	
	    1.���α׷��� ����Ǹ� ó������ p �����Ͱ� � �ּҵ� ����Ű�� �ʰ�(������ ���� ��� ����) while ������ �����մϴ�.

		2.������ �� �ݺ����� new int[10'000'000]�� ȣ���Ͽ� 10, 000, 000 ���� int ��Ҹ� �����ϴ� �迭�� �������� �Ҵ��մϴ�.�� �迭�� �� �޸𸮿� ����˴ϴ�.

		3.�� �迭�� �޸𸮸� �����ϰ�, �� �޸𸮴� ���� �����˴ϴ�.

		4.this_thread::sleep_for(500ms)�� ȣ���Ͽ� �ݺ����� 0.5�� ���� ���α׷��� ��� ���¿� ���ϴ�.�� ���ȿ��� �Ҵ�� �޸𸮰� �������� �ʽ��ϴ�.

		5.�� ������ �ݺ��Ǹ鼭 ����ؼ� ���ο� �迭�� �Ҵ�ǰ�, �޸� �Һ��� ����ؼ� �����մϴ�.

		6.�� �޸𸮰� ��� �����ϸ� �ᱹ �� �̻� ��� ������ �޸𸮰� ������ ���Դϴ�.

		7.�޸𸮰� �� �̻� �Ҵ���� ���ϸ�, ���� �޸� �Ҵ��� �����ϰ� ���α׷��� "new" �����ڰ� ������ ���� �����ϰ� ������ �߻���ų ���Դϴ�.

		���α׷��� �̷��� ������ ���� �޸� �������� ���� �ᱹ ������ ���Դϴ�.
		���α׷��� ������ ȯ��(Visual Studio ���� �� ��ǻ�� �޸� �뷮)�� ���� 
		��Ȯ�� ���� ���� �� �޸� �Һ��� �ٸ� �� �ֽ��ϴ�.
		Visual Studio ������ ������ ����� ������ ������ ������, 
		���⼭ ������ ������ ���� ����� ��� �� x86 ���� ����Ǿ����� ������� ������ �����߽��ϴ�.*/

	//3. sort �Լ��� ����Ͽ� text�� ��ҹ��� �������
	//������������ �����϶�.
	//(����) char c�� �ҹ��ڷ� ��ȯ�Ϸ��� tolower(c)��
	//ȣ���ϸ� �ȴ�.

	//��ü namespace�� ������� �ʰ� ���̻� s�� ����Ϸ���
	
	//using namespace std::string_literals;

	string text{ "The Quick Brown Fox Jumps Over The Lazy Dog"s };

	////���⿡ �� �ڵ带 ������ �����.
	sort(text.begin(), text.end(), [](char& fir,char& sec) {
		return tolower(fir) < tolower(sec);
		});

	cout << text << endl;//aBcDeeeFghhiJkLmnooOopQrrsTTuuvwxyz (��°��)

	//4. �� ���α׷��� ���� 50���� ���Ͽ� ����Ѵ�.
	//���Ͽ� �ִ� ��� ������ ��հ��� ����Ͽ� ����ϴ� 
	//�ڵ带 �ۼ��϶�. (����) ��µ� ���� ������ ���.

	makeData();

	//���⿡�� ������ �о� ��հ��� ����ϴ� �ڵ带 �ۼ��ϸ� �ǰڴ�.
	ifstream in{ fileName };
	int temp;
	double sum{};
	int ave;
	if (not in)
		return 0;
	while (in >> temp)
		sum += temp;

	ave = sum / 50;
	cout << "��� : " << ave<< endl;
}

int big(int arr[], int size)
{
	int max = arr[0];

	for (int i{ 1 }; i < size; ++i)
		if (max < arr[i])
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