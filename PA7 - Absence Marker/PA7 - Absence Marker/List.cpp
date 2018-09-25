#include "List.h"
#include "ListNode.h"
#include "Stack.h"

//constructor
List::List()
{
	mpRoot = NULL;
}

//destructor
List::~List()
{
	ListNode *pCur = mpRoot;
	while (pCur != NULL)
	{
		mpRoot = mpRoot->getNext();
		delete pCur;
		pCur = mpRoot;
	}
	cout << "Linked list deleted." << endl;
	mpRoot = NULL;
}

void List::InsertFront(int RecNum, int ID, string FirstName, string LastName, string Email, string Credits, string Major, string Level)
{
	if (mpRoot == NULL)
	{
		mpRoot = new ListNode(RecNum, ID, FirstName, LastName, Email, Credits, Major, Level);
	}
	else
	{
		ListNode *node = new ListNode(RecNum, ID, FirstName, LastName, Email, Credits, Major, Level);
		node->getNext() = mpRoot;
		mpRoot = node;
	}
}

void List::PrintList()
{
	ListNode *pCur = mpRoot;

	if (mpRoot == NULL) 
	{
		cout << "The list is empty" << endl;
		return;
	}

	while (pCur != NULL) 
	{ 
		cout << pCur->getRecNum() << ", ";
		cout << pCur->getID() << ", ";
		cout << pCur->getFirstName() << ", ";
		cout << pCur->getLastName() << ", ";
		cout << pCur->getEmail() << ", ";
		cout << pCur->getCredits() << ", ";
		cout << pCur->getMajor() << ", ";
		cout << pCur->getLevel() << endl;
		
		pCur = pCur->getNext();
	}
	cout << endl;
}

//load list from classList.txt
void List::LoadList()
{
	ListNode node;
	ifstream Infile;
	Infile.open("classList.txt");
	int i = 0;
	while (i < 10)
	{
		Infile >> node;
		InsertFront(node.getRecNum(), node.getID(), node.getFirstName(), node.getLastName(), node.getEmail(), node.getCredits(), node.getMajor(), node.getLevel());
		i++;
	}
	Infile.close();
	
}

//store list to master.txt
void List::StoreList(ofstream &outfile)
{
	ListNode *Node = mpRoot;
	int i = 0;
	while (Node != NULL)
	{
		outfile << Node->getRecNum() << ", " << Node->getID() << ", " << Node->getFirstName() << ", " << Node->getLastName() << ", " << Node->getEmail() << ", " << Node->getCredits() << ", " << Node->getMajor() << ", " << Node->getLevel() << endl;

		Node = Node->getNext();
	}

}

void List::MarkAbsences()
{
	ListNode *pCur = mpRoot;
	char wasAbsent = '\0';
	string noabsences = "NO ABSENCES";
	cout << "Student names:" << endl << endl;
	
	//print off names
	while (pCur != NULL)
	{
		
		cout << pCur->getFirstName() << ", ";
		cout << pCur->getLastName() <<  endl;

		pCur = pCur->getNext();
	}
	cout << endl;
	pCur = mpRoot;


	//get current date
	time_t t = time(0);  
	struct tm * now = localtime(&t);

	cout << "Current Date: " << (now->tm_year + 1900) << '-' << (now->tm_mon + 1) << '-' << now->tm_mday << endl;
	
	string newYear = std::to_string((now->tm_year + 1900));
	string newMonth = std::to_string((now->tm_mon + 1));
	string newDay = std::to_string(now->tm_mday);
	
	//put all the separate dates into one easy string
	string date = newYear + '-' + newMonth + '-' + newDay;
	
	//ask for absence of each student
	while (pCur != NULL)
	{
		cout << "Was ";
		cout << pCur->getFirstName() << ", ";
		cout << pCur->getLastName() << " absent today?" << endl;
		cout << "Enter y for yes and n for no." << endl;

		cin >> wasAbsent;

		//iff absent, push the date onto the stack
		if (wasAbsent == 'y')
		{
			pCur->push(date);
			pCur->IncreaseNumAbsences();
		}

		//if not, push the phrase "no absences" onto the stack
		else
		{
			pCur->push(noabsences);
		}

		cout << endl;
		pCur = pCur->getNext();
	}
	


}

void List::GenerateRecent()
{
	ListNode *pCur = mpRoot;
	ofstream outfile;
	outfile.open("RecentAbsence.txt");

	outfile << "Most recent Absence date for each student:" << endl << endl;
	while (pCur != NULL)
	{
		outfile << pCur->getFirstName() << ", " << pCur->getLastName() << ": " << pCur->peek() << endl;
		pCur = pCur->getNext();
	}
	outfile.close();
}

void List::GenerateMatch()
{
	ListNode *pCur = mpRoot;
	ofstream outfile;
	outfile.open("MatchAbsence.txt");
	int matchNum = 0;
	cout << "Enter a number of absences a student either matches or exceeds to write to file. " << endl;
	cin >> matchNum;
	while (pCur != NULL)
	{
		if (pCur->getNumAbsences() == matchNum)
		{
			outfile << pCur->getFirstName() << ", " << pCur->getLastName() << ": " << pCur->getNumAbsences() << endl;
			
		}
		pCur = pCur->getNext();
	}
	outfile.close();
}

ifstream & operator >> (ifstream & infile, ListNode & Node)
{
	string RecNum, ID;
	string FirstName, LastName, Name, Email, Credits, Major, Level;
	int newRecNum, newID, newCredits;

	getline(infile, RecNum, ',');
	newRecNum = atoi(RecNum.c_str());
	getline(infile, ID, ',');
	newID = atoi(ID.c_str());

	getline(infile, FirstName, ',');
	getline(infile, LastName, ',');
	getline(infile, Email, ',');
	getline(infile, Credits, ',');
	getline(infile, Major, ',');
	getline(infile, Level);


	Node.setRecNum(newRecNum);
	Node.setID(newID);
	Node.setFirstName(FirstName);
	Node.setLastName(LastName);
	Node.setEmail(Email);
	Node.setCredits(Credits);
	Node.setMajor(Major);
	Node.setLevel(Level);

	return infile;

}

ofstream & operator << (ofstream &outfile, ListNode & Node)
{
	outfile << Node.getRecNum() << ", " << Node.getID() << ", " << Node.getFirstName() << ", " << Node.getLastName() << ", " << Node.getEmail() << ", " << Node.getCredits() << ", " << Node.getMajor() << ", " << Node.getLevel() << endl;

	return outfile;
}

void printMenu()
{
	cout << "1.    Import course list" << endl;

	cout << "2.    Load master list" << endl;

		cout << "3.    Store master list" << endl;

		cout << "4.    Mark absences" << endl;

		cout << "5.    Generate report" << endl;

		cout << "6.    Exit" << endl;
}

void printSubMenu()
{
	cout << "1.    Generate most recent absence for each student" << endl;
	cout << "2.    Generate report for student that match or exceed entered number of absences" << endl;
}