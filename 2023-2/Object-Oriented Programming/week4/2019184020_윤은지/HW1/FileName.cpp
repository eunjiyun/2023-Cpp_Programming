//�й� : 2019184020
//�а� : ���Ӱ��а�
//�̸� : ������
//���� : ���� ������ ����ϴ� �Լ��� �������� �Է� �޴�
//�Լ�, �������� ������ ��� �ִ� class�� ����Ͽ� 
//�� ���� 100���� ������ ū�� �˻��ϴ� �ҽ��ڵ� �Դϴ�.

#include <iostream>
using namespace std;

class Circle {
    int radius;
public:
    void setRadius(int r);//������ ����
    double getArea();//���� ����
};

int main() {
    Circle circles[3];
    int numCircles = 3; // 3���� ���� ����

   
    for (int i{}; i < numCircles; ++i) {
        double radius;
        cout << "�� " << i + 1 << "�� ������>>";
        cin >> radius;
        circles[i].setRadius(radius);
    }

    int count = 0; // ������ 100���� ū ���� ����

    // �� ���� ������ ����ϰ�, 100���� ū�� Ȯ��
    for (int i{}; i < numCircles;++i) {
        if (circles[i].getArea() > 100) {
            ++count;
        }
    }

    cout << "������ 100���� ū ���� ����: " << count << endl;
}
void Circle::setRadius(int r) {
    radius = r;
}
double Circle::getArea() {
    return 3.14159 * radius * radius;
}