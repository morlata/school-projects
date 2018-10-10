/*
Taylor Morlan
COMP 53
Project 4 - 27 card trick
*/
#ifndef CARD_H
#define CARD_H


#include <string>
#include <iostream>
using namespace std;

class Card
{
public:
	Card();
	Card(char sym, int val, string s);
	char getSymbol();
	void setSymbol(char s);
	string getSuit();
	void setSuit(string s);
	void setValue(int v);
	int getValue();
	void setAll(char sym, int val, string s);
private:
	char symbol;
	int value;
	string suit;
};

#endif