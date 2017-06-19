// ----------------------------------------------------------------------------
// File Name:	    ProcessViewer.cpp
// Contents : 		Implementation of ProcessViewer class.
// Originator: 	    Madhu Raykar.
// Date:		    04.12.05 
// Version:		    1.00.
// ----------------------------------------------------------------------------

#include "stdafx.h"
#include "AdvancedTaskManager.h"
#include "ProcessViewer.h"
#include "psapi.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CProcessViewer::CProcessViewer()
{

}

CProcessViewer::~CProcessViewer()
{

}

BOOL CProcessViewer::GetProcessInfo( DWORD dwProcessID, 
					 PROCENUMPROCESSINFO lpProc, 
					 LPARAM lParam )
{
	HANDLE hProcess;
	PROCESS_MEMORY_COUNTERS pmc;


	hProcess = OpenProcess(  PROCESS_QUERY_INFORMATION |
                                    PROCESS_VM_READ,
                                    FALSE, dwProcessID );
    if (NULL == hProcess)
        return FALSE;

    if ( GetProcessMemoryInfo( hProcess, &pmc, sizeof(pmc)) )//Archivo de Paginacion
    {
		lpProc(_T("PageFaultCount"), pmc.PageFaultCount, lParam);
        lpProc(_T("PeakWorkingSetSize"), pmc.PeakWorkingSetSize, lParam);
        lpProc(_T("WorkingSetSize"), pmc.WorkingSetSize, lParam);
        lpProc(_T("QuotaPeakPagedPoolUsage"), pmc.QuotaPeakPagedPoolUsage, lParam);
        lpProc(_T("QuotaPagedPoolUsage"), pmc.QuotaPagedPoolUsage, lParam);
		lpProc(_T("QuotaPeakNonPagedPoolUsage"), pmc.QuotaPeakNonPagedPoolUsage, lParam);
		lpProc(_T("QuotaNonPagedPoolUsage"), pmc.QuotaNonPagedPoolUsage, lParam);
        lpProc(_T("PagefileUsage"), pmc.PagefileUsage, lParam);
        lpProc(_T("PeakPagefileUsage"), pmc.PeakPagefileUsage , lParam);

    }

    CloseHandle( hProcess );
	return TRUE;

}

BOOL CProcessViewer::Initialize(DWORD OSVersion)
{
	return TRUE;
}

