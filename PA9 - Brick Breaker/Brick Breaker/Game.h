#pragma once
#include "Ball.h"
#include "Paddle.h"
#include "Board.h"
#include "Button.h"



class Game {

public:
	Game();
	~Game();

	bool Init();
	void Run();

	void Render(int, double, Gamestate);


private:
	unsigned int num_Levels = 0, BRICK_COUNT = 0;
	Board *levels[4];//holds each of the levels in an array
	Ball *ball;//ball shown on screen
	Paddle *paddle;//paddle shown on screen
	int flag = 0;
	bool Paddle_Ball;
	bool Paddle_Stuck;
	Button exitButton;
	Button playButton;
	Button helpButton;

	SDL_Event EVENT;
	SDL_Window *window;
	SDL_Texture *texture;
	SDL_Texture *menuTexture;

	void init();
	Gamestate getGameState(int, int, Gamestate);

	int Brick_Count(int);
	void Cleaner();
	void newGame(int);
	void stickBall();
	void ResetPaddle();
	void update(double, int, int);
	void setPaddleX(double);

	void BoardCollision(int);
	void PaddleCollision();
	void BrickCollision(int);
	void BrickResponse(int);
	double Reflect(double);


	

};


