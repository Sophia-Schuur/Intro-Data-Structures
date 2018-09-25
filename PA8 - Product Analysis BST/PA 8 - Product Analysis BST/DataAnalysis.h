#pragma once

#include <iostream>
#include <fstream>
#include <string>

//#include "Node.h"
//#include "TransactionNode.h"
#include "BST.h"

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::fstream;
using std::string;
using std::ios;

class DataAnalysis
{
public:

	void runAnalysis();
	

private:
	BST mTreeSold;
	BST mTreePurchased;
	ifstream mCsvStream;

	void openFile();
	void readLine();
	void printProductstoScreen();
};

ifstream & operator >> (ifstream & infile, TransactionNode & Node);