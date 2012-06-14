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
	m_username = _T("");
	m_password = _T("");
	m_password_confirm = _T("");
	m_email = _T("");
	//}}AFX_DATA_INIT
}


void Register::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Register)
	DDX_Text(pDX, IDC_EDIT_USERNAME_REGISTER, m_username);
	DDX_Text(pDX, IDC_EDIT_PASSWORD_REGISTER, m_password);
	DDX_Text(pDX, IDC_EDIT_PASSWORD_C_REGISTER, m_password_confirm);
	DDX_Text(pDX, IDC_EDIT_EMAIL_REGISTER, m_email);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(Register, CDialog)
	//{{AFX_MSG_MAP(Register)
	ON_BN_CLICKED(IDC_BUTTON5, OnRegisterCancle)
	ON_BN_CLICKED(IDC_BUTTON4, OnRegister)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Register message handlers

void Register::OnRegisterCancle() 
{
	// TODO: Add your control notification handler code here
	this->OnCancel();
	
}

void Register::OnRegister() 
{
	// TODO: Add your control notification handler code here


	if(!check_register_eidtbox()){
		return;
	}else{

		if(check_username_exit()){
			MessageBox("username has been registerd!!","warning",MB_OK);

			return;
		}else{
			register_account();
			MessageBox("registe success!!","",MB_OK);
		}
	}
	
}


//���ע��༭��������
int Register::check_register_eidtbox()
{
	if(!UpdateData())
		return 0;
	
	//�ж��û���������ȫ
	if (m_username.IsEmpty() || m_password.IsEmpty() || m_password_confirm.IsEmpty() || m_email.IsEmpty()){
		MessageBox("informatino is not detial!!","warning",MB_OK);
		return 0;
	}
	
	if (m_password != m_password_confirm)
	{
		MessageBox("twice password not equal!!","warning",MB_OK);
		return 0;
	}
	
	
	if (-1 == m_email.Find('@'))
	{
		MessageBox("illegal email address!!","warning",MB_OK);
		return 0;
	}


	return 1;
}


//����û����Ƿ����
int Register::check_username_exit()
{
	if(!UpdateData())
		return 0;

	m_db.Close();

	//�������ݿ�����
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
		
		
	CString sql = _T("select username from account where username = '"); //Ҫִ�е�SQL���
	
	sql += m_username;
	sql += "'";
	
	CString psd; //��Ų�ѯ���
	
	TRY
	{
		rs.Open(AFX_DB_USE_DEFAULT_TYPE,sql); //�򿪲�ѯ��¼
		
		
		if ( !rs.IsEOF()){

				//�����û���Ϊ��
				m_username = "";
				//��������
				UpdateData(FALSE);
				//���ý���
				GetDlgItem(IDC_EDIT_USERNAME_REGISTER)-> SetFocus();
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


//ע���˻������ݿ���
int Register::register_account()
{
	if(!UpdateData())
		return 0;
	
	//�������ݿ�����
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
		
		
	CString sql = _T("insert into account(username,password,email) values('"); //Ҫִ�е�SQL���
	
	sql += m_username;
	sql += "','";
	sql += m_password;
	sql += "','";
	sql += m_email;
	sql += "')";
	

	
	TRY
	{
			m_db.ExecuteSQL(sql); //�򿪲�ѯ��¼
			m_db.Close();
			this->OnCancel();
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