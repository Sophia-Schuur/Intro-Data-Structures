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
	
	//constructor with no arguments
	Node();



	//constructor
	Node(char newLetter, string newMorse);
	
	//copy constructor														
	Node(Node &copy);

	//destructor
	~Node();
	
	//getters
	char getLetter(); 
	string getMorse();
	Node *& getLeft();
	Node *& getRight();

	//setters
	void setLetter(char newLetter);
	void setMorse(string newMorse);
	void setLeft(Node * newLeft);
	void setRight(Node * newRight);



private:
	char mLetter;
	string mMorse;

	Node *mpLeft;
	Node *mpRight;
};