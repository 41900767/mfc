// mfctestView.h : CmfctestView ��Ľӿ�
//


#pragma once


class CmfctestView : public CView
{
protected: // �������л�����
	CmfctestView();
	DECLARE_DYNCREATE(CmfctestView)

// ����
public:
	CmfctestDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CmfctestView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // mfctestView.cpp �еĵ��԰汾
inline CmfctestDoc* CmfctestView::GetDocument() const
   { return reinterpret_cast<CmfctestDoc*>(m_pDocument); }
#endif

