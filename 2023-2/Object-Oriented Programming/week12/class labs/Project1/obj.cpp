#include<iostream>
#include"obj.h"

void Point::set(int x, int y) { this->x = x; this->y = y; }
void Point::showPoint() {
	std::cout << "(" << x << "," << y << ")" << std::endl;
}
void ColorPoint::setColor(std::string color) { this->color = color; }
void ColorPoint::showColorPoint() {
	std::cout << color << ":";
	showPoint();
}
bool ColorPoint::equals(ColorPoint p) {
	if (x == p.x && y == p.y && color == p.color)
		return true;
	else
		return false;
}