// mfctestDoc.h : CmfctestDoc ��Ľӿ�
//


#pragma once


class CmfctestDoc : public CDocument
{
protected: // �������л�����
	CmfctestDoc();
	DECLARE_DYNCREATE(CmfctestDoc)

// ����
public:

// ����
public:

// ��д
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

// ʵ��
public:
	virtual ~CmfctestDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};


