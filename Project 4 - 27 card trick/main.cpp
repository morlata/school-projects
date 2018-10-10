/*
Taylor Morlan
COMP 53
Project 4 - 27 card trick
*/

#include <iostream>
#include <ctime>
#include "card.h"
#include "deck.h"
using namespace std;

int main()
{
	int input;//deck choice
	bool failure=false;//error checking
	srand((unsigned)time(0));
	Deck d, s1, s2, s3, temp;//d is the initial deck, and the other 3 are the small decks
	d.fill();
	d.shuffle();
	d.resize();
	d.print();
	cout << "Pick a card from the list above and memorize it."<<endl;
	system("pause");
	system("cls");
	for (int i=0; i<9; i++)//splits the main deck into the 3 small decks
	{
		s1.addCard(d.drawCard());
		s2.addCard(d.drawCard());
		s3.addCard(d.drawCard());
	}
	for (int i=0; i<3; i++)//loop the runs 3 times
	{
		do{//do while loop for input checking
			failure=false;
			cout << "Deck 1" <<endl;
			s1.print();
			cout << "Deck 2" <<endl;
			s2.print();
			cout << "Deck 3" <<endl;
			s3.print();
			cout << "Which deck is your card in?";
			cin >> input;
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				cout << "Error! Invalid Input!"<<endl;
				system("pause");
				system("cls");
				failure=true;
			}
			switch (input)//switch for user input
			{
			case 1://if the case is 1 it simply puts the decks together.
				for (int i=0; i<9; i++)
				{
					d.addCard(s1.drawCard());//takes all the cards from the first deck
				}
				for (int i=0; i<9; i++)
				{
					d.addCard(s2.drawCard());//second deck
				}
				for (int i=0; i<9; i++)
				{
					d.addCard(s3.drawCard());//third deck
				}
				for (int i=0; i<9; i++)//the cards in the main deck are put back into 3 separate small decks
				{
					s1.addCard(d.drawCard());
					s2.addCard(d.drawCard());
					s3.addCard(d.drawCard());
				}
				break;
			case 2://if 2, the second deck is swapped with the first deck and runs the same process as above
				temp=s1;
				s1=s2;
				s2=temp;
				for (int i=0; i<9; i++)
				{
					d.addCard(s1.drawCard());
				}
				for (int i=0; i<9; i++)
				{
					d.addCard(s2.drawCard());
				}
				for (int i=0; i<9; i++)
				{
					d.addCard(s3.drawCard());
				}
				for (int i=0; i<9; i++)
				{
					s1.addCard(d.drawCard());
					s2.addCard(d.drawCard());
					s3.addCard(d.drawCard());
				}
				break;
			case 3://if 3, the third deck is swapped with the 1st deck and the same process as above is run
				temp=s1;
				s1=s3;
				s3=temp;
				for (int i=0; i<9; i++)
				{
					d.addCard(s1.drawCard());
				}
				for (int i=0; i<9; i++)
				{
					d.addCard(s2.drawCard());
				}
				for (int i=0; i<9; i++)
				{
					d.addCard(s3.drawCard());
				}
				for (int i=0; i<9; i++)
				{
					s1.addCard(d.drawCard());
					s2.addCard(d.drawCard());
					s3.addCard(d.drawCard());
				}
				break;
			default://error checking
				cout << "Error! Invalid Input!" <<endl;
				system ("pause");
				system ("cls");
				failure=true;
			}
		}while(failure==true);
		system("pause");
		system("cls");
	}
	s3.displayChoice();//at the end, the user's card is at the top of the 3rd pile, this function displays the end message.
	system("pause");
}