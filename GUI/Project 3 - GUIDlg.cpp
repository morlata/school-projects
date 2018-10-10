/*
Taylor Morlan
COMP 53
Project 3 - GUI
*/
// Project 3 - GUIDlg.cpp : implementation file
//
#include "stdafx.h"
#include "Project 3 - GUI.h"
#include "Project 3 - GUIDlg.h"
#include "afxdialogex.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CProject3GUIDlg dialog




CProject3GUIDlg::CProject3GUIDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CProject3GUIDlg::IDD, pParent)
	, userInput(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CProject3GUIDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, TEXTINPUT, userInput);
}

BEGIN_MESSAGE_MAP(CProject3GUIDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(NORTH, &CProject3GUIDlg::OnBnClickedNorth)
	ON_BN_CLICKED(SOUTH, &CProject3GUIDlg::OnBnClickedSouth)
	ON_BN_CLICKED(East, &CProject3GUIDlg::OnBnClickedEast)
	ON_BN_CLICKED(WEST, &CProject3GUIDlg::OnBnClickedWest)
	ON_EN_CHANGE(TEXTINPUT, &CProject3GUIDlg::OnEnChangeTextinput)
END_MESSAGE_MAP()


// CProject3GUIDlg message handlers

BOOL CProject3GUIDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CProject3GUIDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CProject3GUIDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CProject3GUIDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CProject3GUIDlg::displayMap(Player p)//this is a function that i made to display the map as a 2d character array.
{
	CString msg=_T("");
	CEdit* textPtr = (CEdit*)GetDlgItem(MAP);
	char map[5][5]=
	{'L','L','R','E','L',
	'L','L','E','L','E',
	'L','E','E','L','L',
	'L','L','B','E','L',
	'L','E','L','L','L'};

	for (int i=0; i<5; i++)
	{
		for (int j=0; j<5; j++)
		{
			if (i==p.getRow() && j==p.getCol())
			{
				msg+="*";
			}
			else
			{
				msg+=(_T("%c"), map[i][j]);
			}
		}
		msg+="\r";
	}
	textPtr->SetWindowTextW(msg);
}


void CProject3GUIDlg::OnBnClickedNorth()//this is the handler for the north button
{
	// TODO: Add your control notification handler code here
	CButton* nPtr = (CButton*)GetDlgItem(NORTH);//pointers for the different buttons
	CButton* sPtr = (CButton*)GetDlgItem(SOUTH);
	CButton* wPtr = (CButton*)GetDlgItem(WEST);
	CButton* ePtr = (CButton*)GetDlgItem(East);
	nPtr->EnableWindow(false);//disables all the buttons
	sPtr->EnableWindow(false);
	ePtr->EnableWindow(false);
	wPtr->EnableWindow(false);
	p.setRow(p.getRow()-1);//updates the player location
	displayMap(p);//updates the Map
	running=arr[p.getRow()][p.getCol()]->runEvent(p,this);//calls runEvent for the current Location.
	//CString msg;
	//msg.Format(_T("Location is %i, %i"), p.getRow(), p.getCol());
	//textPtr->SetWindowTextW(msg);
	if (running==true)//if the game doesn't end, re-enables the correct buttons
	{
	if (p.getRow()!=0)
		nPtr->EnableWindow(true);
	if (p.getRow()!=4)
		sPtr->EnableWindow(true);
	if (p.getCol()!=0)
		wPtr->EnableWindow(true);
	if (p.getCol()!=4)
		ePtr->EnableWindow(true);
	}
}


void CProject3GUIDlg::OnBnClickedSouth()//handler for south, pretty much the same as above
{
	// TODO: Add your control notification handler code here
	CButton* nPtr = (CButton*)GetDlgItem(NORTH);
	CButton* sPtr = (CButton*)GetDlgItem(SOUTH);
	CButton* wPtr = (CButton*)GetDlgItem(WEST);
	CButton* ePtr = (CButton*)GetDlgItem(East);
	nPtr->EnableWindow(false);
	sPtr->EnableWindow(false);
	ePtr->EnableWindow(false);
	wPtr->EnableWindow(false);
	p.setRow(p.getRow()+1);
	displayMap(p);
	running=arr[p.getRow()][p.getCol()]->runEvent(p,this);
	if (running==true)
	{
	if (p.getRow()!=0)
		nPtr->EnableWindow(true);
	if (p.getRow()!=4)
		sPtr->EnableWindow(true);
	if (p.getCol()!=0)
		wPtr->EnableWindow(true);
	if (p.getCol()!=4)
		ePtr->EnableWindow(true);
	}
}


void CProject3GUIDlg::OnBnClickedEast()//handler for east, also the same as above
{
	// TODO: Add your control notification handler code here
	CButton* nPtr = (CButton*)GetDlgItem(NORTH);
	CButton* sPtr = (CButton*)GetDlgItem(SOUTH);
	CButton* wPtr = (CButton*)GetDlgItem(WEST);
	CButton* ePtr = (CButton*)GetDlgItem(East);
	nPtr->EnableWindow(false);
	sPtr->EnableWindow(false);
	ePtr->EnableWindow(false);
	wPtr->EnableWindow(false);
	p.setCol(p.getCol()+1);
	displayMap(p);
	running=arr[p.getRow()][p.getCol()]->runEvent(p,this);
	if (running==true)
	{
	if (p.getRow()!=0)
		nPtr->EnableWindow(true);
	if (p.getRow()!=4)
		sPtr->EnableWindow(true);
	if (p.getCol()!=0)
		wPtr->EnableWindow(true);
	if (p.getCol()!=4)
		ePtr->EnableWindow(true);
	}
}


void CProject3GUIDlg::OnBnClickedWest()//handler for west, basically the same as above
{
	// TODO: Add your control notification handler code here
	CButton* nPtr = (CButton*)GetDlgItem(NORTH);
	CButton* sPtr = (CButton*)GetDlgItem(SOUTH);
	CButton* wPtr = (CButton*)GetDlgItem(WEST);
	CButton* ePtr = (CButton*)GetDlgItem(East);
	nPtr->EnableWindow(false);
	sPtr->EnableWindow(false);
	ePtr->EnableWindow(false);
	wPtr->EnableWindow(false);
	p.setCol(p.getCol()-1);
	displayMap(p);
	running=arr[p.getRow()][p.getCol()]->runEvent(p,this);
	if (running==true)
	{
	if (p.getRow()!=0)
		nPtr->EnableWindow(true);
	if (p.getRow()!=4)
		sPtr->EnableWindow(true);
	if (p.getCol()!=0)
		wPtr->EnableWindow(true);
	if (p.getCol()!=4)
		ePtr->EnableWindow(true);
	}
}


void CProject3GUIDlg::OnEnChangeTextinput()//i ended up not using this handler. I was going to try to get user input from an edit control for the Riddles class runEvent function, but I didn't have enough knowledge to get it to work with my code.
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	// TODO:  Add your control notification handler code here
	CEdit* textPtr = (CEdit*)GetDlgItem(TEXTINPUT);
}
