#include<stdio.h>
#include<string.h>
int compare(char *a,char *b)
{
 int i,an,bn,fa=0,fb=0;
 an=strlen(a);
 bn=strlen(b);
 for(i=0;i<an;i++)
 {
  if(a[i]=='0' && i!=an-1)
   fa++;
  else
   break;  
 }
 for(i=0;i<an;i++)
  a[i]=a[i+fa];
 a[an-fa]='\0';
 for(i=0;i<bn;i++)
 {
  if(b[i]=='0' && i!=bn-1)
   fb++;
  else
   break;  
 }
 for(i=0;i<bn;i++)
  b[i]=b[i+fb];
 b[bn-fb]='\0';

 an=strlen(a);
 bn=strlen(b);
 if(strcmp(a,b)==0)
  return 0;
 if(an>bn)
  return 1;
 else if(an==bn)
  return strcmp(a,b);
 else
  return -1;
}
void cop(char *a,int n,char *c)
{
 int i;
 memset(c,0,sizeof(c));
 for(i=0;i<n;i++)
  c[i]=a[i];
}
void cheng(char *a,int n,char *r)
{
 int f;
 int i,j,an;
 int af[1000]={0};
 int c[1000]={0};
 memset(r,0,sizeof(r));
 an=strlen(a);  
 f=0;
 for(i=0;i<an;i++)
  af[i]=a[an-i-1]-'0';
 for(i=0;i<an;i++)
 {
  c[i]+=(n*af[i])%10;
  c[i+1]=(n*af[i])/10;
 }
 for(i=an,j=0;i>=0;i--)
 {
  if(c[i])
   f=1;
  if(f || i==0)
   r[j++]=c[i]+'0';
 }
 r[j]='\0';
 for(i=0;i<=an;i++)
  c[i]=af[i]=0; 
}
void jian(char *a,char *b,char *r)
{
 int f,n;
 int i,j,an,bn,k;
 int af[1000]={0},bf[1000]={0},c[1000];
 an=strlen(a);  
 bn=strlen(b);
 k=an>bn?an:bn;
 c[0]=0;
 f=0;
 n=compare(a,b);
 for(i=0;i<an;i++)
  af[i]=a[an-i-1]-'0';
 for(i=0;i<bn;i++)
  bf[i]=b[bn-i-1]-'0';

 for(i=0;i<k;i++)
 {
  if(n>=0)
  {
   if(af[i]>=bf[i])
    c[i]=af[i]-bf[i];
   else
    c[i]=af[i]-bf[i]+10,af[i+1]--;
  }
  else
  {
   if(bf[i]>=af[i])
    c[i]=bf[i]-af[i];
   else
    c[i]=bf[i]-af[i]+10,bf[i+1]--;
  }
 }
 for(i=k-1,j=0;i>=0;i--)
 {
  if(c[i])
   f=1;
  if(f || i==0)
   r[j++]=c[i]+'0';
 }
 for(i=j;i<1000;i++)
  r[i]='\0';

}
void main()
{
 void jian(char *a,char *b,char *r);
 char a[1000],b[1000];
 int c[1000]={0};
 char r1[1000],r2[1000];
 char p[1000]={0},f[10];
 int i,j,an,bn,q,n;
 while(scanf("%s %s",a,b)!=EOF)
 {
  an=strlen(a);
  bn=strlen(b);
  q=0;f[0]='0';
  if(an>=bn)
  {
   cop(a,bn,p);
   for(j=0;j<an-bn+1;j++)
   {
    for(i=0;;i++)
    {
     cheng(b,i,r1);
     cheng(b,i+1,r2);
     compare(r1,p);
    
     if(compare(r2,p)>0)
      break;
    }
    jian(p,r1,p);
    n=strlen(p);
    //printf("jiu ");puts(p);
    p[n]=a[bn+j];
   // printf("xin ");puts(p);
    
     
    c[j]=i;
   }
   if(c[0]!=0 || c[1]==0)
    printf("%d",c[0]);
   for(j=1;j<an-bn+1;j++)
    printf("%d",c[j]);
   printf(".");
   for(j=0;j<10;j++)
   {
    for(i=0;;i++)
    {
     cheng(b,i,r1);
     cheng(b,i+1,r2);
     if(compare(r2,p)>0)
      break;   
    }
    jian(p,r1,p);
    n=strlen(p);
    p[n]='0';
    c[j]=i;   
   }
   for(j=1;j<10;j++)
    printf("%d",c[j]);
   c[1]=0;
   printf("\n");
  }
  else
  {
   for(i=an,j=0;j<10;i++,j++)
    a[i]='0';
   cop(a,bn,p);
   printf("0.");
   
   for(j=0;j<10;j++)
   {
    for(i=0;;i++)
    {
     cheng(b,i,r1);
     cheng(b,i+1,r2);
     if(compare(r2,p)>0)
      break;   
    }
    jian(p,r1,p);
    p[bn]='0';
    c[j]=i;

    printf("%d",c[j]);  
   }
   c[1]=0;
   printf("\n");
  }
 }
}