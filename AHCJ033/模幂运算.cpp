#include "iostream.h"
#include "math.h"
#include "time.h"
#include "Windows.h"
//int   iBgn;   

void main()
{   int   iBgn; 
	int a,num=0,n;
	cout<<"底数: a=";
	cin>>a;
	cout<<"指数: m=";
	cin>>num;
	cout<<"模数: n(n不能为0，否则会出错)=";
	cin>>n;
	
	//	cout<<"输入一个十进制数："; 
	
//	cout<<"转化为2进制后为："<<endl; 
	int elem[1000]; 
	for(int i=0;i<=1000;i++) 
	{ 
		elem[i]=(num%2); 
		num=(int)(num/2); 
		if(num<1) 
		{ 
			break; 
		} 
		else continue; 
	} 
	for(int j=i;j>=0;j--) 
	{ 
		
	//	cout<<elem[j]; 
        elem[j]=pow(a,elem[j]);
	} 
	int temp=1;
	int temp0;

    for(int t=i;t>=0;t--) 
	{ 
 
	
    	temp=pow(temp,2)*elem[t];
		temp=temp%n;

	} 
    cout<<"结果为："<<temp<<endl;

/*
    int t=6;
	t=pow(6,2);
	cout<<t;
*/


 iBgn=GetTickCount();

cout<<"执行时间为"<<iBgn<<"微妙"<<endl;


}


//  iBgn=GetTickCount();
