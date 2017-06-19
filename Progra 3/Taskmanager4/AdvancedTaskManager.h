// AdvancedTaskManager.h : main header file for the ADVANCEDTASKMANAGER application
//

#if !defined(AFX_ADVANCEDTASKMANAGER_H__7DC8F9ED_A6AB_4583_8EA5_377E2CE52999__INCLUDED_)
#define AFX_ADVANCEDTASKMANAGER_H__7DC8F9ED_A6AB_4583_8EA5_377E2CE52999__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CAdvancedTaskManagerApp:
// See AdvancedTaskManager.cpp for the implementation of this class
//

class CAdvancedTaskManagerApp : public CWinApp
{
public:
	CAdvancedTaskManagerApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAdvancedTaskManagerApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CAdvancedTaskManagerApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADVANCEDTASKMANAGER_H__7DC8F9ED_A6AB_4583_8EA5_377E2CE52999__INCLUDED_)
