/*
Area of Right Angle Triangle
Area of Equilateral Triangle
Area of Triangle using Heron's Formula
*/
#include<stdio.h>
#include<conio.h>
#include<math.h>
void main()
{
int a,b,a1;
float c,a2,d,e,f,g,a3,h;
clrscr();
printf("Enter height of right angle triangle : ");
scanf("%d",&a);
printf("\n Enter base of right angle triangle : ");
scanf("%d",&b);
a1=(a*b)/2;
printf("\n Area of the right angle triangle is : %d \n",a1);
printf("\n Enter side of equilateral triangle : ");
scanf("%f",&c);
a2=((sqrt(3))*c)/4;
printf("\n Area of the equilateral triangle is : %f \n",a2);
printf("\n Enter the sides of any random triangle : ");
scanf("%f%f%f",&d,&e,&f);
g=(d+e+f)/2;
h=(g*(g-d)*(g-e)*(g-f));
a3=sqrt(h);
printf("\n\n Area of the random triangle is : %f",a3);
getch();
}
