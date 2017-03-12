#include "Compositeshape.hpp"
#include "circle.hpp"
#include "rectangle.hpp"
#include "Triangle.hpp"


using namespace std;

int main()
{
	point_t pont1{ 100,20 }, pont2{ 15,15 };

	Circle cir(point_t{ 15,5 },12);
	Triangle treug(pont1, 10), treug2;
	Rectangle rec1(pont2,10,10), rec2(pont1, 5, 10);
	CompositeShape obj(cir);
	spisok spis(obj),obj1(&cir),obj2(&cir);

	obj.addShape(rec1);
	obj.addShape(rec2);

	cout << " Rectangles are ";
	if (!check_if_per(rec1.getFrameRect(), rec2.getFrameRect()))
		cout << " not ";
	cout << "peresek" << endl;

	for (int i = 0; i <2; i++)
	{
		cout << "COMPOSITE  Figure is " << obj[i]->name << " Area = " << obj[i]->getArea() << " x coord = " << obj[i]->pos.x << " y coord = " << obj[i]->pos.y << " Angle = " << obj[i]->angle << endl;
	}


	for (int i = 0; i < 45; i++)
		cout << "*";
	cout << endl;


	rec1 += pont2;
	rec2 += pont1;
	obj1.add_shape(obj);
	obj2.add_shape(obj1);
	obj2.add_shape(&rec1);
	obj2.add_shape(&rec2);
	obj2.add_shape(&treug);
	obj2.add_shape(&treug2);


	
	for (int i = 0; i < obj1.get_length(); i++)
	{
		for (int j = 0; j < obj1[i]->length; j++)
			cout << "Object 1 sloi num " << i << "  Figure is " << obj1[i]->arr[j]->name << " Area = " << obj1[i]->arr[j]->getArea() << " x coord = " << obj1[i]->arr[j]->pos.x << " y coord = " << obj1[i]->arr[j]->pos.y << " Angle = " << obj1[i]->arr[j]->angle << endl;
	}

	for (int i = 0; i < 45; i++)
		cout << "*" ;
	cout << endl;
	for (int i = 0; i < obj2.get_length(); i++)
	{
		for (int j = 0; j < obj2[i]->length; j++)
		cout << "OBJECT 2 sloi num "<< i <<"  Figure is " << obj2[i]->arr[j]->name << " Area = " << obj2[i]->arr[j]->getArea() << " x coord = " << obj2[i]->arr[j]->pos.x << " y coord = " << obj2[i]->arr[j]->pos.y << " Angle = " << obj2[i]->arr[j]->angle << endl;
	}
	for (int i = 0; i < 45; i++)
		cout << "*" ;
	cout << endl;
	
}