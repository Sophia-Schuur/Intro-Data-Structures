class Button {
public:
	Button();
	//~Button();
	
	bool isPressed(int x, int y);
	void setCoordinates(int topLeftX, int topLeftY, int bottomRightX, int bottomRightY);
private:
	int topLeftX, topLeftY, bottomRightX, bottomRightY;
	bool isButtonPressed;
};