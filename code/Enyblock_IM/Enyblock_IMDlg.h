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
	CString   get_local_ip();
	int       update_ip(CString ip,CString username);
	int       log_out(CString username);
	int       check_loged();
	int       set_friend();
	CString   find_friend_ip();
	CString   find_friend_name();

	CString   find_friend_name_from_fip(CString fip);

	//contact ¥¶¿Ì
	void      init_tree_contact();
	void      insert_contact();
	CDatabase m_db;
	CRecordset rs;


	CStringArray   m_fip;
	CStringArray   m_fname;
//	loging my_loging;
// Dialog Data
	//{{AFX_DATA(CEnyblock_IMDlg)
	enum { IDD = IDD_ENYBLOCK_IM_DIALOG };
	CTreeCtrl	m_contact_tree;
	CProgressCtrl	m_progress;
	Register        m_register;
	CString	m_username;
	CString	m_password;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEnyblock_IMDlg)
	public:
	virtual BOOL DestroyWindow();
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
	afx_msg void OnDblclkTreeContact(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ENYBLOCK_IMDLG_H__89DEC288_89D2_4576_BECE_0BAAAD01C30E__INCLUDED_)
