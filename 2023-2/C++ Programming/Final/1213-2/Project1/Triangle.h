//-----------------------------------------------------------------------------
// Triangle.h
//-----------------------------------------------------------------------------

#pragma once
#pragma warning(disable: 4038)
#include <iostream>
//#include <format>
#include "Shape.h"

using std::cout;


class Triangle : public Shape {
public:
	virtual void draw() const override 
	{
		//std::cout << std::format( "[{:3d}] - »ï°¢Çü", id ) << '\n';
		std::cout <<"»ï°¢Çü : "<< id << '\n';
	}
};
