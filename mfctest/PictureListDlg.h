#pragma once


// CPictureListDlg 对话框

class CPictureListDlg : public CDialog
{
	DECLARE_DYNAMIC(CPictureListDlg)

public:
	CPictureListDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CPictureListDlg();

// 对话框数据
	enum { IDD = IDD_PICTURELISTDLG };

protected:
	CListCtrl *m_plistCtrl;
	CImageList m_imageList;
	int m_imageW, m_imageH;

	bool  insertImageItem(const TCHAR* path);

	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
public:
	afx_msg void OnBnClickedButton1();
public:
	afx_msg void OnBnClickedAddPic();
};
