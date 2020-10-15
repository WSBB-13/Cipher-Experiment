//Download by http://www.NewXing.com
#include "stdafx.h"
#include "CCommon.h"
#include "math.h"

int Hexchar_To_Int10(CString input)
{
	int i;
	for(i=0;i<16;i++)
	{
		if(input==HexArr[i])
			break;
	}
	return i;
}

CString Int10_To_Binstr(unsigned pInt)
{
	CString rst="";
	unsigned sang=pInt,remain;
	char c1;
	while(sang>1)
	{
		remain=sang%2;
		sang=sang/2;
		c1=remain+48;
		rst=rst+c1;
	}
	c1=sang+48;
	rst=rst+c1;
	rst.MakeReverse();
	return rst;
}

unsigned Binstr_To_Int10(CString input)//×Ö·û´®
{
	int i,tLen=input.GetLength();
	unsigned rst=0;
	for(i=0;i<tLen;i++)
		rst=rst+(input[i]-48)*(unsigned)pow(2,tLen-i-1);
	return rst;
}

CString Int10_To_Hexstr(unsigned pInt,int ws)
{
	CString rst="",cs1,cs2;
	int i=0,tLen,rm;
	cs1=Int10_To_Binstr(pInt);
	tLen=cs1.GetLength();
	rm=tLen%4;
	if(rm==0) rm=4;
	if(tLen<4) rm=tLen;
	while(i<tLen)
	{
		cs2=cs1.Mid(i,rm);
		rst=rst+HexArr[Binstr_To_Int10(cs2)];
		i+=rm;
		rm=4;
	}
	if(ws>0)
	{
		tLen=rst.GetLength();
		if(tLen<ws)
		{
			for(i=1;i<=(ws-tLen);i++)
				rst="0"+rst;
		}
	}
	return rst;
}

unsigned Hexstr_To_Int10(CString input)
{
	int i,tLen=input.GetLength();
	unsigned rst=0;
	for(i=0;i<tLen;i++)
		rst=rst+Hexchar_To_Int10(input[i])*(unsigned)pow(16,tLen-i-1);
	return rst;
}

CString CrtRandString(int num)
{
	int k,n;
	CString rst="";
	for(k=0;k<num;k++)
	{
		n=rand();
		n=n%60;
		rst=rst+StrArr[n];
	}
	return rst;
}

CString Binstr_To_Charstr(CString input)
{
	CString tRst="",tTmp;
	int i=0,tLen,tCh;
	tLen=input.GetLength();
	while(tLen>0)
	{
		tTmp=input.Mid(i,8);
		tCh=Binstr_To_Int10(tTmp);
		tRst=tRst+CString(tCh);
		i=i+8;
		tLen=tLen-8;
	}
	tRst.TrimRight();
	return tRst;
}
///////////////////
CString Char_To_Binstr(int c,int num)
{
	int i,k=1,m;
	CString tRtn="";
	for(i=0;i<num;i++)
	{
		m=(c>>i)&k;
		tRtn=tRtn+CString(m+48);
	}
	tRtn.MakeReverse();
	return tRtn;
}

CString GStr_To_BinStr(CString input)
{
	int i,tLen;
	CString tRtn="";
	tLen=input.GetLength();
	for(i=0;i<tLen;i++)
		tRtn=tRtn+Char_To_Binstr(input[i],8);
	return tRtn;
}
