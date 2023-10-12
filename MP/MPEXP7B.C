// Program of ASM in C to find GCD
#include<stdio.h>
#include<conio.h>
void main()
{
	int a,b,res;
	clrscr();
	a=12;
	b=16;
	asm mov ax,a
	asm mov bx,b
	bck:
	asm cmp ax,bx
	asm jc second
	first:
	asm sub ax,bx
	asm jmp chk
	second:
	asm sub bx,ax
	chk:
	asm cmp ax,bx
	asm jnz bck
	asm mov res,ax
	printf("The GCD is: %d",res);
	getch();
}