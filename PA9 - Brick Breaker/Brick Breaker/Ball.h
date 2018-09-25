#pragma once
#include "Shape.h"

class Ball : public Shape
{
public:
	Ball();
	~Ball();

	void update(double);
	void render(double);

	void setDirection(double, double);

	void SetX_Dir(double);
	void setY_Dir(double);

	double GetX_Dir(void);
	double GetY_Dir(void);

protected:
	double X_dir, Y_dir;

private:
	SDL_Texture * texture;
};








