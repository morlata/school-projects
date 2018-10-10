/*
Taylor Morlan
COMP 53
Project 3 - GUI
*/
#include "StdAfx.h"
#include <ctime>
#include <Windows.h>

//comments on the enemy class are in the header

CString Enemy::getType()
{
	return type;
}

void Enemy::eDisplay()
{
	cout << "Enemy: "<<type<<"		Life: "<<health<<endl;
}

char Enemy::printCell()
{
	return 'E';
}

Enemy::Enemy()
{
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

bool Enemy::runEvent(Player& p, CDialog* window)
{
	srand((unsigned)time(0));
	CString text;
	CEdit* txtPtr = (CEdit*)window->GetDlgItem(TEXTBOX);
	if (type=="Minotaur")
	{
	CStatic* picChange = (CStatic*)window->GetDlgItem(PICTURE);
	CBitmap picture;
	picture.LoadBitmapW(MINOTAUR);
	picChange->SetBitmap(picture);
	}

	else if (type=="Giant")
	{
	CStatic* picChange = (CStatic*)window->GetDlgItem(PICTURE);
	CBitmap picture;
	picture.LoadBitmapW(GIANT);
	picChange->SetBitmap(picture);
	}

	else
	{
	CStatic* picChange = (CStatic*)window->GetDlgItem(PICTURE);
	CBitmap picture;
	picture.LoadBitmapW(TROLL);
	picChange->SetBitmap(picture);
	}
	
	if (visited==true)
	{
		text.Format(_T("You step into a chamber and you see the remains of a %s."),type);
		txtPtr->SetWindowTextW(text);
	}
	if (visited==false)
	{
		visited=true;
		text="You step into a dark chamber, and there is a foul stench in the air...";
		txtPtr->SetWindowTextW(text);
		Sleep(1500);
		if (type=="Minotaur")
		{
			do{
				text.Format(_T("You: %i	Enemy: %i \n A Minotaur rams you!"),p.getLife(),health);
				txtPtr->SetWindowTextW(text);
				Sleep(1500);
				p.setLife(p.getLife()-5);
				if (p.getLife()<=0)
				{
					p.setLife(0);
					break;
				}
				if (p.getSword()==true)
				{
					text.Format(_T("You: %i	Enemy: %i \n You slash the Minotaur with your sword!"),p.getLife(),health);
					txtPtr->SetWindowTextW(text);
					Sleep(1500);
					health=health-20;
					if (health<=0)
					{
						health=0;
						break;
					}
				}
				else
				{
					text.Format(_T("You: %i	Enemy: %i \n You fight back with your bare hands!"),p.getLife(),health);
					txtPtr->SetWindowTextW(text);
					Sleep(1500);
					health=health-5;
					if (health<=0)
					{
						health=0;
						break;
					}
				}
			}while(p.getLife()>0 && health>0);
		}
		else if (type=="Giant")
		{
			do{
				text.Format(_T("You: %i	Enemy: %i \n A Giant stomps on you!"),p.getLife(),health);
				txtPtr->SetWindowTextW(text);
				Sleep(1500);
				p.setLife(p.getLife()-5);
				if (p.getLife()<=0)
				{
					p.setLife(0);
					break;
				}
				if (p.getSword()==true)
				{
					text.Format(_T("You: %i	Enemy: %i \n You slash the Giant with your sword!"),p.getLife(),health);
					txtPtr->SetWindowTextW(text);
					Sleep(1500);
					health=health-20;
					if (health<=0)
					{
						health=0;
						break;
					}
				}
				else
				{
					text.Format(_T("You: %i	Enemy: %i \n You fight back with your bare hands!"),p.getLife(),health);
					txtPtr->SetWindowTextW(text);
					Sleep(1500);
					health=health-5;
					if (health<=0)
					{
						health=0;
						break;
					}
				}
			}while(p.getLife()>0 && health>0);
		}
		else if (type=="Troll")
		{
			do{
				text.Format(_T("You: %i	Enemy: %i \n A Troll clubs you!"),p.getLife(),health);
				txtPtr->SetWindowTextW(text);
				Sleep(1500);
				p.setLife(p.getLife()-5);
				if (p.getLife()<=0)
				{
					p.setLife(0);
					break;
				}
				if (p.getSword()==true)
				{
					text.Format(_T("You: %i	Enemy: %i \n You slash the Troll with your sword!"),p.getLife(),health);
					txtPtr->SetWindowTextW(text);
					Sleep(1500);
					health=health-20;
					if (health<=0)
					{
						health=0;
						break;
					}
				}
				else
				{
					text.Format(_T("You: %i	Enemy: %i \n You fight back with your bare hands!"),p.getLife(),health);
					txtPtr->SetWindowTextW(text);
					Sleep(1500);
					health=health-5;
					if (health<=0)
					{
						health=0;
						break;
					}
				}
			}while(p.getLife()>0 && health>0);
		}
		if (p.getLife()==0)
		{
			text="You have been defeated.";
			txtPtr->SetWindowTextW(text);
			return false;
		}
		else if(health==0)
			text.Format(_T("You defeated the %s!"),type);
			txtPtr->SetWindowTextW(text);
			Sleep(1500);
	}
	return true;
	
return true;
}