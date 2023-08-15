//Program to enter 3 students , their marks and roll no
#include<stdio.h>
#include<conio.h>
struct student
{
 char fname[10];
 char sname[10];
 long roll_no;
 long marks;
	      };
void main()
{
 struct student stu[3];
 int i;
 clrscr();
 for(i=0;i<3;i++)
 {
  printf("\nEnter details of student %d",i+1);
  printf("\nFirst name : ");
  scanf("%s",stu[i].fname);
  printf("Surname : ");
  scanf("%s",stu[i].sname);
  printf("roll no : ");
  scanf("%ld",&stu[i].roll_no);
  printf("marks : ");
  scanf("%ld",&stu[i].marks);
			      }
 printf("\nFName\tSurname\tRoll no\tMarks");
 for(i=0;i<3;i++)
 {
  printf("\n%s\t%s\t",stu[i].fname,stu[i].sname);
  printf("%ld\t%ld",stu[i].roll_no,stu[i].marks);
							}
 getch();
 }