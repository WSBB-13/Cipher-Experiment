#include <stdio.h>

#include <math.h> 

#include <stdlib.h> 

int b[8]={0},key1[128]={0},g[16]={0}; 

void chang1(char c,int b[8])    //将一个字母转换成二进制数 

{ 

int i=0;  

int d=c;  

while(d!=0)  

{  

b[i++]=d%2;   

d=d/2;

} 

} 

long chang2(int d[],long n)  //将一串16位的二进制数转换成一个十进制数 

{ 

int i; 

for(i=0;i<16;i++)   

n=n+d[i]*(int)pow(2,i);  

return n; 

} 

void chang3(long x,int d[])  //将一个十进制数装换成二进制数 

{ 

int i=0;  

while(x!=0)  

{  

d[i++]=x%2;   

x=x/2; 

} 

} 

int chang4(int d[]) //将一串二进制数转换成十进制数 

{    

int i,n=0;  

for(i=0;i<8;i++)  

n=n+d[i]*(int)pow(2,i);  

return n; 

} 

void revolve(int a[128])  //将一串128位的二进制左旋25位

{ 

int c[25],i;   

for(i=0;i<25;i++)   

c[i]=a[i];  

for(i=0;i<103;i++)   

a[i]=a[i+25];  

for(i=0;i<25;i++)   

a[i+103]=c[i]; 

} 

void main() 

{ 

char c[8],key[16];  

unsigned  long  d1[4]={0}, d2[8]={0}, d3[56]={0}, d4[8][6]={0}, d5[4], a1, a2, a3, a4, a5,a6,a7,a8,a9,a10,t;   

int b1[4][16],b2[8][16],g1[8],g2[8],n,x[4],y[4];

int i,j,k=0,l;  

printf("\n\n\t\t---------------欢迎使用IDEA加密系统-----------------\n\n"); 

printf("\t\t\t请选择: 1.加密 2.退出\n\n");  

do 

{  

printf("请选择:");   

scanf("%d",&n);   

switch(n)   

{  

case 1:    

{    

printf("请输入8个明文字母:");              

scanf("%s",c);              

printf("请输入16个密钥字母:");              

scanf("%s",key);              

for(j=0;j<8;j=j+2)   //将每一个明文字母转换为二进制数      

{              

chang1(c[j+1],b);              

for(i=0;i<8;i++)                  

b1[j/2][i]=b[i];               

chang1(c[j],b);               

for(i=0;i<8;i++)               

b1[j/2][8+i]=b[i];      

}               

for(i=0;i<4;i++)              

d1[i]=chang2(b1[i],d1[i]); //将16位的二进制数转换为十进制数                

for(j=0;j<16;j=j+2)    //将16个密钥字母转换为128个二进制数        

{               

chang1(key[j+1],b);               

for(i=j*8;i<(j*8+8);i++)                 

key1[i]=b[i];                

chang1(key[j],b);                

for(i=j*8+8;i<(j*8+16);i++)                

key1[i]=b[i];        

} /*             

for(i=0;i<128;i++)                  

printf("%d",key1[i]);               

printf("\n\n");              

revolve(key1);               

for(i=0;i<128;i++)

printf("%d",key1[i]); */                 

j=7;                 

while(j!=0)     //将128位的二进制一直左旋，直到产生52个子密钥     

{     

for(i=0;i<128;i++)                     

b2[i/16][i%16]=key1[i];                     

for(l=0;l<8;l++)      

{      

d3[k]=chang2(b2[l],d3[k]);                 

k++;      

}               

revolve(key1);                  

j--;        

}                  

for(i=0;i<48;i++)     //将52个密钥的前48个分成8组               

d4[i/6][i%6]=d3[i];              

for(i=0;i<4;i++)   //后四个密钥               

d5[i]=d3[i+48]; //              printf("%dln",d1[3]);                

for(i=0;i<8;i++)     

{                

a1=(d1[0]*d4[i][0])%((long)(pow(2,16)+1));               

a2=(d1[1]+d4[i][1])%((long)(pow(2,16)));               

a3=(d1[2]+d4[i][2])%((long)(pow(2,16)));                     

a4=(d1[3]*d4[i][3])%((long)(pow(2,16)+1));                

a5=a1^a3;               

a6=a2^a4;                

a7=(a5*d4[i][4])%((long)(pow(2,16)+1));               

a8=(a6+a7)%((long)(pow(2,16)));               

a9=(a8*d4[i][5])%((long)(pow(2,16)+1));                

a10=(a7+a9)%((long)(pow(2,16)));               

d1[0]=a1^a9;               

d1[2]=a2^a10;                  

d1[1]=a3^a9;                

d1[3]=a4^a10; //               printf("%dln",d1[3]);    

}              

t=d1[1];              

d1[1]=d1[2];

d1[2]=t; //              printf("%dln",d1[3]);                  

d1[0]=(d1[0]*d5[0])%((long)(pow(2,16)+1));                 

d1[1]=(d1[1]+d5[1])%((long)(pow(2,16)));                

d1[2]=(d1[2]+d5[2])%((long)(pow(2,16)));                 

d1[3]=(d1[3]*d5[3])%((long)(pow(2,16)+1)); //             printf("%dl,%dl",d1[3],d5[3]);                

printf("密文为:\n用二进制表示,每串由高位到低位:\n");                   

for(j=0;j<4;j++)     

{ //              printf("%dln",d1[j]);                  

chang3(d1[j],g);                     

for(i=0;i<8;i++)                

g2[i]=g[i+8];      

x[j]=chang4(g2);      

for(i=7;i>=0;i--)       

printf("%d",g2[i]);                

printf(" ");                

for(i=0;i<8;i++)      

{                 

g1[i]=g[i];     

}     

y[j]=chang4(g1);                   

for(i=7;i>=0;i--)       

printf("%d",g1[i]);               

printf(" ");     

}    

printf("\n用十进制表示:");     

for(j=0;j<4;j++)      

printf("%d %d ",x[j],y[j]);     

printf("\n");     

break;    

}   

case 2:     n=0;     break;    

default:     printf("请重新输入!\n");     

}  

}while(n!=0);

printf("\n"); 

}

