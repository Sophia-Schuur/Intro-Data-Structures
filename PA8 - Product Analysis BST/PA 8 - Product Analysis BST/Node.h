#pragma once

#include <iostream>
#include <fstream>
#include <string>


using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::fstream;
using std::string;
using std::ios;

class Node
{
public:
	//default constructor 
	Node();

	// argument constructor
	Node(string newData);

	//virtual destructor
	virtual ~Node();

	//getters
	string getData();
	Node *& getLeft();
	Node *& getRight();
	string getType();

	//setters
	void setData(string newData);
	void setLeft(Node * newLeft);
	void setRight(Node * newRight);
	void setType(string newType);
	

	//print data()

	void printData();



protected:
	string mData;
	string mType;
	Node * mpLeft;
	Node * mpRight;
};


