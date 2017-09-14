#include "header.h"
/* **********************************************************************************************************************
Author:Pevnotios Hany Makram
Date:14/9/2017
Description: Base64 Encryption decryption.
Email:Pevnotios@gmail.com
*************************************************************************************************************************
*/
void dec2binaryd(int);
void bin2dec_decoder(void);
void printd(void);

void decode(void)
{
    char c;  // char c to store message char by char
    int i=0,n; //counter
    printf("enter your message in the file >encoded_message.txt:\n");   // ask the user for the message
     binary_file2=fopen("data2.txt","w"); //create file to store binary code
     decoded=fopen("decoded_message.txt","w"); // create file to store encoded message
     encoded=fopen("encoded_message.txt","r");
     while(!feof(encoded))
     {
      fscanf(encoded,"%c",&c);
      i=c;
      if(c>=65&&c<=90)              //ASCII conversion cases : for capital letters add 65
    {dec2binaryd(c-65);}
    else if (c>=97&&c<=122)
     {dec2binaryd(c-97+26);}  //small letters add 97-26
    else if (c>=48&c<=57)
         {dec2binaryd(c-48+52);}    //numbers add 48-52
    else if (c==43)      // if 62 this means +
          {dec2binaryd(62);}
    else if (c==47)   // if 63 this mean /
         {dec2binaryd(63);}
    else{dec2binaryd(c);} //else leave it like it is
     }
     fclose(encoded);
     fclose(binary_file2);
   bin2dec_decoder(); //start encoding
   fclose(decoded);  //close encoded file
   printd();  //print that file to the user
    return;  // return
}
/*
decimal to binary: this function returns void and  takes integer which is the ASCII of the char typed by the user
and it convert it to binary and store it in a file named data
*/
void dec2binaryd(int n) //int n to store the number
{
  int c, k ;                 /* c is the number of shift */
  for (c = 5; c >= 0; c--)    /*for loop for a max 8 bit char binary number c=7 stop when c=0  */
  {
    k = n >> c;          /*use bitwise right shift operator to shift n 8 shifts and store in k */
    if (k & 1)           /*after shifting the number make bitwise and with 1 if true print 1 if no print 0*/
      fprintf(binary_file2,"%c",'1');
    else
      fprintf(binary_file2,"%c",'0');
  }
  }

/*
Binary to decimal: this function returns void and  this function decodes the binary file using 8 bit per char to encode it reads the file from left to right
and encode
*/

void bin2dec_decoder(void)  //counter k
 {
    char bin;  int dec=0,j=7;  //char bin to store binary number ,int dec to store the decimal number , i,j counters
  binary_file2=fopen("data2.txt","r"); //opens the binary file
    while (!feof(binary_file2))  //while loop until reaching the end of the file which is 8*k each char is 8 bit
    {
        while(j>=0)  // while loop to convert each six binary numbers in a row and write their value in encode
    {
    fscanf(binary_file2,"%c",&bin); //scans the binary file char by char and store in bin
    if (bin == '1') dec+=pow(2,j);   // if bin =1 then dec=dec+2^i
    else if (bin == '0') dec=0+dec;  //if bin=0 then dec=0+dec which is dummy operation// if it reads something else than 0 or 1 then there must be a redundant number> k*8 not divisible by 3
    j--;    //i--   j++
    }
    fprintf(decoded,"%c",dec);
    j=7;dec=0;  // re initialize the counter and the dec
 }
 }
 /*
Print function this function prints the file encoded
*/

 void printd(void)
 {
  char ch='0',c='0';    // char ch and c initiated with 0
 decoded=fopen("decoded_message.txt","r");  //open file encoded message in reading mode
while(!feof(decoded))   //while not end of file
{
    c=ch;  //c =ch  to check repeated values
  fscanf(decoded,"%c",&ch);
  if(c!=ch) // if not repeated
  printf("%c",ch);
}
 }


