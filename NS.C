// Swap program
#include<stdio.h>
#include<conio.h>
void main()
{
 int a,b,t;
 clrscr();
 printf(" Enter one number,a= ");
 scanf("%d",&a);
 printf("\n Enter another number ,b= ");
 scanf("%d",&b);
 t=a;
 a=b;
 b=t;
 printf("\n After Swapping numbers \n a=%d",a);
 printf("\n b=%d",b);
 getch();
 }
