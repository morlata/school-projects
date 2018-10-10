#include "enemy.h"

//comments on the enemy class are in the header

string Enemy::getType()
{
	return type;
}

void Enemy::eDisplay()
{
	cout << "Enemy: "<<type<<"		Life: "<<health<<endl;
}

void Enemy::printCell()
{
	cout << "#";
}

Enemy::Enemy()
{
	srand((unsigned)time(0));
	Location::Location();
	health=30;
	int i=rand()%90;
	if (i>=0 && i<=30)
	{
		type="Minotaur";
	}
	else if (i>=31 && i<=60)
	{
		type="Giant";
	}
	else if (i>=61 && i<=90)
	{
		type="Troll";
	}
}

bool Enemy::runEvent(Player& p)
{
	if (visited==true)
	{
		cout << "You step into a chamber and you see the remains of a "<<type<<"."<<endl;
		system("pause");
	}
	if (visited==false)
	{
		visited=true;
		cout << "You step into a dark chamber, and there is a foul stench in the air..."<<endl;
		if (type=="Minotaur")
		{
			do{
				cout << "A Minotaur rams you!"<<endl;
				p.setLife(p.getLife()-5);
				system("pause");
				if (p.getLife()<=0)
				{
					p.setLife(0);
					break;
				}
				system("cls");
				p.display();
				eDisplay();
				if (p.getSword()==true)
				{
					cout << "You slash the Minotaur with your sword!"<<endl;
					health=health-20;
					system("pause");
					if (health<=0)
					{
						health=0;
						break;
					}
					system("cls");
					p.display();
					eDisplay();
				}
				else
				{
					cout << "You fight back with you hands!"<<endl;
					health=health-5;
					system("pause");
					if (health<=0)
					{
						health=0;
						break;
					}
					system("cls");
					p.display();
					eDisplay();
				}
			}while(p.getLife()>0 && health>0);
		}
		else if (type=="Giant")
		{
			do{
				cout << "A Giant stomps on you!"<<endl;
				p.setLife(p.getLife()-5);
				system("pause");
				if (p.getLife()<=0)
				{
					p.setLife(0);
					break;
				}
				system("cls");
				p.display();
				eDisplay();
				if (p.getSword()==true)
				{
					cout << "You slash the Giant with your sword!"<<endl;
					health=health-20;
					system("pause");
					if (health<=0)
					{
						health=0;
						break;
					}
					system("cls");
					p.display();
					eDisplay();
				}
				else
				{
					cout << "You fight back with you hands!"<<endl;
					health=health-5;
					system("pause");
					if (health<=0)
					{
						health=0;
						break;
					}
					system("cls");
					p.display();
					eDisplay();
				}
			}while(p.getLife()>0 && health>0);
		}
		else if (type=="Troll")
		{
			do{
				cout << "A Troll clubs you!"<<endl;
				p.setLife(p.getLife()-5);
				system("pause");
				if (p.getLife()<=0)
				{
					p.setLife(0);
					break;
				}
				system("cls");
				p.display();
				eDisplay();
				if (p.getSword()==true)
				{
					cout << "You slash the Troll with your sword!"<<endl;
					health=health-20;
					system("pause");
					if (health<=0)
					{
						health=0;
						break;
					}
					system("cls");
					p.display();
					eDisplay();
				}
				else
				{
					cout << "You fight back with you hands!"<<endl;
					health=health-5;
					system("pause");
					if (health<=0)
					{
						health=0;
						break;
					}
					system("cls");
					p.display();
					eDisplay();
				}
			}while(p.getLife()>0 && health>0);
		}
		system("cls");
		p.display();
		eDisplay();
		if (p.getLife()==0)
		{
			cout << "You have been defeated."<<endl;
			return false;
		}
		else if(health==0)
			cout << "You defeated the "<<type<<"!"<<endl;
	}
	return true;
}