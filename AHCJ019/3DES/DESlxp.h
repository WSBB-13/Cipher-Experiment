// DESlxp.h : main header file for the DESLXP application
//

#if !defined(AFX_DESLXP_H__E21409AA_93C0_48E3_89E9_A3C08300CD55__INCLUDED_)
#define AFX_DESLXP_H__E21409AA_93C0_48E3_89E9_A3C08300CD55__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CDESlxpApp:
// See DESlxp.cpp for the implementation of this class
//

class CDESlxpApp : public CWinApp
{
public:
	CDESlxpApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDESlxpApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CDESlxpApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DESLXP_H__E21409AA_93C0_48E3_89E9_A3C08300CD55__INCLUDED_)
