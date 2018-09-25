#include "Paddle.h"
#include <iostream>

Paddle::Paddle(/*SDL_Renderer *Renderer*/) : Shape()
{
	SDL_Surface* surface = IMG_Load("paddle.png");//might need to change the name of this
	texture = SDL_CreateTextureFromSurface(Renderer, surface);
	SDL_FreeSurface(surface);
	if (texture == nullptr)
		std::cout << IMG_GetError() << std::endl;
	W = 128;
	H = 32;

	Y = 532;//might need to change the y cordinate
}

Paddle::~Paddle()
{
	SDL_DestroyTexture(texture);
}

void Paddle::update(double Delta)
{

}

void Paddle::render()
{
	SDL_Rect rectangle;

	rectangle.x = (int)(X + .5f);
	rectangle.y = (int)(Y + .5f);
	rectangle.w = W;
	rectangle.h = H;

	SDL_RenderCopy(Renderer, texture, 0, &rectangle);
}



