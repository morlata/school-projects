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
	string type;//name of the enemy
public:
	Enemy();//gives the enemy 30 health
	void printCell();//prints the character that represents this type of cell on the map.
	string Enemy::getType();//returns the name of the enemy
	bool runEvent(Player& p);//starts the battle with the enemy
	void eDisplay();//a display that shows the type of enemy and its health.
};

#endif