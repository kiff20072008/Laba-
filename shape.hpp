#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "base-types.hpp"
#include <string>


#define PI 3.1415926

class Shape
{
public:
	virtual double getArea() const =0;
	virtual rectangle_t getFrameRect()=0;
	virtual void setScale(double) = 0;
	void move(point_t temp);
	void move(double x, double y) ;
	void setAngle(double temp);
	std::string getName()const;
	point_t getPos()const;
	double getAngle() const;
	void operator+=(point_t right_obj);
protected:
	point_t pos_;
	std::string name_;
	rectangle_t rect_;
	double angle_;
};
#endif


