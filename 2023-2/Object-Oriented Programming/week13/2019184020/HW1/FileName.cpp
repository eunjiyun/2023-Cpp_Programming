//�а� : ���Ӱ��а�
//�й� : 2019184020
//�̸� : ������
//���� : Point Ŭ������ ��ӹ��� ColorPoint Ŭ������
//�ۼ��ϰ�, �־��� ���� ����� �������� ��ü ���α׷��� �ϼ��ϱ�

#include<iostream>
using namespace std;

class Point {
	int x, y;
public:
	Point(int x, int y) { this->x = x;  this->y = y; }
	int getX() { return x; }
	int getY() { return y; }
protected:
	void move(int x, int y) { this->x = x, this->y = y; }
};

class ColorPoint : public Point {
	string color;
public:
	ColorPoint(int x, int y, const string& color) : Point(x, y), color{color}{}
    void setPoint(int x, int y) { move(x, y); }
    void setColor(const string& color)  { this->color = color; }
    void show() 
	{
        cout << color << "������ (" << getX() << ", " << getY() << ")�� ��ġ�� ���Դϴ�." << endl;
    }
};

int main()
{
	ColorPoint cp(5, 5, "RED");
	cp.setPoint(10, 20);
	cp.setColor("BLUE");
	cp.show();
}