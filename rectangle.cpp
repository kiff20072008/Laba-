#include "rectangle.hpp"


void Rectangle::setScale(double coef) 
{ 
	if (coef>0)
	{ 
		width_ *= coef;
		height_ *= coef;
	} 
}

Rectangle::Rectangle() :width_(10), height_(10)
{ 
	pos_.x = pos_.y = 5;
	name_ = "Rectangle";
	angle_ = 0;
	rect_.pos = pos_;
	rect_.height = height_;
	rect_.width = width_;
}

Rectangle::Rectangle(point_t p, double x, double y) :Rectangle()
{
	rect_.height = height_ = x;
	rect_.width = width_ = y;
	pos_.x = p.x;
	pos_.y = p.y;
	rect_.pos = pos_;
}

Rectangle& Rectangle::operator=(const Rectangle& obj)
{
	if (this != &obj)
	{
		angle_ = obj.angle_;
		rect_.height = height_ = obj.height_;
		name_ = obj.name_;
		rect_.pos = pos_ = obj.pos_;
		rect_.width = width_ = obj.width_;

	}
	return *this;
}

Rectangle::Rectangle(const Rectangle& obj)
{
	angle_ = obj.angle_;
	rect_.height = height_ = obj.height_;
	name_ = obj.name_;
	rect_.pos = pos_ = obj.pos_;
	rect_.width = width_ = obj.width_;
}

double Rectangle::getArea() const 
{
	return width_*height_;
}

rectangle_t Rectangle::getFrameRect()
{
	rect_.pos = pos_;
	rect_.height = height_*cos(angle_) + width_*sin(angle_);
	rect_.width = width_*cos(angle_) + height_*sin(angle_);
	return rect_;
}