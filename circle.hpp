#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "shape.hpp"

#define PI 3.1415926

class Circle : public Shape
{
public:
	Circle(); 
	Circle(point_t p, double raad) ;
	Circle(const Circle& obj);
	Circle& operator=(const Circle& obj);
	rectangle_t getFrameRect();
	double getArea() const;
	void setScale(double coef);
	double  get_rad() const;
private:
	double r_;
};
#endif