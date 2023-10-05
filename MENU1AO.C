// Program to select add, sub, multiply, div, modulus
#include<stdio.h>
#include<conio.h>
void main()
{
 int a,b,f,s,c;
 clrscr();
 printf("Enter two integers which you wanna operate : \n");
 scanf("%d%d",&a,&b);
 choice:
 printf("\n Do you want to operate ? \n 1-Yes \n default integer/character-Stop");
 printf("\n Enter your choice : ");
 scanf("%d",&f);
 switch(f)
 {
  case 1:printf("\n 1-add \n 2-subtract \n 3-multiply \n 4-divide \n 5-modulus");
	 printf("\n Enter your choice of operation : ");
	 scanf("%d",&s);
	 switch(s)
	 {
	  case 1: c=a+b;
		  printf("\n The sum of the two numbers are %d \n",c);
		  break;
	  case 2: c=a-b;
		  printf("\n The difference of the two numbers are %d \n",c);
		  break;
	  case 3: c=a*b;
		  printf("\n The product of the two numbers are %d \n",c);
		  break;
	  case 4: c=a/b;
		  printf("\n The quotient of the two numbers are %d \n",c);
		  break;
	  case 5: c=a%b;
		  printf("\n The modulus of the two numbers are %d \n",c);
		  break;
	  default:printf("\n Wrong choice. Try again \n");
			}
	 goto choice;
  default:printf("\n The program has been stopped");
  }
 getch();
 }