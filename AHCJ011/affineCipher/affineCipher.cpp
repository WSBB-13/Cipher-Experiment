#include <stdio.h> 
#include <conio.h> 
#include <iostream>

    
int gcd(int a, int b) /*辗转相除法求a,b的最大公因数*/ 
{ 
   int k = 0; 
     
   do 
   { 
    k = a%b; 
    a = b; 
    b = k; 
   }while(k!=0); 

   return a; 
 } 
    
int Ni(int a, int b) /*求a相对于b的逆*/ 
{ 
    int i = 0; 
    while(a*(++i)%b!=1); 
    return i; 
} 
    


void Affine() /*仿射密码*/ 
{ 
    char c[100]; 
    int length, i=0, ka=0, kb=0, tmp; 
    system("cls"); 
    
    printf("********仿射密码********\n请输入最初的明文: "); 
    gets(c); 
    length = strlen(c); 
    printf("请输入密钥（两数字）: "); 
    scanf("%d%d", &ka, &kb); 
    getchar(); 
    while(gcd(ka,26)!=1) 
    { 
       printf("密钥输入错误，请重新输入"); 
	   scanf("%d%d", &ka, &kb); 
       getchar(); 
    } 
    
    for(i=0; i<length; i++) 
    { 
        if(c[i]>96&&c[i]<123) 
        c[i] = (ka*(c[i]-97)+kb)%26+65; 
        else if(c[i]>64&&c[i]<91) 
        c[i] = (ka*(c[i]-65)+kb)%26+65; 
    } 
    
    printf("\n密文为:\n%s\n", c); 
    printf("按任何键返回..."); 
    getch(); 
}  

void exAffine() /*仿射解密*/ 
{ 
    char c[100]; 
    int length, i=0, ka=0, kb=0, tmp; 
    system("cls"); 
    
    printf("********仿射密码********\n请输入最初的密文: "); 
    gets(c); 
    length = strlen(c); 
    printf("请输入密钥（两数字）: "); 
    scanf("%d%d", &ka, &kb); 
    getchar(); 
    while(gcd(ka,26)!=1) 
    { 
       printf("密钥输入错误，请重新输入"); 
	   scanf("%d%d", &ka, &kb); 
       getchar(); 
    } 
    
    
    for(i=0; i<length; i++) 
    { 
        if(c[i]>64&&c[i]<91) 
        { 
            tmp = Ni(ka,26)*((c[i]-65)-kb); 
            if(tmp<0) 
                c[i] = tmp%26+26+97; 
            else 
                c[i] = tmp%26+97; 
        } 
    } 
    printf("\n明文为:\n%s\n", c); 
    printf("按任何键返回..."); 
    getch(); 
} 
int main()
{ 
    char i = '0'; 
 
    printf("********请按1～3选择:********\n"); 
    printf("1.仿射加密\n2.仿射解密\n3.退出\n"); 
    i = getch(); 
    while(i!='3')
	{	
	    if(i=='1') 
        Affine(); 
        else if(i=='2') 
        exAffine();
		i = getch(); 
    }
    
	return 0;
}