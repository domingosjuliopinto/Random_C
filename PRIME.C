// Prime number or Not
#include<stdio.h>
#include<conio.h>
void main()
{
 int n,b,c=0,i;
 clrscr();
 printf("Enter a number : ");
 scanf("%d",&n);
 for(i=1;i<=n/2;i++)
 {
  b=n%i;
  if(b==0)
  {
   c=c+1;
   }
  }
 if(c==1)
 {
  printf("The number is a prime number");
  }
 else
 {
  printf("The number is not a prime number");
  }
  getch();
  }