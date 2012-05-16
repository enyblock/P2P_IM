// loging.cpp : implementation file
//

#include "stdafx.h"
#include "Enyblock_IM.h"
#include "loging.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// loging dialog
// struct threadInfo
// {
// 	int i;
// 	CProgressCtrl* p_progress;
// }Info;
// 
// UINT fun(LPVOID p)
// {
// 	threadInfo* pInfo = (threadInfo*)p;
// 	for(int i=0;i<100;i++)
// 	{
// 		int tmp = pInfo->i;
// 		pInfo->p_progress->SetPos(i);
// 		Sleep(tmp);
// 	}
// 	return 0;
// }


loging::loging(CWnd* pParent /*=NULL*/)
	: CDialog(loging::IDD, pParent)
{
	//{{AFX_DATA_INIT(loging)
		// NOTE: the ClassWizard will add member initialization here

	//}}AFX_DATA_INIT

// 	Info.i = 9;
// 	Info.p_progress = &m_progress;
// 	CWinThread *pThread = AfxBeginThread(fun, &Info);
// 	
// 	AfxMessageBox("OK");

	

}


void loging::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(loging)
	DDX_Control(pDX, IDC_PROGRESS1, m_progress);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(loging, CDialog)
	//{{AFX_MSG_MAP(loging)
	ON_BN_CLICKED(IDC_BUTTON1, OnProcess)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// loging message handlers

void loging::OnProcess() 
{
	// TODO: Add your control notification handler code here
	m_progress.SetRange(0,100);
	int i = 0;
	while (i < 100)
	{
		Sleep(20);
		m_progress.SetPos(i+1);
		i++;
		
	}
	
}
