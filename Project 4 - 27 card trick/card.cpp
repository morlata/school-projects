/*
Taylor Morlan
COMP 53
Project 4 - 27 card trick
*/
#include "card.h"


Card::Card()
{
	symbol=0;
	suit="0";
	value=0;
}

Card::Card(char sym, int val, string s)
{
	symbol=sym;
	value=val;
	suit=s;
}

char Card::getSymbol()
{
	return symbol;
}

void Card::setSymbol(char s)
{
	symbol=s;
}

int Card::getValue()
{
	return value;
}

void Card::setValue(int v)
{
	value=v;
}

string Card::getSuit()
{
	return suit;
}

void Card::setSuit(string s)
{
	suit=s;
}

void Card::setAll(char sym, int val, string s)
{
	symbol=sym;
	value=val;
	suit=s;
}

