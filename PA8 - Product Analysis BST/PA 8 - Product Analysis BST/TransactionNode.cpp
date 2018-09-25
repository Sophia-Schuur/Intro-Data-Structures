#include "TransactionNode.h"

TransactionNode::TransactionNode()
{
	mUnits = 0;
	mData = "";
	mpLeft = nullptr;
	mpRight = nullptr;
}

TransactionNode::TransactionNode(string newData, int newUnits)
{
	mUnits = newUnits;
	mData = newData;
	mpLeft = nullptr;
	mpRight = nullptr;
}

TransactionNode::~TransactionNode()
{
	//cout << "TransactionNode destructor" << endl;
}

int TransactionNode::getUnits()
{
	return mUnits;
}

void TransactionNode::setUnits(int newUnits)
{
	mUnits = newUnits;
}

void TransactionNode::printUnits()
{
	cout << getUnits();
}
