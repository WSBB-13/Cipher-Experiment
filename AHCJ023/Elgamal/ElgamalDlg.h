// ElgamalDlg.h : header file
//
#define N 30000
#define M 10000
#define zz 50
#if !defined(AFX_ELGAMALDLG_H__77D12C1F_A8FA_4CD1_A6B2_D110E6241EC0__INCLUDED_)
#define AFX_ELGAMALDLG_H__77D12C1F_A8FA_4CD1_A6B2_D110E6241EC0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CElgamalDlg dialog

class CElgamalDlg : public CDialog
{
// Construction
public:
	int m_p;//素数P
	int m_x1;//密钥X
	int m_r;
	int m_s;
	int g;
	int m_v1;
	int m_v2;
	int m_y;//公钥Y
	int gcd(int a ,int b);
	int  moni(int d,int n);//求模逆
	int momi(int a,int e,int n);//求模幂
	bool prime(int n,int z);
	int scy(int n);
	CElgamalDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CElgamalDlg)
	enum { IDD = IDD_ELGAMAL_DIALOG };
	CString	m_aa;
	CString	m_sss;
	CString	m_x4;
	CString	m_bb;
	CString	m_qqq;
	CString	m_ttt;
	CString	m_rrr;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CElgamalDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CElgamalDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	afx_msg void OnButton4();
	afx_msg void OnButton5();
	afx_msg void OnButton6();
	afx_msg void OnButton7();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ELGAMALDLG_H__77D12C1F_A8FA_4CD1_A6B2_D110E6241EC0__INCLUDED_)
