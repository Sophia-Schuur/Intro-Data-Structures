#include "Board.h"

Board::Board() : Shape()
{
	if (Renderer)
	{
		SDL_Surface* surface = nullptr;

		surface = IMG_Load("bricks.png");//might need to change file name
		brick = SDL_CreateTextureFromSurface(Renderer, surface);
		SDL_FreeSurface(surface);
		if (brick == nullptr)
			std::cout << IMG_GetError() << std::endl;


		surface = IMG_Load("side.png");//file name
		side = SDL_CreateTextureFromSurface(Renderer, surface);
		SDL_FreeSurface(surface);
		if (side == nullptr)
			std::cout << IMG_GetError() << std::endl;




		W = WINDOW_X;
		H = WINDOW_Y;

		X_Offset = SIDE_OFFSET; //SIDE_WIDTH;
		Y_Offset = TOP_SPACE;
	}
}

Board::~Board()
{
	SDL_DestroyTexture(side);
	SDL_DestroyTexture(brick);
}

void Board::update(double delta)
{
}

void Board::render(double delta)
{
	int i = 0, j = 0;
	SDL_Rect sRect, dRect;


	while (i < BOARD_WIDTH)
	{
		j = 0;
		while (j < BOARD_HEIGHT)
		{
			Brick curr = Game_Board[i][j];

			if (curr.getStatus() == true)//checks if the brick is empty, if full render brick
			{
				sRect.x = (curr.getColor() % 2) * BRICK_WIDTH;
				sRect.y = (curr.getColor() / 2) * BRICK_HEIGHT;
				sRect.w = BRICK_WIDTH;
				sRect.h = BRICK_HEIGHT;

				dRect.x = X_Offset + X + i * BRICK_WIDTH;//BOARD_WIDTH;
				dRect.y = Y_Offset + Y + j * BRICK_HEIGHT;
				dRect.w = BRICK_WIDTH;
				dRect.h = BRICK_HEIGHT;

				SDL_RenderCopy(Renderer, brick, &sRect, &dRect);

			}

			++j;
		}
		++i;
	}

	//these values never change
	//sides
	dRect.x = 0;
	dRect.y = 0;
	dRect.w = SIDE_WIDTH;
	dRect.h = SIDE_HEIGHT;
	SDL_RenderCopy(Renderer, side, NULL, &dRect);

	dRect.x = SIDE_HEIGHT - SIDE_WIDTH;
	dRect.y = 0;
	dRect.w = SIDE_WIDTH;
	dRect.h = SIDE_HEIGHT;
	SDL_RenderCopy(Renderer, side, NULL, &dRect);



}

void Board::fillBoard()//fill board with full rectangle
{
	int i = 0, j = 0, count = 0;
	srand(time(0));

	while (i < BOARD_WIDTH)
	{
		j = 0;
		while (j < BOARD_HEIGHT)
		{
			Brick temp;

			temp.setColor(rand() % 4);
			temp.setStatus(true);


			temp.setDiff((rand() % 3) + 1);
			Game_Board[i][j] = temp;
			j++;
		}
		i++;
	}
}

void Board::fillDiamond()
{
	srand(time(0));

	Game_Board[0][0].setStatus(false);
	Game_Board[0][1].setStatus(false);
	Game_Board[1][0].setStatus(false);

	Game_Board[7][0].setStatus(false);
	Game_Board[6][0].setStatus(false);
	Game_Board[7][1].setStatus(false);

	Game_Board[0][9].setStatus(false);
	Game_Board[1][9].setStatus(false);
	Game_Board[0][8].setStatus(false);

	Game_Board[7][9].setStatus(false);
	Game_Board[7][8].setStatus(false);
	Game_Board[6][9].setStatus(false);

	Game_Board[3][4].setStatus(false);
	Game_Board[3][5].setStatus(false);
	Game_Board[4][4].setStatus(false);
	Game_Board[4][5].setStatus(false);


	for (int i = 0; i < BOARD_WIDTH; i++) {
		for (int j = 0; j < BOARD_HEIGHT; j++) {

			if (Game_Board[i][j].getStatus() == true)
			{
				Game_Board[i][j].setColor(rand() % 4);
				Game_Board[i][j].setStatus(true);
				Game_Board[i][j].setDiff((rand() % 3) + 1);
			}
		}
	}


}


void Board::fillSpiral()
{
	int i = 0, j = 0, count = 0;
	srand(time(0));

	while (i < BOARD_WIDTH)
	{
		j = 0;
		while (j < BOARD_HEIGHT)
		{
			Brick temp;

			temp.setColor(rand() % 4);


			temp.setStatus(true);


			temp.setDiff((rand() % 3) + 1);
			Game_Board[i][j] = temp;
			j++;


			count++;
		}
		i++;
	}

	Game_Board[7][2].setStatus(false);
	Game_Board[6][2].setStatus(false);
	Game_Board[5][2].setStatus(false);
	Game_Board[4][2].setStatus(false);
	Game_Board[3][2].setStatus(false);
	Game_Board[2][2].setStatus(false);

	Game_Board[7][3].setStatus(false);
	Game_Board[6][3].setStatus(false);
	Game_Board[5][3].setStatus(false);
	Game_Board[4][3].setStatus(false);
	Game_Board[3][3].setStatus(false);
	Game_Board[2][3].setStatus(false);

	Game_Board[0][6].setStatus(false);
	Game_Board[1][6].setStatus(false);
	Game_Board[2][6].setStatus(false);
	Game_Board[3][6].setStatus(false);
	Game_Board[4][6].setStatus(false);
	Game_Board[5][6].setStatus(false);

	Game_Board[0][7].setStatus(false);
	Game_Board[1][7].setStatus(false);
	Game_Board[2][7].setStatus(false);
	Game_Board[3][7].setStatus(false);
	Game_Board[4][7].setStatus(false);
	Game_Board[5][7].setStatus(false);
}


void Board::fillBoardInceptSquare()
{
	srand(time(0));
	int i = 1;
	while (i < 9)
	{
		Game_Board[1][i].setStatus(false);
		i++;
	}

	i = 1;
	while (i < 7)
	{
		Game_Board[i][8].setStatus(false);
		i++;
	}

	i = 1;
	while (i < 8)
	{
		Game_Board[6][i].setStatus(false);
		i++;
	}

	i = 1;
	while (i < 7)
	{
		Game_Board[i][1].setStatus(false);
		i++;
	}

	Game_Board[3][4].setStatus(false);
	Game_Board[3][5].setStatus(false);
	Game_Board[4][4].setStatus(false);
	Game_Board[4][5].setStatus(false);

	for (int i = 0; i < BOARD_WIDTH; i++) {
		for (int j = 0; j < BOARD_HEIGHT; j++) {

			if (Game_Board[i][j].getStatus() == true)
			{
				Game_Board[i][j].setColor(rand() % 4);
				Game_Board[i][j].setStatus(true);
				Game_Board[i][j].setDiff((rand() % 3) + 1);
			}
		}
	}
}


double Board::getX_offset(void)
{
	return X_Offset;
}

double Board::getY_offset(void)
{
	return Y_Offset;
}


