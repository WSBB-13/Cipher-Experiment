#include"des.h"

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define PACKETLEN 8
#define RAND_MAX 0x7fff

int main()

{

unsigned char pt[1024];
unsigned char ct[1024];

//unsigned char key[1024]={'a','b','c','d','a','b','c','d'};
unsigned char key[1024];



	int i = 0;
	//int in_len = PACKETLEN;
	int in_len;
	int key_len;
	time_t t;                 //�����б�֤ÿ�β������������ͬ
    srand( (unsigned) time( &t ) ); 


char *show = (char *)malloc(sizeof(char)*1024); 

	//pt[in_len] = '\0';

/*
	for(i=0;i<in_len;i++)
		pt[i] = 97+rand()*26/RAND_MAX;

	for(i=0;i<in_len;i++)
		key[i] = 97+rand()*26/RAND_MAX;
*/
printf("��������Ҫ���ܵ�����\n");
	for(i=0;i<1025;i++)
	{
		scanf("%c",pt+i);
		if(pt[i] == '\n')
		{
			pt[i]='\0';
			in_len = i-1;
			break;
		}
	}
printf("�����������Կ\n");
    for(i=0;i<1025;i++)
	{
		scanf("%c",key+i);
		if(key[i] == '\n')
		{
			key[i]='\0';
		    key_len = i-1;
			break;
		}
	}


des_key skey;

pt[in_len+1]=ct[in_len+1]='\0';
des_setup((unsigned char*)key,key_len,0,&skey);

printf("����: %s\n",pt);

printf("������س������м���\n");
scanf("%c",show);

des_ecb_encrypt(pt,ct,&skey);

printf("����: %s\n",ct);

printf("������س������н���\n");
scanf("%c",show);


des_ecb_decrypt(ct,pt,&skey);

printf("����: %s\n",pt);

 

system("PAUSE");

return 0;

}

