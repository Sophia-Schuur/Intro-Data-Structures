#include "BST.h"
//#include "BSTNode.h"


//CONSTRUCTOR -
//THIS FUNCTION INTIALIZES ENTIRE TREE, PRINTS THE TREE IN ORDER OF INCREASING ASCII VALUE, 
//PERFORMS THE CONVERSION FROM MORSE TO ENGLISH AND CLOSES THE INFILE.
BST::BST()
{
	mpRoot = nullptr;
	Node node;
	ifstream Infile;
	Infile.open("MorseTable.txt");
	string line;

	//Open file and read lines into objects
	int i = 0;
	while (i <39)
	{
		Infile >> node;
		insert(node.getLetter(), node.getMorse());
		i++;
	}
	cout << "BST tree in order of ascii value :" << endl;
	PrintInOrder();
	
	search();
	Infile.close();

}


//DESTRUCTOR
BST::~BST()
{
	Destroy_BST();
}

//PRIVATE DESTROY TREE
void BST::Destroy_BST(Node *& pTree)
{
	if (pTree != NULL)
	{
		Destroy_BST(pTree->getLeft());
		Destroy_BST(pTree->getRight());
		delete pTree;
	}
}

//PUBLIC DESTORY TREE
void BST::Destroy_BST()
{
	Destroy_BST(this->mpRoot);
}

//PUBLIC INSERT FUNCTION
void BST::insert(char letter, string morse)
{
	// call private insert ()
	insert(this->mpRoot, letter, morse);
}

//PRIVATE INSERT FUNCTION
void BST::insert(Node *& pTree, char letter, string morse)
{
	if (pTree == nullptr) // base case - we found spot in tree to insert
	{
		pTree = new Node(letter, morse);
	}
	else if (letter < pTree->getLetter())
	{
		insert(pTree->getLeft(), letter, morse);
	}
	else if (letter > pTree->getLetter())
	{
		insert(pTree->getRight(), letter, morse);
	}
	else
	{
		cout << "duplicate?" << endl;
	}
}

//GETTER FOR BST ROOT
Node * BST::getRoot()
{
	return mpRoot;
}

//SETTER FOR BST ROOT
void BST::setRoot(Node * newRoot)
{
	mpRoot = newRoot;
}

//PUBLIC. PRINTS TREE IN ORDER OF ASCII VALUE
void BST::PrintInOrder()
{
	PrintInOrder(this->mpRoot);
}

//PRIVATE. PRINTS TREE IN ORDER OF ASCII VALUE
void BST::PrintInOrder(Node *& pTree)
{
	
	if (pTree != nullptr)
	{
		PrintInOrder(pTree->getLeft());
		cout << pTree->getLetter() << endl;
		PrintInOrder(pTree->getRight());

	}
}

//PRIVATE. SEARCHES THRU TREE AND TRANSLATES ENGLISH LETTER TO MORSE LETTER.
void BST::search(Node * root)
{
	string newPhrase = getPhrase();
	int index = 0;
	Node * pCur = root;

	cout << endl << "Translated phrase: " << endl;
	while (pCur != NULL)
	{
		
		if (pCur->getLetter() == newPhrase[index])
		{
			cout << pCur->getMorse() << " ";
			index++;
			pCur = root;
		}
		else if (newPhrase[index] == ' ')
		{
			cout << "   ";
			index++;
			pCur = root;
		}
		else if (newPhrase[index] == '\n')
		{
			cout << endl;
			index++;
			pCur = root;
		}
		else if (pCur->getLetter() < newPhrase[index])
		{
			pCur = pCur->getRight();
		}
		else
		{
			pCur = pCur->getLeft();
		}
		
	}
	
}


//OPENS CONVERT.TXT AND GRABS LINES. PUTS LINES INTO ONE PHRASE FOR SIMPLER TRANSLATING.
string BST::getPhrase()
{
	ifstream Infile;
	Infile.open("Convert.txt");
	string phrase, newPhrase, NEWPhrase, end;

	cout << endl << "Phrase to be translated into morse: " << endl;
	while (!Infile.eof())
	{
		getline(Infile, phrase);
		cout << phrase << endl;
		newPhrase = newPhrase + phrase + "\n";
	}
	//cout << newPhrase;
	NEWPhrase = newPhrase;
	int index = 0;
	int size = newPhrase.size();
	while (index < size)
	{
		NEWPhrase[index] = toupper(newPhrase[index]);
		index++;
	}
	return NEWPhrase;
}

//PUBLIC. SEARCHES THRU TREE AND TRANSLATES ENGLISH LETTER TO MORSE LETTER.
void BST::search()
{
	search(this->mpRoot/*, this->getPhrase()*/);
}

//overloaded operator for reading in MorseTable.txt correctly
ifstream & operator >> (ifstream &infile, Node &Node)
{
	char letter;
	string first, morse, end;

	//infile.get(letter);
	//getline(infile, end);
	getline(infile, first);
	letter = first[0];
	getline(infile, morse);
	getline(infile, end);
	

	Node.setLetter(letter);
	Node.setMorse(morse);
	

	return infile;

}

	
