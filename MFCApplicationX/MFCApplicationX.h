
// MFCApplicationX.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CMFCApplicationXApp:
// See MFCApplicationX.cpp for the implementation of this class
//

class CMFCApplicationXApp : public CWinApp
{
public:
	CMFCApplicationXApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CMFCApplicationXApp theApp;
