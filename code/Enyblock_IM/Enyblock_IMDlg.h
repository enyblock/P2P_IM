// Enyblock_IMDlg.h : header file
//

#if !defined(AFX_ENYBLOCK_IMDLG_H__89DEC288_89D2_4576_BECE_0BAAAD01C30E__INCLUDED_)
#define AFX_ENYBLOCK_IMDLG_H__89DEC288_89D2_4576_BECE_0BAAAD01C30E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CEnyblock_IMDlg dialog

#include "Register.h"
#include "MESSAGEBOX.h"

class CEnyblock_IMDlg : public CDialog
{
// Construction
public:
	CEnyblock_IMDlg(CWnd* pParent = NULL);	// standard constructor
//	loging my_loging;
// Dialog Data
	//{{AFX_DATA(CEnyblock_IMDlg)
	enum { IDD = IDD_ENYBLOCK_IM_DIALOG };
	CProgressCtrl	m_progress;
	Register        m_register;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEnyblock_IMDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CEnyblock_IMDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnLogOn();
	afx_msg void OnRegister();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ENYBLOCK_IMDLG_H__89DEC288_89D2_4576_BECE_0BAAAD01C30E__INCLUDED_)
