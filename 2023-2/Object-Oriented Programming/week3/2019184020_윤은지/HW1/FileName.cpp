//�а� : ���Ӱ��а�
//�й� : 2019184020
//�̸� : ������
//���� : TowerŬ������ ����� �־��� ���� ����� 
//�������� �Ѵ�.

#include<iostream>
using namespace std;

class Tower
{
private:
    int height;//��� ����

public:
    Tower(int h = 1)//������
    {
        height = h;
    }

    int getHeight()//��� �Լ�
    {
        return height;
    }
};

int main()
{
    Tower myTower;
    Tower seoulTower(100);

    cout << "���̴� " << myTower.getHeight() << "����" << endl;
    cout << "���̴� " << seoulTower.getHeight() << "����" << endl;
}