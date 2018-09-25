#include "DataAnalysis.h"

//public runAnalysis()
void DataAnalysis::runAnalysis()
{
	int i = 0;
	openFile();
	TransactionNode node;
	
	while (i < 14)
	{
		mCsvStream >> node;
		if (node.getType() == "Purchased")
		{
			mTreePurchased.insert(node.getData(), node.getUnits());
		}
		if (node.getType() == "Sold")
		{
			mTreeSold.insert(node.getData(), node.getUnits());
		}
			i++;
	}
	//print out each separate, ordered BST
	cout << "Sold BST:" << endl << endl;
	mTreeSold.PrintInOrder();
	cout << endl << endl << "Purchased BST:" << endl << endl;
	mTreePurchased.PrintInOrder();
	cout << endl << endl;

	printProductstoScreen();
	
}

//private printProductstoScreen()
void DataAnalysis::printProductstoScreen()
{
	//find the most sold and least sold products and print them to screen
	TransactionNode mostSold = mTreeSold.findLargest();
	TransactionNode leastSold = mTreeSold.findSmallest();
	cout << "Most Sold Product: " << mostSold.getData() << " with " << mostSold.getUnits() << " units " << endl;
	cout << "Least Sold Product: " << leastSold.getData() << " with " << leastSold.getUnits() << " units " << endl << endl;

	TransactionNode mostPurchased = mTreePurchased.findLargest();
	TransactionNode leastPurchased = mTreePurchased.findSmallest();
	cout << "Most Purchased Product: " << mostPurchased.getData() << " with " << mostPurchased.getUnits() << " units " << endl;
	cout << "Least Purchased Product: " << leastPurchased.getData() << " with " << leastPurchased.getUnits() << " units " << endl << endl;
}


//private openfile()
void DataAnalysis::openFile()
{
	mCsvStream.open("data.txt");

}

//private readline()
void DataAnalysis::readLine()
{
	openFile();
	TransactionNode node;
	mCsvStream >> node;


}

ifstream & operator >> (ifstream & infile, TransactionNode & Node)
{
	string units;
	string item, type;
	int newUnits;

	getline(infile, units, ',');
	newUnits = atoi(units.c_str());

	getline(infile, item, ',');
	getline(infile, type);

	Node.setUnits(newUnits);
	Node.setData(item);
	Node.setType(type);

	return infile;
}
