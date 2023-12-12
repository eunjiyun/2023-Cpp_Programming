#pragma once

class Point {
protected:
	int x, y;

public:
	void set(int x, int y);
	void showPoint();
};
class ColorPoint :public Point {
	std::string color;

public:
	void setColor(std::string color);
	void showColorPoint();
	bool equals(ColorPoint p);
};
