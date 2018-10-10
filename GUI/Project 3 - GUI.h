
// Project 3 - GUI.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CProject3GUIApp:
// See Project 3 - GUI.cpp for the implementation of this class
//

class CProject3GUIApp : public CWinApp
{
public:
	CProject3GUIApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CProject3GUIApp theApp;