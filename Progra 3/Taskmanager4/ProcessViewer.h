// ----------------------------------------------------------------------------
// File Name:	    ProcessViewer.h
// Contents : 		ProcessViewer class definition.
// Originator: 	    Madhu Raykar.
// Date:		    04.12.05 
// Version:		    1.00.
// ----------------------------------------------------------------------------

#if !defined(AFX_PROCESSVIEWER_H__B4BDBCF9_3AEF_4827_B914_9244076B698D__INCLUDED_)
#define AFX_PROCESSVIEWER_H__B4BDBCF9_3AEF_4827_B914_9244076B698D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

typedef BOOL (CALLBACK *PROCENUMPROCESSINFO)( CString, INT, LPARAM lParam) ;

///////////////////////////////////////////////////////////////////////////// 
//
//	This class is responsible of loading the process information 
//	of a specified process ID.
//  This class uses a callback PROCENUMPROCESSINFO to send the
//  data back to the caller.
///////////////////////////////////////////////////////////////////////////// 
class CProcessViewer  
{
public:
	CProcessViewer();
	virtual ~CProcessViewer();

	BOOL GetProcessInfo( DWORD dwProcessID, 
						 PROCENUMPROCESSINFO lpProc, 
						 LPARAM lParam );
	BOOL Initialize(DWORD OSVersion);

private:

};

#endif // !defined(AFX_PROCESSVIEWER_H__B4BDBCF9_3AEF_4827_B914_9244076B698D__INCLUDED_)
