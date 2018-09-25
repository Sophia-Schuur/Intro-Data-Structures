//#include "Game.h"
//#include <stdio.h>
//
//
//
//Game::Game()
//{
//	window = nullptr;
//	Renderer = nullptr;
//	
//}
//void Game::init() {
//	playButton.setCoordinates(PlayTLX, PlayTLY, PlayBRX, PlayBRY);
//	helpButton.setCoordinates(HelpTLX, HelpTLY, HelpBRX, HelpBRY);
//	exitButton.setCoordinates(QuitTLX, QuitTLY, QuitBRX, QuitBRY);
//
//	texture = IMG_LoadTexture(Renderer, "help.png");
//	if (texture == NULL) {
//		cout << IMG_GetError();
//	}
//	menuTexture = IMG_LoadTexture(Renderer, "menu.png");
//	if (menuTexture == NULL) {
//		cout << IMG_GetError();
//	}
//}
//Game::~Game()
//{
//
//}
//
//void Game::Cleaner()
//{
//	SDL_DestroyRenderer(Renderer);
//	SDL_DestroyWindow(window);
//	SDL_DestroyTexture(texture);
//}
//Gamestate Game::getGameState(int x, int y, Gamestate state) {
//	if (state != EXIT) {
//		if (helpButton.isPressed(x, y) && state != PLAY) {
//			//state = HELP;
//			return HELP;
//			//SDL_Quit();
//			//return EXIT;
//		}
//		if (playButton.isPressed(x, y) && state != PLAY) {
//			return PLAY;
//		}
//		if (exitButton.isPressed(x, y) && state != PLAY) {
//			//return ;
//		//	SDL_Quit();
//			return EXIT;
//		}
//		if (state == HELP && state != PLAY) {
//			
//			return MENU;
//
//		}
//		else
//		{
//			return MENU;
//		}
//	}
//}
//
//void Game::Run()
//{
//	if (!(this->Init()))//if the game could not be intialized then return out of the run function
//		return;
//	init();
//	SDL_Event EVENT;
//
//
//	double Delta = 0.0, CurrTick = 0.0, lastTick = 0.0;
//
//	char BUFFER[100];
//	Gamestate state = MENU;
//	int mouseX = 0, mouseY = 0;
//
//
//
//
//	SDL_RenderCopy(Renderer, texture, NULL, NULL);
//
//	paddle = new Paddle();
//	ball = new Ball();
//
//
//	newGame(num_Levels);
//
//
//
//	while (state != PLAY)
//	{
//		if (SDL_PollEvent(&EVENT))
//			if (EVENT.type == SDL_QUIT)
//				break;
//
//		if (EVENT.type == SDL_MOUSEBUTTONDOWN)
//		{
//
//			SDL_GetMouseState(&mouseX, &mouseY);
//			if (state != PLAY)
//				state = getGameState(mouseX, mouseY, state);
//		}
//
//
//		Render(num_Levels, Delta, state);
//
//	}
//
//	EVENT.type = NULL;
//
//
//	while (1)//main game loop
//	{
//		SDL_GetMouseState(&mouseX, &mouseY);
//		if (SDL_PollEvent(&EVENT))
//			if (EVENT.type == SDL_QUIT)
//				break;
//
//		lastTick = CurrTick;
//		CurrTick = SDL_GetTicks();
//		Delta = (CurrTick - lastTick) / 1000.0;
//
//
//
//		cout << "LAST TICK: " << lastTick << "\tCURRENT TICK:  " << CurrTick << "\tDELTA: " << Delta << endl << endl;
//
//		update(Delta, mouseX, mouseY);
//		Render(num_Levels, Delta, state);
//
//	}
//
//
//	delete levels[num_Levels];
//	delete paddle;
//	delete ball;
//
//	Cleaner();
//
//	SDL_Quit();
//
//	
//	//if (!(this->Init()))//if the game could not be intialized then return out of the run function
//	//	return;
//	//init();
//	////SDL_Event EVENT;
//
//	//int num = 0;//game level numbers
//	//unsigned int CurrTick;
//	//double Delta;
//	//char BUFFER[100];
//
//	//SDL_RenderCopy(Renderer, texture, NULL, NULL);
//
//	//		board[num] = new Board();
//	//		paddle = new Paddle();
//	//		ball = new Ball();
//	//		Gamestate state = MENU;
//	//		newGame(num);
//	//		int mouseX, mouseY;
//	//		SDL_Event EVENT;
//	//		while (1)//main game loop
//	//		{
//	//			if (SDL_PollEvent(&EVENT)) {
//	//				if (EVENT.type == SDL_QUIT) {
//	//					break;
//	//				}
//	//				if (EVENT.type == SDL_MOUSEBUTTONDOWN) 
//	//				{
//	//					SDL_GetMouseState(&mouseX, &mouseY);
//	//					cout << mouseX << " " << mouseY << endl;
//	//					if (state != PLAY)
//	//					{
//	//						state = getGameState(mouseX, mouseY, state);
//	//					}
//	//				}
//
//	//			}
//
//
//	//			CurrTick = SDL_GetTicks();
//	//			Delta = (CurrTick - lastTick) / 1000;
//
//	//			if (CurrTick - FPSTick >= DELAY)
//	//			{
//	//				FPS = FrameCount * (1000 / (CurrTick - FPSTick));
//	//				FPSTick = CurrTick;
//	//				FrameCount = 0;
//
//	//				snprintf(BUFFER, 100, "PA 9 BREAKOUT (fps: %u)", FPS);
//	//				SDL_SetWindowTitle(window, BUFFER);
//	//			}
//
//	//			lastTick = CurrTick;
//
//	//			update(Delta);
//	//			Render(num, Delta, state);
//
//	//			
//	//			
//	//			stickBall();
//	//		}
//
//
//
//	//		delete board[num];
//	//		delete paddle;
//	//		delete ball;
//
//	//	Cleaner();
//
//	//		SDL_Quit();
//}
//
//void Game::update(double Delta, int Mouse_X, int Mouse_Y)
//{
//
//	setPaddleX(Mouse_X - paddle->getW() / 2);//paddle is matched with mouse, center it with mouse by offsetting with width
//
//	if (EVENT.type == SDL_MOUSEBUTTONDOWN) //if button was pressed 
//	{
//		if (Paddle_Stuck == true)//launchs ball if we have it stuck to the paddle after a death or new level
//		{
//			Paddle_Stuck = false;
//			ball->setDirection(1, -1);
//		}
//
//	}
//
//	if (Paddle_Stuck == true)//if we want the ball to stick to the paddle, call function
//		stickBall();
//
//	BoardCollision(num_Levels);
//	PaddleCollision();
//	BrickCollision(num_Levels);
//
//
//	BRICK_COUNT = Brick_Count(num_Levels);
//
//	if (BRICK_COUNT == 0)//if the bricks have been cleared create new level
//	{
//		num_Levels = num_Levels + 1;
//		newGame(num_Levels);
//
//	}
//
//	if (Paddle_Stuck == false)//update ball if it is not stuck to the paddle
//		ball->update(Delta);
//
//
//	levels[num_Levels]->update(Delta);//update current level
//	paddle->update(Delta);//updates paddle
//
//}
//
//
//void Game::setPaddleX(double X_Value)
//{
//	if (X_Value < SIDE_WIDTH)//if mouse is to the left of the left Side border, then set paddle X to edge of border
//		paddle->setX(SIDE_WIDTH);//sets position to zero
//
//	else if (X_Value + PADDLE_WIDTH > WINDOW_X - SIDE_WIDTH)//mouse is at the far right of the screen
//		paddle->setX(WINDOW_X - PADDLE_WIDTH - SIDE_WIDTH);//paddle width to left of the right bound
//
//	else//mouse is in between the left and right bounds
//		paddle->setX(X_Value);
//}
//
//
//
//
//
//
////void Game::Wrapper()
////{
////	if (!(this->Init()))//if the game could not be intialized then return out of the run function
////		return;
////
////	SDL_Event EVENT;
////
////	Button buttonPlay, buttonHelp, buttonExit;
////	buttonPlay.setCoordinates(PlayTLX, PlayTLY, PlayBRX, PlayBRY);
////	buttonHelp.setCoordinates(MenuTLX, MenuTLY, MenuBRX, MenuBRY);
////	buttonExit.setCoordinates(QuitTLX, QuitTLY, QuitBRX, QuitBRY);
////	int mouseX, mouseY;
////	bool buttonPressed = false;
////
////	bool buttonPressedPlay = false;
////	bool buttonPressedHelp = false;
////	bool buttonPressedExit = false;
////
////
////
////	SDL_Surface* menu = IMG_Load("menu.png");//might need to change the name of this
////	texture = SDL_CreateTextureFromSurface(Renderer, menu);
////
////
////
////
////
////	SDL_RenderCopy(Renderer, texture, NULL, NULL);
////	while (buttonPressedPlay != true && buttonPressedHelp != true && buttonPressedExit != true)
////	{
////		SDL_RenderPresent(Renderer);
////		if (SDL_PollEvent(&EVENT)) {
////			if (EVENT.type == SDL_MOUSEBUTTONDOWN) {
////
////				SDL_GetMouseState(&mouseX, &mouseY);
////				printf("%d %d", mouseX, mouseY);
////				buttonPressedPlay = buttonPlay.isPressed(mouseX, mouseY);
////				buttonPressedHelp = buttonHelp.isPressed(mouseX, mouseY);
////				buttonPressedExit = buttonExit.isPressed(mouseX, mouseY);
////			}
////		}
////	}
////
////	if (buttonPressedPlay == true)
////	{
////		Run(EVENT);
////	}
////	else if (buttonPressedHelp == true)
////	{
////		Help(EVENT);
////	}
////	else if (buttonPressedExit == true)
////	{
////		
////
////		Cleaner();
////
////		SDL_Quit();
////	}
////}
//
//
////void Game::Help(SDL_Event EVENT)
////{
////	//SDL_Event EVENT;
////	SDL_Surface* menu = IMG_Load("help.png");//might need to change the name of this
////	texture = SDL_CreateTextureFromSurface(Renderer, menu);
////
////	SDL_RenderCopy(Renderer, texture, NULL, NULL);
////	
////	/*while (EVENT.type != SDL_MOUSEBUTTONDOWN)
////	{
////		SDL_RenderPresent(Renderer);
////	}*/
////	/*if (SDL_PollEvent(&EVENT)) {*/
////	if (SDL_PollEvent(&EVENT) != 0) {
////		SDL_RenderPresent(Renderer);
////		while (EVENT.type != SDL_MOUSEBUTTONDOWN)
////		{
////
////			cout << "j";
////		}
////	}
////	//SDL_RenderPresent(Renderer);
////	/*}*/
////}
//
//bool Game::Init()
//{
//	SDL_Init(SDL_INIT_VIDEO);
//
//	window = SDL_CreateWindow("Brick Breaker - CptS 122 PA9", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_X, WINDOW_Y, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
//
//	if (!window)
//	{
//		cout << "Error in creation of Window: " << SDL_GetError() << endl;
//		return false;
//	}
//
//	Renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
//
//	if (!Renderer)
//	{
//		cout << "Error in creation of Renderer: " << SDL_GetError() << endl;
//		return false;
//	}
//
//	return true;
//}
//
//void Game::Render(int level_num, double delta, Gamestate gamestate)
//{
//
//	SDL_RenderClear(Renderer);
//
//	
//	if (gamestate == PLAY) {
//		levels[level_num]->render(delta);
//		paddle->render();
//		ball->render(delta);
//	}if (gamestate == MENU) {
//		SDL_RenderCopy(Renderer, menuTexture, NULL, NULL);
//	}if (gamestate == HELP) {
//		SDL_RenderCopy(Renderer, texture, NULL, NULL);
//	}
//
//if (gamestate == EXIT) {
//	SDL_Quit();
//}
//	SDL_RenderPresent(Renderer);//RENDERS
//}
//
//
//void Game::ResetPaddle()
//{
//	Paddle_Stuck = true;
//	stickBall();
//}
//
//void Game::newGame(int level) {
//
//	
//
//		levels[num_Levels] = new Board();
//		switch (level)
//		{
//		case 0: levels[level]->fillBoard();
//			break;
//		case 1: levels[level]->fillDiamond();
//			break;
//		case 2:
//			levels[level]->fillBoardInceptSquare();
//			break;
//		case 3: levels[level]->fillSpiral();
//			break;
//		default:
//			SDL_Quit();
//			break;
//		}
//
//
//		ResetPaddle();
//	
//
//}
//
//void Game::stickBall()
//{
//	/*ball.setX(paddle.getX() + (paddle.getW() / 2) - (ball.getW() / 2));
//	ball.setY(paddle.getY() - ball.getH());*/
//
//	ball->setX(paddle->getX() + (paddle->getW() / 2 - ball->getW() / 2));
//	ball->setY(paddle->getY() - ball->getH());
//}
//
//int Game::Brick_Count(int Level_num)
//{
//	int Count = 0, i = 0, j = 0;
//
//	while (i < BOARD_WIDTH)
//	{
//		j = 0;
//		while (j < BOARD_HEIGHT)
//		{
//			if (levels[Level_num]->Game_Board[i][j].getStatus())
//				Count++;
//			j++;
//		}
//		i++;
//	}
//
//	return Count;
//}
//
//double Game::Reflect(double HIT)
//{
//	//checks if HIT is between the ends of the paddle
//	if (HIT < 0)
//		HIT = 0;
//
//	else if (HIT > paddle->getW())
//		HIT = paddle->getW();
//
//	HIT -= paddle->getW() / 2.0;//left of center, relfect to left,  right of center, reflect to right
//
//	return 2.0*(HIT / (paddle->getW() / 2.0));
//}
//
//void Game::PaddleCollision()
//{
//	double Ball_Center = ball->getX() + (ball->getW() / 2.0);
//
//	if (ball->COLLIDED(paddle) == true)//checks if ball colllides with paddle
//	{
//		ball->setY(paddle->getY() - ball->getH());
//		ball->setDirection(Reflect(Ball_Center - paddle->getX()), -1);
//
//	}
//
//}
//
//void Game::BoardCollision(int num)//checks if ball has hit the walls at all
//{
//	if (ball->getY() < levels[num]->getY())//top collision
//	{
//		ball->setY(levels[num]->getY());
//		ball->setY_Dir(-1); // X, Y direction,
//	}
//
//
//
//	else if (ball->getH() + ball->getY() > levels[num]->getH() + levels[num]->getY())//bottom collision
//		ResetPaddle(); //ball was missed by paddle
//
//	if (ball->getX() <= levels[num]->getX() + SIDE_WIDTH)//left collision
//	{
//		ball->setX(levels[num]->getX() + SIDE_WIDTH);
//		ball->SetX_Dir(-1);//flips x direction
//	}
//
//
//	else if (ball->getW() + ball->getX() >= (levels[num]->getW() + levels[num]->getX()) - SIDE_WIDTH) //right collision
//	{
//		ball->setX((levels[num]->getX() + levels[num]->getW() - SIDE_WIDTH) - ball->getW());
//		ball->SetX_Dir(-1);//flips x direction
//	}
//}
//
//void Game::BrickResponse(int index)
//{
//	//Left = 0, Top = 1, Right = 2, Bottom = 3
//	int Factor_X = 1, Factor_Y = 1;
//
//
//	if (ball->GetX_Dir() > 0)//positive X direction
//	{
//		if (ball->GetY_Dir() > 0)//positive Y direction
//		{
//			if (index == 0 || index == 3)
//				Factor_X = -1;
//			else
//				Factor_Y = -1;
//		}
//	}
//
//	else if (ball->GetX_Dir() < 0)//negative x direction
//	{
//		if (ball->getY() > 0)//positive y direction
//		{
//			if (index == 2 || index == 3)
//				Factor_X = -1;
//			else
//				Factor_Y = -1;
//		}
//
//		else if (ball->getY() < 0)
//
//			if (index == 1 || index == 2)
//				Factor_Y = -1;
//	}
//
//	ball->setDirection(Factor_X*ball->GetX_Dir(), Factor_Y * ball->GetY_Dir());
//
//}
//
//
//
//
//void Game::BrickCollision(int num)
//{
//	double BRICK_X = 0, BRICK_Y = 0, w = 0, h = 0, CHANGE_X = 0, CHANGE_Y = 0, W_Y = 0, H_X = 0;
//	int i = 0, j = 0;
//	Brick temp;
//
//	W_Y = CHANGE_Y * w;
//	H_X = CHANGE_X * h;
//
//	while (i < BOARD_WIDTH)
//	{
//		j = 0;
//		while (j < BOARD_HEIGHT)
//		{
//
//			temp = levels[num]->Game_Board[i][j];
//
//			if (temp.getStatus() == true)//if a brick exists, continue
//			{
//
//				BRICK_X = levels[num]->getX() + i*BRICK_WIDTH + levels[num]->getX_offset();
//				BRICK_Y = levels[num]->getY() + j*BRICK_HEIGHT + levels[num]->getY_offset();
//
//				w = .5 * (ball->getW() + BRICK_WIDTH);
//				h = .5 * (ball->getH() + BRICK_HEIGHT);
//
//				CHANGE_X = (ball->getX() + .5*ball->getW()) - (BRICK_X + .5*BRICK_WIDTH);
//
//				CHANGE_Y = (ball->getY() + .5*ball->getH()) - (BRICK_Y + .5*BRICK_HEIGHT);
//
//
//				if ((abs(CHANGE_X) <= w) && (abs(CHANGE_Y) <= h))
//				{
//					//there is a collision
//
//					levels[num_Levels]->Game_Board[i][j].setStatus(false);
//
//
//					if (W_Y > H_X)
//					{
//						if (W_Y > -H_X)
//							BrickResponse(3);//bottom
//						else
//							BrickResponse(0);//go left
//					}
//					else
//					{
//						if (W_Y > -H_X)
//							BrickResponse(2);//go right
//						else
//							BrickResponse(1);//TOP
//					}
//					return;//only handles one brick collision at a time
//
//				}
//
//
//			}
//
//			++j;
//		}
//
//		++i;
//	}
//
//}

#include "Game.h"



Game::Game()
{
	window = nullptr;
	Renderer = nullptr;
}

Game::~Game()
{
	Cleaner();
}

void Game::Cleaner()
{
	SDL_DestroyRenderer(Renderer);
	SDL_DestroyWindow(window);
}

void Game::Run()
{

	if (!(this->Init()))//if the game could not be intialized then return out of the run function
		return;
	init();
	//SDL_Event EVENT;


	double Delta = 0.0, CurrTick = 0.0, lastTick = 0.0;

	char BUFFER[100];
	Gamestate state = MENU;
	int mouseX = 0, mouseY = 0;




	SDL_RenderCopy(Renderer, texture, NULL, NULL);

	paddle = new Paddle();
	ball = new Ball();


	newGame(num_Levels);



	while (state != PLAY)
	{
		if (SDL_PollEvent(&EVENT))
			if (EVENT.type == SDL_QUIT)
				break;

		if (EVENT.type == SDL_MOUSEBUTTONDOWN)
		{

			SDL_GetMouseState(&mouseX, &mouseY);
			if (state != PLAY)
				state = getGameState(mouseX, mouseY, state);
		}


		Render(num_Levels, Delta, state);

	}

	EVENT.type = NULL;


	while (1)//main game loop
	{
		SDL_GetMouseState(&mouseX, &mouseY);
		if (SDL_PollEvent(&EVENT))
			if (EVENT.type == SDL_QUIT)
				break;

		lastTick = CurrTick;
		CurrTick = SDL_GetTicks();
		Delta = (CurrTick - lastTick) / 1000.0;



		cout << "LAST TICK: " << lastTick << "\tCURRENT TICK:  " << CurrTick << "\tDELTA: " << Delta << endl << endl;

		update(Delta, mouseX, mouseY);
		Render(num_Levels, Delta, state);

	}


	delete levels[num_Levels];
	delete paddle;
	delete ball;

	Cleaner();

	SDL_Quit();
}



void Game::update(double Delta, int Mouse_X, int Mouse_Y)
{

	setPaddleX(Mouse_X - paddle->getW() / 2);//paddle is matched with mouse, center it with mouse by offsetting with width

	if (EVENT.type == SDL_MOUSEBUTTONDOWN) //if button was pressed 
	{
		if (Paddle_Stuck == true)//launchs ball if we have it stuck to the paddle after a death or new level
		{
			Paddle_Stuck = false;
			ball->setDirection(1, -1);
		}

	}

	if (Paddle_Stuck == true)//if we want the ball to stick to the paddle, call function
		stickBall();

	BoardCollision(num_Levels);
	PaddleCollision();
	BrickCollision(num_Levels);


	BRICK_COUNT = Brick_Count(num_Levels);

	if (BRICK_COUNT == 0)//if the bricks have been cleared create new level
	{
		num_Levels = num_Levels + 1;
		newGame(num_Levels);

	}

	if (Paddle_Stuck == false)//update ball if it is not stuck to the paddle
		ball->update(Delta);


	levels[num_Levels]->update(Delta);//update current level
	paddle->update(Delta);//updates paddle

}

void Game::setPaddleX(double X_Value)
{
	if (X_Value < SIDE_WIDTH)//if mouse is to the left of the left Side border, then set paddle X to edge of border
		paddle->setX(SIDE_WIDTH);//sets position to zero

	else if (X_Value + PADDLE_WIDTH > WINDOW_X - SIDE_WIDTH)//mouse is at the far right of the screen
		paddle->setX(WINDOW_X - PADDLE_WIDTH - SIDE_WIDTH);//paddle width to left of the right bound

	else//mouse is in between the left and right bounds
		paddle->setX(X_Value);
}

bool Game::Init()
{
	SDL_Init(SDL_INIT_EVERYTHING);

	window = SDL_CreateWindow("Brick Breaker - CptS 122 PA9", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_X, WINDOW_Y, SDL_WINDOW_SHOWN);

	if (!window)
	{
		cout << "Error in creation of Window: " << SDL_GetError() << endl;
		return false;
	}

	Renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	if (!Renderer)
	{
		cout << "Error in creation of Renderer: " << SDL_GetError() << endl;
		return false;
	}

	/*
	Here we would intialize our texture and render it to a surface if we wanted a better background
	*/


	return true;
}

void Game::Render(int level_num, double delta, Gamestate gamestate)
{

	SDL_RenderClear(Renderer);


	if (gamestate == PLAY) {
		
		levels[level_num]->render(delta);
		paddle->render();
		ball->render(delta);
	}

	else if (gamestate == MENU)
		SDL_RenderCopy(Renderer, menuTexture, NULL, NULL);

	else  if (gamestate == HELP)
		SDL_RenderCopy(Renderer, texture, NULL, NULL);


	else if (gamestate == EXIT)
		SDL_Quit();

	SDL_RenderPresent(Renderer);//RENDERS
}



void Game::init() {
	playButton.setCoordinates(PlayTLX, PlayTLY, PlayBRX, PlayBRY);
	helpButton.setCoordinates(HelpTLX, HelpTLY, HelpBRX, HelpBRY);
	exitButton.setCoordinates(QuitTLX, QuitTLY, QuitBRX, QuitBRY);

	texture = IMG_LoadTexture(Renderer, "help.png");
	if (texture == NULL) {
		cout << IMG_GetError();
	}
	menuTexture = IMG_LoadTexture(Renderer, "menu.png");
	if (menuTexture == NULL) {
		cout << IMG_GetError();
	}
}


Gamestate Game::getGameState(int x, int y, Gamestate state) {
	if (state != EXIT) {
		if (helpButton.isPressed(x, y) && state != PLAY) {
			//state = HELP;
			return HELP;
			//SDL_Quit();
			//return EXIT;
		}
		if (playButton.isPressed(x, y) && state != PLAY) {
			return PLAY;
		}
		if (exitButton.isPressed(x, y) && state != PLAY) {
			//return ;
			//    SDL_Quit();
			return EXIT;
		}
		if (state == HELP && state != PLAY) {

			return  MENU;

		}
		else
		{
			return MENU;
		}
	}
}


void Game::ResetPaddle()
{
	Paddle_Stuck = true;
	stickBall();
}

void Game::newGame(int level) {

	levels[num_Levels] = new Board();
	switch (level)
	{
	case 0: levels[level]->fillBoard();
		break;
	case 1: levels[level]->fillDiamond();
		break;
	case 2:
		levels[level]->fillBoardInceptSquare();
		break;
	case 3: levels[level]->fillSpiral();
		break;
	default:
		SDL_Quit();
		break;
	}


	ResetPaddle();
}

void Game::stickBall()
{
	ball->setX(paddle->getX() + (paddle->getW() / 2) - (ball->getW() / 2));
	ball->setY(paddle->getY() - ball->getH());
}

int Game::Brick_Count(int Level_num)
{
	int Count = 0, i = 0, j = 0;

	while (i < BOARD_WIDTH)
	{
		j = 0;
		while (j < BOARD_HEIGHT)
		{
			if (levels[Level_num]->Game_Board[i][j].getStatus())
				Count++;
			j++;
		}
		i++;
	}

	return Count;
}

double Game::Reflect(double HIT)
{
	//checks if HIT is between the ends of the paddle
	if (HIT < 0)
		HIT = 0;

	else if (HIT > paddle->getW())
		HIT = paddle->getW();

	HIT -= paddle->getW() / 2.0;//left of center, relfect to left,  right of center, reflect to right

	return 2.0*(HIT / (paddle->getW() / 2.0));
}

void Game::PaddleCollision()
{
	double Ball_Center = ball->getX() + (ball->getW() / 2.0);

	if (ball->COLLIDED(paddle) == true)//checks if ball colllides with paddle
	{
		ball->setY(paddle->getY() - ball->getH());
		ball->setDirection(Reflect(Ball_Center - paddle->getX()), -1);

	}

}

void Game::BoardCollision(int num)//checks if ball has hit the walls at all
{
	if (ball->getY() < levels[num]->getY())//top collision
	{
		ball->setY(levels[num]->getY());
		ball->setY_Dir(-1); // X, Y direction,
	}



	else if (ball->getH() + ball->getY() > levels[num]->getH() + levels[num]->getY())//bottom collision
		ResetPaddle(); //ball was missed by paddle

	if (ball->getX() <= levels[num]->getX() + SIDE_WIDTH)//left collision
	{
		ball->setX(levels[num]->getX() + SIDE_WIDTH);
		ball->SetX_Dir(-1);//flips x direction
	}


	else if (ball->getW() + ball->getX() >= (levels[num]->getW() + levels[num]->getX()) - SIDE_WIDTH) //right collision
	{
		ball->setX((levels[num]->getX() + levels[num]->getW() - SIDE_WIDTH) - ball->getW());
		ball->SetX_Dir(-1);//flips x direction
	}
}

void Game::BrickResponse(int index)
{
	//Left = 0, Top = 1, Right = 2, Bottom = 3
	int Factor_X = 1, Factor_Y = 1;


	if (ball->GetX_Dir() > 0)//positive X direction
	{
		if (ball->GetY_Dir() > 0)//positive Y direction
		{
			if (index == 0 || index == 3)
				Factor_X = -1;
			else
				Factor_Y = -1;
		}
		else if (ball->GetY_Dir() < 0)//negative Y direction
		{
			if (index == 0 || index == 1)
				Factor_X = -1;
			else
				Factor_Y = -1;
		}
	}

	else if (ball->GetX_Dir() < 0)//negative x direction
	{
		if (ball->getY() > 0)//positive y direction
		{
			if (index == 2 || index == 3)
				Factor_X = -1;
			else
				Factor_Y = -1;
		}

		else if (ball->getY() < 0)//negative Y direction

			if (index == 1 || index == 2)
				Factor_X = -1;
			else
				Factor_Y = -1;
	}

	ball->setDirection(Factor_X*ball->GetX_Dir(), Factor_Y * ball->GetY_Dir());//sets direction of ball based upon direction factors deretermined by direction of ball

}





void Game::BrickCollision(int num)
{
	double BRICK_X = 0, BRICK_Y = 0, w = 0, h = 0, CHANGE_X = 0, CHANGE_Y = 0, W_Y = 0, H_X = 0;
	int i = 0, j = 0;
	Brick temp;

	W_Y = CHANGE_Y * w;
	H_X = CHANGE_X * h;

	while (i < BOARD_WIDTH)
	{
		j = 0;
		while (j < BOARD_HEIGHT)
		{

			temp = levels[num]->Game_Board[i][j];

			if (temp.getStatus() == true)//if a brick exists, continue
			{

				BRICK_X = levels[num]->getX() + i*BRICK_WIDTH + levels[num]->getX_offset();
				BRICK_Y = levels[num]->getY() + j*BRICK_HEIGHT + levels[num]->getY_offset();

				w = .5 * (ball->getW() + BRICK_WIDTH);
				h = .5 * (ball->getH() + BRICK_HEIGHT);

				CHANGE_X = (ball->getX() + .5*ball->getW()) - (BRICK_X + .5*BRICK_WIDTH);

				CHANGE_Y = (ball->getY() + .5*ball->getH()) - (BRICK_Y + .5*BRICK_HEIGHT);


				if ((abs(CHANGE_X) <= w) && (abs(CHANGE_Y) <= h))
				{
					//there is a collision

					levels[num_Levels]->Game_Board[i][j].setStatus(false);


					if (W_Y > H_X)
					{
						if (W_Y > -H_X)
							BrickResponse(3);//bottom
						else
							BrickResponse(0);//go left
					}
					else
					{
						if (W_Y > -H_X)
							BrickResponse(2);//go right
						else
							BrickResponse(1);//TOP
					}
					return;//only handles one brick collision at a time

				}


			}

			++j;
		}

		++i;
	}

}






