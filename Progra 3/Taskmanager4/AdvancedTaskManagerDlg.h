// AdvancedTaskManagerDlg.h : header file
//

#if !defined(AFX_ADVANCEDTASKMANAGERDLG_H__627EEC9E_5BBF_4818_96D6_E90381E5858F__INCLUDED_)
#define AFX_ADVANCEDTASKMANAGERDLG_H__627EEC9E_5BBF_4818_96D6_E90381E5858F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CAdvancedTaskManagerDlg dialog
#include "ProcessEnumerator.h"
#include "VersionViewer.h"
#include "ProcessViewer.h"


class CAdvancedTaskManagerDlg : public CDialog
{
// Construction
public:
	CAdvancedTaskManagerDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CAdvancedTaskManagerDlg)
	enum { IDD = IDD_ADVANCEDTASKMANAGER_DIALOG };
	CListCtrl	m_CtrlProcessPropList;
	CListCtrl	m_CtrlProcessProp;
	CListCtrl	m_CtrlProcessList;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAdvancedTaskManagerDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	CProcessEnumerator	m_ProcessEnumViewer;
	CVersionViewer		m_VersionViewer;
	CProcessViewer		m_ProcessViewer;

	// Generated message map functions
	//{{AFX_MSG(CAdvancedTaskManagerDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnRefresh();
	afx_msg void OnEndtask();
	afx_msg void OnTimer(UINT nIDEvent);
	virtual void OnCancel();
	afx_msg void OnItemchangedListProcess(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnItemchangedListProperties(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

	void InitilizeViews();

private:
	BOOL CheckOSVersion(DWORD &OSVersion);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADVANCEDTASKMANAGERDLG_H__627EEC9E_5BBF_4818_96D6_E90381E5858F__INCLUDED_)
