// CTestDlg.cpp: 实现文件
//

#include "pch.h"
#include "Test1.h"
#include "CTestDlg.h"
#include "afxdialogex.h"
#include "InfoFile.h"


// CTestDlg 对话框

IMPLEMENT_DYNAMIC(CTestDlg, CDialogEx)

CTestDlg::CTestDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_TEST, pParent)
	, m_user(_T(""))
	, m_pwd(_T(""))
{

}

CTestDlg::~CTestDlg()
{
}

void CTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_user);
	DDX_Text(pDX, IDC_EDIT2, m_pwd);
}


BEGIN_MESSAGE_MAP(CTestDlg, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT2, &CTestDlg::OnEnChangeEdit2)
	ON_BN_CLICKED(IDC_BUTTON1, &CTestDlg::OnBnClickedButton1)
	ON_WM_CLOSE()
END_MESSAGE_MAP()


// CTestDlg 消息处理程序


void CTestDlg::OnEnChangeEdit2()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CTestDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码

	//单击确认,登陆窗口
	UpdateData(TRUE);

	//获取到正确值
	CInfoFile file;
	CString name, pwd;
	file.ReadLogin(name, pwd);
	
	if (m_user.IsEmpty()||m_pwd.IsEmpty())
	{	
		MessageBoxW(TEXT("登陆名和密码不能为空"));
		return;
	}


	if (name==m_user)
	{	
		if (pwd==m_pwd)
		{
			//关闭当前对话框
			CDialog::OnCancel();
			//MessageBoxW(TEXT("登陆名不存在"));
		} 
		else
		{
			MessageBoxW(TEXT("密码不正确"));

		}
	} 
	else
	{
		MessageBoxW(TEXT("登陆名或密码不正确"));

	}


}


void CTestDlg::OnClose()//关闭整个程序
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	exit(0);
	CDialogEx::OnClose();
}


void CTestDlg::OnOK()
{
	// TODO: 在此添加专用代码和/或调用基类

	//CDialogEx::OnOK();
}


BOOL CTestDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化


	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
