#include "header.h"
/* **********************************************************************************************************************
Author:Pevnotios Hany Makram
Date:14/9/2017
Description: Base64 Encryption decryption.
Email:Pevnotios@gmail.com
*************************************************************************************************************************
*/
void dec2binary(int);
void bin2dec_encoder(int);
void print(void);

void encode(void)
{
    printf("Enter your message to encrypt :\n");   // ask the user for the message
    char c;  // char c to store message char by char
    int i=0; //counter
     binary_file=fopen("data.txt","w"); //create file to store binary code
     encoded=fopen("encoded_message.txt","w"); // create file to store encoded message
     fflush(stdin);
    while((c=getchar())!='\n')   // while the user did not hit enter keep getting characters
    {
    dec2binary(c);  //send the character to the decimal to binary function which will convert the ASCII to binary
    i++; //counter ++
    }

   fclose(binary_file);  // close the binary file
   bin2dec_encoder(i); //start encoding
   fclose(encoded);  //close encoded file
   print();  //print that file to the user
    return;  // return
}
/*
decimal to binary: this function returns void and  takes integer which is the ASCII of the char typed by the user
and it convert it to binary and store it in a file named data
*/
void dec2binary(int n) //int n to store the number
{
  int c, k ;                   /* c is the number of shift */
  for (c = 7; c >= 0; c--)    /*for loop for a max 8 bit char binary number c=7 stop when c=0  */
  {
    k = n >> c;          /*use bitwise right shift operator to shift n 8 shifts and store in k */
    if (k & 1)           /*after shifting the number make bitwise and with 1 if true print 1 if no print 0*/
      fprintf(binary_file,"%c",'1');
    else
      fprintf(binary_file,"%c",'0');
  }
}
/*
Binary to decimal: this function returns void and  takes integer which is the counter indicating how many characters entered
by the user this function encodes the binary file using 6 bit per char to encode it reads the file from left to right
and encode
*/

void bin2dec_encoder(int k)  //counter k
 {
    char bin;  int dec=0,i=5,j=1;  //char bin to store binary number ,int dec to store the decimal number , i,j counters
    binary_file=fopen("data.txt","r"); //opens the binary file
    while (j<=k*8)  //while loop until reaching the end of the file which is 8*k each char is 8 bit
    {
        while(i>=0&&j<=k*8)  // while loop to convert each six binary numbers in a row and write their value in encode
    {
    fscanf(binary_file,"%c",&bin); //scans the binary file char by char and store in bin
    if (bin == '1') dec+=pow(2,i);   // if bin =1 then dec=dec+2^i
    else if (bin == '0') dec=0+dec;  //if bin=0 then dec=0+dec which is dummy operation
    else {dec=80;} // if it reads something else than 0 or 1 then there must be a redundant number> k*8 not divisible by 3
                      //it will be given 80 to make it print "="
    i--;j++;    //i--   j++
    }
    if(dec<=25)              //ASCII conversion cases : for capital letters add 65
    {fprintf(encoded,"%c",dec+65);}
    else if (dec<=51&&dec>25)
     {fprintf(encoded,"%c",dec+97-26);}  //small letters add 97-26
    else if (dec<=61&&dec>51)
         {fprintf(encoded,"%c",dec+48-52);}    //numbers add 48-52
    else if (dec==62)      // if 62 this means +
          {fprintf(encoded,"%c",43);}
    else if (dec==63)   // if 63 this mean /
         {fprintf(encoded,"%c",47);}
    else if (dec==80)   //if 80 this means =
         {fprintf(encoded,"%c",61);}
    else{fprintf(encoded,"%c",dec);} //else leave it like it is
    i=5;dec=0;  // re initialize the counter and the dec
 }
 }
 /*
Print function this function prints the file encoded
*/

 void print(void)
 {
     printf("\nYour encoded message is :\n");
     char ch='0',c='0';    // char ch and c initiated with 0
 encoded=fopen("encoded_message.txt","r");  //open file encoded message in reading mode
while(!feof(encoded))   //while not end of file
{
    c=ch;  //c =ch  to check repeated values
  fscanf(encoded,"%c",&ch);
  if(c!=ch) // if not repeated
  printf("%c",ch);
}
 }


