// Array of struct program
#include<stdio.h>
#include<conio.h>
struct student
{
 char fname[10];
 char sname[10];
 long roll_no;
 int marks[3];
	      };
void main()
{
 struct student stu[3];
 int i,j;
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
  for(j=0;j<3;j++)
  {
   printf("marks %d: ",j+1);
   scanf("%d",&stu[i].marks[j]);
			      }
				}
 printf("\nFName\tSurname\tRoll no\t");
 printf("Marks 1\tMarks 2\tMarks 3");
 for(i=0;i<3;i++)
 {
  printf("\n%s\t%s\t",stu[i].fname,stu[i].sname);
  printf("%ld\t",stu[i].roll_no);
  for(j=0;j<3;j++)
  {
   printf("%d\t",stu[i].marks[j]);
				}
							}
 getch();
 }