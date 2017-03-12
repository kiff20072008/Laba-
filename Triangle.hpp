#pragma once
#include <math.h>
#include "shape.hpp"

#define OTNOSH (sqrt(3)/2.)

class Triangle : public Shape
{
protected:
	double side;
	double height;
public:
	Triangle() :height(10), side(10 / OTNOSH) { pos.x = 5; pos.y = 5; name = "Triangle"; rect.height = height; rect.width = side; angle = 0; }
	Triangle(point_t p, double x) :Triangle() {	rect.height = height = x; rect.width = side = x / OTNOSH;  pos.x = p.x; pos.y = p.y; rect.pos = pos;}
	Triangle(const Triangle & obj) 
	{
		angle = obj.angle;
		rect.height = height = obj.height;
		name = obj.name;
		rect.pos = pos = obj.pos;
		rect.width = side = obj.side;
	}

	Triangle& operator=(const Triangle& obj)
	{
		if (this != &obj)
		{
			angle = obj.angle;
			rect.height = height = obj.height;
			name = obj.name;
			rect.pos = pos = obj.pos;
			rect.width = side = obj.side;
		}
		return *this;
	}
	void scale(double coef) { if (coef>0) { side*= coef; height *= coef; } }
	
	double getArea() { return (height*height/sqrt(3)); }
	rectangle_t getFrameRect() 
	{  
		rect.pos = pos;
		rect.height = side*sin(angle) + side*(cos(angle) *OTNOSH - sin(angle)/2);
		rect.width =side*cos(angle) + side*(sin(angle)*OTNOSH -cos(angle) / 2 );
		return rect; 
	}
};

