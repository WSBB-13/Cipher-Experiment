#include<iostream>
#include<cstring>
#include<ctime>
#include<cstdlib>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

int S_box[16][16] ={{0xd6,0x90,0xe9,0xfe,0xcc,0xe1,0x3d,0xb7,0x16,0xb6,0x14,0xc2,0x28,0xfb,0x2c,0x05},
                  {0x2b,0x67,0x9a,0x76,0x2a,0xbe,0x04,0xc3,0xaa,0x44,0x13,0x26,0x49,0x86,0x06,0x99},
                  {0x9c,0x42,0x50,0xf4,0x91,0xef,0x98,0x7a,0x33,0x54,0x0b,0x43,0xed,0xcf,0xac,0x62},
                  {0xe4,0xb3,0x1c,0xa9,0xc9,0x08,0xe8,0x95,0x80,0xdf,0x94,0xfa,0x75,0x8f,0x3f,0xa6},
                  {0x47,0x07,0xa7,0xfc,0xf3,0x73,0x17,0xba,0x83,0x59,0x3c,0x19,0xe6,0x85,0x4f,0xa8},
                  {0x68,0x6b,0x81,0xb2,0x71,0x64,0xda,0x8b,0xf8,0xeb,0x0f,0x4b,0x70,0x56,0x9d,0x35},
                  {0x1e,0x24,0x0e,0x5e,0x63,0x58,0xd1,0xa2,0x25,0x22,0x7c,0x3b,0x01,0x21,0x78,0x87},
                  {0xd4,0x00,0x46,0x57,0x9f,0xd3,0x27,0x52,0x4c,0x36,0x02,0xe7,0xa0,0xc4,0xc8,0x9e},
                  {0xea,0xbf,0x8a,0xd2,0x40,0xc7,0x38,0xb5,0xa3,0xf7,0xf2,0xce,0xf9,0x61,0x15,0xa1},
                  {0xe0,0xae,0x5d,0xa4,0x9b,0x34,0x1a,0x55,0xad,0x93,0x32,0x30,0xf5,0x8c,0xb1,0xe3},
                  {0x1d,0xf6,0xe2,0x2e,0x82,0x66,0xca,0x60,0xc0,0x29,0x23,0xab,0x0d,0x53,0x4e,0x6f},
                  {0xd5,0xdb,0x37,0x45,0xde,0xfd,0x8e,0x2f,0x03,0xff,0x6a,0x72,0x6d,0x6c,0x5b,0x51},
                  {0x8d,0x1b,0xaf,0x92,0xbb,0xdd,0xbc,0x7f,0x11,0xd9,0x5c,0x41,0x1f,0x10,0x5a,0xd8},
                  {0x0a,0xc1,0x31,0x88,0xa5,0xcd,0x7b,0xbd,0x2d,0x74,0xd0,0x12,0xb8,0xe5,0xb4,0xb0},
                  {0x89,0x69,0x97,0x4a,0x0c,0x96,0x77,0x7e,0x65,0xb9,0xf1,0x09,0xc5,0x6e,0xc6,0x84},
                  {0x18,0xf0,0x7d,0xec,0x3a,0xdc,0x4d,0x20,0x79,0xee,0x5f,0x3e,0xd7,0xcb,0x39,0x48}};

unsigned int ck[32] = {0x00070e15,0x1c232a31,0x383f464d,0x545b6269,0x70777e85,0x8c939aa1,0xa8afb6bd,0xc4cbd2d9,              0xe0e7eef5,0xfc030a11,0x181f262d,0x343b4249,0x50575e65,0x6c737a81,0x888f969d,0xa4abb2b9,                    0xc0c7ced5,0xdce3eaf1,0xf8ff060d,0x141b2229,0x30373e45,0x4c535a61,0x686f767d,0x848b9299,                     0xa0a7aeb5,0xbcc3cad1,0xd8dfe6ed,0xf4fb0209,0x10171e25,0x2c333a41,0x484f565d,0x646b7279};
unsigned int fk[4] = {0xa3b1bac6,0x56aa335,0x677d9197,0xb27022dc};

void pri(char a[], int n)//数组输出
{
	for(int i = 0; i < n; i++)
	{
		cout << a[i];
	}
	cout << endl;
}

void pri_(char a[], int n)//16进制输出
{
	int m = n / 4;
	for(int i = 0; i < m; i++)
	{
		int k = i * 4;
		int temp = (a[k]-'0') * 8 + (a[k+1]-'0') * 4 + (a[k+2]-'0') * 2 + (a[k+3]-'0');
		if(temp < 10)
		{
			cout << temp;
		}
		else
		{
			char temp_ = temp - 10 + 'A';
			cout << temp_;
		}
	}
	cout << endl;
}

void pri__(char a[], int n)//二进制转字符输出
{
	int m = n / 8;
	for(int i = 0; i < m; i++)
	{
		int temp = 0,k = i * 8;
		for(int j = 0; j < 8; j++)
		{
			temp = temp * 2;
			temp = temp + a[k+j] - '0';
		}
		cout << char(temp);
	}
	cout << endl;
}

void getbi(char a[], char re[], int n)//获得二进制码
{
	for(int i = 0; i < n; i++)
	{
		int sb = a[i];
		for(int j = 0; j < 8; j++)
		{
			re[i*8+7-j] = sb % 2 + '0';
			sb = sb / 2;
		}
	}
}

void giv(char a[32], char re[32])//赋值
{
	for(int i = 0; i < 32; i++)
		re[i] = a[i];
}

void xor(char a[32], char b[32], char re[32])//异或
{
	for(int i = 0; i < 32; i++)
	{
		if(a[i] == b[i])
			re[i] = '0';
		else
			re[i] = '1';
	}
}

void zy(char a[32], int n)//循环左移
{
	while(n--)
	{
		char temp = a[0];
		for(int i = 0; i < 31; i++)
			a[i] = a[i+1];
		a[31] = temp;
	}
}

void d_to_b(unsigned int a, char re[32])//十进制转二进制
{
	for(int i = 1; i <= 32; i++)
	{
		re[32-i] = a % 2 + '0';
		a = a / 2;
	}
}

void h_to_b(char a[32], char re[4][32])//十六进制转二进制
{
	int i,j;
	char b[128];
	for(i = 0; i < 32; i++)
	{
		int d;
		if(a[i] >= 'A')
			d = a[i] - 'A' + 10;
		else
			d = a[i] - '0';
		for(j = 0; j < 4; j++)
		{
			b[i*4+3-j] = d % 2 + '0';
			d = d / 2;
		}
	}
	for(i = 0; i < 4; i++)
	{
		for(j = 0; j < 32; j++)
			re[i][j] = b[i*32+j];
	}
}

void S_change(char a[32], char re[32])//4个S盒并行置换
{
	for(int i = 0; i < 4; i++)
	{
		int xtemp = 0;
		int ytemp = 0;
		for(int j = 0; j < 4; j++)
		{
			xtemp = xtemp * 2 + a[8*i+j] - '0';
			ytemp = ytemp * 2 + a[8*i+j+4] - '0';
		}
		int temp = S_box[xtemp][ytemp];
		for(int k = 0; k < 8; k++)
		{
			re[i*8+7-k] = temp % 2 + '0';
			temp = temp / 2;
		}
	}
}

void L_change(char a[32], char re[32])//L置换
{
	char temp[32];
	giv(a,temp);
	zy(temp,2);
	xor(a,temp,re);
	zy(temp,8);
	xor(re,temp,re);
	zy(temp,8);
	xor(re,temp,re);
	zy(temp,6);
	xor(re,temp,re);
}

void key_LC(char a[32], char re[32])//L*置换
{
	char temp[32];
	giv(a,temp);
	zy(temp,13);
	xor(a,temp,re);
	zy(temp,10);
	xor(re,temp,re);
}

void F_change(char a[32], char b[32], char c[32], char d[32], char rk[32], char re[32])//F变换
{
	xor(b,c,re);
	xor(re,d,re);
	xor(re,rk,re);
	S_change(re,re);
	L_change(re,re);
	xor(a,re,re);
}

void key_ex(char a[4][32], char re[32][32])//密钥扩展
{
	int i;
	char K[36][32];
	char FK[4][32];
	for(i = 0; i < 4; i++)
	{
		d_to_b(fk[i], FK[i]);
		xor(a[i],FK[i],K[i]);
	}
	char CK[32][32];
	for(i = 0; i < 32; i++)
		d_to_b(ck[i], CK[i]);
	for(i = 0; i < 32; i++)
	{
		char temp[32];
		xor(K[i+1],K[i+2],temp);
		xor(temp,K[i+3],temp);
		xor(temp,CK[i],temp);
		S_change(temp,temp);
    	key_LC(temp,temp);
		xor(K[i],temp,re[i]);
		giv(re[i],K[i+4]);
	}
}

void pu_to_pr(char a[4][32], char b[32][32], char re[4][32])//加密
{
	int i = 0;
	char X[36][32];
	for(i = 0; i < 4; i++)
		giv(a[i],X[i]);
	for(i = 0; i < 32; i++)
		F_change(X[i],X[i+1],X[i+2],X[i+3],b[i],X[i+4]);
	for(i = 0; i < 4; i++)
		giv(X[35-i],re[i]);
}

void pr_to_pu(char a[4][32], char b[32][32], char re[4][32])//解密
{
	int i = 0;
	char X[36][32];
	for(i = 0; i < 4; i++)
		giv(a[i],X[i]);
	for(i = 0; i < 32; i++)
		F_change(X[i],X[i+1],X[i+2],X[i+3],b[31-i],X[i+4]);
	for(i = 0; i < 4; i++)
		giv(X[35-i],re[i]); 
}

double comp(char a[], char b[], int n)//比较俩数组不同的位数
{
	double re = 0;
	for(int i = 0; i < n; i++)
	{
		if(a[i] != b[i])
			re++;
	}
	return re;
}

double comp_Z(char a[4][32], char b[32][32])//输入改变一位，输出平均改变位数
{
	double re = 0;
	char pr[4][32],pr_[4][32];
	pu_to_pr(a,b,pr);
	srand(time(0));
	for(int i = 0; i < 1000; i++)
	{
		int p = rand() % 128;
		if(a[p/32][128%32] == '0')
			a[p/32][128%32] = '1';
		else
			a[p/32][128%32] = '0';
		pu_to_pr(a,b,pr_);
		for(int j = 0; j < 4; j++)
			re = re + comp(pr[j],pr_[j],32);
		for(int k = 0; k < 4; k++)
			giv(pr_[k],pr[k]);
	}
	re = re / 1000;
	return re;
}

double comp_SL(char a[32], int n)//S或L变换输入改变一位，输出平均改变位数
{
	double re = 0;
	char b[32],c[32];
	if(n == 0)
    	S_change(a,b);
	else
		L_change(a,b);
	srand(time(0));
	for(int i = 0; i < 1000; i++)
	{
		int p = rand() % 32;
		if(a[p] == '0')
			a[p] = '1';
		else
			a[p] = '0';
		if(n == 0)
        	S_change(a,c);
    	else
    		L_change(a,c);
		re = re + comp(b,c,32);
		giv(c,b);
	}
	re = re / 1000;
	return re;
}

void round_S()//输入经S盒多次改变后等于输出需要的变化次数
{
	for(int i = 0; i < 256; i++)
	{
		int a = i;
		int re = 1;
		int x = a / 16;
		int y = a % 16;
		int b = S_box[x][y];
		while(1)
		{
			if(a == b)
			{
				if(x > 9)
					cout << char(x+'A'-10);
				else
					cout << char(x+'0');
				if(y > 9)
					cout << char(y+'A'-10) << ": ";
				else
					cout << char(y+'0') << ": ";
				cout << re <<"   ";
				if((i+1) % 8 == 0)
					cout << endl;
				break;
			}
			int x_ = b / 16;
			int y_ = b % 16;
			b = S_box[x_][y_];
			re++;
		}
	}
}

int main()
{
	while(1)
	{
	cout << "SMS4加密" << endl;//界面
	cout << "_______________________________________________________________________________" << endl;
	cout << "0: SMS4加密"<< endl;
	cout << "1: SMS4解密"<< endl;
	cout << "2: SMS4加密输入改变一位，输出平均改变位数"<< endl;
	cout << "3: S和L变换输入改变一位，输出平均改变位数"<< endl;
	cout << "4: 输入经S盒多次改变后等于输出需要的变化次数"<< endl;
	cout << "5: 清屏"<< endl;
	cout << "6: 退出"<< endl;
	cout << "_______________________________________________________________________________" << endl;
	

	int choice;
	cin >> choice;

	if(choice == 0)//加密
	{
	int i,j,k;
	char keys[16], pus[10000], temp[128], key_[4][32], prs[80000] ,key[32][32];
	cout << "请输入密钥（16位字符）： " <<endl;
	for(i = 0; i < 16; i++)
		cin >> keys[i];
	getbi(keys, temp, 16);
	for(i = 0; i < 4; i++)
	{
		for(j = 0; j < 32; j++)
			key_[i][j] = temp[i*32+j];
	}
	key_ex(key_,key);
	cout << "请输入明文： " <<endl;
	cin.ignore();
	cin.getline(pus,100000);
	int t = strlen(pus);
	for(i = t; i < ((t+15)/16)*16; i++)
		pus[i] = ' ';
	t = (t+15)/16;
	for(i = 0; i < t; i++)
	{
		char pu[4][32], pr[4][32];
		char pu_[16];
		for(j = 0; j < 16; j++)
			pu_[j] = pus[i*16+j];
		getbi(pu_, temp, 16);
		for(j = 0; j < 4; j++)
		{
			for(k = 0; k < 32; k++)
		    	pu[j][k] = temp[j*32+k];
		}
		pu_to_pr(pu,key,pr);
		for(j = 0; j < 4; j++)
		{
			for(k = 0; k < 32; k++)
		    	prs[i*128+j*32+k] = pr[j][k];
		}
	}
	cout << "加密后密文为： " <<endl;
	pri_(prs, t*128);
	}

	else if(choice == 1)//解密
	{
	int i,j,k;
	char keys[16], temp[128], pus_[80000], key_[4][32], prs[80000] ,key[32][32];
	cout << "请输入密钥（16位字符）： " <<endl;
	for(i = 0; i < 16; i++)
		cin >> keys[i];
	getbi(keys, temp, 16);
	for(i = 0; i < 4; i++)
	{
		for(j = 0; j < 32; j++)
			key_[i][j] = temp[i*32+j];
	}
	key_ex(key_,key);
	cout << "请输入密文： " <<endl;
	cin.ignore();
	cin.getline(prs,800000);
	int t = strlen(prs);
	t = t / 32;
	for(i = 0; i < t; i++)
	{
		char pu[4][32], pr[4][32];
		char pr_[32];
		for(j = 0; j < 32; j++)
			pr_[j] = prs[i*32+j];
		h_to_b(pr_,pr);
		pr_to_pu(pr,key,pu);
		for(j = 0; j < 4; j++)
		{
			for(k = 0; k < 32; k++)
		    	pus_[i*128+j*32+k] = pu[j][k];
		}
	}
	cout << "解密后明文为： " <<endl;
	pri__(pus_, t*128);
	}

	else if(choice == 2)//测试SMS4加密输入改变一位，输出平均改变位数
	{
	char ce[4][32];
	srand(time(0));
	unsigned int sraa = rand();
	unsigned int srab = rand();
	unsigned int srac = rand();
	unsigned int srad = rand();
	d_to_b(sraa,ce[0]);
	d_to_b(sraa,ce[1]);
	d_to_b(sraa,ce[2]);
	d_to_b(sraa,ce[3]);
	cout << "此次测试结果为： " << endl;
	cout << comp_Z(ce,ce) << "位" << endl;
	}

	else if(choice == 3)//测试S和L变换输入改变一位，输出平均改变位数
	{
	char ce_[32];
	srand(time(0));
	unsigned int sra = rand();
	d_to_b(sra,ce_);
	cout << "此次测试结果为： " << endl;
	cout << "S: " << comp_SL(ce_,0) << "位" << endl;
	cout << "L: " << comp_SL(ce_,1) << "位" << endl;
	}

	else if(choice == 4)//输入经S盒多次改变后等于输出需要的变化次数
	{
	cout << "输入与需要轮数的对应关系为： " <<endl;
	round_S();
	}

	else if(choice == 5)//清屏
	{
		system("cls");
	}

	else if(choice == 6)//退出
	{
		break;
	}

	else//无效输入
	{
		cout << "无效输入" <<endl;
	}
	cout << endl;
	}
	return 0;
}
