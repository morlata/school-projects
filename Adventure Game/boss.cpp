#include "boss.h"

//comments on the boss class are in the header

void Boss::display()
{
	cout << "Enemy: Slenderman		Life: "<<health<<endl;
}

Boss::Boss()
{
	Location::Location();
	health=80;
}

void Boss::printCell()
{
	cout << "B";
}

bool Boss::runEvent(Player& p)
{
	cout << "You step into a room that seems darker than all of the others..."<<endl;
	cout << "In the center of the room is the Slenderman!"<<endl;
	system("pause");
	do{
		system("cls");
		p.display();
		display();
		if (p.getSword()==false)
		{
			cout << "The Slenderman looks into your eyes and you are lost to the darkness!"<<endl;
			break;
		}
		cout << "The Slender man looks into your eyes and you are afraid!"<<endl;
		p.setLife(p.getLife()-10);
		if (p.getLife()<0)
		{
			p.setLife(0);
			break;
		}
		system("pause");
		system("cls");
		p.display();
		display();
		cout << "You slash the Slenderman with your sword!"<<endl;
		health=health-20;
		if (health<0)
			health=0;
		system("pause");
	}while(health>0 && p.getLife()>0);
	system ("cls");
	p.display();
	display();
	if (health>0)
	{
		cout << "You lose."<<endl;
		return false;
	}
	else
	{
		cout << "You deffeated the Slenderman!"<<endl;
		cout << "A portal opens in front of you..."<<endl;
		cout << "You step into it, and you awaken from the dream."<<endl;
		return false;
	}
}