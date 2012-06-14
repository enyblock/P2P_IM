#if !defined(AFX_REGISTER_H__F8AD8527_F6BA_44EB_B99F_6DBAD80A1987__INCLUDED_)
#define AFX_REGISTER_H__F8AD8527_F6BA_44EB_B99F_6DBAD80A1987__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Register.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// Register dialog

class Register : public CDialog
{
// Construction
public:
	Register(CWnd* pParent = NULL);   // standard constructor
	int check_register_eidtbox();
	int check_username_exit();
	int register_account();
	CDatabase m_db;
	CRecordset rs;

// Dialog Data
	//{{AFX_DATA(Register)
	enum { IDD = IDD_Register };
	CString	m_username;
	CString	m_password;
	CString	m_password_confirm;
	CString	m_email;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Register)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(Register)
	afx_msg void OnRegisterCancle();
	afx_msg void OnRegister();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_REGISTER_H__F8AD8527_F6BA_44EB_B99F_6DBAD80A1987__INCLUDED_)
