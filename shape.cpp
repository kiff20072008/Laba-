#include "shape.hpp"


void Shape::move(point_t temp)
{
	pos_ = temp;
};

void Shape::move(double x, double y)
{
	pos_.x += x;
	pos_.y += y;
};

void Shape::setAngle(double temp)
{
	if (temp > -1 && temp < 361)
	{
		angle_ = temp*PI / 180;
	}
};

void Shape::operator+=(point_t right_obj)
{
	move(right_obj.x, right_obj.y);
};

std::string Shape::getName() const
{
	return name_;
}

point_t Shape::getPos() const
{
	return pos_;
}

double Shape::getAngle()const
{
return angle_;
}