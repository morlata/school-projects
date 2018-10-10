/*
Taylor Morlan
COMP 53
Project 3 - GUI
*/
// Project 3 - GUIDlg.h : header file
//

#pragma once


// CProject3GUIDlg dialog
class CProject3GUIDlg : public CDialogEx
{
// Construction
public:
	CProject3GUIDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_PROJECT3GUI_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedNorth();//North handler
	afx_msg void OnBnClickedSouth();//South handler
	afx_msg void OnBnClickedEast();//East handler
	afx_msg void OnBnClickedWest();//West handler
	void displayMap(Player p);//this is a function that displays the the map as a 2d character array
	CString userInput;//this is a variable i ended up not using
	afx_msg void OnEnChangeTextinput();//this handler isn't used
	bool running;
};
