#include <stdio.h> 
#include <conio.h> 
#include <iostream>

    
int gcd(int a, int b) /*շת�������a,b���������*/ 
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
    
int Ni(int a, int b) /*��a�����b����*/ 
{ 
    int i = 0; 
    while(a*(++i)%b!=1); 
    return i; 
} 
    


void Affine() /*��������*/ 
{ 
    char c[100]; 
    int length, i=0, ka=0, kb=0, tmp; 
    system("cls"); 
    
    printf("********��������********\n���������������: "); 
    gets(c); 
    length = strlen(c); 
    printf("��������Կ�������֣�: "); 
    scanf("%d%d", &ka, &kb); 
    getchar(); 
    while(gcd(ka,26)!=1) 
    { 
       printf("��Կ�����������������"); 
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
    
    printf("\n����Ϊ:\n%s\n", c); 
    printf("���κμ�����..."); 
    getch(); 
}  

void exAffine() /*�������*/ 
{ 
    char c[100]; 
    int length, i=0, ka=0, kb=0, tmp; 
    system("cls"); 
    
    printf("********��������********\n���������������: "); 
    gets(c); 
    length = strlen(c); 
    printf("��������Կ�������֣�: "); 
    scanf("%d%d", &ka, &kb); 
    getchar(); 
    while(gcd(ka,26)!=1) 
    { 
       printf("��Կ�����������������"); 
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
    printf("\n����Ϊ:\n%s\n", c); 
    printf("���κμ�����..."); 
    getch(); 
} 
int main()
{ 
    char i = '0'; 
 
    printf("********�밴1��3ѡ��:********\n"); 
    printf("1.�������\n2.�������\n3.�˳�\n"); 
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