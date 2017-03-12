#pragma once
#include "shape.hpp"

#define MAX_SIZE 12




class CompositeShape
{
private:
	struct shapes
	{
		Shape *obj;
		shapes *next;

	};
	int length;
public:
	int get_length() { return length; }
	shapes *obj;
	CompositeShape() :length(0) {  obj = NULL; }
	CompositeShape(Shape &obj1) :length(1) { obj = new (shapes); obj->obj = &obj1; obj->next = NULL;}

	void addShape(Shape &obj1) 
	{
			shapes *tmp=new (shapes);
			if (tmp)
			{
				tmp->obj = &obj1;
				tmp->next = obj;
				obj = tmp;
				length++;
			}
	}

	Shape * operator[](int i) { shapes *tmp; tmp = obj; if (i<0 || i>(length - 1))i = 0; for (int j = 0; j < i; j++)tmp = tmp->next; return tmp->obj; }
};


bool check_if_per(rectangle_t obj1, rectangle_t obj2)
{
	if (obj1.pos.x > (obj2.pos.x + obj2.width) || (obj1.pos.x + obj1.width) < obj2.pos.x)  
		return false;
	if (obj1.pos.y > (obj2.pos.y + obj2.height) || (obj1.pos.y + obj1.height) < obj1.pos.y)
		return false;
		return true;
}




class spisok
{
private:
	int length;
	struct sloi
	{
		Shape *arr[MAX_SIZE + 1];
		sloi *next;
		int length;
	};
	sloi *ptr;
	sloi *temp_ptr;
public:
	
	int get_length() { return length; }

	spisok():length(0) { temp_ptr= ptr = NULL; }
	spisok(Shape *obj1):spisok() { add_shape(obj1); }
	spisok(CompositeShape &obj1):spisok() { for (int i=0; i<obj1.get_length();i++) add_shape(obj1[i]); }
	spisok(spisok &obj) { ptr = obj.ptr; length = obj.length; }

	spisok& operator=(spisok &obj) { temp_ptr= ptr = obj.ptr; length = obj.length; }

	void add_shape(Shape *obj);
	void add_shape(CompositeShape &obj1) { for (int i = 0; i<obj1.get_length(); i++) add_shape(obj1[i]); }
	void add_shape(spisok &obj) 
	{ 
		for (int i = 0; i < obj.get_length(); i++)
			for (int j = 0; j < obj[i]->length; j++)
				add_shape(obj[i]->arr[j]);
	}

	sloi* operator[](int z) {  temp_ptr = ptr; if (z<0 || z>(length - 1)) z = 0; for (int i = 0; i < z; i++) temp_ptr = temp_ptr->next;   return temp_ptr; }
	bool is_per(sloi* ptr, Shape* obj);

};


bool spisok::is_per(sloi* ptr_obj, Shape* obj)
{
	for (int i = 0; i < ptr_obj->length; i++)
		if (check_if_per(ptr_obj->arr[i]->getFrameRect(), obj->getFrameRect()))
			return true;
	return false;
}

void spisok::add_shape(Shape *obj)
{
	if (!ptr)
	{
		ptr = new(sloi);
		ptr->next = NULL;
		ptr->arr[0] = obj;
		ptr->length = 1;
		length++;
		temp_ptr = ptr;
		return;
	}
	temp_ptr = ptr;

	while (temp_ptr->next&&(temp_ptr->length == MAX_SIZE))
		temp_ptr = temp_ptr->next;

	while (is_per(temp_ptr, obj))
	{
		if (!temp_ptr->next)
		{
			temp_ptr->next = new (sloi);
			temp_ptr->next->next = NULL;
			temp_ptr->next->length = 0;
			temp_ptr = temp_ptr->next;
			length++;
			break;
		}
		temp_ptr = temp_ptr->next;
	}
	if (temp_ptr->length == MAX_SIZE)
	{
		temp_ptr->next = new(sloi);
		temp_ptr->next->next = NULL;
		temp_ptr = temp_ptr->next;
		length++;
	}
	temp_ptr->arr[temp_ptr->length] = obj;
	temp_ptr->length++;
}