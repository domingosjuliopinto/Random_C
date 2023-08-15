// Trial Struct Program
#include<stdio.h>
#include<conio.h>
struct employee
{
 char name[10];
 long id;
 float salary;
	      };
void main()
{
 struct employee emp;
 clrscr();
 printf("Enter name : ");
 scanf("%s",emp.name);
 printf("Enter id : ");
 scanf("%ld",&emp.id);
 printf("Enter salary : ");
 scanf("%f",&emp.salary);
 printf("\n The details of the employee are :\n");
 printf("\n Name is %s",emp.name);
 printf("\n ID is %ld",emp.id);
 printf("\n Salary is %f",emp.salary);
 getch();
 }