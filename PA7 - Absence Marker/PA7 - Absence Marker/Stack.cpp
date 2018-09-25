#include "Stack.h"

Stack::Stack()
{
	mTop = 0;
}

void Stack::push1(string & newDate)
{
	if (mTop < 100)
	{
		list[mTop++] = newDate;
		
	}

}

void Stack::pop1()
{
	if (mTop != 0)
	{
		list[mTop--];
		mTop--;
	}
}

string Stack::peek1()
{
	return list[mTop - 1];
}

void Stack::printStack1()
{
	int i = 0;
	while (i <= mTop)
	{
		cout << list[i];
		i++;
	}
}

int Stack::getSize1()
{
	return mTop;
}
