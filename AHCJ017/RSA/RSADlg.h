//Download by http://www.NewXing.com
// RSADlg.h : header file
//

#if !defined(AFX_RSADLG_H__309CECCE_1473_4C39_8679_7F9DD1FEBFC5__INCLUDED_)
#define AFX_RSADLG_H__309CECCE_1473_4C39_8679_7F9DD1FEBFC5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CRSADlg dialog
#include "CRSA.h"

class CRSADlg : public CDialog
{
// Construction
public:
	CRSADlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CRSADlg)
	enum { IDD = IDD_RSA_DIALOG };
	CStatic	m_Mess1;
	CEdit	m_Mess;
	CEdit	m_Jmmw2;
	CEdit	m_Pqned;
	CEdit	m_Mw2;
	CEdit	m_Mw;
	CEdit	m_Mmw;
	CEdit	m_Jmmw;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRSADlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL
public:
	int m_IsCrtKey;
	int *m_JmArr;
	int m_JMArrCount;
	private_key m_RSA;
// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CRSADlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtonCrt();
	afx_msg void OnButtonJm();
	afx_msg void OnButtonEm();
	afx_msg void OnButtonClear();
	afx_msg void OnClose();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RSADLG_H__309CECCE_1473_4C39_8679_7F9DD1FEBFC5__INCLUDED_)
