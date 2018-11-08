// mfctestDoc.cpp : CmfctestDoc 类的实现
//

#include "stdafx.h"
#include "mfctest.h"

#include "mfctestDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CmfctestDoc

IMPLEMENT_DYNCREATE(CmfctestDoc, CDocument)

BEGIN_MESSAGE_MAP(CmfctestDoc, CDocument)
END_MESSAGE_MAP()


// CmfctestDoc 构造/析构

CmfctestDoc::CmfctestDoc()
{
	// TODO: 在此添加一次性构造代码

}

CmfctestDoc::~CmfctestDoc()
{
}

BOOL CmfctestDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}




// CmfctestDoc 序列化

void CmfctestDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 在此添加存储代码
	}
	else
	{
		// TODO: 在此添加加载代码
	}
}


// CmfctestDoc 诊断

#ifdef _DEBUG
void CmfctestDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CmfctestDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CmfctestDoc 命令
