//素性的检测
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <assert.h>

#define MAXSIZE 30

int gcd(int x,int y)
{
    int g;

    if(x<0)
    {
        x=-x;
    }
    if(y<0)
    {
        y=-y;
    }
    if(x+y==0)
    {
        return -100;
    }

    g=y;
    while(x>0)
    {
        g=x;
        x=y%x;
        y=g;
    }
    return g;
  }


/*计算雅克比符号*/
int jacobi(int a,int b)
{
    int g;

    if(b%2==0)   //b是一个偶数
    {
       return -100;
    }
    if(a>=b)    //J(a,n)=J((a mod n),n)
    {
        a=a%b;
    }
    if(a==0)    //J(0,n)=0
    {
        return 0;
    }
    if(a==1)      //J(1,n)=1
    {
        return 1;
    }

    if(a<0)                // J(a,b)=(-1){(b-1)/2 }J(-a,b)
    {
        if((b-1)/2%2==0)
        {
            return jacobi(-a,b);
        }
        else
        {
            return -jacobi(-a,b);
        }
    }

    if(a%2==0)              //a是偶数
    {
        if(((b*b-1)/8)%2==0)
        {
            return +jacobi(a/2,b);
        }
        else
        {
            return -jacobi(a/2,b);   //如果(n*n-1)/8是偶数，则J(2,n)=1，否则为-1；
                                     //J(2×m,n)=J(2,n)×J(m,n),
        }
    }

    g=gcd(a,b);

    if(a%2==0)     //s是偶数
    {
        return -100;
    }

    if(g==a)    //J(a,a)=J(0,a)=0
    {
        return 0;
    }
    else
    {
        if(g!=1)
        {
            return jacobi(g,b)*jacobi(a/g,b);
        }
        else
        {
            if(((a-1)*(b-1)/4)%2==0)
            {
                return +jacobi(b,a);
            }
            else
            {
                return -jacobi(b,a);
            }
        }
    }
}

//指数运算
int pow_self(int di,int mi,int mod)
{
    int temp;
    int i;

    temp=1;
    for(i=1;i<=mi;i++)
    {
       temp=(temp*di)%mod;
    }
    return temp;
}

void Solovag(int n)  //n是要被检查的数字
{
    int a,temp;
    //double m;
    int m;
    int j;
    int t;   //用于反复监测的次数
    int i;   //用于计数
    double prob;
    int return_value;

    prob=1;
    printf("请输入要检查的次数:");
    scanf("%d",&t);
    printf("\n");
    srand(time(NULL));
    for(i=1;i<=t;i++)
    {
        a=rand()%n;            //产生随机数a<n
        printf("a=%d\n",a);

       return_value=gcd(a,n);
       if(return_value==1)      //a，p互素
       {
          temp=(n-1)/2;
          m=pow_self(a,temp,n); //进行指数运算

          j=m%n;  //进行模运算  ; j= (a){(n-1)/2 } mod n
          printf("指数运算结果：j=%d\n",j);
          return_value=jacobi(a,n);       //J(a,n)
          printf("雅克比符号计算：%d\n",return_value);
          if(j!=return_value)               //j!=J(a,n)
             {
                printf("p是合数\n");
                break;
             }
          if(j==return_value)
            {
               prob=prob*0.5;
               printf("第%d次:p以概率%lf为素数\n",i,prob);
            }
        }
      if(return_value!=1)       //a，p不互素
       {
            printf("p是合数\n");
            break;
       }
       printf("\n");
   }//for

}

void Lehmam(int l)
{
    int a,temp;
    int m;
    int j;
    int t;   //用于反复监测的次数
    int i;   //用于计数
    double prob;

    prob=1;

    printf("请输入要检查的次数:");
    scanf("%d",&t);
    printf("\n");
    srand(time(NULL));
    for(i=1;i<=t;i++)
    {
        a=rand()%l;
        printf("a=%d\n",a);

        temp=(l-1)/2;
        m=pow_self(a,temp,l);
        j=m%l;
        printf("指数运算的结果=%d\n",j);
        if(j!=1||j!=-1)
         {
           printf("p是合数\n");
           break;
         }
        if(j==1||j==-1)
         {
            prob=prob*0.5;
            printf("第%d次:p以概率%lf为素数\n",i,prob);
        }
         printf("\n");
    }
}

void RM(int r)
{
   int b,m;
   int a;
   int i;
   int t;
   int j,z;

   printf("请输入要检查的次数:");
   scanf("%d",&t);
   printf("\n");

   b=0;
   m=r-1;
   while(m%2==0)
   {
      b=b+1;
      m=m/2;
    }                          //b是能整除n-1的2的最大幂
   printf("end:b=%d\n",b);
   m=(r-1)/(int)pow(2,b);       //p-1=m*pow(2,b)
   printf("m=%d\n",m);
   srand(time(NULL));
   for(i=1;i<=t;i++)
   {
        a=rand()%r;
        printf("a=%d\n",a);

        j=0;
        z=pow_self(a,m,r);           //z=pow(a,m) mod p

        if(z==1||z==-1)
        {
            printf("p以3/4的概率为素数，检测停止！\n");
            break;
        }
        else
        {   //如果j>0且z=1，p为素数
          while(z!=1)
           {
              j=j+1;
             z=z*z%r;
             if(j>b||(j=b&&z!=r-1) )
             {
                printf("p为合数，检测停止！\n");
                break;
             }
             else
             {
                if(z==-1)
                {
                  printf("p以3/4的概率为素数，检测停止！\n");
                  break;
                }
                else
                 {
                    if(z==1)
                     {
                       printf("p为合数，检测停止！\n");
                       break;
                     }
                     else
                     {
                       continue;
                     }
                 }
             }
          }//while
          break;
        }//else
         printf("\n");
   }//for
}


   int main()
{
    int p,k;   //被检查的数字

    fflush(stdin);
    printf("请输入要被检查素性的数字：");
    scanf("%d",&p);

    printf("\n\n");
	printf("***********************素性检测菜单**********************\n");
	printf("                  1.Solovag-Strassen检测\n");
	printf("                  2.Lehmam检测\n");
	printf("                  3.Rabin-Miller检测\n");
	printf("                  0.退出\n");
    printf("请选择：");
    scanf("%d",&k);
	while(k){
    switch(k)
	{
		case 1:{printf("Solovag-Strassen的素性检测结果：\n");
                Solovag(p);
                printf("\n");};
                 break;
		case 2:{printf("Lehmam的素性检测结果：\n");
                Lehmam(p);
                printf("\n");};
                break;
		case 3:{printf("Rabin-Miller的素性检测结果：\n");
                RM(p);
                printf("\n");} ;
                 break;
	}
    printf("\n\n");
	printf("***********************素性检测菜单**********************\n");
	printf("                  1.Solovag-Strassen检测\n");
	printf("                  2.Lehmam检测\n");
	printf("                  3.Rabin-Miller检测\n");
	printf("                  0.退出\n");
    printf("请选择：");
    scanf("%d",&k);
	}
	
     return 0;
     
}
