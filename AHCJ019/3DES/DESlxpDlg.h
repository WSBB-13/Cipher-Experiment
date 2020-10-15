// DESlxpDlg.h : header file
//

#if !defined(AFX_DESLXPDLG_H__204FC5E8_7214_4D1B_8473_CD7FDC2329D6__INCLUDED_)
#define AFX_DESLXPDLG_H__204FC5E8_7214_4D1B_8473_CD7FDC2329D6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CDESlxpDlg dialog

class CDESlxpDlg : public CDialog
{
// Construction
public:
	CDESlxpDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CDESlxpDlg)
	enum { IDD = IDD_DESLXP_DIALOG };
	CString	m_plain;
	CString	m_key;
	CString	m_enc;
	CString	m_back;
	CString	m_filename;
	CString	m_filekey;
	CString	m_savefile;
	CString	m_sd;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDESlxpDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CDESlxpDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	afx_msg void Onfileenc();
	afx_msg void Onfiledec();
	afx_msg void Onsefile();
	afx_msg void Onsavefile();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DESLXPDLG_H__204FC5E8_7214_4D1B_8473_CD7FDC2329D6__INCLUDED_)
