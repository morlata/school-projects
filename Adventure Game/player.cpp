#include "player.h"

//comments on the player class are in the header
Player::Player()
{
	sword=false;
	row=0;
	col=0;
	life=100;
	cout << "Enter your name: ";
	cin >> name;
	system ("cls");
}
void Player::setSword(bool s)
{
	sword=s;
}

bool Player::getSword()
{
	return sword;
}

void Player::setCol(int c)
{
	col=c;
}

int Player::getCol()
{
	return col;
}

void Player::setLife(int s)
{
	life=s;
}

int Player::getLife()
{
	return life;
}

void Player::setRow(int r)
{
	row=r;
}

int Player::getRow()
{
	return row;
}

string Player::getName()
{
	return name;
}

void Player::display()
{
	cout << "Name: "<<name<< "		Life: "<<life<<endl;
}
