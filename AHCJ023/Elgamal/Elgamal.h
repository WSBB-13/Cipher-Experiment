// Elgamal.h : main header file for the ELGAMAL application
//

#if !defined(AFX_ELGAMAL_H__88935201_50CB_4083_A8B5_0635D0FF25B8__INCLUDED_)
#define AFX_ELGAMAL_H__88935201_50CB_4083_A8B5_0635D0FF25B8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CElgamalApp:
// See Elgamal.cpp for the implementation of this class
//

class CElgamalApp : public CWinApp
{
public:
	CElgamalApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CElgamalApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CElgamalApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ELGAMAL_H__88935201_50CB_4083_A8B5_0635D0FF25B8__INCLUDED_)
