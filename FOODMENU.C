// Food Menu Program
#include<stdio.h>
#include<conio.h>
void main()
{
 int f;
 clrscr();
 printf("1-Pizza,Rs 239\n2-Burger,Rs129\n3-Pasta,Rs179\n4-French Fries,Rs99\n5-Sandwich,Rs149");
 printf("\n Enter your choice ");
 scanf("%d",&f);
 switch(f)
 {
  case 1:printf("\n Food item - Pizza \n Price 239");
	 break;
  case 2:printf("\n Food item - Burger \n Price 129");
	 break;
  case 3:printf("\n Food item - Pasta \n Price 179");
	 break;
  case 4:printf("\n Food item - French Fries \n Price 99");
	 break;
  case 5:printf("\n Food item - Sandwich \n Price 149");
	 break;
  default : printf("\n Use default case");
  }
 getch();
 }