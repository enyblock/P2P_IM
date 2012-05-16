// Register.cpp : implementation file
//

#include "stdafx.h"
#include "Enyblock_IM.h"
#include "Register.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Register dialog


Register::Register(CWnd* pParent /*=NULL*/)
	: CDialog(Register::IDD, pParent)
{
	//{{AFX_DATA_INIT(Register)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void Register::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Register)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(Register, CDialog)
	//{{AFX_MSG_MAP(Register)
	ON_BN_CLICKED(IDC_BUTTON5, OnRegisterCancle)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Register message handlers

void Register::OnRegisterCancle() 
{
	// TODO: Add your control notification handler code here
	EndDialog(NULL);
	
}
