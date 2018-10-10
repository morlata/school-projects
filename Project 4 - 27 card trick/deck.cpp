/*
Taylor Morlan
COMP 53
Project 4 - 27 card trick
*/
#include "deck.h"

Deck::Deck()
{
	top=NULL;
	bot=NULL;
}

void Deck::displayChoice()//displays the users card, which is at the top of the 3rd deck.
{
	Card final=drawCard();
	cout << "Your card is the ";
	if (final.getValue()==1)
		cout << "A";
	else if (final.getValue()>1 && final.getValue()<11)
		cout << final.getValue();
	else if (final.getValue()==11)
		cout << "J";
	else if (final.getValue()==12)
		cout << "Q";
	else if (final.getValue()==13)
		cout << "K";
	cout << " of " << final.getSymbol() << endl;
}

void Deck::print()//displays all the cards in a deck.
{
	Node* cur=top;//pointer to walk through deck
	if (cur==NULL)
	{
		cout << "Fatal Error!";
	}
	while (cur!=bot)//loop goes until all the cards have been printed but the last
	{
		if (cur->data.getValue()>1 && cur->data.getValue()<11)
			cout << cur->data.getValue() << cur->data.getSymbol() << endl;
		else if (cur->data.getValue()==1)
			cout << "A" << cur->data.getSymbol() << endl;
		else if (cur->data.getValue()==11)
			cout << "J" << cur->data.getSymbol() << endl;
		else if (cur->data.getValue()==12)
			cout << "Q" << cur->data.getSymbol() << endl;
		else if (cur->data.getValue()==13)
			cout << "K" << cur->data.getSymbol() << endl;
		cur=cur->next;
	}
	//this prints the last card in the deck
		if (cur->data.getValue()>1 && cur->data.getValue()<11)
			cout << cur->data.getValue() << cur->data.getSymbol() << endl;
		else if (cur->data.getValue()==1)
			cout << "A" << cur->data.getSymbol() << endl;
		else if (cur->data.getValue()==11)
			cout << "J" << cur->data.getSymbol() << endl;
		else if (cur->data.getValue()==12)
			cout << "Q" << cur->data.getSymbol() << endl;
		else if (cur->data.getValue()==13)
			cout << "K" << cur->data.getSymbol() << endl;
}

void Deck::fill()
{
	Node* cur= new Node;
	top=cur;
	bot=cur;
	
	for (int i=1;i<14; i++)//makes the suit of hears
	{
			cur = new Node;
			cur->data.setAll('\3', i, "heart");
			cur->next=top;
			top=cur;
	}

	for (int i=1;i<14; i++)//makes the suit of diamonds
	{
			cur = new Node;
			cur->data.setAll('\4', i, "diamond");
			cur->next=top;
			top=cur;
	}

	for (int i=1;i<14; i++)//makes the suit of clubs
	{
			cur = new Node;
			cur->data.setAll('\5', i, "club");
			cur->next=top;
			top=cur;
	}

	for (int i=1;i<14; i++)//makes the suit of spades
	{
			cur = new Node;
			cur->data.setAll('\6', i, "spade");
			cur->next=top;
			top=cur;
	}
}

void Deck::addCard(Card c)//adds a card to the top of a deck
{
	Node* cur= new Node;
	cur->data=c;
	cur->next=top;
	top=cur;
	if (cur->next==NULL)
	{
		bot=top;
	}
}

Card Deck::drawCard()//takes a card from the top of a deck
{
	Node* cur=top;
	if (cur==NULL)
	{
		cout << "Fatal Error!"<<endl;
		system("pause");
		exit(EXIT_FAILURE);
	}
	top=cur->next;
	return cur->data;
}

void Deck::resize()//shrinks a 52 card deck to 27
{
	for (int i=0; i<25; i++)
		drawCard();
}

void Deck::shuffle()//randomly switches 2 card in a deck, 200 times
{
	int r, r2;
	Node* cur=top;
	Node* cur2=top;
	Card temp, temp2;
	for (int i=0; i<200; i++)
	{
		cur=top;
		cur2=top;
		do{
		r=rand()%52 + 1;
		r2=rand()%52 + 1;
		}while (r==r2);
		for (int j=0; j<r-1; j++)
		{
			cur=cur->next;
		}
		for (int k=0; k<r2-1; k++)
		{
			cur2=cur2->next;
		}
		temp=cur->data;
		temp2=cur2->data;
		cur->data=temp2;
		cur2->data=temp;
	}
}