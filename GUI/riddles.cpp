/*
Taylor Morlan
COMP 53
Project 3 - GUI
*/

#include "stdafx.h"
#include "Project 3 - GUIDlg.h"

//comments on the riddles class are in the header

char Riddles::printCell()
{
	return 'R';
}

bool Riddles::runEvent(Player& p, CDialog* window)
{
	CEdit* txtPtr = (CEdit*)window->GetDlgItem(TEXTBOX);
	CStatic* picChange = (CStatic*)window->GetDlgItem(PICTURE);
	CBitmap picture;
	picture.LoadBitmapW(RIDDLES);
	picChange->SetBitmap(picture);
	//CEdit* input = (CEdit*)window->GetDlgItem(TEXTINPUT);
	//HWND hWnd = GetDlgItem(TEXTINPUT);
	CString text, response;
	
	if (visited==true)
	{
		text = "You step into the chamber where you answered riddles and claimed the sword.";
		txtPtr->SetWindowTextW(text);
		return true;
	}
	if (visited==false)
	{
		visited=true;
		text="You enter into a dark circular room. There is a stone pedestal in the center. You start to approach the pedestal. As you get closer, you begin to make out what seems to be the hilt of a sword  protruding from the pedestal.You start to get excited, and quickly move the rest of the way to the pedestal.You reach out to grasp the sword, but an unknown force stops you. A mysterious voice utters \"three riddles you must answer to pass\"You realize that you must answer these riddles and leave with the sword, or die. \"I am lighter than a feather, yet no man can hold me for very long. What am I?\" \"Yes, breath is correct, Next riddle.\" \n \"What ends everything always?\" \"Yes, the letter g is correct. Final riddle.\" \"What goes around the world but stays in a corner?\" \"Yes the answer is stamps. You are worthy of the blade\" You step forward and grasp the hilt of the sword and pull it out of the pedestal.";
		txtPtr->SetWindowTextW(text);
		//input->EnableWindow(true);
		//input->ShowWindow(true);
		//input->GetWindowTextW(response);
		


		//text="\"Yes, breath is correct, Next riddle.\" \n \"What ends everything always?\"";
		p.setSword(true);
	

		/*cout << "\"Yes, the letter g is correct. Final riddle.\" \n"<<endl;


			cout << "\"What goes around the world but stays in a corner?\"(one word plural)";


		cout <<endl<< "\" Yes the answer is stamps. You are worthy of the blade\""<<endl<<"You step forward and grasp the hilt of the sword and pull it out of the pedestal."<<endl;
		p.setSword(true);

		cout << "The moment you pull the sword out of the pedestal, exits from the chamber open."<<endl;
	
		}*/
		return true;
}
}

Riddles::Riddles()
{
	Location::Location();
}