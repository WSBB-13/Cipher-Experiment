// ElgamalDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Elgamal.h"
#include "ElgamalDlg.h"
//#include"ctype.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About


#include"stdio.h"
#include"iostream.h"

/* Constants for MD5Transform routine.*/
 
typedef unsigned char* POINTER;

/* UINT2 defines a two byte word */
typedef unsigned short int UINT2;

/* UINT4 defines a four byte word */
typedef unsigned long int UINT4;
typedef struct {
  UINT4 state[4];                                   /* state (ABCD) */
  UINT4 count[2];        /* number of bits, modulo 2^64 (lsb first) */
  unsigned char buffer[64];                         /* input buffer */
} MD5_CTX;


#define S11 7
#define S12 12
#define S13 17
#define S14 22
#define S21 5
#define S22 9
#define S23 14
#define S24 20
#define S31 4
#define S32 11
#define S33 16
#define S34 23
#define S41 6
#define S42 10
#define S43 15
#define S44 21

static unsigned char PADDING[64] = {
  0x80, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};

/* F, G, H and I are basic MD5 functions.
 */
#define F(x, y, z) (((x) & (y)) | ((~x) & (z)))
#define G(x, y, z) (((x) & (z)) | ((y) & (~z)))
#define H(x, y, z) ((x) ^ (y) ^ (z))
#define I(x, y, z) ((y) ^ ((x) | (~z)))

/* ROTATE_LEFT rotates x left n bits.
 */
#define ROTATE_LEFT(x, n) (((x) << (n)) | ((x) >> (32-(n))))

/* FF, GG, HH, and II transformations for rounds 1, 2, 3, and 4.
Rotation is separate from addition to prevent recomputation.
 */
#define FF(a, b, c, d, x, s, ac) { \
 (a) += F ((b), (c), (d)) + (x) + (UINT4)(ac); \
 (a) = ROTATE_LEFT ((a), (s)); \
 (a) += (b); \
  }
#define GG(a, b, c, d, x, s, ac) { \
 (a) += G ((b), (c), (d)) + (x) + (UINT4)(ac); \
 (a) = ROTATE_LEFT ((a), (s)); \
 (a) += (b); \
  }
#define HH(a, b, c, d, x, s, ac) { \
 (a) += H ((b), (c), (d)) + (x) + (UINT4)(ac); \
 (a) = ROTATE_LEFT ((a), (s)); \
 (a) += (b); \
  }
#define II(a, b, c, d, x, s, ac) { \
 (a) += I ((b), (c), (d)) + (x) + (UINT4)(ac); \
 (a) = ROTATE_LEFT ((a), (s)); \
 (a) += (b); \
  }


int hx1;//ǩ��ʱɢ����
int hx2;//��֤ʱɢ����


/* MD5 initialization. Begins an MD5 operation, writing a new context.*/
 
void Decode (UINT4 *output,unsigned char *input,unsigned int len) //
{
  unsigned int i, j;

  for (i = 0, j = 0; j < len; i++, j += 4)
 output[i] = ((UINT4)input[j]) | (((UINT4)input[j+1]) << 8) |
   (((UINT4)input[j+2]) << 16) | (((UINT4)input[j+3]) << 24);
}
void MD5Init(MD5_CTX *context)                                        /* context */
{
  context->count[0] = context->count[1] = 0;
  /* Load magic initialization constants.*/

  context->state[0] = 0x67452301;
  context->state[1] = 0xefcdab89;
  context->state[2] = 0x98badcfe;
  context->state[3] = 0x10325476;
}


 void MD5_memcpy (POINTER output, POINTER input, unsigned int len)
{
  unsigned int i;

  for (i = 0; i < len; i++)
    output[i] = input[i];
}

/* Note: Replace "for loop" with standard memset if possible. */

 void MD5_memset (POINTER output, int value,unsigned int len)
{
  unsigned int i;

  for (i = 0; i < len; i++)
 ((char *)output)[i] = (char)value;

}

  void Encode (unsigned char *output,UINT4 *input, unsigned int len)
{
  unsigned int i, j;

  for (i = 0, j = 0; j < len; i++, j += 4) {
 output[j] = (unsigned char)(input[i] & 0xff);
 output[j+1] = (unsigned char)((input[i] >> 8) & 0xff);
 output[j+2] = (unsigned char)((input[i] >> 16) & 0xff);
 output[j+3] = (unsigned char)((input[i] >> 24) & 0xff);
  }
}
/* MD5 block update operation. Continues an MD5 message-digest
  operation, processing another message block, and updating the
  context.
 */

/* MD5 finalization. Ends an MD5 message-digest operation, writing the
  the message digest and zeroizing the context.
 */


/* MD5 basic transformation. Transforms state based on block.*/
 
 void MD5Transform (UINT4 state[4], unsigned char block[64])
{
  UINT4 a = state[0], b = state[1], c = state[2], d = state[3], x[16];

  Decode (x, block, 64);

  /* Round 1 */
  FF (a, b, c, d, x[ 0], S11, 0xd76aa478); /* 1 */
  FF (d, a, b, c, x[ 1], S12, 0xe8c7b756); /* 2 */
  FF (c, d, a, b, x[ 2], S13, 0x242070db); /* 3 */
  FF (b, c, d, a, x[ 3], S14, 0xc1bdceee); /* 4 */
  FF (a, b, c, d, x[ 4], S11, 0xf57c0faf); /* 5 */
  FF (d, a, b, c, x[ 5], S12, 0x4787c62a); /* 6 */
  FF (c, d, a, b, x[ 6], S13, 0xa8304613); /* 7 */
  FF (b, c, d, a, x[ 7], S14, 0xfd469501); /* 8 */
  FF (a, b, c, d, x[ 8], S11, 0x698098d8); /* 9 */
  FF (d, a, b, c, x[ 9], S12, 0x8b44f7af); /* 10 */
  FF (c, d, a, b, x[10], S13, 0xffff5bb1); /* 11 */
  FF (b, c, d, a, x[11], S14, 0x895cd7be); /* 12 */
  FF (a, b, c, d, x[12], S11, 0x6b901122); /* 13 */
  FF (d, a, b, c, x[13], S12, 0xfd987193); /* 14 */
  FF (c, d, a, b, x[14], S13, 0xa679438e); /* 15 */
  FF (b, c, d, a, x[15], S14, 0x49b40821); /* 16 */

 /* Round 2 */
  GG (a, b, c, d, x[ 1], S21, 0xf61e2562); /* 17 */
  GG (d, a, b, c, x[ 6], S22, 0xc040b340); /* 18 */
  GG (c, d, a, b, x[11], S23, 0x265e5a51); /* 19 */
  GG (b, c, d, a, x[ 0], S24, 0xe9b6c7aa); /* 20 */
  GG (a, b, c, d, x[ 5], S21, 0xd62f105d); /* 21 */
  GG (d, a, b, c, x[10], S22,  0x2441453); /* 22 */
  GG (c, d, a, b, x[15], S23, 0xd8a1e681); /* 23 */
  GG (b, c, d, a, x[ 4], S24, 0xe7d3fbc8); /* 24 */
  GG (a, b, c, d, x[ 9], S21, 0x21e1cde6); /* 25 */
  GG (d, a, b, c, x[14], S22, 0xc33707d6); /* 26 */
  GG (c, d, a, b, x[ 3], S23, 0xf4d50d87); /* 27 */
  GG (b, c, d, a, x[ 8], S24, 0x455a14ed); /* 28 */
  GG (a, b, c, d, x[13], S21, 0xa9e3e905); /* 29 */
  GG (d, a, b, c, x[ 2], S22, 0xfcefa3f8); /* 30 */
  GG (c, d, a, b, x[ 7], S23, 0x676f02d9); /* 31 */
  GG (b, c, d, a, x[12], S24, 0x8d2a4c8a); /* 32 */

  /* Round 3 */
  HH (a, b, c, d, x[ 5], S31, 0xfffa3942); /* 33 */
  HH (d, a, b, c, x[ 8], S32, 0x8771f681); /* 34 */
  HH (c, d, a, b, x[11], S33, 0x6d9d6122); /* 35 */
  HH (b, c, d, a, x[14], S34, 0xfde5380c); /* 36 */
  HH (a, b, c, d, x[ 1], S31, 0xa4beea44); /* 37 */
  HH (d, a, b, c, x[ 4], S32, 0x4bdecfa9); /* 38 */
  HH (c, d, a, b, x[ 7], S33, 0xf6bb4b60); /* 39 */
  HH (b, c, d, a, x[10], S34, 0xbebfbc70); /* 40 */
  HH (a, b, c, d, x[13], S31, 0x289b7ec6); /* 41 */
  HH (d, a, b, c, x[ 0], S32, 0xeaa127fa); /* 42 */
  HH (c, d, a, b, x[ 3], S33, 0xd4ef3085); /* 43 */
  HH (b, c, d, a, x[ 6], S34,  0x4881d05); /* 44 */
  HH (a, b, c, d, x[ 9], S31, 0xd9d4d039); /* 45 */
  HH (d, a, b, c, x[12], S32, 0xe6db99e5); /* 46 */
  HH (c, d, a, b, x[15], S33, 0x1fa27cf8); /* 47 */
  HH (b, c, d, a, x[ 2], S34, 0xc4ac5665); /* 48 */

  /* Round 4 */
  II (a, b, c, d, x[ 0], S41, 0xf4292244); /* 49 */
  II (d, a, b, c, x[ 7], S42, 0x432aff97); /* 50 */
  II (c, d, a, b, x[14], S43, 0xab9423a7); /* 51 */
  II (b, c, d, a, x[ 5], S44, 0xfc93a039); /* 52 */
  II (a, b, c, d, x[12], S41, 0x655b59c3); /* 53 */
  II (d, a, b, c, x[ 3], S42, 0x8f0ccc92); /* 54 */
  II (c, d, a, b, x[10], S43, 0xffeff47d); /* 55 */
  II (b, c, d, a, x[ 1], S44, 0x85845dd1); /* 56 */
  II (a, b, c, d, x[ 8], S41, 0x6fa87e4f); /* 57 */
  II (d, a, b, c, x[15], S42, 0xfe2ce6e0); /* 58 */
  II (c, d, a, b, x[ 6], S43, 0xa3014314); /* 59 */
  II (b, c, d, a, x[13], S44, 0x4e0811a1); /* 60 */
  II (a, b, c, d, x[ 4], S41, 0xf7537e82); /* 61 */
  II (d, a, b, c, x[11], S42, 0xbd3af235); /* 62 */
  II (c, d, a, b, x[ 2], S43, 0x2ad7d2bb); /* 63 */
  II (b, c, d, a, x[ 9], S44, 0xeb86d391); /* 64 */

  state[0] += a;
  state[1] += b;
  state[2] += c;
  state[3] += d;

  /* Zeroize sensitive information. */
  
  MD5_memset ((POINTER)x, 0, sizeof (x));
}

/* Encodes input (UINT4) into output (unsigned char). Assumes len is
  a multiple of 4.
 */


/* Decodes input (unsigned char) into output (UINT4). Assumes len is
  a multiple of 4.
 */
 

/* Note: Replace "for loop" with standard memcpy if possible.*/
 



 void MD5Update (MD5_CTX * context,unsigned char* input,unsigned int inputLen)
                                       /* context */
                               /* input block */
                   /* length of input block */
{
  unsigned int i, index, partLen;

  /* Compute number of bytes mod 64 */
  index = (unsigned int)((context->count[0] >> 3) & 0x3F);//�ֽ���

  /* Update number of bits */
  if ((context->count[0] += ((UINT4)inputLen << 3))//inputLen << 3�����λ��
   < ((UINT4)inputLen << 3))
 context->count[1]++;
  context->count[1] += ((UINT4)inputLen >> 29);
//inputlen �ŵ�count�� count��Ϊ�ֽ���

  partLen = 64 - index;

  /* Transform as many times as possible.
*/
  if (inputLen >= partLen) {
 MD5_memcpy
   ((POINTER)&context->buffer[index], (POINTER)input, partLen);
 MD5Transform (context->state, context->buffer);

 for (i = partLen; i + 63 < inputLen; i += 64)
   MD5Transform (context->state, &input[i]);

 index = 0;
  }
  else
 i = 0;

  /* Buffer remaining input */
  MD5_memcpy
 ((POINTER)&context->buffer[index], (POINTER)&input[i],
  inputLen-i);
}

void MD5Final (unsigned char digest[16], MD5_CTX *context)
                        /* message digest           /* context */
{
  unsigned char bits[8];
  unsigned int index, padLen;

  /* Save number of bits */
  Encode (bits, context->count, 8);

  // Pad out to 56 mod 64.

  index = (unsigned int)((context->count[0] >> 3) & 0x3f);
  padLen = (index < 56) ? (56 - index) : (120 - index);
  MD5Update (context, PADDING, padLen);

  /* Append length (before padding) */
  MD5Update (context, bits, 8);

  /* Store state in digest */
  Encode (digest, context->state, 16);

  /* Zeroize sensitive information.
*/
  MD5_memset ((POINTER)context, 0, sizeof (*context));
}

 int MDPrint (unsigned char digest[16])
{

  unsigned int i;
  unsigned char c;
  int a;
  for(c=digest[0],i=1;i<16;i++)
	  c=c^digest[i];
  a=(int)c;
  return a;
 
}

 


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
// CElgamalDlg dialog

CElgamalDlg::CElgamalDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CElgamalDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CElgamalDlg)
	m_aa = _T("");
	m_sss = _T("");
	m_x4 = _T("");
	m_bb = _T("");
	m_qqq = _T("");
	m_ttt = _T("");
	m_rrr = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CElgamalDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CElgamalDlg)
	DDX_Text(pDX, IDC_EDIT1, m_aa);
	DDX_Text(pDX, IDC_EDIT2, m_sss);
	DDX_Text(pDX, IDC_EDIT4, m_x4);
	DDX_Text(pDX, IDC_EDIT5, m_bb);
	DDX_Text(pDX, IDC_EDIT6, m_qqq);
	DDX_Text(pDX, IDC_EDIT7, m_ttt);
	DDX_Text(pDX, IDC_EDIT8, m_rrr);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CElgamalDlg, CDialog)
	//{{AFX_MSG_MAP(CElgamalDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_BN_CLICKED(IDC_BUTTON4, OnButton4)
	ON_BN_CLICKED(IDC_BUTTON5, OnButton5)
	ON_BN_CLICKED(IDC_BUTTON6, OnButton6)
	ON_BN_CLICKED(IDC_BUTTON7, OnButton7)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CElgamalDlg message handlers

BOOL CElgamalDlg::OnInitDialog()
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
    	CWnd *pWndButn;
		pWndButn=GetDlgItem(IDC_BUTTON4);
		pWndButn->EnableWindow(false);
	

	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CElgamalDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CElgamalDlg::OnPaint() 
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
HCURSOR CElgamalDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CElgamalDlg::OnButton1() 
{
	// TODO: Add your control notification handler code here
	UpdateData();
	FILE *file;
	MD5_CTX context;
	int len,m_k,k1,k2,k3,k4,k5,k6;
	bool flag;
    char *filename;
	filename=(char *)(LPCTSTR)m_aa; 
    unsigned char buffer[1024], digest[16];
    file = fopen ((const char *)(filename), "rb");
    if (file == NULL)
	{
	    MessageBox("�򲻿��ļ����޴��ļ�,����������ļ�");
	    return ;
	}
	else 
	{
         MD5Init (&context);
		 while (len = fread (buffer, 1, 1024, file))
	    	 MD5Update (&context, buffer, len);
		 MD5Final (digest, &context);
         fclose (file);
         hx1= MDPrint (digest);
	} 
	k2=m_p-1;
	flag=1;
	while(flag)
	{
		m_k=rand();
		if(m_k<m_p &&gcd(m_k,m_p)==1 && gcd(m_k,k2)==1)
		flag=0;
	}
	m_r=momi(g,m_k,m_p);
	k1=moni(m_k,k2);
	k3=hx1-m_x1*m_r;
	k4=momi(k3,1,k2);
	k5=momi(k1,1,k2);
	k6=k4*k5;
	m_s=momi(k6,1,k2);
    m_ttt.Format("%d",m_s);
    m_sss.Format("%d",m_r);
	UpdateData(false);
	MessageBox("ǩ�������");
		
}

	void CElgamalDlg::OnButton2() 
{
		// TODO: Add your control notification handler code here
		CWnd *pWndButn;
		pWndButn=GetDlgItem(IDC_BUTTON4);
		pWndButn->EnableWindow();
		
		bool a1,a2;
		a1=a2=1;
		while(a1)
		{
		//	srand(time(NULL));
			m_p=rand();
			if(M<=m_p && m_p<N && prime(m_p,zz)==1)
				a1=0;
		}
		g=scy(m_p);
		while(a2)
		{
		    m_x1=rand();
			if(m_x1<m_p && gcd(m_x1,m_p)==1)
				a2=0;
		}


	
		m_y=momi(g,m_x1,m_p);
		m_x4.Format("%d",m_x1);
		UpdateData(false);
		MessageBox("��Կ���ɳɹ����뱣�ܺ�!");
}


int CElgamalDlg::gcd(int a ,int b)//���Լ��
{
	int r;
	r=a%b;
	if(r==0)
	  return b;
	while(r)
	{
		r=a%b;
		a=b;
		b=r;
	}
	return a;
}

int CElgamalDlg::momi(int a,int e,int n)//��ģ�ݣ���������
{	
	int i,ab[100],temp=0,tempn;	//����ab�����洢2����
	for(i=0,temp=e;temp!=0;i++)
	{	//��2����
		ab[i]=(int)temp%2;
		temp=(int)temp/2;
	}
	tempn=i-1;
    if(e==1)
		temp=a%n;
	else
	{
	for(i=tempn-1,temp=a;i>=0;i--)
		{	//����ģ��
			temp=temp*temp%n;
			if(ab[i]==1)
				temp=temp*a%n;
		}
	}
	while(temp<0)
	   temp=temp+n;
	return temp;
}
int  CElgamalDlg::moni(int d,int n)	//��ģ��
{
	int i,a[100][2],temp=0,vk,u=0,t;	//����a���������״̬
	a[0][0]=n;	//��ʼ��a0=n,a1=d
	a[1][0]=d;
	if(d==1)
		return d;
	for(i=2;a[i-1][0]!=0;i++)
	{	//����
		a[i][0]=a[i-2][0]%a[i-1][0];
		a[i-1][1]=(int)a[i-2][0]/a[i-1][0];
	}
	temp=i-3;	//����
	if(a[temp+1][0]!=1)	//�����һ�Ϊ1�򲻻��أ���ģ��
		return 0;
	else
	{	//����ģ��
	//	for(i=1;i<=temp+1;i++)//a[i-1][0]!=0;i++)
	//		printf("%d=%d*%d+%d\n",a[i-1][0],a[i][1],a[i][0],a[i+1][0]);
		for(i=1,vk=-a[1][1],u=1;i<temp;i++)
		{	//���㣡
			t=vk;
			vk=u-vk*a[i+1][1];
			u=t;
		}
		a[0][1]=vk;
	//	printf("Vk=%d",vk);
		if(vk<0)
		{
			vk=n+vk;
	//		printf("=%d\n",vk);
		}
		
	}
	return vk;
}
 bool CElgamalDlg::prime(int n,int z)//�ж�����
 {
 		int a,r,k1,k2;
 		bool falt=1;
 		k1=n-1;
 		k2=n-2;
 		for(int i=1;i<=z;i++)
 		{
		 while(falt)
 		{
			
			a=rand();
 			if(a>=2 && a<=k2)
			{    cout<<a<<endl;
				falt=0;
 			}
 		}
 		falt=1;
		 r=momi(a,k1,n);
 		if(r!=1)
 			return 0;

		}
 		return 1;
 
 }

int CElgamalDlg::scy(int n)
{
	int x,k;
	bool biao1,biao2;
    
	biao1=biao2=1;
    for(x=2;x<n;x++)
	{
		for(k=1;k<n;k++)
		{
			if(momi(x,k,n)==1)
			{
				if(k==n-1)
					return x;
				break;
			}
		}
	}
	MessageBox("������Ԫ");
	return 0;
}

void CElgamalDlg::OnButton4() 
{
	// TODO: Add your control notification handler code here
	
	char *s="";
	m_x4.Format("%s",s);
	UpdateData(false);
	
}


void CElgamalDlg::OnButton5() 
{
	// TODO: Add your control notification handler code here
	UpdateData();
	FILE *file;
	MD5_CTX context;
	int len,j1,j2,j3;
    char *filename;
	unsigned char buffer[1024], digest[16];
	filename=(char *)(LPCTSTR)m_bb; 
    file = fopen ((const char *)(filename), "rb");
    if (file == NULL)
	{ 
	    MessageBox("�򲻿��ļ����޴��ļ�,����������ļ�");
		return ;
	}
	else 
	{
        MD5Init (&context);
		while (len = fread (buffer, 1, 1024, file))
		MD5Update (&context, buffer, len);
		MD5Final (digest, &context);
		fclose (file);
		hx2= MDPrint (digest);
	}
	if(m_r<1 || m_r>m_p-1)
	{
		MessageBox("ǩ��Ϊ�Ƿ�����֤���ɹ�");
		return ;
	}
    j1=momi(m_y,m_r,m_p);
	j2=momi(m_r,m_s,m_p);
	j3=j1*j2;
	m_v1=momi(j3,1,m_p);
    m_v2=momi(g,hx2,m_p);
	m_qqq.Format("%d",m_v1);
	m_rrr.Format("%d",m_v2);
	UpdateData(false);
	if(m_v1==m_v2)
        MessageBox("v1=v2 ,��֤�ɹ�!");
	else
		MessageBox("v1��=v2,��֤ʧ��");
		
}


void CElgamalDlg::OnButton6() 
{
	// TODO: Add your control notification handler code here
	CFileDialog  MyFileDlg(TRUE,NULL,NULL,0,"�ı��ļ�(*.txt)|*.txt||");
	if(MyFileDlg.DoModal()==IDOK)
	{
		CString strFileName=MyFileDlg.GetFileName();
		CString strPathName=MyFileDlg.GetPathName();
		m_aa=strPathName;
		UpdateData(false);

	}
	
}

void CElgamalDlg::OnButton7() 
{
	// TODO: Add your control notification handler code here
	CFileDialog  MyFileDlg(TRUE,NULL,NULL,0,"�ı��ļ�(*.txt)|*.txt||");
	if(MyFileDlg.DoModal()==IDOK)
	{
		CString strFileName=MyFileDlg.GetFileName();
		CString strPathName=MyFileDlg.GetPathName();
		m_bb=strPathName;
		UpdateData(false);
	}
}




