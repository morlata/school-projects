/*
Taylor Morlan
COMP 53
Project 4 - 27 card trick
*/
#ifndef DECK_H
#define DECK_H

#include "card.h"
#include "node.h"

class Deck
{
public:
	Deck();//constructor
	void shuffle();//randomizes the 52 card deck
	Card drawCard();//takes the top card from a deck
	void addCard(Card c);//adds a card to the top of a deck
	void fill();//fills a deck with 52 cards
	void print();//prints the cards in a deck
	void resize();//takes 25 cards from the deck to make it 27 cards total
	void displayChoice();//this function prints the card that the user chooses in the beginning of the program.
private:
	Node* top;
	Node* bot;
};

#endif