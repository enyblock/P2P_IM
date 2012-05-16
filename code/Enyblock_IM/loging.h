#if !defined(AFX_LOGING_H__C0666F2E_95C9_4CF3_AA60_1D7AC2BCE09B__INCLUDED_)
#define AFX_LOGING_H__C0666F2E_95C9_4CF3_AA60_1D7AC2BCE09B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// loging.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// loging dialog

class loging : public CDialog
{
// Construction
public:
	loging(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(loging)
//	enum { IDD = IDD_DIALOG1 };
	CProgressCtrl	m_progress;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(loging)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
public:

	// Generated message map functions
	//{{AFX_MSG(loging)
	afx_msg void OnProcess();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LOGING_H__C0666F2E_95C9_4CF3_AA60_1D7AC2BCE09B__INCLUDED_)
