// Program of ASM in C to add two numbers
#include<stdio.h>
 
void main() {
 
   int a = 3, b = 3, c;
   clrscr();
   asm {
      mov ax,a
      mov bx,b
      add ax,bx
      mov c,ax
   }
 
   printf("%d",c);
   getch();
}