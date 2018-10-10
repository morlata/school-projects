#include "riddles.h"

//comments on the riddles class are in the header

void Riddles::printCell()
{
	cout << "R";
}

bool Riddles::runEvent(Player& p)
{
	if (visited==true)
	{
		cout << "You step into the chamber where you answered riddles and claimed the sword."<<endl;
	}
	if (visited==false)
	{
		visited=true;
		cout << "You enter into a dark rectangular room with a body of water."<<endl;
		cout << "You think you can make out a small island at the center of the water, with a "<<endl<<" stone pedestal at it's center."<<endl;
		cout << "You swim to the island, and approach the pedestal."<<endl;
		cout << "As you get closer, you begin to make out what seems to be the hilt of a sword "<<endl<<" protruding from the pedestal."<<endl;
		cout << "You start to get excited, and begin running toward the pedestal."<<endl;
		cout << "You reach out to grasp the sword, but an unknown force stops you."<<endl;
		cout << "A mysterious voice utters \"three riddles you must answer to pass\""<<endl;
		cout << "You realize that you must answer these riddles and leave with the sword, or die."<<endl;
		system ("pause");
		system ("cls");
		string response;
		do{
			cout << "\"I am lighter than a feather, yet no man can hold me for very long. What am I?\"(one word)";
			cin >> response;
			if (response!="Breath" && response!="breath" && response != "BREATH")
				cout <<endl<< "\"Incorrect! Try again\""<<endl;
		}while(response!="Breath" && response!="breath" && response != "BREATH");
		cout << "\"Correct. Next riddle.\""<<endl;
		system ("pause");
		system ("cls");
		do{
			cout << "\"What ends everything always?\"";
			cin >> response;
			if (response!="g" && response!= "G")
				cout <<endl<< "\"Incorrect! Think about the word everything.\""<<endl;
		}while (response!="g" && response!= "G");
		cout << "\"Correct. Final riddle.\""<<endl;
		system ("pause");
		system ("cls");
		do{
			cout << "\"What goes around the world but stays in a corner?\"(one word plural)";
			cin >> response;
			if (response!="stamps" && response !="Stamps" && response != "STAMPS")
				cout <<endl<< "\"Incorrect! Think about mail.\""<<endl;
		}while (response!="stamps" && response !="Stamps" && response != "STAMPS");
		cout <<endl<< "\"You are worthy of the blade\""<<endl<<"You step forward and grasp the hilt of the sword and pull it out of the pedestal."<<endl;
		p.setSword(true);
		system ("pause");
		system ("cls");
		cout << "The moment you pull the sword out of the pedestal exits from the chamber open."<<endl;
	}
	return true;
}

Riddles::Riddles()
{
	Location::Location();
}