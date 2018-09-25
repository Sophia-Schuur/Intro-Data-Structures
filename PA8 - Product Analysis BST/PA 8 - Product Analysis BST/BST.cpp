#include "BST.h"

//default constructor
BST::BST()
{
	mpRoot = nullptr;
}

BST::~BST()
{
	//cout << "Destructor for BST" << endl;
	destroyTree();
}

//getter
Node * BST::getRoot()
{
	return mpRoot;
}

//setter
void BST::setRoot(Node * newRoot)
{
	mpRoot = newRoot;
}

//public insert
void BST::insert(string newString, int newUnits)
{
	insert(this->mpRoot, newString, newUnits);
}

//public destroy tree
void BST::destroyTree()
{
	destroyTree(this->mpRoot);
}

//public print in order
void BST::PrintInOrder()
{
	PrintInOrder(this->mpRoot);
}

//private findLargest()
TransactionNode & BST::findLargest()
{
	return findLargest(this->mpRoot);
}

//private findSmallest()
TransactionNode & BST::findSmallest()
{
	return findSmallest(this->mpRoot);
}

//private findlargest()
TransactionNode & BST::findLargest(Node * pTree)
{
	if (pTree->getRight() == nullptr)
	{
		return  dynamic_cast<TransactionNode &>(*pTree);
	}
	else
	{
		findLargest(pTree->getRight());
	}
}

//private findSmallest()
TransactionNode & BST::findSmallest(Node * pTree)
{
	if (pTree->getLeft() == nullptr)
	{
		return  dynamic_cast<TransactionNode &>(*pTree);
	}
	else
	{
		findLargest(pTree->getLeft());
	}
}

//private destroy tree
void BST::destroyTree(Node *& pTree)
{
	if (pTree != NULL)
	{
		destroyTree(pTree->getLeft());
		destroyTree(pTree->getRight());
		delete pTree;
	}
}

//private insert
void BST::insert(Node *& pTree, string newString, int newUnits)
{
	if (pTree == nullptr)
	{
		pTree = new TransactionNode(newString, newUnits);
	}
	else if (newUnits < dynamic_cast<TransactionNode *>(pTree)->getUnits())
	{
		insert(pTree->getLeft(), newString, newUnits);
	}
	else if (newUnits > dynamic_cast<TransactionNode *>(pTree)->getUnits())
	{
		insert(pTree->getRight(), newString, newUnits);
	}
	else
	{
		cout << "Duplicate!" << endl;
	}
}

//private print in order
void BST::PrintInOrder(Node *& pTree)
{
	if (pTree != nullptr)
	{
		PrintInOrder(pTree->getLeft());
		cout << "Product: " <<pTree->getData() << ", Units: " << dynamic_cast<TransactionNode *>(pTree)->getUnits() << pTree->getType() << endl;
		PrintInOrder(pTree->getRight());

	}
}

