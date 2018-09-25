#pragma once

#include <iostream>
#include <fstream>
#include <string>

#include "Node.h"

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::fstream;
using std::string;
using std::ios;

class TransactionNode:public Node
{
public:
	//default constructor 
	TransactionNode();

	//argument constructor
	TransactionNode(string newData, int newUnits);

	//desctructor
	~TransactionNode();

	//getter
	int getUnits();

	//setter
	void setUnits(int newUnits);

	void printUnits();




private:
	int mUnits;
};