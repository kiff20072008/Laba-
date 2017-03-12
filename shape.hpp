#pragma once
#include <string>
#include "base-types.hpp"

#define PI 3.1415926

class Shape
{
public:
	point_t pos;
	std::string name;
	rectangle_t rect;
	double angle;
	virtual double getArea()=0;
	virtual rectangle_t getFrameRect()=0;
	virtual void scale(double) = 0;
	void move(point_t temp) { pos = temp; };
	void move(double x, double y) { pos.x += x; pos.y += y; };
	void setAngle(double temp) { if (temp > -1 && temp < 361) angle = temp*PI / 180; }
	void operator+=( point_t &right_obj) { move(right_obj.x,right_obj.y); }
};


