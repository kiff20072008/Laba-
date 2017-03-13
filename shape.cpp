#include "shape.hpp"

#define PI 3.1415926

void Shape::move(point_t temp)
{
	rect_.pos=pos_ = temp;
};

void Shape::move(double x, double y)
{
	rect_.pos.x=pos_.x += x;
	rect_.pos.y = pos_.y += y;
};

void Shape::setAngle(double temp)
{
	if (temp > -1 && temp < 361)
	{
		angle_ = temp*PI / 180;
		updateRecAfterTurn();
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

Shape::Shape() :pos_({ 0,0 }), angle_(0)
{
}

void Shape::updateRecAfterTurn()
{
}