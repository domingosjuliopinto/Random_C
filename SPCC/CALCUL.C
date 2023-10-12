#include<stdio.h>
#include<conio.h>
#include"calcul.h"

float a,b;
void ask(){
	printf("\nEnter 1st value : ");
	scanf("%f",&a);
	printf("Enter 2nd value : ");
	scanf("%f",&b);
}

void main()
{
	int choice,loop=1;
	float res;
	clrscr();
	while(loop==1)
	{
		printf("\nCalculator Program\n");
		ask();
		printf("\n1-Add\n2-Sub\n3-Mul\n4-Div\n5-Square");
		printf("\n6-Square Root\n7-Cube Root");
		printf("\nYour choice ? : ");
		scanf("%d",&choice);
		switch(choice)
		{

			case 1: res=add(a,b);
				printf("The sum is %.2f",res);
				break;
			case 2: res=sub(a,b);
				printf("The diff is %.2f",res);
				break;
			case 3: res=mul(a,b);
				printf("The product is %.2f",res);
				break;
			case 4: res=div(a,b);
				printf("The quotient is %.2f",res);
				break;
			case 5: res=sq(a);
				printf("The square of %.2f is %.2f",a,res);
				res=sq(b);
				printf("\nThe square of %.2f is %.2f",b,res);
				break;
			case 6: square_root(a);
				square_root(b);
				break;
			case 7: cube_root(a);
				cube_root(b);
				break;
			default:printf("Wrong Choice");
				break;
		}
		printf("\nDo Again?\n1-Yes\nOther Characters-No");
		printf("\nYour choice ? : ") ;
		scanf("%d",&choice);
		if(choice==1)
		{
			loop=1;
		}
		else
		{
			loop=0;
		}
	}
	getch();
}