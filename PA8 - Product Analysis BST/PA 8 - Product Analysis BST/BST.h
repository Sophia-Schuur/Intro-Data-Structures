#pragma once

#include <iostream>
#include <fstream>
#include <string>

#include "Node.h"
#include "TransactionNode.h"

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::fstream;
using std::string;
using std::ios;

class BST
{
public:
	//default constructor
	BST();

	//destructor - calls destroyTree()
	~BST();

	

	//getter for root
	Node *getRoot();

	//setter for root
	void setRoot(Node * newRoot);

	//public insert() - calls private insert()
	void BST::insert(string newString, int newUnits);

	//public destroyTree() - calls private destroyTree()
	void destroyTree();

	//public printInOrder() - calls private printInOrder()
	void PrintInOrder();

	//public findLargest() - calls private findLargest()
	TransactionNode & findLargest();

	//public findSmallest() - calls private findSmallest()
	TransactionNode & findSmallest();

private:
	Node *mpRoot;

	//acutal function for destorying the bst
	void destroyTree(Node *& pTree);

	//actual function for inserting nodes into tree
	void insert(Node *& pTree, string newString, int newUnits);

	//actual function for printing the tree in order
	void PrintInOrder(Node *& pTree);

	//private findLargest
	TransactionNode & findLargest(Node * pTree);

	//private findSmallest()
	TransactionNode & findSmallest(Node * pTree);
};