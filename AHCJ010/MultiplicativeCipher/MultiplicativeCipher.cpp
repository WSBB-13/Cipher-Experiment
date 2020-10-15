#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

main()
{

 char M[200];
 char C[200];
 int K[200],q=26,i,j;
 srand( (unsigned)time( NULL ) );
 for(j=0;j<=200;j++)
 {
     K[j]=rand()%50;
 }
 printf("please input chars:\n");
 gets(M);

 for(i=0;M[i]!='\0';i++)
 {
     if(M[i]>='a'&&M[i]<='z')
	 {
         C[i]=((M[i]-'a'+1)*K[i])%q+'a';
	 }
     else if(M[i]>='A'&&M[i]<='Z')
	 {
     C[i]=((M[i]-'A'+1)*K[i])%q+'A';
	 }
     else
     C[i]=M[i];
 }
 
 C[i]='\0';
 printf("The result is:\n%s\n",C);
 getch();

 return 0;
}

