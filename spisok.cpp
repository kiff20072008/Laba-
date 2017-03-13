#include "spisok.hpp"
struct sloi;
int Spisok::getLength() const 
{ 
	return length_;
}

Spisok::Spisok() :length_(0)
{
	temp_ptr_ = ptr_ = NULL;
}

Spisok::Spisok(Shape *obj1) :Spisok() 
{
	addShape(obj1); 
}

Spisok::Spisok(CompositeShape &obj1) :Spisok() 
{ 
	for (int i = 0; i < obj1.getLength(); i++)
	{
		addShape(obj1[i]);
	}
}

Spisok::Spisok(Spisok &obj) 
{
	ptr_ = obj.ptr_; 
	length_ = obj.length_;
}

Spisok& Spisok::operator=(Spisok &obj) 
{ 
	temp_ptr_ = ptr_ = obj.ptr_;
	length_ = obj.length_;
	return *this;
}


void Spisok::addShape(CompositeShape &obj1)
{
	for (int i = 0; i<obj1.getLength(); i++)
		addShape(obj1[i]); 
}

void Spisok::addShape(Spisok &obj)
{
	for (int i = 0; i < obj.getLength(); i++)
	{
		for (int j = 0; j < obj[i]->length; j++)
		{
			addShape(obj[i]->arr[j]);
		}
	}
}

Spisok::sloi* Spisok::operator[](int z)
{ 
	temp_ptr_ = ptr_; 
	if (z<0 || z>(length_ - 1))
	{
		z = 0;
	}
	for (int i = 0; i < z; i++)
	{
		temp_ptr_ = temp_ptr_->next;
	}
	return temp_ptr_;
}


bool Spisok::isPer(Spisok::sloi* ptr_obj, Shape* obj)
{
	for (int i = 0; i < ptr_obj->length; i++)
		if (check_if_per(ptr_obj->arr[i]->getFrameRect(), obj->getFrameRect()))
			return true;
	return false;
}

void Spisok::addShape(Shape *obj)
{
	if (!ptr_)
	{
		ptr_ = new(sloi);
		ptr_->next = NULL;
		ptr_->arr[0] = obj;
		ptr_->length = 1;
		length_++;
		temp_ptr_ = ptr_;
		return;
	}
	temp_ptr_ = ptr_;

	while (temp_ptr_->next && (temp_ptr_->length == MAX_SIZE))
		temp_ptr_ = temp_ptr_->next;

	while (isPer(temp_ptr_, obj))
	{
		if (!temp_ptr_->next)
		{
			temp_ptr_->next = new (sloi);
			temp_ptr_->next->next = NULL;
			temp_ptr_->next->length = 0;
			temp_ptr_ = temp_ptr_->next;
			length_++;
			break;
		}
		temp_ptr_ = temp_ptr_->next;
	}
	if (temp_ptr_->length == MAX_SIZE)
	{
		temp_ptr_->next = new(sloi);
		temp_ptr_->next->next = NULL;
		temp_ptr_ = temp_ptr_->next;
		length_++;
	}
	temp_ptr_->arr[temp_ptr_->length] = obj;
	temp_ptr_->length++;
}