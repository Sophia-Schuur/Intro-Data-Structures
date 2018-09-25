
#pragma once
#include "Shape.h"
#include <SDL.h>

class Paddle : public Shape
{
public:
	Paddle(/*SDL_Renderer *renderer = nullptr*/);
	~Paddle();

	void update(double);
	void render();


private:
	SDL_Texture * texture;
};




