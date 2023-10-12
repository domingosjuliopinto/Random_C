#include<stdio.h>
#include<conio.h>
#include"area.h"

void circle()
{
  float area_circle,r;
  printf("\nEnter Radius : ");
  scanf("%f",&r);
  area_circle=C_area(r);
  printf("Area of circle is %.2f",area_circle);
}

void square()
{
  float area_square,s;
  printf("\nEnter Side : ");
  scanf("%f",&s);
  area_square=S_area(s);
  printf("Area of Square is %.2f",area_square);
}

void triangle()
{
  float area_triangle,h,b;
  printf("\nEnter Height : ");
  scanf("%f",&h);
  printf("\Enter Base : ");
  scanf("%f",&b);
  area_triangle=T_area(h,b);
  printf("Area of Triangle is %.2f",area_triangle);
}

void rectangle()
{
  float area_rectangle,l,b;
  printf("\nEnter Length : ");
  scanf("%f",&l);
  printf("\Enter Breadth : ");
  scanf("%f",&b);
  area_rectangle=R_area(l,b);
  printf("Area of Rectangle is %.2f",area_rectangle);
}

void main()
{
	int choice,loop=1;
	clrscr();
	while(loop==1)
	{
		printf("\nArea Program\n");
		printf("1-Circle\n2-Square\n3-Triangle\n4-Rectangle\nOther Character-exit");
		printf("\nYour choice ? : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: circle();
				break;
			case 2: square();
				break;
			case 3: triangle();
				break;
			case 4: rectangle();
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