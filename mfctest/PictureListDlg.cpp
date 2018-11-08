// PictureListDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "mfctest.h"
#include "PictureListDlg.h"
#include <atlimage.h>

// CPictureListDlg �Ի���

IMPLEMENT_DYNAMIC(CPictureListDlg, CDialog)

CPictureListDlg::CPictureListDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPictureListDlg::IDD, pParent)
{

}

CPictureListDlg::~CPictureListDlg()
{
}

void CPictureListDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CPictureListDlg, CDialog)
	ON_BN_CLICKED(IDC_ADD_PIC, &CPictureListDlg::OnBnClickedAddPic)
END_MESSAGE_MAP()


// CPictureListDlg ��Ϣ�������

BOOL CPictureListDlg::OnInitDialog()
{
	CDialog::OnInitDialog();


	m_plistCtrl = (CListCtrl*) GetDlgItem(IDC_LIST_PIC);
	//Status a = GdiplusStartup(&m_gdiplusToken, &m_gdiplusStartupInput, NULL );  //��ʼ��GDI+


	m_plistCtrl->SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);
	m_plistCtrl->SetIconSpacing(CSize(140, 130));     //set pictures spacing

	m_imageW = 120;
	m_imageH = 90;
	m_imageList.Create(m_imageW, m_imageH, ILC_COLORDDB|ILC_COLOR32, 1, 1);     //wide of picture is 120,height is 90
	m_plistCtrl->SetImageList(&m_imageList,LVSIL_NORMAL);     //CImageList associates CListCtrl

	//insertImageItem(_T("D:/work//wuseng1.png"));  //����·��

	return TRUE;  // return TRUE  un
}

bool  CPictureListDlg::insertImageItem(const TCHAR* path)
{
#if 0
	CBitmap bmp(path);                     //����ͼƬ·��

	int sourceWidth = m_imageW;           //���ͼƬ���,���120�ʹ�����120������ͬ��
	int sourceHeight = bmp.GetHeight();   //���ͼƬ���                                   
	if(sourceHeight>m_imageH)             //��m_ImageList.Create(120��)�кܴ��ϵ�����С����
	{
		sourceHeight= m_imageH;           //���Ŀ�ȣ�ͼƬ���޷���ʾ
	}


	Bitmap* pThumbnail = (Bitmap*)bmp.GetThumbnailImage(sourceWidth, sourceHeight, NULL, NULL); //�趨����ͼ�Ĵ�С
	HBITMAP hBmp;
	pThumbnail->GetHBITMAP(Color(255,255,255),&hBmp);
	CBitmap *pImage = CBitmap::FromHandle(hBmp);         //ת����CBitmap��ʽλͼ

	TCHAR drive[MAX_PATH] = _T("");
	TCHAR dir[MAX_PATH] = _T("");
	TCHAR fname[MAX_PATH] = _T("");
	TCHAR ext[MAX_PATH] = _T("");

	_wsplitpath(path ,drive, dir,fname, ext);
	CString itemName(fname);
	itemName.Append(ext);

	int index = m_imageList.Add(pImage,RGB(255,255, 255));
	m_listCtrl.InsertItem(index, itemName, index);               // itemName,���Լ��跨�õ�ͼƬƬ�����֡����ֻ���ʾ��ͼƬ��
#endif
	CImage img;
	if(img.Load(path) == NOERROR){
		HDC hTempDC;
		hTempDC = CreateCompatibleDC(NULL);
		
		HBITMAP hTempBmp = CreateCompatibleBitmap(::GetDC(NULL), m_imageW, m_imageH);
		hTempBmp = (HBITMAP)SelectObject(hTempDC, hTempBmp);

		::SetStretchBltMode(hTempDC, HALFTONE);
		img.StretchBlt(hTempDC, 0, 0, m_imageW, m_imageH, 0, 0, img.GetWidth(), img.GetHeight(), SRCCOPY);
		//img.BitBlt(hTempDC, 0, 0, SRCCOPY);

		hTempBmp = (HBITMAP)SelectObject(hTempDC, hTempBmp);
		//HBITMAP hbmp =(HBITMAP)img.operator HBITMAP();
		HBITMAP hbmp =hTempBmp;
		CBitmap cbmp;
		cbmp.Attach(hbmp);
		
		static int i = 0;

		m_imageList.Add(&cbmp,(CBitmap*)NULL);
		m_plistCtrl->InsertItem(0, path, i);
		cbmp.Detach();
		DeleteObject(hTempBmp);
		DeleteDC(hTempDC);

		i ++;
	}

	
	return true;
}
void CPictureListDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}

void CPictureListDlg::OnBnClickedAddPic()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString filter;
	CString dir = TEXT("*.jpg");

	filter=TEXT("ͼƬ�ļ�(*.jpg,*.bmp)|*.jpg;*.bmp;*.png|(*.bmp)|*.bmp||");  

	//filter=TEXT("�ı��ĵ�(*.txt)|*.txt|PDF�ĵ�(*.pdf)|*.pdf||");
	//CFileDialog dlg(TRUE, NULL, dir, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, filter, NULL);  
	CFileDialog dlg(TRUE, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, filter, NULL);  
	if(dlg.DoModal() == IDOK){
		insertImageItem(dlg.GetPathName().GetString());
	}
}
