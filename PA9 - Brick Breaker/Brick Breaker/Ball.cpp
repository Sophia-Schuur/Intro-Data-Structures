#include "Ball.h"


Ball::Ball() : Shape()
{
	if (Renderer)
	{
		SDL_Surface* surface = IMG_Load("ball.png");//might need to change the name of this
		texture = SDL_CreateTextureFromSurface(Renderer, surface);

		if (texture == nullptr)
			std::cout << IMG_GetError() << std::endl;
		SDL_FreeSurface(surface);

		X = Y = 0;
		W = H = 24;

		X_dir = Y_dir = 1;

		setDirection(1, 1);

	}
}

Ball::~Ball()
{
	SDL_DestroyTexture(texture);
}

void Ball::update(double Delta)
{
	X = X + X_dir*Delta;
	Y = Y + Y_dir *Delta;
}

void Ball::render(double Delta)
{
	SDL_Rect rectangle;

	rectangle.x = (int)(X + .5f);
	rectangle.y = (int)(Y + .5f);
	rectangle.w = W;
	rectangle.h = H;

	SDL_RenderCopy(Renderer, texture, NULL, &rectangle);


}

void Ball::setDirection(double X, double Y)
{
	double length = sqrt(X * X + Y * Y);//creates unit vector with directions

	X_dir = Ball_Speed * (X / length);//creates vector with ball speed and unit vector
	Y_dir = Ball_Speed *(Y / length);
}

void Ball::SetX_Dir(double X)
{
	X_dir = X_dir * X;
}

void Ball::setY_Dir(double Y)
{
	Y_dir = Y_dir * Y;
}

double Ball::GetX_Dir(void)
{
	return X_dir;
}

double Ball::GetY_Dir(void)
{
	return Y_dir;
}

