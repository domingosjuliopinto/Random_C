// Program to get grade after entering marks
#include<stdio.h>
#include<conio.h>
void main()
{
 int m;
 clrscr();
 printf("Enter marks : ");
 scanf("%d",&m);
 if(m>=85&&m<=100)
 {
  printf(" The Grade is A ");
  }
 else if(m>=70&&m<=84)
 {
  printf(" The Grade is B ");
  }
 else if(m>=55&&m<=69)
 {
  printf(" The Grade is C ");
  }
 else if(m>=40&&m<=54)
 {
  printf(" The Grade is D ");
  }
 else
 {
  printf(" The Grade is F ");
  }
 getch();
	 }