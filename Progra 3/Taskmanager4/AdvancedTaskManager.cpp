// ----------------------------------------------------------------------------
// File Name:	    AdvancedTaskManager.cpp
// Contents : 		Defines the class behaviors for the application.
// Originator: 	    Madhu Raykar.
// Date:		    04.12.05 
// Version:		    1.00.
// ----------------------------------------------------------------------------

#include "stdafx.h"
#include "AdvancedTaskManager.h"
#include "AdvancedTaskManagerDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


BEGIN_MESSAGE_MAP(CAdvancedTaskManagerApp, CWinApp)
	//{{AFX_MSG_MAP(CAdvancedTaskManagerApp)
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAdvancedTaskManagerApp construction

CAdvancedTaskManagerApp::CAdvancedTaskManagerApp()
{
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CAdvancedTaskManagerApp object

CAdvancedTaskManagerApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CAdvancedTaskManagerApp initialization

BOOL CAdvancedTaskManagerApp::InitInstance()
{
	AfxEnableControlContainer();

#ifdef _AFXDLL
	Enable3dControls();			
#else
	Enable3dControlsStatic();	
#endif

	CAdvancedTaskManagerDlg dlg;
	m_pMainWnd = &dlg;
	int nResponse = dlg.DoModal();

	return FALSE;
}
