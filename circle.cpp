#include "circle.hpp"

Circle::Circle() :r_(1)
{
	pos_.x = pos_.y = 1;
	name_ = "Circle";
	angle_ = 0;
	rect_.height = rect_.width = 2;
	rect_.pos = pos_;
}

Circle::Circle(point_t p, double raad) :r_(raad)
{
	rect_.pos = pos_ = p;
	name_ = "Circle";
	angle_ = 0;
	rect_.height = rect_.width = 2 * raad;
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
	rect_.pos = pos_;
	rect_.height = rect_.width = 2 * r_;
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
	}
}

double  Circle::get_rad() const
{
	return r_;
}