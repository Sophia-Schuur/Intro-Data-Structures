#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

#include "ListNode.h"
#include "Stack.h"


using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::fstream;
using std::string;
using std::ios;
using std::istream;

#define IMPORT 1
#define LOADMASTER 2
#define STOREMASTER 3
#define MARKABSENCES 4
#define GENERATEREPORT 5
#define EXIT 6

class List
{
public:

	//constructor
	List();

	//destructor
	~List();

	void InsertFront(int RecNum, int ID, string FirstName, string LastName, string Email, string Credits, string Major, string Level);

	//void InsertFront(ListNode);
	void PrintList();
	void LoadList();
	void StoreList(ofstream &outfile);
	void MarkAbsences();
	void GenerateRecent();
	void GenerateMatch();



private:
	ListNode *mpRoot;
};

ifstream & operator >> (ifstream &infile, ListNode &Node);
void printMenu();
void printSubMenu();