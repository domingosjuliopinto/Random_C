//Program to implement struct of books
#include<stdio.h>
#include<conio.h>
#include<string.h>
struct book
{
 char title[20];
 char author[20];
 int price;
	   };
void main()
{
 struct book b[4];
 int i,p,t1;
 char t2[20];
 clrscr();
 for(i=0;i<4;i++)
 {
  printf("\nEnter details of book %d",i+1);
  printf("\n Title : ");
  scanf("%s",b[i].title);
  printf("Author : ");
  scanf("%s",b[i].author);
  printf("Price : ");
  scanf("%d",&b[i].price);
  }
 for(p=1;p<3;p++)
 {
  for(i=0;i<3;i++)
  {
   if(b[i].price>b[i+1].price)
   {
     t1=b[i].price;
     b[i].price=b[i+1].price;
     b[i+1].price=t1;
     strcpy(t2,b[i].title);
     strcpy(b[i].title,b[i+1].title);
     strcpy(b[i+1].title,t2);
     strcpy(t2,b[i].author);
     strcpy(b[i].author,b[i+1].author);
     strcpy(b[i+1].author,t2);
			      }
			       }
				}
 printf("Title\t\tAuthor\t\tPrice\n");
 for(i=0;i<4;i++)
 {
  printf("%s\t\t%s\t\t%d\n",b[i].title,b[i].author,b[i].price);
  }
 getch();
	}