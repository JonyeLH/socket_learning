
// MFCsocket1.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMFCsocket1App: 
// �йش����ʵ�֣������ MFCsocket1.cpp
//

class CMFCsocket1App : public CWinApp
{
public:
	CMFCsocket1App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMFCsocket1App theApp;