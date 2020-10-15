#include<iostream>
#include<vector>
#include<cmath>
#include<fstream>
using namespace std;
void main()
{
	
///下面是密钥的产生/////////////
	int a[31]={1,1,0,0,1};
	for(int k=5;k<31;++k)
		a[k]=(a[k-2]+a[k-5])%2;
	cout<<"密钥如下:"<<endl;
	for(int jj=0;jj<31;++jj)
		cout<<a[jj]<<' ';
	cout<<endl;
//////////////////////
	int i=0,key;
	cout<<"请选择操作方式: 1-加密  2-解密"<<endl;
	cin>>key;	
	vector<int> s,ss;
	if(key==1||key==2)
	{

	  if(key==1)
	  {   cout<<"加密成功，密文见out.txt"<<endl;
		  ifstream in("in.txt");
		  ofstream out("out.txt");
		  char c;
          while(in>>c)
		  {
		     int sum=0;
		     for(int j=0;j<8;++j)
			     sum+=pow(2,7-j)*a[(i+j)%31];
		     if(i+j>32)
			    i=(i+j-1)%31+1;
		     else
			    i=i+8;
		     s.push_back((int(c))^sum);
		  }
	      for(int kk=0;kk<s.size();++kk)
		  {
			 out<<char(s[kk]);
		  }

	  }
	  if(key==2)
	  {   
		cout<<"解密成功，明文见in.txt"<<endl;
		ifstream in("out.txt");
		ofstream out("in.txt");
		    char c;
         while(in>>c)
		 {
		    int sum=0;
		    for(int j=0;j<8;++j)
			    sum+=pow(2,7-j)*a[(i+j)%31];
		    if(i+j>32)
			i=(i+j-1)%31+1;
		    else
			   i=i+8;
		    s.push_back((int(c))^sum);

		 }

	     for(int kk=0;kk<s.size();++kk)
		 {
		   out<<char(s[kk]);
		 }

	  }

	  ////////////
	}
	else
		cout<<"操作无效！"<<endl;
}