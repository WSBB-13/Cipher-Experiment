#include<stdio.h>
#include<string.h>
void main()
{
 int f;
 int i,an,bn,k;
 char a[1000],b[1000];
 int af[1000]={0},bf[1000]={0},c[1000];         
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
  
  for(i=0;i<k;i++)
  {
   c[i]+=(af[i]+bf[i])%10;            
   c[i+1]=(af[i]+bf[i])/10;
  }
  if(c[i]!=0) k++;                        

  for(i=k-1;i>=0;i--)                  
  {
   if(c[i])                                      
    f=1;
   if(f || i==0)
    printf("%d",c[i]);
  }
  printf("\n");
  for(i=0;i<k;i++)
   af[i]=bf[i]=0; 
 }
}