#include<iostream>
#include<string.h>
#define MAXNUM 65536

using namespace std;

char info[MAXNUM]="\0";
__int64 num=0;
unsigned long A=0x67452301;
unsigned long B=0xefcdab89;
unsigned long C=0x98badcfe;
unsigned long D=0x10325476;

int F(int X,int Y,int Z)
{
	return (X&Y)|((~X)&Z);
}
int G(int X,int Y,int Z)
{
	return (X&Z)|(Y&(~Z));
}
int H(int X,int Y,int Z)
{
	return X^Y^Z;
}
int I(int X,int Y,int Z)
{
	return Y^(X|(~Z));
}


void FF(unsigned long &a,unsigned long b,unsigned long c,unsigned long d,unsigned long M,unsigned long s,unsigned long ti)
{
	unsigned long tmp=(a+F(b,c,d)+M+ti);
	a=(tmp<<s)|(tmp>>(32-s));
	a=a+b;
}
void GG(unsigned long &a,unsigned long b,unsigned long c,unsigned long d,unsigned long M,unsigned long s,unsigned long ti)
{
	unsigned long tmp=(a+G(b,c,d)+M+ti);
	a=(tmp<<s)|(tmp>>(32-s));
	a=a+b;
}
void HH(unsigned long &a,unsigned long b,unsigned long c,unsigned long d,unsigned long M,unsigned long s,unsigned long ti)
{
	unsigned long tmp=(a+H(b,c,d)+M+ti);
	a=(tmp<<s)|(tmp>>(32-s));
	a=a+b;
}
void II(unsigned long &a,unsigned long b,unsigned long c,unsigned long d,unsigned long M,unsigned long s,unsigned long ti)
{
	unsigned long tmp=(a+I(b,c,d)+M+ti);
	a=(tmp<<s)|(tmp>>(32-s));
	a=a+b;
}

void input()
{
	printf("Please enter the origin information:\n");
	gets(info);
	num=strlen(info);
}

void append()
{
	__int64 tmp=num*8;
	for(int i=0;i<64;i++)
		if((num+i)%64==56)
			break;
	if(i)
	{
		info[num++]=(char)0x80;
		while(--i)
			info[num++]=0;
	}
	memmove(info+num,(char*) &tmp,sizeof(tmp));
	num+=8;
}

int main()
{
	int i;
	unsigned long a;
	unsigned long b;
	unsigned long c;
	unsigned long d;
	unsigned long M[16];

	input();
	append();
	for(i=0;i<num;i=i+64)
	{
		a=A;b=B;c=C;d=D;
		memmove((char*)M,info+i,64);
		//第一轮
		FF(a, b, c, d, M[0], 7, 0xd76aa478);
		FF(d, a, b, c, M[1], 12, 0xe8c7b756);
		FF(c, d, a, b, M[2], 17, 0x242070db);
		FF(b, c, d, a, M[3], 22, 0xc1bdceee);
		FF(a, b, c, d, M[4], 7, 0xf57c0faf);
		FF(d, a, b, c, M[5], 12, 0x4787c62a);
		FF(c, d, a, b, M[6], 17, 0xa8304613);
		FF(b, c, d, a, M[7], 22, 0xfd469501);
		FF(a, b, c, d, M[8], 7, 0x698098d8);
		FF(d, a, b, c, M[9], 12, 0x8b44f7af);
		FF(c, d, a, b, M[10], 17, 0xffff5bb1);
		FF(b, c, d, a, M[11], 22, 0x895cd7be);
		FF(a, b, c, d, M[12], 7, 0x6b901122);
		FF(d, a, b, c, M[13], 12, 0xfd987193);
		FF(c, d, a, b, M[14], 17, 0xa679438e);
		FF(b, c, d, a, M[15], 22, 0x49b40821);
		//第二轮
		GG(a, b, c, d, M[1], 5, 0xf61e2562);
		GG(d, a, b, c, M[6], 9, 0xc040b340);
		GG(c, d, a, b, M[11], 14, 0x265e5a51);
		GG(b, c, d, a, M[0], 20, 0xe9b6c7aa);
		GG(a, b, c, d, M[5], 5, 0xd62f105d);
		GG(d, a, b, c, M[10], 9, 0x02441453);
		GG(c, d, a, b, M[15], 14, 0xd8a1e681);
		GG(b, c, d, a, M[4], 20, 0xe7d3fbc8);
		GG(a, b, c, d, M[9], 5, 0x21e1cde6);
		GG(d, a, b, c, M[14], 9, 0xc33707d6);
		GG(c, d, a, b, M[3], 14, 0xf4d50d87);
		GG(b, c, d, a, M[8], 20, 0x455a14ed);
		GG(a, b, c, d, M[13], 5, 0xa9e3e905);
		GG(d, a, b, c, M[2], 9, 0xfcefa3f8);
		GG(c, d, a, b, M[7], 14, 0x676f02d9);
		GG(b, c, d, a, M[12], 20, 0x8d2a4c8a);
		//第三轮
		HH(a, b, c, d, M[5], 4, 0xfffa3942);
		HH(d, a, b, c, M[8], 11, 0x8771f681);
		HH(c, d, a, b, M[11], 16, 0x6d9d6122);
		HH(b, c, d, a, M[14], 23, 0xfde5380c);
		HH(a, b, c, d, M[1], 4, 0xa4beea44);
		HH(d, a, b, c, M[4], 11, 0x4bdecfa9);
		HH(c, d, a, b, M[7], 16, 0xf6bb4b60);
		HH(b, c, d, a, M[10], 23, 0xbebfbc70);
		HH(a, b, c, d, M[13], 4, 0x289b7ec6);
		HH(d, a, b, c, M[0], 11, 0xeaa127fa);
		HH(c, d, a, b, M[3], 16, 0xd4ef3085);
		HH(b, c, d, a, M[6], 23, 0x04881d05);
		HH(a, b, c, d, M[9], 4, 0xd9d4d039);
		HH(d, a, b, c, M[12], 11, 0xe6db99e5);
		HH(c, d, a, b, M[15], 16, 0x1fa27cf8);
		HH(b, c, d, a, M[2], 23, 0xc4ac5665);
		//第四轮
		II(a, b, c, d, M[0], 6, 0xf4292244);
		II(d, a, b, c, M[7], 10, 0x432aff97);
		II(c, d, a, b, M[14], 15, 0xab9423a7);
		II(b, c, d, a, M[5], 21, 0xfc93a039);
		II(a, b, c, d, M[12], 6, 0x655b59c3);
		II(d, a, b, c, M[3], 10, 0x8f0ccc92);
		II(c, d, a, b, M[10], 15, 0xffeff47d);
		II(b, c, d, a, M[1], 21, 0x85845dd1);
		II(a, b, c, d, M[8], 6, 0x6fa87e4f);
		II(d, a, b, c, M[15], 10, 0xfe2ce6e0);
		II(c, d, a, b, M[6], 15, 0xa3014314);
		II(b, c, d, a, M[13], 21, 0x4e0811a1);
		II(a, b, c, d, M[4], 6, 0xf7537e82);
		II(d, a, b, c, M[11], 10, 0xbd3af235);
		II(c, d, a, b, M[2], 15, 0x2ad7d2bb);
		II(b, c, d, a, M[9], 21, 0xeb86d391);
		A+=a;B+=b;C+=c;D+=d;
	}

	unsigned char r[16];

	memmove(r+0,(char *)&A,4);
	memmove(r+4,(char *)&B,4);
	memmove(r+8,(char *)&C,4);
	memmove(r+12,(char *)&D,4);
	printf("MD5:\n");

	for(i=0;i<16;i++)
		printf("%02x",r[i]);
	printf("\n");
	return 0;
}