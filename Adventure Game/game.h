#ifndef GAME_H
#define GAME_H
#include "location.h"
#include "player.h"
#include "riddles.h"
#include "boss.h"
#include "enemy.h"
#include <fstream>
#include <iostream>
using namespace std;
class Game
{
private:
	int rows,cols;//ints for the total number of rows and columns in the grid
	char c;//temporary char used for extracting data from the text file
	Location ***arr;//triple pointer for the array of class objects
public:
	Game();//constructor
	bool playGame (Player &p);//function that runs runEvent
	void getGrid();//function to read the text file
	void displayGrid(Player p);//function to display the area to the screen; also calls the player display function
	void makeMove(Player &p);//changes the location of the player
};

#endif