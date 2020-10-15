//Download by http://www.NewXing.com
// RSADlg.cpp : implementation file
//

#include "stdafx.h"
#include "RSA.h"
#include "RSADlg.h"
#include "CCommon.h"
#include "stdlib.h"
#include "CDSA.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRSADlg dialog

CRSADlg::CRSADlg(CWnd* pParent /*=NULL*/)
	: CDialog(CRSADlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CRSADlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CRSADlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CRSADlg)
	DDX_Control(pDX, IDC_MESS, m_Mess1);
	DDX_Control(pDX, IDC_EDIT_JMMW2, m_Jmmw2);
	DDX_Control(pDX, IDC_EDIT_PQNED, m_Pqned);
	DDX_Control(pDX, IDC_EDIT_MW2, m_Mw2);
	DDX_Control(pDX, IDC_EDIT_MW, m_Mw);
	DDX_Control(pDX, IDC_EDIT_MMW, m_Mmw);
	DDX_Control(pDX, IDC_EDIT_JMMW, m_Jmmw);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CRSADlg, CDialog)
	//{{AFX_MSG_MAP(CRSADlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(ID_BUTTON_CRT, OnButtonCrt)
	ON_BN_CLICKED(ID_BUTTON_JM, OnButtonJm)
	ON_BN_CLICKED(ID_BUTTON_EM, OnButtonEm)
	ON_BN_CLICKED(ID_BUTTON_CLEAR, OnButtonClear)
	ON_WM_CLOSE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRSADlg message handlers

BOOL CRSADlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	m_Mess1.SetWindowText("");
	m_IsCrtKey=0;
	m_JmArr=NULL;
	m_JMArrCount=0;
	m_Mw.SetWindowText("Anheng");
	m_Mw2.SetWindowText("");
	m_Pqned.SetWindowText("");
	m_Mmw.SetWindowText("");
	m_Jmmw.SetWindowText("");

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CRSADlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CRSADlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CRSADlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CRSADlg::OnButtonCrt() 
{
	// TODO: Add your control notification handler code here
	char ccc;
	int kk;
	zeronetochar8(ccc,"01000010"); //字符串变成数
	zeronetochar6(kk,"111111");

	//产生密钥
	m_Mess1.SetWindowText("正在随机产生1024位密钥，请稍侯...");
	CString str1,str2="";
	int i,tLen,tLen1;
	m_Mw.GetWindowText(str1);
	tLen=str1.GetLength();
	if((tLen%3)==0) tLen1=tLen/3;
	else tLen1=tLen/3+1;
	if(m_JmArr!=NULL)
	{
		free(m_JmArr);
		m_JmArr=NULL;
	}
	m_JmArr=(int *)malloc(sizeof(int)*tLen1);
	if(m_JmArr==NULL)
		return;
	if(tLen<=0)
	{
		MessageBox("请输入明文!");
		return;
	}
	int c1;
	for(i=0;i<tLen;i++)
	{
		c1=str1[i];
		if(c1<0)
			c1+=256;
		str2=str2+Int10_To_Hexstr(c1,2);
	}
	m_Mw2.SetWindowText(str2);
	CString rstr1,rstr2,rstr3;
	rstr1=CrtRandString(64);//产生一个随机64字节字符串
	rstr2=CrtRandString(64);
	rstr3=CrtRandString(64);
//	m_RSA.create("w1p)tab|@&}5cm$$yx/]2h)9{>%_)k::=x_a","&-r{p;ug2m/_@ms50&z@:=q3o80uwu93{6-:");
	m_RSA.create(rstr1,rstr2,rstr3); //生成密钥

	CString sp="p为:\n",sq="q为:\n",sn="n为:\n",se="e为:\n",sd="d为:\n",srst;
	int np,nq,nn,ne,nd;
	np=m_RSA.p.value->n;
	nq=m_RSA.q.value->n;
	nn=m_RSA.m.value->n;
	ne=m_RSA.e.value->n;
	nd=m_RSA.md.value->n;
	
	for(i=0;i<np;i++)//十进制数变成用16进制字符串
		sp=sp+Int10_To_Hexstr(m_RSA.p.value->get(i),0);
	    sp+="\r\n";
	for(i=0;i<nq;i++)
		sq=sq+Int10_To_Hexstr(m_RSA.q.value->get(i),0);
	    sq+="\r\n";
	for(i=0;i<nn;i++)
		sn=sn+Int10_To_Hexstr(m_RSA.m.value->get(i),0);
	    sn+="\r\n";
	for(i=0;i<ne;i++)
		se=se+Int10_To_Hexstr(m_RSA.e.value->get(i),0);
	    se+="\n\n";
	for(i=0;i<nd;i++)
		sd=sd+Int10_To_Hexstr(m_RSA.md.value->get(i),0);
	srst.Format("%s\n%s\n%s\n%s\n%s",sp,sq,sn,se,sd);
	m_Pqned.SetWindowText(srst);
	m_IsCrtKey=1;
	m_Mess1.SetWindowText("");
}

void CRSADlg::OnButtonJm() 
{
	// TODO: Add your control notification handler code here
	//加密
	m_JMArrCount=0;
	if(m_IsCrtKey==0)
	{
		MessageBox("请先产生密钥!");
		return;
	}
	else
		m_IsCrtKey=2;
	m_Mess1.SetWindowText("正在加密明文，请稍侯...");
	vlong tmpRst;
	CString str1,str2,tmRst="",tmMId;
	unsigned tu;
	int m=0,i=0,j,tLen,rm,tmpRstn;
	m_Mw2.GetWindowText(str1);
	tLen=str1.GetLength();
	if(tLen<6) rm=tLen;
	else rm=6;
	while(i<tLen)
	{
		tmMId="";
		str2=str1.Mid(i,rm);
		tu=Hexstr_To_Int10(str2);

		tmpRst=m_RSA.encrypt(tu);  //加密

		tmpRstn=tmpRst.value->n;
		for(j=0;j<tmpRstn;j++)
			tmMId=tmMId+Int10_To_Hexstr(tmpRst.value->get(j),8);
		m_JmArr[m]=tmMId.GetLength();
		tmRst=tmRst+tmMId;
		m+=1;
		m_JMArrCount+=1;
		i+=rm;
		if((tLen-i)<6) rm=tLen-i;
	}
	m_Mmw.SetWindowText(tmRst);
	m_Mess1.SetWindowText("");
}

void CRSADlg::OnButtonEm() 
{
	// TODO: Add your control notification handler code here
	//解密
	if(m_IsCrtKey!=2)
	{
		MessageBox("请先进行加密!");
		return;
	}
	m_Mess1.SetWindowText("正在解密密文，请稍侯...");
	vlong tmpRst(0),JmvRst;
	CString str1,str2,str3,tmRst="";
	unsigned tu;
	int k,m,i=0,j,tLen,rm,nnnn;

	m_Mmw.GetWindowText(str1);
	tLen=str1.GetLength();

	rm=8;
	for(m=0;m<m_JMArrCount;m++)
	{
		k=0;j=0;
		str3=str1.Mid(i,m_JmArr[m]);
		while(j<m_JmArr[m])
		{
			str2=str3.Mid(j,rm);
			tu=Hexstr_To_Int10(str2);
			tmpRst.value->set(k,tu);
			k+=1;
			j+=rm;
		}

		JmvRst=m_RSA.decrypt(tmpRst);   //解密

		nnnn=JmvRst.value->n;
		for(k=0;k<nnnn;k++)
			tmRst=tmRst+Int10_To_Hexstr(JmvRst.value->get(k),0);
		i+=m_JmArr[m];
	}
	m_Jmmw2.SetWindowText(tmRst);
	m_Jmmw2.GetWindowText(str1);
	tLen=str1.GetLength();
	tmRst="";
	char c1;
	for(i=0;i<tLen;i+=2)
	{
		str2=str1.Mid(i,2);
		c1=Hexstr_To_Int10(str2);
		tmRst=tmRst+c1;
	}
	m_Jmmw.SetWindowText(tmRst);
	m_Mess1.SetWindowText("");
}

void CRSADlg::OnButtonClear() 
{
	// TODO: Add your control notification handler code here
	m_Mw2.SetWindowText("");
	m_Pqned.SetWindowText("");
	m_Mmw.SetWindowText("");
	m_Jmmw.SetWindowText("");
	m_IsCrtKey=0;
}

void CRSADlg::OnClose() 
{
	// TODO: Add your message handler code here and/or call default
	if(m_JmArr!=NULL)
		free(m_JmArr);
	CDialog::OnClose();
}
