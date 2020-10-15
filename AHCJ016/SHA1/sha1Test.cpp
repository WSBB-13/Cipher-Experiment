
/*
 *  sha1test.c
 *
 *  测试模块
 *
 */

#include "stdint.h"
#include <stdio.h>
#include <string.h>
#include "sha1.h"

// 定义测试模式

// #define TEST1   "abc"       /*  只有一个分组--共有24位长度
//                              *  需要填充一个"1"和423个"0"
//                              *  最后两个字"00000000 00000018"表明原始消息长度是24位
//                              */
//                              
// #define TEST2a  "abcdbcdecdefdefgefghfghighijhi"
// 
// #define TEST2b  "jkijkljklmklmnlmnomnopnopq"      
//                                                     
// #define TEST2   TEST2a TEST2b      /*  消息M是448位之ASCII码串
//                                     *  该消息被填充一个"1"，后跟511个"0"
//                                     *  并且以十六进制"00000000 000001c0"结束
//                                     *  最后经填充过之消息由两个512位分组组成
//                                     */
// #define TEST3   "a"      /*  1,000,000个a循环出现  */
// #define TEST4a  "01234567012345670123456701234567"
// #define TEST4b  "01234567012345670123456701234567"
//     /* an exact multiple of 512 bits */
// #define TEST4   TEST4a TEST4b      /*  一组长度刚好为512位之消息  */
// char *testarray[4] =
// {
//     TEST1,
//     TEST2,
//     TEST3,
//     TEST4
// };
// long int repeatcount[4] = { 1, 1, 1000000, 10 };	//不明白此数组的作用
// char *resultarray[4] =
// {
//     "A9 99 3E 36 47 06 81 6A BA 3E 25 71 78 50 C2 6C 9C D0 D8 9D",
//     "84 98 3E 44 1C 3B D2 6E BA AE 4A A1 F9 51 29 E5 E5 46 70 F1",
//     "34 AA 97 3C D4 C4 DA A4 F6 1E EB 2B DB AD 27 31 65 34 01 6F",
//     "DE A3 56 A2 CD DD 90 C7 A7 EC ED C5 EB B5 63 93 4F 46 04 52"
// };
// 
// int main()
// {
//     SHA1Context sha;
//     int i, j, err;
//     uint8_t Message_Digest[20];
// 
//     /*
//      *  执行 SHA-1 tests
//      */
//     for(j = 0; j < 4; ++j)
//     {
//         printf( "\nTest %d: %d, '%s'\n",j+1,repeatcount[j],testarray[j]);
// 
//         err = SHA1Reset(&sha);	//返回0
// 
//         if (err)
//         {
//             fprintf(stderr, "SHA1Reset Error %d.\n", err );
//             break;    /* out of for j loop */
//         }
// 
//         for(i = 0; i < repeatcount[j]; ++i)
//         {
// 			err = SHA1Input(&sha,(const unsigned char *) testarray[j],
// 				strlen(testarray[j]));
// 
//             if (err)
//             {
//                 fprintf(stderr, "SHA1Input Error %d.\n", err );
//                 break;    /* out of for i loop */
// 			}
//          }
// 
//         err = SHA1Result(&sha, Message_Digest);
// 
//         if (err)
//         {
//             fprintf(stderr,
//             "SHA1Result Error %d, could not compute message digest.\n",
//             err );
//         }
//         else
//         {
//             printf("\t");
//             for(i = 0; i < 20 ; ++i)
//             {
//                 printf("%02X ", Message_Digest[i]);
//             }
//             printf("\n");
//         }
// 		
//         printf("Should match:\n");
//         printf("\t%s\n", resultarray[j]);
//     }
// 	
//     /* Test some error returns */
//     err = SHA1Input(&sha,(const unsigned char *) testarray[1], 1);
//     printf ("\nError %d. Should be %d.\n", err, shaStateError );
//     err = SHA1Reset(0);
//     printf ("\nError %d. Should be %d.\n", err, shaNull );
//     return 0;
// }

int main()
{
    SHA1Context sha;
    int i, err;
    uint8_t Message_Digest[20];

 
    // 执行 SHA-1 tests
    char * test = "Anheng"; 

    printf( "\nTest Message:\t'%s'\n",test);

    err = SHA1Reset(&sha);	//返回0

    if (err)
    {
        fprintf(stderr, "SHA1Reset Error %d.\n", err );
        return 0;
    }

	err = SHA1Input(&sha, (const unsigned char *)test, strlen(test));

    if (err)
    {
        fprintf(stderr, "SHA1Input Error %d.\n", err );
        return 0;
	}

    err = SHA1Result(&sha, Message_Digest);

    if (err)
    {
        fprintf(stderr,
        "SHA1Result Error %d, could not compute message digest.\n",
        err );
    }
    else
    {
        printf("Message Digest:\t");
        for(i = 0; i < 20 ; ++i)
        {
            printf("%02X ", Message_Digest[i]);
        }
        printf("\n");
    }
	
    return 0;
}