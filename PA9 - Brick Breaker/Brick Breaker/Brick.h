#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "Globals.h"

class Brick
{
public:
	Brick();
	void setStatus(bool);
	void setColor(int);
	void setDiff(int);

	bool getStatus(void);
	int getColor(void);

protected:
	bool Status;
	int color;
	int Difficulty;
};


