/*
Taylor Morlan
COMP 53
Project 3 - GUI
*/
#include "StdAfx.h"
//comments on the location class are in the header
char Location::printCell()
{
	return 'L';
}

bool Location::runEvent (Player& p, CDialog* window)
{
	visited=true;
	CEdit* txtPtr = (CEdit*)window->GetDlgItem(TEXTBOX);
	CStatic* picChange = (CStatic*)window->GetDlgItem(PICTURE);
	CBitmap picture;
	picture.LoadBitmapW(LOCATION);
	picChange->SetBitmap(picture);
	CString text;
	text	= "You step into a cold, dark room with multiple entrances.";
	txtPtr->SetWindowTextW(text);

	return true;
}

Location::Location()
{
	visited=false;
}

