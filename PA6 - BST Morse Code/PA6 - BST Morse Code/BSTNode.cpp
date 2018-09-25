#include "BSTNode.h"


Node::Node()
{
	this->mLetter = NULL;
	this->mMorse = "";

	mpLeft = nullptr;
	mpRight = nullptr;
}






//ARGUMENT CONSTRUCTOR
Node::Node(char newLetter, string newMorse)
{
	//this->mLetter = NULL;
	mLetter = newLetter;
	mMorse = newMorse;
	//this->mMorse = "";

	mpLeft = nullptr;
	mpRight = nullptr;
}

//COPY CONSTRUCTOR
Node::Node(Node &copy)
{
	setLetter(copy.getLetter());
	setMorse(copy.getMorse());
	setLeft(copy.getLeft());
	setRight(copy.getRight());
}



//DESTRUCTOR
Node::~Node()
{
	
}


//SETTERS
char Node::getLetter()
{
	return mLetter;
}

string Node::getMorse()
{
	return mMorse;
}

Node *& Node::getLeft()
{
	return mpLeft;
}
Node *& Node::getRight()
{
	return mpRight;
}

//GETTERS
void Node::setLetter(char newLetter)
{
	mLetter = newLetter;
}

void Node::setMorse(string newMorse)
{
	mMorse = newMorse;
}

void Node::setLeft(Node * const newLeft)
{
	mpLeft = newLeft;
}
void Node::setRight(Node * const newRight)
{
	mpRight = newRight;
}
