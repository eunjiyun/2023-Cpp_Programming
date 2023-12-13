//-----------------------------------------------------------------------------
// Circle.h
//-----------------------------------------------------------------------------

#pragma once

#include <iostream>
//#include <format>
#include "Shape.h"

using std::cout;

struct Point {							// 2차원 좌표(x, y)
	int x;
	int y;
};


class Circle : public Shape {
	Point center{};						// 중심점의 좌표
	int rad{};							// 반지름

public:
	Circle( ) = default;
	Circle( Point c, int r ) : center{ c }, rad{ r } { }

	int getRad( ) const				// 반지름을 알려준다
	{
		return rad;
	}


	virtual void draw() const override 
	{
		/*cout << std::format( "[{:3d}] - 원, ",id )  
			<< std::format( "중심점({:d}, {:d}), ", center.x, center.y ) 
			<< std::format( "반지름 - {:3d}", rad )
			<< '\n';*/

		cout << " 원 : " << id
			<< "중심점 :" << center.x, center.y;
			cout<<"반지름 :" << rad
			<< '\n';
	}
};

