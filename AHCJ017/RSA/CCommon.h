//Download by http://www.NewXing.com
static CString HexArr[]={"0","1","2","3","4","5","6","7","8","9","A","B","C","D","E","F"};
static CString StrArr[]={"1","2","3","4","5","6","7","8","9","0","q","w","e","r","t","y","u","i","o","p",
						 "a","s","d","f","g","h","j","k","l","z","x","c","v","b","n","m","#","~","!","@",
						 "$","^","&","*","(",")","-","_","+","=","|","[","]","{","}",":",";","<",">","?"};
//ʮ�������ַ�ת����ʮ������
int Hexchar_To_Int10(CString input);
//ʮ����ת���ɶ������ַ���
CString Int10_To_Binstr(unsigned pInt);
//�Ѷ������ַ���ת����ʮ������
unsigned Binstr_To_Int10(CString input);
//ʮ����ת����ʮ�������ַ���
CString Int10_To_Hexstr(unsigned pInt,int ws);
//ʮ�������ַ���ת����ʮ������
unsigned Hexstr_To_Int10(CString input);
//����һ������ַ���
CString CrtRandString(int num);

//�Ѷ�������ʽ�ַ���ת����ASCII�ַ���
CString Binstr_To_Charstr(CString input); 
//��һ���ַ��ö����ƴ���ʾ
CString Char_To_Binstr(int c,int num);
//��һ���ַ����ö����ƴ���ʾ
CString GStr_To_BinStr(CString input);