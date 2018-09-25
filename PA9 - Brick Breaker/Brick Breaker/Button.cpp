#include "Button.h"
Button::Button() {
	this->topLeftX = 0;
	this->topLeftY = 0;
	this->bottomRightX = 0;
	this->bottomRightY = 0;
	this->isButtonPressed = false;
}
void Button::setCoordinates(int topLeftX, int topLeftY, int bottomRightX, int bottomRightY) {
	this->topLeftX = topLeftX;
	this->topLeftY = topLeftY;
	this->bottomRightX = bottomRightX;
	this->bottomRightY = bottomRightY;
}
bool Button::isPressed(int x, int y) {
	if (x >= topLeftX && x <= bottomRightX) 
	{
		if (y >= topLeftY && y <= bottomRightY) 
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}

}