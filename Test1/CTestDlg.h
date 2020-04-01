#pragma once


// CTestDlg 对话框

class CTestDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CTestDlg)

public:
	CTestDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CTestDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_TEST };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit2();
private:
	CString m_user;
	CString m_pwd;
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnClose();
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton2();
};
