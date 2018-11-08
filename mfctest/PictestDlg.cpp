

// PictestDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "mfctest.h"
#include "PictestDlg.h"


// CPictestDlg �Ի���

IMPLEMENT_DYNAMIC(CPictestDlg, CDialog)

CPictestDlg::CPictestDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPictestDlg::IDD, pParent)
{
	
}

CPictestDlg::~CPictestDlg()
{
}

void CPictestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CPictestDlg, CDialog)
	ON_BN_CLICKED(IDC_NEXT, &CPictestDlg::OnBnClickedNxt)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CPictestDlg ��Ϣ�������

void CPictestDlg::OnBnClickedNxt()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	DWORD dwTick = GetTickCount();
	FindNextFile(m_hFind, &m_fd);
	//Sleep(200);
	
	CString cPath = m_Path;
	cPath.Append(m_fd.cFileName);
	m_img.Destroy();

	m_img.Load(cPath);

	dwTick = GetTickCount() - dwTick;
	//dwTick += 30;
	if(dwTick < 300)
		Sleep(300 - dwTick);
	InvalidateRect(NULL, TRUE);
	
}

BOOL CPictestDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	MoveWindow(0, 0, 800, 480);
	 m_Path = TEXT("C:\\Users\\Administrator.KO4B3DUASSQRBNR\\Desktop\\DCIM\\Camera\\");
	
	CString cPath = m_Path;
	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	SetDlgItemText(IDC_EDIT_PATH, m_Path);
	cPath.Append(TEXT("*.jpg"));
	m_hFind = FindFirstFile(cPath, &m_fd);


	cPath = m_Path;
	cPath.Append(m_fd.cFileName);
	m_img.Load(cPath);

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}

void CPictestDlg::OnPaint()
{

	DWORD dwTick = GetTickCount();
	CPaintDC dc(this); // device context for painting


	RECT rt;
	GetClientRect(&rt);

	RECT src;
	src.left = 0;
	src.top = 0;
	src.right = m_img.GetWidth();
	src.bottom = m_img.GetHeight();
	::SetStretchBltMode(dc.m_hDC, HALFTONE);
	//m_img.StretchBlt(dc.m_hDC, rt, src, SRCCOPY);
	POINT pt;
	pt.x = 0;
	pt.y = 0;
	m_img.BitBlt(dc.m_hDC, rt, pt,SRCCOPY);
	dwTick = GetTickCount() - dwTick;

}
