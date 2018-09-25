#include "Brick.h"

////////////////BRICK//////////////
Brick::Brick()
{
	Status = true;
	color = 2;
}


void Brick::setStatus(bool temp)
{
	Status = temp;
}
void Brick::setColor(int temp)
{
	color = temp;
}


void Brick::setDiff(int diff)
{
	Difficulty = diff;
}


bool Brick::getStatus(void)
{
	return Status;
}

int Brick::getColor(void)
{
	return color;
}


