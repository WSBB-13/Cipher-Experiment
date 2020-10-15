#include"iostream"
using namespace std;
#define MINCHAR 97
#define CHARSUM 26
char table[CHARSUM][CHARSUM];
bool Init();
bool Encode(char* key, char* source, char* dest);
bool Dncode(char* key, char* source, char* dest);
int main()
{
  if(!Init())
  {
      cout << "初始化错误！" << endl;
      return 1;
  }
  char key[256];
  char str1[256];
  char str2[256];
  int operation;
  while(1)
  {
      do
      {
        cout << "请选择一个操作：1. 加密；2. 解密；-1. 退出\n";
        cin >> operation;
      }while(operation != -1 && operation != 1 && operation != 2);
      if(operation == -1)
        return 0;
      else if(operation == 1)//加密
      {
        cout << "请输入密钥：";
        cin >> key;
        cout << "请输入待加密字符串：";
        cin >> str1;
        Encode(key, str1, str2);
        cout << "加密后的字符串：" << str2 << endl;
      }
      else if(operation == 2)//解密
      {
        cout << "请输入密钥：";
        cin >> key;
        cout << "请输入待解密字符串：";
        cin >> str1;
        Dncode(key, str1, str2);
        cout << "解密后的字符串：" << str2 << endl;
      }
      cout << endl;
  }
  return 0;
}
// 初始化维吉尼亚方阵
bool Init()
{
  int i, j;
  for(i = 0; i < CHARSUM; i++)
  {
      for(j = 0; j < CHARSUM; j++)
      {
        table[i][j] = 65 + (i + j) % CHARSUM;
      }
  }
  return true;
}
// 加密
// key：密钥
// source：待加密的字符串
// dest：经过加密后的字符串
bool Encode(char* key, char* source, char* dest)
{
  char* tempSource = source;
  char* tempKey = key;
  char* tempDest = dest;
    do
  {
      *tempDest = table[(*tempKey) - MINCHAR][(*tempSource) - MINCHAR];
      tempDest++;
      if(!(*(++tempKey)))
        tempKey = key;
  }while(*tempSource++);
    dest[strlen(source)] = 0;
  return true;
}
// 解密
// key：密钥
// source：待解密的字符串
// dest：经过解密后的字符串
bool Dncode(char* key, char* source, char* dest)
{
  char* tempSource = source;
  char* tempKey = key;
  char* tempDest = dest;
  char offset;
    do
  {
      offset = (*tempSource) - (*tempKey);
      offset = offset >= 0 ? offset : offset + CHARSUM;
      *tempDest = MINCHAR + offset;
      tempDest++;
      if(!(*(++tempKey)))
        tempKey = key;
  }while(*++tempSource);
  dest[strlen(source)] = 0;
  return true;
}