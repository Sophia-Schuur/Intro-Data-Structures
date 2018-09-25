
#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <math.h>
#include <time.h>


extern SDL_Renderer *Renderer;

using std::cout;
using std::endl;


#define WINDOW_X 600
#define WINDOW_Y 600
#define DELAY 500
#define BOARD_WIDTH 8
#define BOARD_HEIGHT 10
#define BRICK_WIDTH 64
#define BRICK_HEIGHT 24

#define PADDLE_WIDTH 128
#define PADDLE_HEIGHT 32
#define PADDLE_Y 560
#define SIDE_WIDTH 16
#define SIDE_HEIGHT 600
#define SIDE_OFFSET 44
#define TOP_SPACE 16




#define PlayTLX 141
#define PlayTLY 155
#define PlayBRX 440
#define PlayBRY 250

#define HelpTLX 141
#define HelpTLY 292
#define HelpBRX 440
#define HelpBRY 376

#define QuitTLX 141
#define QuitTLY 430
#define QuitBRX 440
#define QuitBRY 509


const double Ball_Speed = 550;

typedef enum Gamestate {
	MENU, HELP, EXIT, PLAY, START
}Gamestate;