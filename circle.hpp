#include "shape.hpp"

#define pi 3.1415926

class Circle : public Shape
{
protected:
	double r;
public:
	
	Circle() :r(1) { pos.x = pos.y = 1; name = "Circle"; angle = 0; rect.height = rect.width = 2; rect.pos = pos; }
	Circle(point_t p, double raad) :r(raad) { rect.pos = pos = p; name = "Circle"; angle = 0; rect.height = rect.width = 2 * raad; }
	Circle(const Circle& obj) { pos = obj.pos;  r = obj.r; name = "Circle"; angle = obj.angle; rect = obj.rect; }

	Circle& operator=(const Circle& obj) { pos = obj.pos; r = obj.r; name = "Circle"; angle = obj.angle; rect = obj.rect; return *this; }

	rectangle_t getFrameRect() { rect.pos = pos; rect.height = rect.width = 2 * r; return rect; }
	double getArea() { return pi*r*r; }
	void scale(double coef) { if (coef>0 && coef<1000) r *= coef; }
	double  get_rad() { return r; }
};

