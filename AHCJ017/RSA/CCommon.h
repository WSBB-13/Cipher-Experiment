//Download by http://www.NewXing.com
static CString HexArr[]={"0","1","2","3","4","5","6","7","8","9","A","B","C","D","E","F"};
static CString StrArr[]={"1","2","3","4","5","6","7","8","9","0","q","w","e","r","t","y","u","i","o","p",
						 "a","s","d","f","g","h","j","k","l","z","x","c","v","b","n","m","#","~","!","@",
						 "$","^","&","*","(",")","-","_","+","=","|","[","]","{","}",":",";","<",">","?"};
//十六进制字符转换成十进制数
int Hexchar_To_Int10(CString input);
//十进制转换成二进制字符串
CString Int10_To_Binstr(unsigned pInt);
//把二进制字符串转换成十进制数
unsigned Binstr_To_Int10(CString input);
//十进制转换成十六进制字符串
CString Int10_To_Hexstr(unsigned pInt,int ws);
//十六进制字符串转换成十进制数
unsigned Hexstr_To_Int10(CString input);
//产生一个随机字符串
CString CrtRandString(int num);

//把二进制形式字符串转换成ASCII字符串
CString Binstr_To_Charstr(CString input); 
//把一个字符用二进制串表示
CString Char_To_Binstr(int c,int num);
//把一个字符串用二进制串表示
CString GStr_To_BinStr(CString input);