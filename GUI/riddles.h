/*
Taylor Morlan
COMP 53
Project 3 - GUI
*/
#ifndef RIDDLES_H
#define RIDDLES_H
#include "player.h"
#include "location.h"

class Riddles :public Location
{
public:
	bool runEvent(Player& p, CDialog* window);//starts the riddle game
	char printCell();//prints the char that symbolizes the Riddles class on the grid.
	Riddles();//runs the inherited constructor.
};

#endif