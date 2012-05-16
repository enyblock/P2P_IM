// Enyblock_IM.h : main header file for the ENYBLOCK_IM application
//

#if !defined(AFX_ENYBLOCK_IM_H__AED62EE7_E7D4_41C9_84DB_AC2A9380611B__INCLUDED_)
#define AFX_ENYBLOCK_IM_H__AED62EE7_E7D4_41C9_84DB_AC2A9380611B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CEnyblock_IMApp:
// See Enyblock_IM.cpp for the implementation of this class
//

class CEnyblock_IMApp : public CWinApp
{
public:
	CEnyblock_IMApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEnyblock_IMApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CEnyblock_IMApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ENYBLOCK_IM_H__AED62EE7_E7D4_41C9_84DB_AC2A9380611B__INCLUDED_)
