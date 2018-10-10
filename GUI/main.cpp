/*Taylor Morlan
  Comp 53

//THERE SHOULD ONLY BE 1 BOSS INSTANCE AND 1 RIDDLES INSTANCE
//To beat the game, you must go to the instance of the Riddles class where you receive the sword, then go to the instance of the boss class and kill the Slenderman
#include<iostream>
#include "player.h"
#include "location.h"
#include "riddles.h"
#include "enemy.h"
#include "boss.h"
#include "game.h"

int main()
{
bool playing=true;//bool for checking win loss.
Player p;
cout << "You awaken, surrounded by darkness. There is a cool draft wafting towards you. You walk towards it..."<<endl;
Game g;
g.getGrid();
g.displayGrid(p);
while(playing==true)//loop that runs the game, exits when the player wins or loses.
{
	playing=g.playGame(p);
	if (playing==false)
		break;
	g.displayGrid(p);
	g.makeMove(p);
}
system ("pause");
}*/