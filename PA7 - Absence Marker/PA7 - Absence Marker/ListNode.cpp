#include "ListNode.h"

//ZERO ARGUMENT CONSTRUCTOR
ListNode::ListNode()
{
	this->mRecNum = 0;
	this->mID = 0;
	this->mFirstName = "";
	this->mLastName = "";
	this->mEmail = "";
	this->mCredits = "";
	this->mMajor = "";
	this->mLevel = "";
	this->mNumAbsences = 0;
	//THIS STACK??
	pNext = nullptr;
}


//ARGUMENT CONSTRUCTOR
ListNode::ListNode(int RecNum, int ID, string FirstName, string LastName, string Email, string Credits, string Major, string Level)
{
	mRecNum = RecNum;
	mID = ID;
	mFirstName = FirstName;
	mLastName = LastName;
	mEmail = Email;
	mCredits = Credits;
	mMajor = Major;
	mLevel = Level;

	this->mNumAbsences = 0;
	//THIS STACK??
	pNext = nullptr;
}

//COPY CONSTRUCTOR
ListNode::ListNode(ListNode & copy)
{
	setRecNum(copy.getRecNum());
	setID(copy.getID());
	setFirstName(copy.getFirstName());
	setEmail(copy.getEmail());
	setCredits(copy.getCredits());
	setMajor(copy.getMajor());
	setLevel(copy.getLevel());
	setNumAbsences(copy.getNumAbsences());

	//SET STACK???
}

//GETTERS
int ListNode::getRecNum()
{
	return mRecNum;
}

int ListNode::getID()
{
	return mID;
}

string ListNode::getFirstName()
{
	return mFirstName;
}

string ListNode::getLastName()
{
	return mLastName;
}

string ListNode::getEmail()
{
	return mEmail;
}

string ListNode::getCredits()
{
	return mCredits;
}

string ListNode::getMajor()
{
	return mMajor;
}

string ListNode::getLevel()
{
	return mLevel;
}


Stack ListNode::getStack()
{
	return mStack;
}

int ListNode::getNumAbsences()
{
	return mNumAbsences;
}

ListNode *& ListNode::getNext()
{
	return pNext;
}


//SETTERS
void ListNode::setRecNum(int newRecNum)
{
	mRecNum = newRecNum;
}

void ListNode::setID(int newID)
{
	mID = newID;
}

void ListNode::setFirstName(string newFirstName)
{
	mFirstName = newFirstName;
}

void ListNode::setLastName(string newLastName)
{
	mLastName = newLastName;
}

void ListNode::setEmail(string newEmail)
{
	mEmail = newEmail;
}

void ListNode::setCredits(string newCredits)
{
	mCredits = newCredits;
}

void ListNode::setMajor(string newMajor)
{
	mMajor = newMajor;
}

void ListNode::setLevel(string newLevel)
{
	mLevel = newLevel;
}

void ListNode::setNumAbsences(int newAbsences)
{
	mNumAbsences = newAbsences;
}


//void ListNode::setStack(Stack newDate)
//{
//	mStack = newDate;
//}

void ListNode::SetNext(ListNode * newNext)
{
	pNext = newNext;
}

void ListNode::push(string newDate)
{
	mStack.push1(newDate);

}

void ListNode::pop()
{
	mStack.pop1();
}

string ListNode::peek()
{
	return mStack.peek1();
}

void ListNode::printList()
{
	mStack.printStack1();
}

void ListNode::IncreaseNumAbsences()
{
	mNumAbsences++;
}
