// mfctest.h : mfctest Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CmfctestApp:
// �йش����ʵ�֣������ mfctest.cpp
//

class CmfctestApp : public CWinApp
{
public:
	CmfctestApp();


// ��д
public:
	virtual BOOL InitInstance();
	afx_msg void OnFileNewTest();
// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CmfctestApp theApp;