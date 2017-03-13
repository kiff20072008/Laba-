#include "Compositeshape.hpp"

int CompositeShape::getLength() 
{ 
	return length_;
}

CompositeShape::CompositeShape() :length_(0)
{
	obj_ = NULL;
}

CompositeShape::CompositeShape(Shape &obj1) :length_(1)
{
	obj_ = new (shapes);
	obj_->obj = &obj1;
	obj_->next = NULL;
}

void CompositeShape::addShape(Shape &obj1)
{
	shapes *tmp = new (shapes);
	if (tmp)
	{
		tmp->obj = &obj1;
		tmp->next = obj_;
		obj_ = tmp;
		length_++;
	}
}

Shape* CompositeShape::operator[](int i)
{
	shapes *tmp; 
	tmp = obj_;
	if (i<0 || i>(length_ - 1))
	{
		i = 0;
	}
	for (int j = 0; j < i; j++)
	{
		tmp = tmp->next;
	}
	return tmp->obj;
}



bool check_if_per(rectangle_t obj1, rectangle_t obj2)
{
	if (obj1.pos.x > (obj2.pos.x + obj2.width) || (obj1.pos.x + obj1.width) < obj2.pos.x)
		return false;
	if (obj1.pos.y > (obj2.pos.y + obj2.height) || (obj1.pos.y + obj1.height) < obj1.pos.y)
		return false;
	return true;
}