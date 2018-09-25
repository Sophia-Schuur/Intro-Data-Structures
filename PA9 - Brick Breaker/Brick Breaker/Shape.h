#pragma once
#include "Globals.h"


class Shape
{
public:
	Shape();//constructor
	virtual ~Shape();//destructor

	virtual void update(double);//delta
	virtual void render(double);//delta

	void setX(double);
	void setY(double);
	double getX(void);
	double getY(void);


	void setw(double);
	void setH(double);
	double getW(void);
	double getH(void);

	bool COLLIDED(Shape *);

protected:
	double X, Y, W, H;
};



