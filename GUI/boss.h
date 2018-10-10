/*
Taylor Morlan
COMP 53
Project 3 - GUI
*/
#ifndef BOSS_H
#define BOSS_H
#include "location.h"
#include "player.h"

class Boss: public Location
{
private:
	int health;//health of the slenderman
public:
	Boss();//constructor gives the slenderman health
	char printCell();//prints the char to symbolize the boss on the grid.
	bool runEvent(Player& p, CDialog* window);//starts the fight with the slenderman
	void display();//function to show the name of the enemy and its health
};

#endif