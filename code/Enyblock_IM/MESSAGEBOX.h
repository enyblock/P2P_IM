#if !defined(AFX_MESSAGEBOX_H__EE3404F9_3D3E_4344_AFD1_EED67A2E2C1F__INCLUDED_)
#define AFX_MESSAGEBOX_H__EE3404F9_3D3E_4344_AFD1_EED67A2E2C1F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MESSAGEBOX.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMESSAGEBOX dialog

class CMESSAGEBOX : public CDialog
{
// Construction
public:
	CMESSAGEBOX(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CMESSAGEBOX)
	enum { IDD = IDD_MESSAGE_BOX };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMESSAGEBOX)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CMESSAGEBOX)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MESSAGEBOX_H__EE3404F9_3D3E_4344_AFD1_EED67A2E2C1F__INCLUDED_)
