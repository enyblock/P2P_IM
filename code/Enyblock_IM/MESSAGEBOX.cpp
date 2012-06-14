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
		AfxMessageBox("�����׽���ʧ��");
		return FALSE;
	}
	
	int flags = 1;  
	int flaglen = sizeof(flags); 

	//���յ�ַ
	SOCKADDR_IN add_sock;
	add_sock.sin_family = AF_INET;
	add_sock.sin_port = htons(6000);
	add_sock.sin_addr.S_un.S_addr=htons(INADDR_ANY);
	int retval = 0;
	
	//�󶨵�ַ���׽���
	retval  =  bind(m_socket,(SOCKADDR*)&add_sock,sizeof(SOCKADDR));
	
	if (SOCKET_ERROR == retval)
	{
		closesocket(m_socket);
		
		AfxMessageBox("��ʧ�ܣ�������룺");
		
		return FALSE;
	}

//	SO_LINGER��0

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
	this->GetWindowRect(rcDlgs);		//�õ��Ի����Rect �Ի���Ĵ�С
	ScreenToClient(rcDlgs);             //����Ļ��ֵת����Ӧ��ʵ�ʵ�ֵ
	
	int   cx   =   GetSystemMetrics(   SM_CXSCREEN   );  //�����Ļ�ķֱ���
	int   cy   =   GetSystemMetrics(   SM_CYSCREEN   ); 
	
	
	this->MoveWindow(cx-rcDlgs.Width()-(cx/4),cy-rcDlgs.Height()-(cy/2),rcDlgs.Width(),rcDlgs.Height(),SWP_NOSIZE);


	




	//��ʼ���׽���
	InitSocket();
	// TODO: Add extra initialization here
	
	//�����߳�
	RECVPARAM * pRecvParam = new RECVPARAM;
	
	pRecvParam->sock = m_socket;
	pRecvParam->hwnd = m_hWnd;
	HANDLE hThread=CreateThread(NULL,0,RecvProc,(LPVOID)pRecvParam,0,NULL);
	CloseHandle(hThread);




	



	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}


//�̴߳�����
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
		//�����׽������������
		retval = recvfrom(sock,recvBuf,200,0,(SOCKADDR*)&addrFrom,&len);
		if (SOCKET_ERROR == retval)
			break;
		
		//��ʽ������
		//sprintf(tempBuf,"%s say:  %s",inet_ntoa(addrFrom.sin_addr),recvBuf);
		sprintf(tempBuf,"%s say:  %s",friend_name,recvBuf);
		//ͨ����Ϣ���ݰ�tempbuf��������
		::PostMessage(hwnd,WM_RECVDATA,0,(LPARAM)tempBuf);
	}
	
	
	
	
	
	return 0;

}


//��Ϣ��Ӧ����ʵ��
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

	
	//ͨ��������IP��ַ
	((CIPAddressCtrl*)GetDlgItem(IDC_IPADDRESS1))->GetAddress(m_dwIP);
	
	//��ʼ�����͵�ַ
	SOCKADDR_IN addrTo;
	addrTo.sin_family = AF_INET;
	addrTo.sin_port = htons(6000);
	addrTo.sin_addr.S_un.S_addr=htonl(m_dwIP);
	
	//��������
	CString strSend;
	char tempBuf[300];
	//��ñ༭������
	GetDlgItemText(IDC_EDIT_SEND,strSend);

	sprintf(tempBuf,"me  say:  %s",strSend);

	CString strTemp;
	GetDlgItemText(IDC_EDIT_RECV,strTemp);
	
	CString temp;

	temp = tempBuf;

	temp += "\r\n";

	temp += strTemp;
	

	SetDlgItemText(IDC_EDIT_RECV,temp);



	//�������ݵ��׽���
	sendto(m_socket,strSend,strSend.GetLength()+1,0,
		(SOCKADDR*)&addrTo,sizeof(SOCKADDR));
	//���÷��ͱ༭�����
	SetDlgItemText(IDC_EDIT_SEND,"");
	
}

void CMESSAGEBOX::OnButtonCancle() 
{
	// TODO: Add your control notification handler code here

	char    HostName[100];
	
	CString strIPAddr;
	
	gethostname(HostName, sizeof(HostName));// ��ñ���������.
	
	
	hostent* hn;
	hn = gethostbyname(HostName);                             //���ݱ����������õ�����ip
	
	
	strIPAddr=inet_ntoa(*(struct in_addr *)hn->h_addr_list[0]);//��ip�����ַ�����ʽ
	

	//ͨ��������IP��ַ
//	((CIPAddressCtrl*)strIPAddr)->GetAddress(m_dwIP);
//	hostent&   he   =   *hn; 
//	sockaddr_in   sa; 
	
 //   memcpy   (   &sa.sin_addr.s_addr,   he.h_addr_list[0],he.h_length);
	

//	m_dwIP = (DWORD)sa.sin_addr.S_un.S_addr;

	 SetDlgItemText(IDC_IPADDRESS1,strIPAddr);

     AfxMessageBox(strIPAddr);
	
}



//����IP��ַ
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


//���friend name
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
