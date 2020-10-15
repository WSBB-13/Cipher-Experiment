// ECCDlg.h : header file
//

#if !defined(AFX_ECCDLG_H__F4FFF531_A090_49FB_9BE4_FFBBBB32E5EA__INCLUDED_)
#define AFX_ECCDLG_H__F4FFF531_A090_49FB_9BE4_FFBBBB32E5EA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CECCDlg dialog

class CECCDlg : public CDialog
{
// Construction
public:
	CECCDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CECCDlg)
	enum { IDD = IDD_ECC_DIALOG };
	CButton	m_gc;
	CButton	m_exit;
	CButton	m_enfile;
	CButton	m_defile;
	CString	m_canshu;
	CString	m_result;
	CString	m_foot;
	CString	m_path;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CECCDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CECCDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void Onexit();
	afx_msg void Ongc();
	afx_msg void Onenfile();
	afx_msg void Ondefile();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ECCDLG_H__F4FFF531_A090_49FB_9BE4_FFBBBB32E5EA__INCLUDED_)
