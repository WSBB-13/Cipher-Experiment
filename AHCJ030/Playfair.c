#include<stdio.h>
#include<string.h>	
int find(char *key,int n,char c);
char alph[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o',
		'p','q','r','s','t','u','v','w','x','y','z'};
void find_fang(char fang[5][5],char c1,int *i_1,int *j_1);
void main()
{	char miwen[100];
	char fang[5][5];
	int i,j,k=0,len,t=0;
	char t1,t2;
	int i_1=-1,j_1=-1,i_2=-1,j_2=-1;
	char key[25]={'c','i','p','h','e','r','a','b','d','f','g','k','l','m','n','o','q','s','t','u','v','w','x','y','z'};
	char yuanwen[100]={'A','n','h','e','n','g'};
	len=strlen(key);
	for(i=0;i<5;i++)
		for(j=0;j<5;j++)
		{	if(key[k]!='\0')
			{
				fang[i][j]=key[k];
				k++;
			}
			else
			{
				while(find(key,len,alph[t]))
					t++;
				fang[i][j]=alph[t];
				t++;
			}
		}
	for(i=0;i<strlen(yuanwen);i+=2)
	{
		t1=yuanwen[i];
		t2=yuanwen[i+1];
		if(t1==t2||t2=='\0')
		{
			miwen[i]=t1;
			miwen[i+1]=t2;
		}
		else
		{
			find_fang(fang,t1,&i_1,&j_1);
			find_fang(fang,t2,&i_2,&j_2);
			if(i_1==-1||j_1==-1||i_2==-1||j_2==-1)
			{
				miwen[i]=t1;
				miwen[i+1]=t2;
			}
			else if(i_1==i_2&&j_1!=j_2)
			{
				miwen[i]=fang[i_1][(j_1+1)%5];
				miwen[i+1]=fang[i_2][(j_2+1)%5];
			}
			else if(j_1==j_2&&i_1!=i_2)
			{
			    miwen[i]=fang[(i_1+1)%5][j_1];
				miwen[i+1]=fang[(i_2+1)%5][j_2];
            }
			else
			{
				miwen[i]=fang[i_1][j_2];
				miwen[i+1]=fang[i_2][j_1];
			}
		}
			
	}
	miwen[i] =0;
	printf("plaintext:Anheng\n");
	printf("ciphertext:%s\n",miwen);
}

int find(char *key,int n,char c)
{
	int i,flag=0;
	for(i=0;i<n;i++)
		if(key[i]==c)
		{
			flag=1;
			break;
		}
	return flag;
}
void find_fang(char fang[5][5],char c1,int *i_1,int *j_1)
{
	int i,j;
	for(i=0;i<5;i++)
		for(j=0;j<5;j++)
			if(fang[i][j]==c1)
			{
				*i_1=i;
				*j_1=j;
				break;
			}
}