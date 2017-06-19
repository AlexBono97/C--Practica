// ----------------------------------------------------------------------------
// File Name:	    VersionViewer.h
// Contents : 		VersionViewer class definition.
// Originator: 	    Madhu Raykar.
// Date:		    04.12.05 
// Version:		    1.00.
// ----------------------------------------------------------------------------

#if !defined(AFX_VERSIONVIEWER_H__FFAF5996_2B46_46FB_AFC6_00BFD12D944B__INCLUDED_)
#define AFX_VERSIONVIEWER_H__FFAF5996_2B46_46FB_AFC6_00BFD12D944B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

typedef BOOL (CALLBACK *PROCENUMVERSIONINFO)( CString&, CString&, LPARAM lParam) ;

#define VERINFO_ProductName			"ProductName"
#define VERINFO_CompanyName			"CompanyName"
#define VERINFO_ProductVersion		"ProductVersion"
#define VERINFO_comments			"Comments"
#define VERINFO_FileDescrib			"FileDescription"
#define VERINFO_FileVersion			"FileVersion"
#define VERINFO_InternalName		"InternalName"
#define VERINFO_LegalCopyright		"LegalCopyright"
#define VERINFO_LegalTrademarks		"LegalTrademarks"
#define VERINFO_OriginalFilename	"OriginalFilename"
#define VERINFO_PrivateBuild		"PrivateBuild"
#define VERINFO_SpecialBuild		"SpecialBuild"


///////////////////////////////////////////////////////////////////////////// 
//
//	This class is responsible of loading the version information 
//	of a specified binary file.
//  This class uses a callback PROCENUMVERSIONINFO to send the
//  data back to the caller.
///////////////////////////////////////////////////////////////////////////// 
class CVersionViewer  
{
private:
	struct LANGANDCODEPAGE 
	{
		WORD wLanguage;
		WORD wCodePage;
	};

public:
	CVersionViewer();
	virtual ~CVersionViewer();
	BOOL GetVersionInfo( LPCTSTR strFileName, 
						 PROCENUMVERSIONINFO lpProc, 
						 LPARAM lParam );
	BOOL Initialize(DWORD OSVersion);

private:
	CString GetFileVersionInfoString(LPCSTR fileFullName, LPCSTR verInfoString);
	void SendData(  PROCENUMVERSIONINFO lpProc, 
					CString ItemName, 
					CString strFileName, 
					LPARAM lParam) ;
};

#endif // !defined(AFX_VERSIONVIEWER_H__FFAF5996_2B46_46FB_AFC6_00BFD12D944B__INCLUDED_)
