// ----------------------------------------------------------------------------
// File Name:	    AdvancedTaskManagerDlg.cpp
// Contents : 		Implementation of AdvancedTaskManagerDlg class.
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

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


///////////////////////////////////////////////////////////////////////////// 
// Call back for ProcessViewer.
// This method is passed as a call back to process viewer and the details
// of the process is loaded into the contols by this method.
/////////////////////////////////////////////////////////////////////////////
BOOL CALLBACK ProcessInfoProc( CString strItemName, INT nValue, LPARAM lParam) 
{
	CListCtrl* p_ListCtrl = NULL;
	CString strVaue;

	// Get the handle to the control where the data has to be loaded.
	p_ListCtrl = (CListCtrl*)AfxGetMainWnd()->GetDlgItem(IDC_LIST_PROCESS_PROPERTIES);
	if(p_ListCtrl != NULL)
	{
		int nIndex = p_ListCtrl->GetItemCount();
		strVaue.Format("%d", nValue);
		//strVaue.Format("0x%08X", nValue);

		// Load the data to the controls
		p_ListCtrl->InsertItem(nIndex, strItemName, nIndex);
		p_ListCtrl->SetItemText(nIndex, 1, strVaue);	
	}

	return TRUE;
}

///////////////////////////////////////////////////////////////////////////// 
// Call back for VersionViewer.
// This method is passed as a call back to version viewer and the details
// of the version is loaded into the contols by this method.
/////////////////////////////////////////////////////////////////////////////
BOOL CALLBACK VersionInfoProc( 
							  CString& strItemName, 
							  CString& strItemValue, 
							  LPARAM lParam) 
{
	CListCtrl* p_ListCtrl = NULL;

	// Get the handle to the control where the data has to be loaded.
	p_ListCtrl = (CListCtrl*)AfxGetMainWnd()->GetDlgItem(IDC_LIST_PROPERTIES);
	if(p_ListCtrl != NULL)
	{
		int nIndex = p_ListCtrl->GetItemCount();

		// Load the data to the controls
		p_ListCtrl->InsertItem(nIndex, strItemName, nIndex);
		p_ListCtrl->SetItemText(nIndex, 1, strItemValue);	
	}

	return TRUE;
}

///////////////////////////////////////////////////////////////////////////// 
// Call back for ProcessEnumerator.
// This method is passed as a call back to Process Enumerator and all the 
// processes are listed into the contols by this method.
/////////////////////////////////////////////////////////////////////////////
BOOL CALLBACK EnumProcessProc( 
							  DWORD dwProcessID, 
							  WORD wdTaskNo, 
							  LPSTR lpstrFilePath, 
							  LPARAM lParam )
{
	CString strTemp;
	CListCtrl* p_ListCtrl = NULL;
	
	// Get the handle to the control where the data has to be loaded.
	p_ListCtrl = (CListCtrl*)AfxGetMainWnd()->GetDlgItem(IDC_LIST_PROCESS);

	if((p_ListCtrl != NULL) && (strlen(lpstrFilePath) != 0))
	{
		// Load the data to the controls
		CString strFileName;
		TCHAR tszFileName [MAX_PATH];
		TCHAR tszFileExt [MAX_PATH];
		_splitpath(lpstrFilePath, NULL, NULL, tszFileName, tszFileExt);

		strFileName = strFileName + tszFileName + tszFileExt;
		p_ListCtrl->InsertItem(0, strFileName, 0);

		strTemp.Format("%d", dwProcessID);
		p_ListCtrl->SetItemText(0, 1, strTemp);

		strTemp.Format("%d", wdTaskNo);
		p_ListCtrl->SetItemText(0, 2, strTemp);
		p_ListCtrl->SetItemText(0, 3, lpstrFilePath);	
	}
	
	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CAdvancedTaskManagerDlg dialog

CAdvancedTaskManagerDlg::CAdvancedTaskManagerDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAdvancedTaskManagerDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAdvancedTaskManagerDlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CAdvancedTaskManagerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAdvancedTaskManagerDlg)
	DDX_Control(pDX, IDC_LIST_PROCESS_PROPERTIES, m_CtrlProcessPropList);
	DDX_Control(pDX, IDC_LIST_PROPERTIES, m_CtrlProcessProp);
	DDX_Control(pDX, IDC_LIST_PROCESS, m_CtrlProcessList);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAdvancedTaskManagerDlg, CDialog)
	//{{AFX_MSG_MAP(CAdvancedTaskManagerDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDREFRESH, OnRefresh)
	ON_BN_CLICKED(ID_ENDTASK, OnEndtask)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST_PROCESS, OnItemchangedListProcess)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAdvancedTaskManagerDlg message handlers

BOOL CAdvancedTaskManagerDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	DWORD OSVersion = 0;
	if(CheckOSVersion(OSVersion) == FALSE)
	{
		AfxMessageBox("This application runs only on Windows NT or Windows 2000");
		PostQuitMessage(0);
	}

	InitilizeViews();

	if(m_ProcessEnumViewer.Initialize(OSVersion) == FALSE)
	{
		AfxMessageBox("Could not Initialize process enum viewer");
		return FALSE;
	}
	
	if(m_VersionViewer.Initialize(OSVersion) == FALSE)
	{
		AfxMessageBox("Could not Initialize version viewer");
		return FALSE;
	}

	if(m_ProcessViewer.Initialize(OSVersion) == FALSE)
	{
		AfxMessageBox("Could not Initialize process viewer");
		return FALSE;
	}
	
	OnRefresh();	
	return TRUE;  
}

void CAdvancedTaskManagerDlg::InitilizeViews()
{
	m_CtrlProcessList.InsertColumn(0, _T("Process Name"), LVCFMT_LEFT, 100);
	m_CtrlProcessList.InsertColumn(1, _T("Process ID"), LVCFMT_LEFT, 75);
	m_CtrlProcessList.InsertColumn(2, _T("Task no"), LVCFMT_LEFT, 75);
	m_CtrlProcessList.InsertColumn(3, _T("Path"), LVCFMT_LEFT, 40);
	
	m_CtrlProcessList.SetItemState(0, LVIS_SELECTED, LVIS_SELECTED);
	m_CtrlProcessList.ModifyStyle(LVS_TYPEMASK,LVS_REPORT);
	m_CtrlProcessList.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	m_CtrlProcessProp.InsertColumn(0, _T(" "), LVCFMT_LEFT, 100);
	m_CtrlProcessProp.InsertColumn(1, _T(" "), LVCFMT_LEFT, 250);
	
	m_CtrlProcessProp.SetItemState(0, LVIS_SELECTED, LVIS_SELECTED);
	m_CtrlProcessProp.ModifyStyle(LVS_TYPEMASK,LVS_REPORT);
	m_CtrlProcessProp.SetExtendedStyle(LVS_EX_FULLROWSELECT);
	//m_CtrlProcessProp.SetTextColor(RGB(0,0,255));

	m_CtrlProcessPropList.InsertColumn(0, _T(" "), LVCFMT_LEFT, 200);
	m_CtrlProcessPropList.InsertColumn(1, _T(" "), LVCFMT_LEFT, 100);
	
	m_CtrlProcessPropList.SetItemState(0, LVIS_SELECTED, LVIS_SELECTED);
	m_CtrlProcessPropList.ModifyStyle(LVS_TYPEMASK,LVS_REPORT);
	m_CtrlProcessPropList.SetExtendedStyle(LVS_EX_FULLROWSELECT);


}

void CAdvancedTaskManagerDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CAdvancedTaskManagerDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CAdvancedTaskManagerDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CAdvancedTaskManagerDlg::OnRefresh() 
{
	// Requery everything..
	m_CtrlProcessList.DeleteAllItems();
	m_CtrlProcessProp.DeleteAllItems();
	m_CtrlProcessPropList.DeleteAllItems();

	m_ProcessEnumViewer.EnumProcs(&EnumProcessProc, 0);

	m_CtrlProcessList.SetItem(0 , 0, LVIF_STATE, NULL, 0, LVIS_SELECTED, LVIS_SELECTED, 0);
	m_CtrlProcessList.SetSelectionMark(0);
	m_CtrlProcessList.SetFocus();
}

void CAdvancedTaskManagerDlg::OnEndtask() 
{
	CString strSelected;
	int nCount  = m_CtrlProcessList.GetItemCount();
	
	// Terminate the selected processes
	for (int i = 0; i <= nCount; i++)
	{
		if(m_CtrlProcessList.GetItemState(i, LVIS_SELECTED) == LVIS_SELECTED) 
		{
			DWORD dwProcessId;
			strSelected = m_CtrlProcessList.GetItemText(i, 1) ;

			dwProcessId = atoi(strSelected.operator LPCTSTR());

		    HANDLE hProcess = OpenProcess(PROCESS_TERMINATE ,
											FALSE, dwProcessId) ;
			if( hProcess != NULL )
			{
				DWORD ExitCode;
				GetExitCodeProcess(hProcess, &ExitCode);
				if(TerminateProcess  (hProcess, ExitCode) == FALSE)
				{
					AfxMessageBox("Could not terminate process");
				}
			}
			else
			{
				AfxMessageBox("You do not have permission to 'END' this Task");
			}
		}
	}
	// Wait till processes end..
	Sleep(500);
	OnRefresh();	
}

void CAdvancedTaskManagerDlg::OnCancel() 
{
	CDialog::OnCancel();
}

void CAdvancedTaskManagerDlg::OnItemchangedListProcess(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;
	
	m_CtrlProcessProp.DeleteAllItems();
	m_CtrlProcessPropList.DeleteAllItems();

	int nCount  = m_CtrlProcessList.GetItemCount();
	int nItemsSelected = 0;	
	for (int nIndex = 0; nIndex <= nCount; nIndex++)
	{
		if(m_CtrlProcessList.GetItemState(nIndex, LVIS_SELECTED) == LVIS_SELECTED) 
		{
			nItemsSelected++;
			if(nItemsSelected > 1)
			{
				m_CtrlProcessProp.DeleteAllItems();
				m_CtrlProcessPropList.DeleteAllItems();
				break;
			}
			
			CString strSelected = m_CtrlProcessList.GetItemText(nIndex, 3) ;
			m_VersionViewer.GetVersionInfo( strSelected, VersionInfoProc, NULL);

			int nProcessId = atoi(m_CtrlProcessList.GetItemText(nIndex, 1));
			m_ProcessViewer.GetProcessInfo( nProcessId, ProcessInfoProc, NULL);
		}
	}

	*pResult = 0;
}


BOOL CAdvancedTaskManagerDlg::CheckOSVersion(DWORD &OSVersion)
{
	OSVERSIONINFO  osver ;
	
	// Check to see if were running under Windows95 or
	// Windows NT.
	osver.dwOSVersionInfoSize = sizeof( osver ) ;
	if( !GetVersionEx( &osver ) )
	{
		return FALSE ;
	}
	OSVersion = osver.dwPlatformId;

	if( (OSVersion == VER_PLATFORM_WIN32_NT ) ||
		(OSVersion == VER_PLATFORM_WIN32_WINDOWS) )
	{
		return TRUE;
	}		

	return FALSE ;
}
