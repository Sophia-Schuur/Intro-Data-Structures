#pragma once

#include <iostream>
#include <fstream>
#include <string>

//#include "ListNode.h"



using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::fstream;
using std::string;
using std::ios;
using std::istream;

class Stack
{
public:
	Stack();
	//~Stack();

	void push1(string &newDate);
	void pop1();
	string peek1();
	void printStack1();

	int getSize1();

private:
	int mTop;
	string list[100];


};