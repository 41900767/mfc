// mfctestDoc.cpp : CmfctestDoc ���ʵ��
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


// CmfctestDoc ����/����

CmfctestDoc::CmfctestDoc()
{
	// TODO: �ڴ����һ���Թ������

}

CmfctestDoc::~CmfctestDoc()
{
}

BOOL CmfctestDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}




// CmfctestDoc ���л�

void CmfctestDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: �ڴ���Ӵ洢����
	}
	else
	{
		// TODO: �ڴ���Ӽ��ش���
	}
}


// CmfctestDoc ���

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


// CmfctestDoc ����
