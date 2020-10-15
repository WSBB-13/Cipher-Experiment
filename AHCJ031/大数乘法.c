#include<stdio.h>
#include<string.h>
void main()
{
 int f;
 int i,j,an,bn,k,d;
 char a[1000],b[1000];
 int af[1000]={0},bf[1000]={0},c[1000]={0};
 while(scanf("%s%s",a,b)!=EOF)
 {
  an=strlen(a);  
  bn=strlen(b);
  k=an>bn?an:bn;
  c[0]=0;
  f=0;
  for(i=0;i<an;i++)
   af[i]=a[an-i-1]-'0';
  for(i=0;i<bn;i++)
   bf[i]=b[bn-i-1]-'0';
  
  for(j=0;j<bn;j++)
  {
   for(i=0;i<an;i++)
   {
    d=c[i+j];
    c[i+j]=(d+bf[j]*af[i])%10;
    c[i+1+j]+=(d+bf[j]*af[i])/10;
   }
  }
  for(i=an+bn;i>=0;i--)
  {
   if(c[i])
    f=1;
   if(f || i==0)
    printf("%d",c[i]);
  }
  printf("\n");
  for(i=0;i<2*k;i++)
   c[i]=af[i]=bf[i]=0; 
 }
}