#pragma once

#include <atlimage.h>
// CPictestDlg 对话框

class CPictestDlg : public CDialog
{
	DECLARE_DYNAMIC(CPictestDlg)
	
public:
	CPictestDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CPictestDlg();


// 对话框数据
	enum { IDD = IDD_PIC_TEST };

protected:
	HANDLE m_hFind;
	CImage m_img;
	WIN32_FIND_DATA m_fd;
	CString m_Path;
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedNxt();
public:
	virtual BOOL OnInitDialog();
public:
	afx_msg void OnPaint();
};
