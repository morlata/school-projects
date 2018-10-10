#ifndef PLAYER_H
#define PLAYER_H
//header for player class
#include<iostream>
#include<string>
using namespace std;

class Player
{
private:
	bool sword;//bool for whether or not the player has a sword
	int life, row, col;//ints for location and health
	string name;//name of player
public:
	void setSword (bool s);//sets the bool sword to true or false
	bool getSword();//returns the value of bool sword
	void setRow (int r);//sets the row the player is in
	int getRow();//returns the row the player is in.
	void setCol(int c);//sets the col the player is in.
	int getCol();//returns the col the player is in.
	void setLife(int l);//sets how much life the player has
	int getLife();//returns how much life the player has.
	string getName();//returns the name of the Player.
	Player();//sets sword to false, life to 100, row and col to 0, and takes keyboard input for name.
	void display();//displays the name and life of the character.
};

#endif