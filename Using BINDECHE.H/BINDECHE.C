#include<stdio.h>
#include<conio.h>
#include "bindeche.h"

void main(){
   long int binary;
   int choice,check=0;
   clrscr();
   printf("Enter the binary number: ");
   scanf("%ld", &binary);
   printf("\n0 = Binary to Decimal\n1 = Binary to Hexadecimal\n Enter your choice : ");
   scanf("%d", &choice);
   while(check!=1){
	   if(choice ==0 || choice ==1){
		   check=1;
	   }
	   else{
		   printf("Wrong choice.\n 0 = Binary to Decimal\n1 = Binary to Hexadecimal\nEnter your choice again : ");
		   scanf("%d", &choice);
	   }
   }
   if(choice == 0){
	   bin_dec(binary);
   }
   else{
	   bin_hex(binary);
   }
   getch();
}