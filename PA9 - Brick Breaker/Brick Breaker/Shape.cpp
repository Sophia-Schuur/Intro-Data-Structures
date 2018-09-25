#include "Shape.h"

Shape::Shape()
{
	X = Y = 0;
	W = H = 1;
}

Shape::~Shape()
{
}

void Shape::update(double delta)
{
}

void Shape::render(double Delta)
{
}

void Shape::setX(double temp)
{
	X = temp;
}
void Shape::setY(double temp)
{
	Y = temp;
}

double Shape::getX(void)
{
	return X;
}

double Shape::getY(void)
{
	return Y;
}

void Shape::setw(double temp)
{
	W = temp;
}

void Shape::setH(double temp)
{
	H = temp;
}
double Shape::getW(void)
{
	return W;
}

double Shape::getH(void)
{
	return H;
}

bool Shape::COLLIDED(Shape *obj)
{
	if (X + W > obj->getX() && X < obj->getX() + obj->getW())
		if (Y + H > obj->getY() && Y <obj->getY() + obj->getH())
			return true;


	return false;
}



