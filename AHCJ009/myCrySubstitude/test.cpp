
#include "myCrySubstitude.h"

#define MAXLEN 1024
#define RAND_MAX 0x7fff

void main()

{

	//unsigned char * str;
	unsigned char *str = (unsigned char *)malloc(sizeof(char)*1024);
	unsigned char* code;
	unsigned char* encode;

	int i = 0;
	int in_len = 0;

	//str = new unsigned char(MAXLEN+1);

    

	code = new unsigned char(2);
	encode = new unsigned char(MAXLEN+1);
	time_t t;                 //�����б�֤ÿ�β������������ͬ
    srand( (unsigned) time( &t ) ); 
	
	in_len = rand()*MAXLEN/RAND_MAX;
/*	for(i=0;i<1024;i++)
	{
		in_len = rand()*MAXLEN/RAND_MAX+1;
		printf("len= %d    ",in_len);
	}
	*/
	str[in_len] = '\0';

       
/*
	for(i=0;i<in_len;i++)
		str[i] = 97+rand()*26/RAND_MAX;

	code[0]=97+rand()*10/RAND_MAX;
*/

	printf("���������ģ�С��1024��Ӣ���ַ���\n");
	for(i=0;i<1025;i++)
	{
		scanf("%c",str+i);
		if(str[i] == '\n')
		{
			str[i]='\0';
			break;
		}
	}

	printf("���������루һλӢ���ַ���\n");
	scanf("%c",code);



	code[1]='\0';

	Encrypt(str,code);
	printf("����%s\n",str);

	Decrypt(str,code);
	printf("����%s\n",str);
    
	
	scanf("%c",str);
}