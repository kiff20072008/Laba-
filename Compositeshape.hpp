#ifndef COMPOSITE_SHAPE_HPP
#define COMPOSITE_SHAPE_HPP
#include "shape.hpp"

#define MAX_SIZE 12


class CompositeShape
{
public:
	CompositeShape();
	CompositeShape(Shape &obj1);
	Shape * operator[](int i);

	void addShape(Shape &obj1);
	int getLength();


private:
	struct shapes
	{
		Shape *obj;
		shapes *next;

	};
	int length_;
	shapes *obj_;
};

bool check_if_per(rectangle_t obj1, rectangle_t obj2);
#endif