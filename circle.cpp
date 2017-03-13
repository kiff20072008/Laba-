#include "circle.hpp"

#define PI 3.1415926

Circle::Circle() :r_(1)
{
	name_= "Circle";
	rect_.height = rect_.width = 2 * r_;
}

Circle::Circle(point_t p, double raad=1) 
{
	if (raad <= 0)
	{
		r_ = 1;
	}else {
		r_ = raad;
	}
	rect_.pos = pos_ = p;
	name_ = "Circle";
	rect_.height = rect_.width = 2 * r_;
}


Circle::Circle(const Circle& obj)
{
	pos_ = obj.pos_;
	r_ = obj.r_;
	name_ = "Circle";
	angle_ = obj.angle_;
	rect_ = obj.rect_;
}

Circle& Circle::operator=(const Circle& obj)
{
	if (this != &obj)
	{
		pos_ = obj.pos_;
		r_ = obj.r_;
		name_ = "Circle";
		angle_ = obj.angle_;
		rect_ = obj.rect_;
	}
	return *this;
}

rectangle_t Circle::getFrameRect()
{
	return rect_;
}

double Circle::getArea() const
{
	return PI*r_*r_;
}

void Circle::setScale(double coef)
{
	if (coef > 0 && coef < 1000)
	{
		r_ *= coef;
		rect_.height = rect_.width = 2 * r_;

	}
}

double  Circle::get_rad() const
{
	return r_;
}