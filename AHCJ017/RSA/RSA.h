//Download by http://www.NewXing.com
// RSA.h : main header file for the RSA application
//

#if !defined(AFX_RSA_H__71BEB6EE_ED5C_4A17_9CFF_6E906F0217CB__INCLUDED_)
#define AFX_RSA_H__71BEB6EE_ED5C_4A17_9CFF_6E906F0217CB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CRSAApp:
// See RSA.cpp for the implementation of this class
//

class CRSAApp : public CWinApp
{
public:
	CRSAApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRSAApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CRSAApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RSA_H__71BEB6EE_ED5C_4A17_9CFF_6E906F0217CB__INCLUDED_)
