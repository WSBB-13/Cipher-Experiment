#include <stdio.h>
#include <string.h>

void InitS(unsigned char *s)
{
 int i;
 for(i=0;i<256;i++)
  s[i]=i;
}

void InitT(unsigned char *t,char *key)
{
 int i;
 for(i=0;i<256;i++)
  {
   t[i]=key[i%strlen(key)];
  }
}

void Swap(unsigned char *s,int first,int last)
{
 unsigned char temp;
 temp=s[first];
 s[first]=s[last];
 s[last]=temp;
}

void InitPofS(unsigned char *s,unsigned char *t)
{
 int i;
 int j=0;
 for(i=0;i<256;i++)
  {
   j=(j+s[i]+t[i])%256;
   Swap(s,i,j);
  }
}


int encypher(char *sourcepath,char *destpath,char *key)
{
 unsigned char s[256]={0};
 unsigned char t[256]={0};
 char   buf;
 FILE *fsource;
 FILE *fdest;
 int i=0,j=0,k=0,l=0;
 int temp;
 long f_len;

 InitS(s);
 InitT(t,key);
 InitPofS(s,t);
 fsource=fopen(sourcepath,"rb");
 fdest=fopen(destpath,"wb");
 fseek(fsource,0L,SEEK_END);
 f_len=ftell(fsource);
 rewind(fsource);
 for(l=0;l<f_len;l++)
 {
  i=(i+1)%256;
  j=(j+s[i])%256;
  Swap(s,i,j);
  temp=(s[i]+s[j])%256;
  k=s[temp];
  buf=fgetc(fsource);
  fputc(k^buf,fdest);
 }
  fclose(fdest); 
  fclose(fsource);
 
 printf("\n................................\n操作完成\n");
 return 1;
}

int main()
{
    char sourcepath[100], destpath[100];
	int i;
	char key[256];

	while(1)
	{   
		printf("\n***********************欢迎使用RC4加解密程序***********************\n");
		printf("请选择操作\n1: 加密\n2: 解密\n3: 退出\n");
		printf("\n选择:");
		scanf("%d",&i);
		if(i!=3)
		{
			printf("请输入文件路径:");
			scanf("%s",&sourcepath);

			printf("请输入保存路径:");
			scanf("%s",&destpath);
			
			printf("请输入密钥:");
			scanf("%s",&key);
		}
		switch(i)
		{
		case 1: 
                        printf("正在执行操作，请稍等。。。");
			encypher(sourcepath, destpath, key);
			break;
		case 2: 
                        printf("正在执行操作，请稍等。。。");
			encypher(sourcepath, destpath, key);
			break;
		case 3:
		default:
			return;
		}
		printf("\n");
	}

}
