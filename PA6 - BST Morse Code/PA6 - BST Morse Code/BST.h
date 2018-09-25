#pragma once

#include <iostream>
#include <fstream>
#include <string>

#include "BSTNode.h"

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::fstream;
using std::string;
using std::ios;
using std::istream;

class BST
{
public:
	//constructor
	BST();

	//destructor
	~BST();

	//public destroy tree. used in destructor
	void Destroy_BST();

	//getter for root
	Node *getRoot();

	//setter for root
	void setRoot(Node * newRoot);

	//public insert
	void BST::insert(char letter, string morse);
	
	//public print tree in order
	void PrintInOrder();

	//public transate
	void search();

	//public get the phrase from the convert.txt file
	string BST::getPhrase();


private:
	Node *mpRoot;
	
	//acutal function for destorying the bst
	void Destroy_BST(Node *& pTree);

	//actual function for inserting nodes into tree
	void insert(Node *& pTree, char letter, string morse);

	//actual function for printing the tree in order of ascii values
	void PrintInOrder(Node *& pTree);

	//actual function for converting from english to morse
	void search(Node * pTree);
};

//overloaded operator for reading in MorseTable.txt correctly
ifstream & operator >> (ifstream &infile, Node &Node);