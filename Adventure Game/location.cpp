#include "location.h"
//comments on the location class are in the header
void Location::printCell()
{
	cout << "#";
}

bool Location::runEvent(Player &p)
{
	visited=true;
	cout << "You step into a cold, dark room with multiple entrances."<<endl;
	system("pause");

	return true;
}

Location::Location()
{
	visited=false;
}

