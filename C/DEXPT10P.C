//Star pattern
#include<stdio.h>
#include<conio.h>
void main()
{
 int i,j,k,b,c;
 clrscr();
 for(i=0;i<=4;i++)
 {
  b=4-i;
  for(j=0;j<=b;j++)
  {
   printf("\t");
		 }
  c=(2*i)-1;
  for(k=1;k<=c;k++)
  {
   if(i==4)
   {
    printf("*\t");
		  }
   else
   {
    if(k==1||k==(2*i)-1)
   {
    printf("*\t");
		  }
   else
   {
    printf("\t");
		 }
		  }
		   }
  printf("\n");
   }
 getch();
 }