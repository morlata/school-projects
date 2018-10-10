/*
Taylor Morlan
COMP 53
Project 3 - GUI
*/
#include "StdAfx.h"
#include <Windows.h>

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

char Boss::printCell()
{
	return 'B';
}

bool Boss::runEvent(Player& p, CDialog* window)
{
	visited=true;
	CStatic* picChange = (CStatic*)window->GetDlgItem(PICTURE);
	CBitmap picture;
	picture.LoadBitmapW(BOSS);
	picChange->SetBitmap(picture);
	CEdit* txtPtr = (CEdit*)window->GetDlgItem(TEXTBOX);
	CString text;
	text="You step into a room that seems darker than all of the others... \n In the center of the room is the Slenderman!";
	txtPtr->SetWindowTextW(text);
	Sleep(3000);
	do{

		if (p.getSword()==false)
		{
			text="You have no chance to beat the Slenderman without some kind of weapon. \n The Slenderman looks into your eyes and you are lost to the darkness!";
			txtPtr->SetWindowTextW(text);
			Sleep(4000);
			break;
		}
		text.Format(_T("You: %i		Enemy: %i \n The Slender man looks into your eyes and you are afraid!"),p.getLife(), health);
		txtPtr->SetWindowTextW(text);
		Sleep(2000);
		p.setLife(p.getLife()-10);
		if (p.getLife()<=0)
		{
			p.setLife(0);
			break;
		}

		text.Format(_T("You: %i		Enemy: %i \n You slash the Slenderman with your sword!"),p.getLife(), health);
		txtPtr->SetWindowTextW(text);
		Sleep(2000);
		health=health-20;
		if (health<0)
			health=0;

	}while(health>0 && p.getLife()>0);

	if (health>0)
	{
		text="You lose.";
		txtPtr->SetWindowTextW(text);
		return false;
	}
	else
	{
		text.Format(_T("You: %i		Enemy: %i \n You deffeated the Slenderman! \n A portal opens in front of you...\n You step into it, and you awaken from the dream.!"),p.getLife(), health);
		txtPtr->SetWindowTextW(text);
		return false;
	}
}