#pragma once
#include <iostream>
#include <fstream>
#include <string>


using std::cin;
using std::cout;
using std::endl;
using std::fstream;
using std::string;
#include "Stack.h"
class ListNode
{
public:
	//constructor
	ListNode();
	ListNode(int RecNum, int ID, string FirstName, string LastName, string Email, string Credits, string Major, string Level);


	//copy constructor
	ListNode(ListNode &copy);

	//destructor
	//~ListNode();

	//getters
	int getRecNum();
	int getID();
	string getFirstName();
	string getLastName();
	string getEmail();
	string getCredits();
	string getMajor();
	string getLevel();

	//string getDate();

	Stack getStack();
	int getNumAbsences();
	//????????/string getAbsenceDate();

	ListNode *& getNext();

	//setters
	void setRecNum(int newRecNum);
	void setID(int newID);
	void setFirstName(string newFirstName);
	void setLastName(string newLastName);
	void setEmail(string newEmail);
	void setCredits(string newCredits);
	void setMajor(string newMajor);
	void setLevel(string newLevel);

	void setNumAbsences(int newAbsences);
	
	
	//void setDate(Stack newDate);

	void SetNext(ListNode * newNext);

	void push(string newDate);
	void pop();
	string peek();
	void printList();

	void IncreaseNumAbsences();


private:
	int mRecNum;
	int mID;
	string mFirstName;
	string mLastName;
	string mEmail;
	string mCredits;			
	string mMajor;
	string mLevel;

	int mNumAbsences;


	Stack mStack;

	ListNode * pNext;


};