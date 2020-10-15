#include<stdio.h>
int gcd(int d,int f)
{
	int temp;
	while(f!=0)
	{
		temp=d;
		d=f;
		f=temp%f;
	}
	return d;
}
int Euclid(int d, int f)
{
	int Q[100],B[100],q1,q2,c1,c2,i=1;
	B[0]=0;
	B[1]=1;
	q1=f/d;
	c1=f%d;
	Q[0]=q1;
    if(c1!=1&&c1!=0)
	{
    	q2=d/c1;
    	c2=d%c1;
        Q[1]=q2;
		while(c2!=1&&c2!=0)
		{
			q2=c1/c2;
			c2=c1%c2;
			c1=c2;
			i++;
			Q[i]=q2;
		}
		for(int j=0;j<=i;j++)
		{
			B[j+2]=(-1)*B[j+1]*Q[j]+B[j];
		}
        return B[i+2];
	}
	else
		return (-1)*B[1]*Q[0]+B[0];
}
void main()
{
	int d,f,d1;
	printf("请输入任意两个互为素数的整数:");
	while(1)
	{
		scanf("%d %d",&d,&f);
		if((gcd(d,f))==1)
		{
	    	d1=Euclid(d, f);
			if(d1<0)
				d1=d1+f;
            printf("%d\n",d1);
			break;
		}
    	else
		    printf("您输入的两数不合法请重新输入\n");
	}
}