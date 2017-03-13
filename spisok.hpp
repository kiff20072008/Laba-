#ifndef SPISOK_HPP
#define SPISOK_HPP

#include "Compositeshape.hpp"

class Spisok
{
	struct sloi;
public:
	Spisok();
	Spisok(Shape *obj1);
	Spisok(CompositeShape &obj1);
	Spisok(Spisok &obj);

	Spisok& operator=(Spisok &obj);

	void addShape(Shape *obj);
	void addShape(CompositeShape &obj1);
	void addShape(Spisok &obj); 
	int getLength()const;
	sloi* operator[](int z);
	bool isPer(sloi* ptr, Shape* obj);
private:
	int length_;
	struct sloi
	{
		Shape *arr[MAX_SIZE + 1];
		sloi *next;
		int length;
	};
	sloi *ptr_;
	sloi *temp_ptr_;
};
#endif