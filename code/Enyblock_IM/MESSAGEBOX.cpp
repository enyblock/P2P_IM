// MESSAGEBOX.cpp : implementation file
//

#include "stdafx.h"
#include "Enyblock_IM.h"
#include "MESSAGEBOX.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMESSAGEBOX dialog


CMESSAGEBOX::CMESSAGEBOX(CWnd* pParent /*=NULL*/)
	: CDialog(CMESSAGEBOX::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMESSAGEBOX)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT


	
}


void CMESSAGEBOX::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMESSAGEBOX)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CMESSAGEBOX, CDialog)
	//{{AFX_MSG_MAP(CMESSAGEBOX)
	ON_BN_CLICKED(IDC_BUTTON_SEND, OnButtonSend)
	ON_BN_CLICKED(IDC_BUTTON_CANCLE, OnButtonCancle)
	ON_WM_CLOSE()
	//}}AFX_MSG_MAP
	ON_MESSAGE(WM_RECVDATA,OnRecvData)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMESSAGEBOX message handlers

BOOL CMESSAGEBOX::InitSocket()
{	


//	int   opt   =   1;  
// 	int   len   =   sizeof(opt);

	m_socket = socket(AF_INET,SOCK_DGRAM,0);

//	setsockopt(m_socket,   SOL_SOCKET,   SO_REUSEADDR,   &opt,   &len);



	if(INVALID_SOCKET == m_socket)
	{
		AfxMessageBox("创建套接字失败");
		return FALSE;
	}
	
	int flags = 1;  
	int flaglen = sizeof(flags); 

	//接收地址
	SOCKADDR_IN add_sock;
	add_sock.sin_family = AF_INET;
	add_sock.sin_port = htons(6000);
	add_sock.sin_addr.S_un.S_addr=htons(INADDR_ANY);
	int retval = 0;
	
	//绑定地址与套接字
	retval  =  bind(m_socket,(SOCKADDR*)&add_sock,sizeof(SOCKADDR));
	
	if (SOCKET_ERROR == retval)
	{
		closesocket(m_socket);
		
		AfxMessageBox("绑定失败！错误代码：");
		
		return FALSE;
	}

//	SO_LINGER＝0

	BOOL bReuseaddr=TRUE;
	setsockopt(m_socket,SOL_SOCKET,SO_REUSEADDR,(const char*)&bReuseaddr,sizeof(BOOL));
	

//	listen(m_socket,5);

	return TRUE;
}

BOOL CMESSAGEBOX::OnInitDialog() 
{
	CDialog::OnInitDialog();


	

	fip = "127.0.0.1";
	SetDlgItemText(IDC_IPADDRESS1,fip);



	CRect rcDlgs;
	this->GetWindowRect(rcDlgs);		//得到对话框的Rect 对话框的大小
	ScreenToClient(rcDlgs);             //把屏幕的值转成相应的实际的值
	
	int   cx   =   GetSystemMetrics(   SM_CXSCREEN   );  //获得屏幕的分辨率
	int   cy   =   GetSystemMetrics(   SM_CYSCREEN   ); 
	
	
	this->MoveWindow(cx-rcDlgs.Width()-(cx/4),cy-rcDlgs.Height()-(cy/2),rcDlgs.Width(),rcDlgs.Height(),SWP_NOSIZE);


	




	//初始化套接字
	InitSocket();
	// TODO: Add extra initialization here
	
	//创建线程
	RECVPARAM * pRecvParam = new RECVPARAM;
	
	pRecvParam->sock = m_socket;
	pRecvParam->hwnd = m_hWnd;
	HANDLE hThread=CreateThread(NULL,0,RecvProc,(LPVOID)pRecvParam,0,NULL);
	CloseHandle(hThread);




	



	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}


//线程处理函数
DWORD WINAPI CMESSAGEBOX::RecvProc(LPVOID lpParameter)
{
	SOCKET sock = ((RECVPARAM*)lpParameter)->sock;
	HWND   hwnd = ((RECVPARAM*)lpParameter)->hwnd;
	delete lpParameter;	
	
	SOCKADDR_IN addrFrom;
	int len   =  sizeof(SOCKADDR);
	
	char recvBuf[200];
	char tempBuf[300];
	
	int retval = 0;
	
	while (TRUE)
	{
		//接收套接字里面的数据
		retval = recvfrom(sock,recvBuf,200,0,(SOCKADDR*)&addrFrom,&len);
		if (SOCKET_ERROR == retval)
			break;
		
		//格式化数据
		//sprintf(tempBuf,"%s say:  %s",inet_ntoa(addrFrom.sin_addr),recvBuf);
		sprintf(tempBuf,"%s say:  %s",friend_name,recvBuf);
		//通过消息传递把tempbuf传给窗口
		::PostMessage(hwnd,WM_RECVDATA,0,(LPARAM)tempBuf);
	}
	
	
	
	
	
	return 0;

}


//消息响应函数实现
void CMESSAGEBOX::OnRecvData(WPARAM wParam, LPARAM lParam)
{
	CString str = (char*) lParam;
	CString strTemp;
	GetDlgItemText(IDC_EDIT_RECV,strTemp);

	str += "\r\n";
	
	str += strTemp;

	SetDlgItemText(IDC_EDIT_RECV,str);
}

void CMESSAGEBOX::OnButtonSend() 
{
	// TODO: Add your control notification handler code here
	// TODO: Add your control notification handler code here

	
	//通过句柄获得IP地址
	((CIPAddressCtrl*)GetDlgItem(IDC_IPADDRESS1))->GetAddress(m_dwIP);
	
	//初始化发送地址
	SOCKADDR_IN addrTo;
	addrTo.sin_family = AF_INET;
	addrTo.sin_port = htons(6000);
	addrTo.sin_addr.S_un.S_addr=htonl(m_dwIP);
	
	//发送数据
	CString strSend;
	char tempBuf[300];
	//获得编辑框内容
	GetDlgItemText(IDC_EDIT_SEND,strSend);

	sprintf(tempBuf,"me  say:  %s",strSend);

	CString strTemp;
	GetDlgItemText(IDC_EDIT_RECV,strTemp);
	
	CString temp;

	temp = tempBuf;

	temp += "\r\n";

	temp += strTemp;
	

	SetDlgItemText(IDC_EDIT_RECV,temp);



	//发送数据到套接字
	sendto(m_socket,strSend,strSend.GetLength()+1,0,
		(SOCKADDR*)&addrTo,sizeof(SOCKADDR));
	//设置发送编辑框设空
	SetDlgItemText(IDC_EDIT_SEND,"");
	
}

void CMESSAGEBOX::OnButtonCancle() 
{
	// TODO: Add your control notification handler code here

	char    HostName[100];
	
	CString strIPAddr;
	
	gethostname(HostName, sizeof(HostName));// 获得本机主机名.
	
	
	hostent* hn;
	hn = gethostbyname(HostName);                             //根据本机主机名得到本机ip
	
	
	strIPAddr=inet_ntoa(*(struct in_addr *)hn->h_addr_list[0]);//把ip换成字符串形式
	

	//通过句柄获得IP地址
//	((CIPAddressCtrl*)strIPAddr)->GetAddress(m_dwIP);
//	hostent&   he   =   *hn; 
//	sockaddr_in   sa; 
	
 //   memcpy   (   &sa.sin_addr.s_addr,   he.h_addr_list[0],he.h_length);
	

//	m_dwIP = (DWORD)sa.sin_addr.S_un.S_addr;

	 SetDlgItemText(IDC_IPADDRESS1,strIPAddr);

     AfxMessageBox(strIPAddr);
	
}



//设置IP地址
void CMESSAGEBOX::set_ip(CString ip)
{
	SetDlgItemText(IDC_IPADDRESS1,ip);
	UpdateData(FALSE);
}

BOOL CMESSAGEBOX::DestroyWindow() 
{
	// TODO: Add your specialized code here and/or call the base class

	

	
	
	return CDialog::DestroyWindow();
}


//获得friend name
void CMESSAGEBOX::get_friend_name(CString fname)
{
	friend_name = fname;
}

void CMESSAGEBOX::OnClose() 
{
	// TODO: Add your message handler code here and/or call default

	closesocket(m_socket);


	CDialog::OnClose();
}
