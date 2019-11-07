
// HW1.h : main header file for the HW1 application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CHW1App:
// See HW1.cpp for the implementation of this class
//

class CHW1App : public CWinApp
{
public:
	CHW1App() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CHW1App theApp;
