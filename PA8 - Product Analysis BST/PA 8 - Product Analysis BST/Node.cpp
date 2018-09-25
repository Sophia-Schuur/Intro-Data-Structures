#include "Node.h"


Node::Node()
{
	mData = "";

	mpLeft = nullptr;
	mpRight = nullptr;
}

Node::Node(string newData)
{
	mData = newData;

	mpLeft = nullptr;
	mpRight = nullptr;
}

Node::~Node()
{
	//cout << "Deleteing Node" << endl;
}

string Node::getData()
{
	return mData;
}

Node *& Node::getLeft()
{
	return mpLeft;
}
Node *& Node::getRight()
{
	return mpRight;
}

string Node::getType()
{
	return mType;
}

void Node::setData(string newData)
{
	mData = newData;
}

void Node::setLeft(Node * const newLeft)
{
	mpLeft = newLeft;
}
void Node::setRight(Node * const newRight)
{
	mpRight = newRight;
}

void Node::setType(string newType)
{
	mType = newType;
}

void Node::printData()
{
	cout << getData();
}
