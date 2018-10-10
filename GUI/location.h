/*
Taylor Morlan
COMP 53
Project 3 - GUI
*/
#ifndef LOCATION_H
#define LOCATION_H
#include "player.h"
#include <afxwin.h>
#include "resource.h"
class Location
{
protected:
	bool visited;//bool that changes when the player visits the cell. inherited
public:
	virtual char printCell();//inherited function that prints the char that symbolizes which class it is
	bool getVisited()//returns whether or not the cell is visited.
	{
		return visited;
	}
	Location();//constructor makes visited=false
	virtual bool runEvent (Player& p, CDialog* window);//virtual runevent function that simply describes the Location.
};

#endif