/*
Taylor Morlan
COMP 53
Project 3 - GUI
*/
#ifndef ENEMY_H
#define ENEMY_H
#include "player.h"
#include "location.h"
#include <ctime>
#include <cstdlib>

class Enemy: public Location
{
private:
	int health;//health of the enemy
	CString type;//name of the enemy
public:
	Enemy();//gives the enemy 30 health
	char printCell();//prints the character that represents this type of cell on the map.
	CString Enemy::getType();//returns the name of the enemy
	bool runEvent(Player& p, CDialog* window);//starts the battle with the enemy
	void eDisplay();//a display that shows the type of enemy and its health.
};

#endif