#include "header.h"
#include "encode.c"
#include "decode.c"
/* **********************************************************************************************************************
Author:Pevnotios Hany Makram
Date:14/9/2017
Description: Base64 Encryption decryption.
Email:Pevnotios@gmail.com
*************************************************************************************************************************
*/
int main()
{
    printf("Base 64 encryption-decryption program\n");
    while(1){
    char choice;
    printf("\n1-Encrypt 2-decrypt 3-Exit:");
    fflush(stdin);
    scanf("%c",&choice);
    switch(choice)
    {
    case '1':encode();break;
    case '2':decode();break;
    case '3':exit(0); break;
    }
    }
}
