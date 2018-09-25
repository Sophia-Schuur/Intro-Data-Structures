#pragma once
#include "Brick.h"
#include "Shape.h"

class Board : public Shape
{
public:
    Board();
    ~Board();

    void update(double);
    void render(double);
    
    void fillBoard();
    void fillDiamond();
    void fillBoardInceptSquare();
    void fillSpiral();
    
    double getX_offset(void);
    double getY_offset(void);

    Brick Game_Board[BOARD_WIDTH][BOARD_HEIGHT];// global constants for the sizes of the array, this lets us change the amount of tiles later on

private:
    double X_Offset, Y_Offset;
    SDL_Texture* brick;
    SDL_Texture* side;
};





