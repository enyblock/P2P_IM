#if !defined(AFX_MESSAGEBOX_H__EE3404F9_3D3E_4344_AFD1_EED67A2E2C1F__INCLUDED_)
#define AFX_MESSAGEBOX_H__EE3404F9_3D3E_4344_AFD1_EED67A2E2C1F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MESSAGEBOX.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMESSAGEBOX dialog

//自定义消息
#define WM_RECVDATA WM_USER+1

//接收参数
struct RECVPARAM
{
	SOCKET sock;
	HWND   hwnd;
};


static CString friend_name;

class CMESSAGEBOX : public CDialog
{
// Construction
public:
	static DWORD WINAPI RecvProc(LPVOID lpParameter);
	BOOL InitSocket();
	CMESSAGEBOX(CWnd* pParent = NULL);   // standard constructor
	void set_ip(CString ip);
	void get_friend_name(CString fname);


	
	DWORD m_dwIP;
	CString fip;


// Dialog Data
	//{{AFX_DATA(CMESSAGEBOX)
	enum { IDD = IDD_MESSAGE_BOX };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMESSAGEBOX)
	public:
	virtual BOOL DestroyWindow();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CMESSAGEBOX)
	virtual BOOL OnInitDialog();
	afx_msg void OnButtonSend();
	afx_msg void OnButtonCancle();
	afx_msg void OnClose();
	//}}AFX_MSG
	afx_msg void OnRecvData(WPARAM wParam, LPARAM lParam);
	DECLARE_MESSAGE_MAP()
private:
	SOCKET m_socket;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MESSAGEBOX_H__EE3404F9_3D3E_4344_AFD1_EED67A2E2C1F__INCLUDED_)
