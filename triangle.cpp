#include "Triangle.hpp"
#include <math.h>

#define OTNOSH (sqrt(3.)/2.)

Triangle::Triangle():height_(10),side_(10/OTNOSH)
{
	name_ = "Triangle";
	rect_.height = height_;
	rect_.width = side_;
}

Triangle::Triangle(point_t p, double x=10)
{ 
	name_ = "Triangle";
	rect_.height = height_ = x;
	rect_.width = side_ = x / OTNOSH;
	rect_.pos=pos_ = p;
}

Triangle::Triangle(const Triangle & obj)
{
	angle_ = obj.angle_;
	rect_.height = height_ = obj.height_;
	name_ = obj.name_;
	rect_.pos = pos_ = obj.pos_;
	rect_.width = side_ = obj.side_;
}

Triangle& Triangle::operator=(const Triangle& obj)
{
	if (this != &obj)
	{
		angle_ = obj.angle_;
		rect_.height = height_ = obj.height_;
		name_ = obj.name_;
		rect_.pos = pos_ = obj.pos_;
		rect_.width = side_ = obj.side_;
	}
	return *this;
}
void Triangle::setScale(double coef)
{
	if (coef>0)
	{
		side_ *= coef;
		height_ *= coef;
		updateRecAfterTurn();
	}
}

double Triangle::getArea()const 
{
	return (height_*height_ / sqrt(3.));
}

rectangle_t Triangle::getFrameRect()
{
	return rect_;
}

void Triangle::updateRecAfterTurn()
{
	rect_.height = side_*sin(angle_) + side_*(cos(angle_) *OTNOSH - sin(angle_) / 2);
	rect_.width = side_*cos(angle_) + side_*(sin(angle_)*OTNOSH - cos(angle_) / 2);
}