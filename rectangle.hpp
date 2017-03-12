#include "shape.hpp"


class Rectangle : public Shape
{
protected:
	double width, height;
public:
	void scale(double coef) { if (coef>0) { width *= coef; height *= coef; } }
	Rectangle() :width(10), height(10) { pos.x = pos.y = 5; name = "Rectangle"; angle = 0; rect.pos = pos; rect.height = height; rect.width = width;}
	Rectangle(point_t p, double x, double y) :Rectangle() { rect.height = height = x; rect.width = width = y; pos.x = p.x; pos.y = p.y; rect.pos = pos;}
	Rectangle& operator=(const Rectangle& obj)
	{
		if (this != &obj)
		{
			angle = obj.angle;
			rect.height=height = obj.height;
			name = obj.name;
			rect.pos=pos = obj.pos;
			rect.width=width = obj.width;
					
		}
		return *this;
	}

	Rectangle(const Rectangle& obj) 
	{
		angle = obj.angle;
		rect.height = height = obj.height;
		name = obj.name;
		rect.pos = pos = obj.pos;
		rect.width = width = obj.width;
	}
	double getArea() { return width*height; }
	rectangle_t getFrameRect()
	{ 
		rect.pos = pos;
		rect.height = height*cos(angle) + width*sin(angle);
		rect.width = width*cos(angle) + height*sin(angle);
		return rect;
	}
};