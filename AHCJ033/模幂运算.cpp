#include "iostream.h"
#include "math.h"
#include "time.h"
#include "Windows.h"
//int   iBgn;   

void main()
{   int   iBgn; 
	int a,num=0,n;
	cout<<"����: a=";
	cin>>a;
	cout<<"ָ��: m=";
	cin>>num;
	cout<<"ģ��: n(n����Ϊ0����������)=";
	cin>>n;
	
	//	cout<<"����һ��ʮ��������"; 
	
//	cout<<"ת��Ϊ2���ƺ�Ϊ��"<<endl; 
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
    cout<<"���Ϊ��"<<temp<<endl;

/*
    int t=6;
	t=pow(6,2);
	cout<<t;
*/


 iBgn=GetTickCount();

cout<<"ִ��ʱ��Ϊ"<<iBgn<<"΢��"<<endl;


}


//  iBgn=GetTickCount();
