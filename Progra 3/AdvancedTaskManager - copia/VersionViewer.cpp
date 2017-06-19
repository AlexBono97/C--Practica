// ----------------------------------------------------------------------------
// File Name:	    VersionViewer.cpp
// Contents : 		Implementation of VersionViewer class.
// Originator: 	    Madhu Raykar.
// Date:		    04.12.05 
// Version:		    1.00.
// ----------------------------------------------------------------------------

#include "stdafx.h"
#include "AdvancedTaskManager.h"
#include "VersionViewer.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CVersionViewer::CVersionViewer()
{

}

CVersionViewer::~CVersionViewer()
{

}

BOOL CVersionViewer::Initialize(DWORD OSVersion)
{
	return TRUE;
}

BOOL CVersionViewer::GetVersionInfo( LPCTSTR strFileName, PROCENUMVERSIONINFO lpProc, LPARAM lParam )
{
	lpProc(CString("Path"), CString(strFileName), lParam);

	SendData(lpProc, VERINFO_ProductName, strFileName, lParam);
	SendData(lpProc, VERINFO_CompanyName, strFileName, lParam);
	SendData(lpProc, VERINFO_ProductVersion, strFileName, lParam);
	SendData(lpProc, VERINFO_comments, strFileName, lParam);
	SendData(lpProc, VERINFO_FileDescrib, strFileName, lParam);
	SendData(lpProc, VERINFO_FileVersion, strFileName, lParam);
	SendData(lpProc, VERINFO_InternalName, strFileName, lParam);
	SendData(lpProc, VERINFO_LegalCopyright, strFileName, lParam);
	SendData(lpProc, VERINFO_LegalTrademarks, strFileName, lParam);
	SendData(lpProc, VERINFO_OriginalFilename, strFileName, lParam);
	SendData(lpProc, VERINFO_PrivateBuild, strFileName, lParam);
	SendData(lpProc, VERINFO_SpecialBuild, strFileName, lParam);

	return TRUE;
}

void CVersionViewer::SendData(  PROCENUMVERSIONINFO lpProc, 
								CString ItemName, 
								CString strFileName, 
								LPARAM lParam) 
{
	lpProc( ItemName, GetFileVersionInfoString(strFileName, ItemName), lParam);
}

CString CVersionViewer::GetFileVersionInfoString(LPCSTR fileFullName, LPCSTR verInfoString)
{
	char *rcData = 0; 
	DWORD dwSize;
	UINT wSize;
	LANGANDCODEPAGE *lpTranslate;
	
	LPTSTR fileName = (LPTSTR)fileFullName;
	
	//file name and path
	CFileStatus status;
	CString verInfo = "Unavailable";
	if( CFile::GetStatus(fileName, status ) )
	{
		//Version
		LPDWORD handle1 = 0;
		dwSize = ::GetFileVersionInfoSize(fileName, handle1);
		if (! dwSize)
			return verInfo;
		
		rcData = new char[dwSize];
		
		// get valid resource data using path, handle, and size
		int result = ::GetFileVersionInfo(fileName, 0, dwSize, (LPVOID)rcData);
		if (result)
		{
			result = ::VerQueryValue(rcData,TEXT("\\VarFileInfo\\Translation" ),
				(LPVOID*)&lpTranslate, &wSize);
			if (result == 0 || wSize == 0)
			{
				delete []rcData;
				return verInfo;
			}
		}
		// Read the file description for each language and code page.
		char SubBlock[100];
		LPVOID lpBuffer;
		for( unsigned i=0; i < (wSize/sizeof(struct LANGANDCODEPAGE)); i++ )
		{
			wsprintf( SubBlock, 
				TEXT("\\StringFileInfo\\%04x%04x\\%s"),
				lpTranslate[i].wLanguage,lpTranslate[i].wCodePage,verInfoString);
			
			result = VerQueryValue(rcData, SubBlock, (LPVOID*)&lpBuffer, &wSize);
			if (!result) 
				break;
			verInfo = (LPCSTR)lpBuffer;
			
		}
		delete []rcData;
	}
	
	return verInfo;
}