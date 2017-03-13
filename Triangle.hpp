#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "shape.hpp"

#define OTNOSH (sqrt(3)/2.)

class Triangle : public Shape
{
public:
	Triangle();
	Triangle(point_t p, double x);
	Triangle(const Triangle & obj);

	Triangle& operator=(const Triangle& obj);

	void setScale(double coef);
	double getArea()const;
	rectangle_t getFrameRect();
private:
	double side_;
	double height_;
};
#endif