// mfctestView.cpp : CmfctestView 类的实现
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
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CmfctestView 构造/析构

CmfctestView::CmfctestView()
{
	// TODO: 在此处添加构造代码

}

CmfctestView::~CmfctestView()
{
}

BOOL CmfctestView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CmfctestView 绘制
extern VFrameBuffer gvfb;
void CmfctestView::OnDraw(CDC* pDC)
{
	CmfctestDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	gvfb.OnScreen(pDC->m_hDC, 0, 0);

	// TODO: 在此处为本机数据添加绘制代码
}


// CmfctestView 打印

BOOL CmfctestView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CmfctestView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CmfctestView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清除过程
}


// CmfctestView 诊断

#ifdef _DEBUG
void CmfctestView::AssertValid() const
{
	CView::AssertValid();
}

void CmfctestView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CmfctestDoc* CmfctestView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CmfctestDoc)));
	return (CmfctestDoc*)m_pDocument;
}
#endif //_DEBUG


// CmfctestView 消息处理程序
