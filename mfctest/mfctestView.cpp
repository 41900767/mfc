// mfctestView.cpp : CmfctestView ���ʵ��
//

#include "stdafx.h"
#include "mfctest.h"

#include "mfctestDoc.h"
#include "mfctestView.h"
#include "VFrameBuffer.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CmfctestView

IMPLEMENT_DYNCREATE(CmfctestView, CView)

BEGIN_MESSAGE_MAP(CmfctestView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CmfctestView ����/����

CmfctestView::CmfctestView()
{
	// TODO: �ڴ˴���ӹ������

}

CmfctestView::~CmfctestView()
{
}

BOOL CmfctestView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CmfctestView ����
extern VFrameBuffer gvfb;
void CmfctestView::OnDraw(CDC* pDC)
{
	CmfctestDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	gvfb.OnScreen(pDC->m_hDC, 0, 0);

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CmfctestView ��ӡ

BOOL CmfctestView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CmfctestView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CmfctestView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CmfctestView ���

#ifdef _DEBUG
void CmfctestView::AssertValid() const
{
	CView::AssertValid();
}

void CmfctestView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CmfctestDoc* CmfctestView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CmfctestDoc)));
	return (CmfctestDoc*)m_pDocument;
}
#endif //_DEBUG


// CmfctestView ��Ϣ�������
