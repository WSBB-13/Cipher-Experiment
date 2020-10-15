// DESlxpDlg.cpp : implementation file
//

#include "stdafx.h"
#include "DESlxp.h"
#include "DESlxpDlg.h"
#include "DES.h"

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
// CDESlxpDlg dialog

CDESlxpDlg::CDESlxpDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDESlxpDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDESlxpDlg)
	m_plain = _T("Anheng");
	m_key = _T("12345678");
	m_enc = _T("");
	m_back = _T("");
	m_filename = _T("");
	m_filekey = _T("12345678");
	m_savefile = _T("");
	m_sd = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDESlxpDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDESlxpDlg)
	DDX_Text(pDX, IDC_EDIT1, m_plain);
	DDX_Text(pDX, IDC_EDIT2, m_key);
	DDX_Text(pDX, IDC_EDIT3, m_enc);
	DDX_Text(pDX, IDC_EDIT4, m_back);
	DDX_Text(pDX, IDC_EDIT5, m_filename);
	DDX_Text(pDX, IDC_EDIT6, m_filekey);
	DDX_Text(pDX, IDC_EDIT7, m_savefile);
	DDX_Text(pDX, IDC_EDIT8, m_sd);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDESlxpDlg, CDialog)
	//{{AFX_MSG_MAP(CDESlxpDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_BN_CLICKED(IDC_BUTTON3, Onfileenc)
	ON_BN_CLICKED(IDC_BUTTON4, Onfiledec)
	ON_BN_CLICKED(IDC_BUTTON5, Onsefile)
	ON_BN_CLICKED(IDC_BUTTON6, Onsavefile)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDESlxpDlg message handlers

BOOL CDESlxpDlg::OnInitDialog()
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
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CDESlxpDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CDESlxpDlg::OnPaint() 
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
HCURSOR CDESlxpDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CDESlxpDlg::OnButton1() 
{
	
		UpdateData(TRUE);
/*int z = m_plain.GetLength();
char *inbuff= new  char[z];
char *skey= new  char[z];
char *oubuff= new  char[z];
for(int i=0;i<z;i++)
{
inbuff[i] =m_plain[i];
skey[i]=m_key[i];
}*/

    char skey[32];
    char inbuff[32],oubuff[32];
	memcpy(skey,(LPCTSTR)m_key,8);
	memcpy(inbuff,(LPCTSTR)m_plain,8);

CString strTmp,str;

DES jm	;
jm.Des_Go(oubuff, inbuff, sizeof(inbuff), skey,sizeof(skey), ENCRYPT);

//for (int c = 0; c<32; ++c)
 //       {
		 // strdemo=strdemo+State[c][r]+" ";
//		  strTmp.Format("%02x",oubuff[c]);
//		str+=strTmp+" ";
//		}
//MessageBox(str);	
for(int i=0;i<32;i++)
  str+=oubuff[i];     

m_enc=str;
UpdateData(FALSE);
}

void CDESlxpDlg::OnButton2() 
{
	UpdateData(TRUE);
/*	int z = m_enc.GetLength();
char *inbuff= new char[z];
char *skey= new char[z];
char *oubuff= new char[z];
for(int i=0;i<z;i++)
{
inbuff[i] =m_enc[i];
skey[i]=m_key[i];
}*/
char skey[32];
    char inbuff[32],oubuff[32];
	memcpy(skey,(LPCTSTR)m_key,8);
	memcpy(inbuff,(LPCTSTR)m_enc,8);

CString strTmp,str;
DES jm	;


jm.Des_Go(oubuff, inbuff, sizeof(inbuff),skey, sizeof(skey),  DECRYPT);

for(int i=0;i<8;i++)
  str +=oubuff[i];
     

m_back=str;
UpdateData(FALSE);	
}


void CDESlxpDlg::Onfileenc() 
{
UpdateData(TRUE);
if(m_filename=="")return;
CFile ff(m_filename,CFile::modeRead);
long lFileLen=ff.GetLength();
long c=lFileLen/8;
long d=lFileLen%8;
if (m_savefile=="")
m_savefile=m_filename+".aen";


   CFile fp(m_savefile,CFile::modeCreate|CFile::modeWrite);
   fp.SeekToBegin();
   ff.SeekToBegin();

//CString inbuff;


DES jm;




char inbuff[8],oubuff[8],skey[8];

/*	char *cr=NULL;
for(int j=0;j<16;j++)
 {
CString str=m_filekey.Mid(2*j,2);
skey[j]=unsigned char(strtol(str,&cr,16));
}*/
memcpy(skey,(LPCTSTR)m_filekey,8);

    CTime tm1,tm2;
	tm1=CTime::GetCurrentTime();

	for(long i=0;i<c;i++)
	{
		ff.Read(inbuff,8);
		jm.Des_Go(oubuff, inbuff, sizeof(inbuff), skey,sizeof(skey), ENCRYPT);
		fp.Write(oubuff,8);
	}
	if(d>0)
	{
		ff.Read(inbuff,d);
		jm.Des_Go(oubuff, inbuff, sizeof(inbuff), skey,sizeof(skey), ENCRYPT);
		fp.Write(oubuff,8);
	}
    tm2=CTime::GetCurrentTime();
	CTimeSpan tmSpan=tm2-tm1;

	CString strspan=tmSpan.Format("Seconds:%S");
    m_sd=strspan+"s";
     
	ff.Close();
	fp.Close();
	AfxMessageBox("加密成功！");
	UpdateData(FALSE);
		
}

void CDESlxpDlg::Onfiledec() 
{
UpdateData(TRUE);
if(m_filename=="")return;
CFile ff(m_filename,CFile::modeRead);
long lFileLen=ff.GetLength();
long c=lFileLen/8;
long d=lFileLen%8;
if (m_savefile=="")
m_savefile=m_filename+".aen";


   CFile fp(m_savefile,CFile::modeCreate|CFile::modeWrite);
   fp.SeekToBegin();
   ff.SeekToBegin();

//CString inbuff;


DES jm;

 char inbuff[8],oubuff[8],skey[8];

 memcpy(skey,(LPCTSTR)m_filekey,8);

CTime tm1,tm2;
	tm1=CTime::GetCurrentTime();

for(long i=0;i<c;i++)
	{
		ff.Read(inbuff,8);
		
        jm.Des_Go(oubuff, inbuff, sizeof(inbuff), skey,sizeof(skey), DECRYPT);
		fp.Write(oubuff,8);
	}
	if(d>0)
	{
		AfxMessageBox("文件可能已损坏或非经aes加密过");
	}
    tm2=CTime::GetCurrentTime();
	CTimeSpan tmSpan=tm2-tm1;

	CString strspan=tmSpan.Format("Seconds:%S");

m_sd=strspan+"s";
     
	ff.Close();
	fp.Close();
	AfxMessageBox("解密成功！");
	UpdateData(FALSE);	
}

void CDESlxpDlg::Onsefile() 
{
	UpdateData(TRUE);
	CFileDialog dlg(1,NULL,NULL,OFN_HIDEREADONLY ,"All Files(*.*)|*.*||");
	if(IDOK!=dlg.DoModal())return;
	m_filename=dlg.GetPathName();	
	UpdateData(FALSE);	
	
}

void CDESlxpDlg::Onsavefile() 
{
UpdateData(TRUE);
	CFileDialog dlg(1,NULL,NULL,OFN_HIDEREADONLY ,"All Files(*.*)|*.*||");
	if(IDOK!=dlg.DoModal())return;
	m_savefile=dlg.GetPathName();	
	UpdateData(FALSE);	
}
