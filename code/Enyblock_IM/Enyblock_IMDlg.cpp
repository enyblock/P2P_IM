// Enyblock_IMDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Enyblock_IM.h"
#include "Enyblock_IMDlg.h"



#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEnyblock_IMDlg dialog

CEnyblock_IMDlg::CEnyblock_IMDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CEnyblock_IMDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CEnyblock_IMDlg)
	m_username = _T("");
	m_password = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CEnyblock_IMDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CEnyblock_IMDlg)
	DDX_Control(pDX, IDC_TREE_CONTACT, m_contact_tree);
	DDX_Control(pDX, IDC_PROGRESS1, m_progress);
	DDX_Text(pDX, IDC_EDIT_USERNAME, m_username);
	DDX_Text(pDX, IDC_EDIT_PASSWORD, m_password);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CEnyblock_IMDlg, CDialog)
	//{{AFX_MSG_MAP(CEnyblock_IMDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON2, OnLogOn)
	ON_BN_CLICKED(IDC_BUTTON1, OnRegister)
	ON_NOTIFY(NM_DBLCLK, IDC_TREE_CONTACT, OnDblclkTreeContact)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEnyblock_IMDlg message handlers

BOOL CEnyblock_IMDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here

	m_username = "admin";
	m_password = "deny1524";

	m_contact_tree.ShowWindow(SW_HIDE);


	CRect rcDlgs;
	this->GetWindowRect(rcDlgs);		//得到对话框的Rect 对话框的大小
	ScreenToClient(rcDlgs);             //把屏幕的值转成相应的实际的值
	
	int   cx   =   GetSystemMetrics(   SM_CXSCREEN   );  //获得屏幕的分辨率
	int   cy   =   GetSystemMetrics(   SM_CYSCREEN   ); 


	this->MoveWindow(cx-rcDlgs.Width()-(cx/20),cy-rcDlgs.Height()-(cy/2.5),rcDlgs.Width(),rcDlgs.Height(),SWP_NOSIZE);



	UpdateData(FALSE);



	SkinH_Attach();

	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CEnyblock_IMDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CEnyblock_IMDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CEnyblock_IMDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

//检查主机已经登录
int CEnyblock_IMDlg::check_loged()
{	
	if(!UpdateData())
		return 0;


	m_db.Close();

	//创建数据库连接
	TRY
	{
		m_db.OpenEx(_T("DSN=enyblock_im;"),CDatabase::noOdbcDialog);
		
		
		rs.m_pDatabase = &m_db;
	}
	CATCH(CDBException,ex)
	{
		AfxMessageBox(ex->m_strError);
		AfxMessageBox(ex->m_strStateNativeOrigin);
	}
	AND_CATCH(CMemoryException,pEx)
	{
		pEx->ReportError();
		AfxMessageBox(_T("memory exception"));
	}
	AND_CATCH(CException,e)
	{
		TCHAR szError[100];
		e->GetErrorMessage(szError,100);
		AfxMessageBox(szError);
	}
	END_CATCH
		
		
		CString sql = _T("select username from online where username = '"); //要执行的SQL语句
	
	sql += m_username;
	sql += "'";
	
	CString psd; //存放查询结果
	
	TRY
	{
		rs.Open(AFX_DB_USE_DEFAULT_TYPE,sql); //打开查询记录
		
		
		if ( !rs.IsEOF()){
			
			//设置用户名为空
			m_username = "";
			//更新数据
			UpdateData(FALSE);
			//设置焦点
			GetDlgItem(IDC_EDIT_USERNAME)-> SetFocus();
			m_db.Close();
			return 1;
		}else{
			m_db.Close();
			return 0;
		}
		
		
		
	}
	
	CATCH(CDBException,ex)
	{
		AfxMessageBox(ex->m_strError);
		AfxMessageBox(ex->m_strStateNativeOrigin);
	}
	AND_CATCH(CMemoryException,pEx)
	{
		pEx->ReportError();
		AfxMessageBox(_T("memory exception"));
	}
	END_CATCH
		
		
	return 0;

}

//退出登陆
int CEnyblock_IMDlg::log_out(CString username)
{

	m_db.Close();
	
	//创建数据库连接
	TRY
	{
		m_db.OpenEx(_T("DSN=enyblock_im;"),CDatabase::noOdbcDialog);
		
		
		rs.m_pDatabase = &m_db;
	}
	CATCH(CDBException,ex)
	{
		AfxMessageBox(ex->m_strError);
		AfxMessageBox(ex->m_strStateNativeOrigin);
	}
	AND_CATCH(CMemoryException,pEx)
	{
		pEx->ReportError();
		AfxMessageBox(_T("memory exception"));
	}
	AND_CATCH(CException,e)
	{
		TCHAR szError[100];
		e->GetErrorMessage(szError,100);
		AfxMessageBox(szError);
	}
	END_CATCH
		
		
		CString sql = _T("delete from online where username = '"); //要执行的SQL语句
	
	sql += username;
	sql += "'";
	
	
	TRY
	{
		m_db.ExecuteSQL(sql); //打开查询记录
		m_db.Close();
		return 1;
		
		
		
		
	}
	
	CATCH(CDBException,ex)
	{
		AfxMessageBox(ex->m_strError);
		AfxMessageBox(ex->m_strStateNativeOrigin);
		return 0;
	}
	AND_CATCH(CMemoryException,pEx)
	{
		pEx->ReportError();
		AfxMessageBox(_T("memory exception"));
		return 0;
	}
	END_CATCH
		
		
	return 1;

}



//获得本机ip地址
CString CEnyblock_IMDlg::get_local_ip()
{
	//上传主机IP地址
	char    HostName[100];
	
	CString strIPAddr;
	
	gethostname(HostName, sizeof(HostName));// 获得本机主机名.
	
	
	hostent* hn;
	hn = gethostbyname(HostName);                             //根据本机主机名得到本机ip
	
	
	strIPAddr=inet_ntoa(*(struct in_addr *)hn->h_addr_list[0]);//把ip换成字符串形式


	return strIPAddr;
}

//上传主机地址与用户名
int CEnyblock_IMDlg::update_ip(CString ip,CString username)
{
	if(!UpdateData())
		return 0;
	
	//创建数据库连接
	TRY
	{
		m_db.OpenEx(_T("DSN=enyblock_im;"),CDatabase::noOdbcDialog);
		
		
		rs.m_pDatabase = &m_db;
	}
	CATCH(CDBException,ex)
	{
		AfxMessageBox(ex->m_strError);
		AfxMessageBox(ex->m_strStateNativeOrigin);
	}
	AND_CATCH(CMemoryException,pEx)
	{
		pEx->ReportError();
		AfxMessageBox(_T("memory exception"));
	}
	AND_CATCH(CException,e)
	{
		TCHAR szError[100];
		e->GetErrorMessage(szError,100);
		AfxMessageBox(szError);
	}
	END_CATCH
		
		
		CString sql = _T("insert into online(username,ip) values('"); //要执行的SQL语句
	
	sql += username;
	sql += "','";
	sql += ip;
	sql += "')";
	
	
	
	TRY
	{
		m_db.ExecuteSQL(sql); //打开查询记录
		m_db.Close();
		return 1;
		
		
		
		
	}
	
	CATCH(CDBException,ex)
	{
		AfxMessageBox(ex->m_strError);
		AfxMessageBox(ex->m_strStateNativeOrigin);
		return 0;
	}
	AND_CATCH(CMemoryException,pEx)
	{
		pEx->ReportError();
		AfxMessageBox(_T("memory exception"));
		return 0;
	}
	END_CATCH
		
		
	return 1;

}


//设置好友ip
int CEnyblock_IMDlg::set_friend()
{
	CString fip;
	
	fip = find_friend_ip();
	
	if (fip == "")
	{
		return 0;
	}else{
		CMESSAGEBOX *m_message_box;

		m_message_box = new CMESSAGEBOX;

		m_message_box->Create(IDD_MESSAGE_BOX,this);

		m_message_box->ShowWindow(SW_SHOW);

//		char ip[50];

//		strncpy(ip,(LPSTR)(LPCTSTR)fip,50);
//
//		SetDlgItemText(IDC_IPADDRESS1,ip);

//		UpdateData(TRUE);

//		char ip1[50];

//		GetDlgItemText(IDC_IPADDRESS1,ip1,50);
	}
	
	return 1;


}

//获取friend name
CString CEnyblock_IMDlg::find_friend_name_from_fip(CString fip)
{

	if(!UpdateData())
		return "";
	
	m_db.Close();
	
	//创建数据库连接
	TRY
	{
		m_db.OpenEx(_T("DSN=enyblock_im;"),CDatabase::noOdbcDialog);
		
		
		rs.m_pDatabase = &m_db;
	}
	CATCH(CDBException,ex)
	{
		AfxMessageBox(ex->m_strError);
		AfxMessageBox(ex->m_strStateNativeOrigin);
	}
	AND_CATCH(CMemoryException,pEx)
	{
		pEx->ReportError();
		AfxMessageBox(_T("memory exception"));
	}
	AND_CATCH(CException,e)
	{
		TCHAR szError[100];
		e->GetErrorMessage(szError,100);
		AfxMessageBox(szError);
	}
	END_CATCH
		
		
	CString sql = _T("select fusername from friend where fip = '"); //要执行的SQL语句
	
	sql += fip;
	sql += "'";
	
	CString psd; //存放查询结果
	
	TRY
	{
		
		rs.Open(AFX_DB_USE_DEFAULT_TYPE,sql); //打开查询记录
		
		
		if ( !rs.IsEOF()){
			
			rs.GetFieldValue(_T("fusername"),psd); //得到数据
	
			m_db.Close();
			return psd;
		}else{
			m_db.Close();
			return "";
		}
		
		
		
	}
	
	CATCH(CDBException,ex)
	{
		AfxMessageBox(ex->m_strError);
		AfxMessageBox(ex->m_strStateNativeOrigin);
	}
	AND_CATCH(CMemoryException,pEx)
	{
		pEx->ReportError();
		AfxMessageBox(_T("memory exception"));
	}
	END_CATCH
		
		
	return "";

}
//获取friend name
CString CEnyblock_IMDlg::find_friend_name()
{
	if(!UpdateData())
		return "";
	
	m_db.Close();
	
	//创建数据库连接
	TRY
	{
		m_db.OpenEx(_T("DSN=enyblock_im;"),CDatabase::noOdbcDialog);
		
		
		rs.m_pDatabase = &m_db;
	}
	CATCH(CDBException,ex)
	{
		AfxMessageBox(ex->m_strError);
		AfxMessageBox(ex->m_strStateNativeOrigin);
	}
	AND_CATCH(CMemoryException,pEx)
	{
		pEx->ReportError();
		AfxMessageBox(_T("memory exception"));
	}
	AND_CATCH(CException,e)
	{
		TCHAR szError[100];
		e->GetErrorMessage(szError,100);
		AfxMessageBox(szError);
	}
	END_CATCH
		
		
	CString sql = _T("select fusername from friend where username = '"); //要执行的SQL语句
	
	sql += m_username;
	sql += "'";
	
	CString psd; //存放查询结果
	
	TRY
	{
		
		rs.Open(AFX_DB_USE_DEFAULT_TYPE,sql); //打开查询记录
		
		
		while ( !rs.IsEOF()){
			
			rs.GetFieldValue(_T("fusername"),psd); //得到数据
			
			m_fname.Add(psd);
			
			rs.MoveNext();
		}
		
		
		m_db.Close();
		return psd;
		
		
		
	}
	
	CATCH(CDBException,ex)
	{
		AfxMessageBox(ex->m_strError);
		AfxMessageBox(ex->m_strStateNativeOrigin);
	}
	AND_CATCH(CMemoryException,pEx)
	{
		pEx->ReportError();
		AfxMessageBox(_T("memory exception"));
	}
	END_CATCH
		
		
	return "";

}


//获取friend IP地址
CString CEnyblock_IMDlg::find_friend_ip()
{

	if(!UpdateData())
		return "";
	
	m_db.Close();
	
	//创建数据库连接
	TRY
	{
		m_db.OpenEx(_T("DSN=enyblock_im;"),CDatabase::noOdbcDialog);
		
		
		rs.m_pDatabase = &m_db;
	}
	CATCH(CDBException,ex)
	{
		AfxMessageBox(ex->m_strError);
		AfxMessageBox(ex->m_strStateNativeOrigin);
	}
	AND_CATCH(CMemoryException,pEx)
	{
		pEx->ReportError();
		AfxMessageBox(_T("memory exception"));
	}
	AND_CATCH(CException,e)
	{
		TCHAR szError[100];
		e->GetErrorMessage(szError,100);
		AfxMessageBox(szError);
	}
	END_CATCH
		
		
		CString sql = _T("select fip from friend where username = '"); //要执行的SQL语句
	
	sql += m_username;
	sql += "'";
	
	CString psd; //存放查询结果
	
	TRY
	{

		rs.Open(AFX_DB_USE_DEFAULT_TYPE,sql); //打开查询记录
		
		
		while ( !rs.IsEOF()){
			
			rs.GetFieldValue(_T("fip"),psd); //得到数据

			m_fip.Add(psd);

			rs.MoveNext();
		}

			
		m_db.Close();
		return psd;
		
		
		
	}
	
	CATCH(CDBException,ex)
	{
		AfxMessageBox(ex->m_strError);
		AfxMessageBox(ex->m_strStateNativeOrigin);
	}
	AND_CATCH(CMemoryException,pEx)
	{
		pEx->ReportError();
		AfxMessageBox(_T("memory exception"));
	}
	END_CATCH
		
		
	return "";
}


//初始化contact 列表
void CEnyblock_IMDlg::init_tree_contact()
{
	//Log on 
	GetDlgItem(IDC_STATIC_LOG_ON)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_STATIC_INFORMATINO)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_STATIC_PASSWORD)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_STATIC_USERNAME)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_EDIT_PASSWORD)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_EDIT_USERNAME)->ShowWindow(SW_HIDE);
	
	
	//log on information
	GetDlgItem(IDC_PROGRESS1)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_BUTTON2)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_BUTTON1)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_STATIC_AUTHOR)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_STATIC_DATE)->ShowWindow(SW_HIDE);
	
	
	
	//设定m_contact_tree显示位置
	CRect rc;
	m_contact_tree.GetClientRect(rc);
	rc.top += 20;
	rc.bottom -= -400;
	rc.left +=12;
	rc.right -= -15;
	
	m_contact_tree.MoveWindow(&rc);

}

//插入联系人
void CEnyblock_IMDlg::insert_contact()
{
	int i = 0;

	while(i < m_fname.GetSize()){
		HTREEITEM hTreeItem = m_contact_tree.InsertItem(_T(m_fname.GetAt(i)+" ("+m_fip.GetAt(i)+")"));
		m_contact_tree.SetItemData(hTreeItem,i);
		i++;
	}
}

void CEnyblock_IMDlg::OnLogOn() 
{
	// TODO: Add your control notification handler code here


	if(!UpdateData())
		return;

	//判断用户名密码完全
	if (m_username.IsEmpty() || m_password.IsEmpty()){
		MessageBox("Uername or Password is empty!!","warning",MB_OK);
		return;
	}


	//进度条控制
	m_progress.SetRange(0,100);
	int i = 0;
	while (i < 100)
	{
		Sleep(10);
		m_progress.SetPos(i+1);
		i++;
		
	}


	
	//创建数据库连接
	TRY
	{
		m_db.OpenEx(_T("DSN=enyblock_im;"),CDatabase::noOdbcDialog);
		
		
		rs.m_pDatabase = &m_db;
	}
	CATCH(CDBException,ex)
	{
		AfxMessageBox(ex->m_strError);
		AfxMessageBox(ex->m_strStateNativeOrigin);
	}
	AND_CATCH(CMemoryException,pEx)
	{
		pEx->ReportError();
		AfxMessageBox(_T("memory exception"));
	}
	AND_CATCH(CException,e)
	{
		TCHAR szError[100];
		e->GetErrorMessage(szError,100);
		AfxMessageBox(szError);
	}
	END_CATCH


	CString sql = _T("select password FROM account where username = '"); //要执行的SQL语句

	sql += m_username;
	sql += "'";
	
	CString psd; //存放查询结果

	TRY
	{
		rs.Open(AFX_DB_USE_DEFAULT_TYPE,sql); //打开查询记录
			

		if ( !rs.IsEOF()){
		
			rs.GetFieldValue(_T("password"),psd); //得到数据
			


			if (psd == m_password){

					
				//	if (check_loged()){
				//		MessageBox("one case has been loged","faile",MB_OK);
				//		return;
				//	}

					MessageBox("log success","Congratulation",MB_OK);
					m_db.Close();
				

					CString ip;

					ip = get_local_ip();


					UpdateData(FALSE);
				//	if (update_ip(ip,m_username)){
						
						CString fip;
						CString fname;
					
						fip = find_friend_ip();
						find_friend_name();

						fname = find_friend_name_from_fip(fip); 		
						if (fip == "")
						{
							return;
						}else{

							//初始化contact 列表
							init_tree_contact();
								
								
							//CImageList m_list;
							
							//m_list.Create(IDB_HEAD,19,19,RGB(255,255,255));
							//	m_contact_tree.SetImageList(&m_list,TVSIL_NORMAL);
							
							insert_contact();
							
							//HTREEITEM hTreeItem = m_contact_tree.InsertItem(_T("Family"));
							//m_contact_tree.SetItemData(hTreeItem,0);
							
						//	HTREEITEM hItem = m_contact_tree.InsertItem(_T("mum(123456)"),hTreeItem);
						//	m_contact_tree.SetItemData(hItem,1);
							
							//m_contact_tree.InsertItem("Parent1",0,1);
							
							
							
							m_contact_tree.ShowWindow(SW_SHOW);
							
							
							


						

							
							
						}


						
						//				SetDlgItemText(IDC_IPADDRESS1,ip);
				//	}
					
	
					

								
				
			}else{
				MessageBox("log faile,check password","warning",MB_OK);
				m_db.Close();
			
				return;
			}
		}else{
			MessageBox("log faile,check username","warning",MB_OK);
			m_db.Close();
		
			return;
		}


	
	}
	CATCH(CDBException,ex)
	{
		AfxMessageBox(ex->m_strError);
		AfxMessageBox(ex->m_strStateNativeOrigin);
	}
	AND_CATCH(CMemoryException,pEx)
	{
		pEx->ReportError();
		AfxMessageBox(_T("memory exception"));
	}
	 END_CATCH

	

	
	
	

	
}

void CEnyblock_IMDlg::OnRegister() 
{
	// TODO: Add your control notification handler code here
	m_register.m_email = "";
	m_register.m_username = "";
	m_register.m_password = "";
	m_register.m_password_confirm = "";
	UpdateData(FALSE);
	m_register.DoModal();

}

BOOL CEnyblock_IMDlg::DestroyWindow() 
{
	// TODO: Add your specialized code here and/or call the base class
	
	log_out(m_username);

	return CDialog::DestroyWindow();
}

void CEnyblock_IMDlg::OnDblclkTreeContact(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	
	//get the mouse message point
	CPoint pt = GetCurrentMessage()->pt;
	
	//exchange the client point
	m_contact_tree.ScreenToClient(&pt);
	
	UINT uflag = 0;
	
	//hit test
	HTREEITEM item = m_contact_tree.HitTest(pt,&uflag);
	
	if ((item != NULL) && (TVHT_ONITEM & uflag))
	{
		m_contact_tree.SelectItem(item);
		int num = m_contact_tree.GetItemData(item);
		
		CMESSAGEBOX *m_message_box;
		
		m_message_box = new CMESSAGEBOX;
		
		m_message_box->Create(IDD_MESSAGE_BOX,this);
		
		m_message_box->set_ip(m_fip.GetAt(num));
		
		m_message_box->GetDlgItem(IDC_EDIT_SEND)->SetFocus();
								
		m_message_box->ShowWindow(SW_SHOW);
		
		m_message_box->get_friend_name(m_fname.GetAt(num));


		/*
		switch (num)
		{
			
		case 1:{

			AfxMessageBox(m_fname.GetAt(num));
			//MessageSendBox *message_send_box = new MessageSendBox;
			//message_send_box->DoModal();
			   }break;
			//AfxMessageBox("mum(123456)");break;
		case 2:{
			//MessageSendBox *message_send_box = new MessageSendBox;
			//message_send_box->DoModal();
			   }break;
			//AfxMessageBox("dad(13571933)");break;
		case 4: {
			//MessageSendBox *message_send_box = new MessageSendBox;
			//message_send_box->DoModal();
				}break;
			//AfxMessageBox("me(502525713)");break;
		default: ;
		}
		*/




	}

	*pResult = 0;
}
