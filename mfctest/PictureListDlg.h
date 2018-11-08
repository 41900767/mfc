#pragma once


// CPictureListDlg �Ի���

class CPictureListDlg : public CDialog
{
	DECLARE_DYNAMIC(CPictureListDlg)

public:
	CPictureListDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CPictureListDlg();

// �Ի�������
	enum { IDD = IDD_PICTURELISTDLG };

protected:
	CListCtrl *m_plistCtrl;
	CImageList m_imageList;
	int m_imageW, m_imageH;

	bool  insertImageItem(const TCHAR* path);

	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
public:
	afx_msg void OnBnClickedButton1();
public:
	afx_msg void OnBnClickedAddPic();
};
