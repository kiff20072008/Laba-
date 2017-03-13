#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"

class Rectangle : public Shape
{
public:
	Rectangle();
	Rectangle(point_t p, double x, double y);
	Rectangle(const Rectangle& obj);

	Rectangle& operator=(const Rectangle& obj);

	void setScale(double coef);
	double getArea() const;
	rectangle_t getFrameRect();
private:
	double width_, height_;
};
#endif