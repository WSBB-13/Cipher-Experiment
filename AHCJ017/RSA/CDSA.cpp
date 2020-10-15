//Download by http://www.NewXing.com
#include "StdAfx.h"
#include "CCommon.h"
#include "CDSA.h"

CString deletestr(CString str,int count)
{
	int tlen=str.GetLength();
	return str.Right(tlen-count);
}

void zeronetochar8(char &g,CString x)
{
	g=(char)(Binstr_To_Int10(x));
}

void zeronetochar6(int &g,CString x)
{
	g=Binstr_To_Int10(x);
}

void initialize8(CString trans[])
{
   int c1, c2, c3, c4, c5, c6, c7, c8;
   CString x;
   char g;
   for(c1=0;c1<2;c1++)
      for(c2=0;c2<2;c2++)
         for(c3=0;c3<2;c3++)
            for(c4=0;c4<2;c4++)
               for(c5=0;c5<2;c5++)
                  for(c6=0;c6<2;c6++)
                     for(c7=0;c7<2;c7++)
                        for(c8=0;c8<2;c8++)
                        {
                           x=char(c1+48) + char(c2+48) + char(c3+48) + char(c4+48) + char(c5+48) + char(c6+48) + char(c7+48) + char(c8+48);
                           zeronetochar8(g, x);
                           trans[g]= x;
                        }
}


void initialize6(CString trans[])
{
   int c1, c2, c3, c4, c5, c6;
   CString x;
   int g;
   for(c1=0;c1<2;c1++)
      for(c2=0;c2<2;c2++)
         for(c3=0;c3<2;c3++)
            for(c4=0;c4<2;c4++)
               for(c5=0;c5<2;c5++)
                  for(c6=0;c6<2;c6++)
                  {
                     x=char(c1+48) + char(c2+48) + char(c3+48) + char(c4+48) + char(c5+48) + char(c6+48);
                     zeronetochar6(g, x);
                     trans[chr64[g]]= x;
                  }
}

void Convert8to6bit(CString str8,CString &str6)
{
   CString temp;
   CString trans[256];
   unsigned i,len6,tlen;
   int g;

   initialize8(trans);
   temp="";tlen=str8.GetLength();
   for(i=0;i<tlen;i++)
	   temp=temp+trans[str8[(int)i]];
   while((temp.GetLength()%6)!=0)
	   temp=temp+'0';
   len6=temp.GetLength()/6;
   str6="";
   for(i=0;i<len6;i++)
   {
      zeronetochar6(g,temp.Mid(0,6));
      str6=str6+chr64[g];
	  temp=deletestr(temp,6);
   }
}


void Convert6to8bit(CString str6,CString &str8)
{
   CString temp;
   CString trans[256];
   unsigned i,len8,tlen;
   char g;

   initialize6(trans);
   temp="";
   tlen=str6.GetLength();
   for(i=0;i<tlen;i++)
	   temp=temp+trans[str6[(int)i]];
   str8="";
   len8=temp.GetLength()/8;
   for(i=0;i<len8;i++)
   {
      zeronetochar8(g,temp.Mid(0,8));
      str8=str8+g;
	  temp=deletestr(temp,8);
   }
}

void Convert8to1bit(CString str8,CString &str1)
{
   CString trans[256];
   unsigned i;

   str1="";
   initialize8(trans);
   for(i=0;i<(unsigned)str8.GetLength();i++)
		str1=str1+trans[str8[(int)i]];
}


void Convert6to1bit(CString str6,CString &str1)
{
   CString trans[256];
   unsigned i;

   str1="";
   initialize6(trans);
   for(i=0;i<(unsigned)str6.GetLength();i++)
		str1=str1+trans[str6[(int)i]];
}


void Convert1to8bit(CString str1,CString &str8)
{
   unsigned i, len8;
   char g;

   str8="";
   while((str1.GetLength()%8)!=0) str1='0'+str1;
   len8=str1.GetLength()/8;
   for(i=0;i<len8;i++)
   {
      zeronetochar8(g,str1.Mid(0,8));
      str8=str8+g;
	  str1=deletestr(str1,8);
   }
}


void Convert1to6bit(CString str1,CString &str6)
{
   unsigned i, len6;
   int g;

   str6="";
   while((str1.GetLength()%6)!=0) str1='0' + str1;
   len6= str1.GetLength()/6;
   for(i=0;i<len6;i++)
   {
      zeronetochar6(g, str1.Mid(0,6));
      str6= str6 + chr64[g];
	  str1=deletestr(str1,6);
   }
}

void DecStrToGInt(CString GIntstr,TGInt *GInt)
{
   TGInt *temp1,*temp2;
   Tsign p;

   while(!(GIntstr.Mid(0,1).FindOneOf("-0123456789")>=0))
	   GIntstr=deletestr(GIntstr,1);

   if(GIntstr[0]=='-')
   {
	  GIntstr=deletestr(GIntstr,1);
      p=negative;
   }
   else p=positive;
   while((GIntstr[0]=='0')&&(GIntstr.GetLength()>1))
	   GIntstr=deletestr(GIntstr,1);

   temp2=new TGInt;
   temp2->next=NULL;
   if((GIntstr.GetLength()%4)==0)
   {

      temp2->value=atol(GIntstr.Mid(0,4));
      GIntstr=deletestr(GIntstr,4);
   }
   else
   {
      temp2->value=atol(GIntstr.Mid(0,(GIntstr.GetLength()%4)));
	  GIntstr=deletestr(GIntstr,(GIntstr.GetLength()%4));
   }

   while(GIntstr.GetLength()>0)
   {
      temp1=new TGInt;
      temp1->next=temp2;
      temp2->prev=temp1;
      temp1->value=atol(GIntstr.Mid(0,4));
      GIntstr=deletestr(GIntstr,4);
      temp2=temp1;
   }

   temp2->prev=NULL;
   temp2->sign=p;
   GInt=temp2;
}

void GIntToDecStr(CString GIntstr, TGInt *GInt)
{
   CString s;
   Tsign p;

   GIntstr="";
   p=GInt->sign;

   s=CString(GInt->value);
   while(s.GetLength()<4)
	   s='0' + s;
   GIntstr= s + GIntstr;
   while(GInt->next!=NULL)
   {
      GInt= GInt->next;
      s=CString(abs(GInt->value));
      while(s.GetLength()<4) s= '0' + s;
      GIntstr = s + GIntstr;
   }

   while((GIntstr[0]=='0')&&(GIntstr.GetLength()>1))
      GIntstr=deletestr(GIntstr,1);

   if(p==negative)
	   GIntstr = '-' + GIntstr;
}