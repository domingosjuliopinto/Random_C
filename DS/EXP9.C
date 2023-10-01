//Program to implement stack of books
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct book
{
  char book_name[50];
  int pages;
  float price;
  struct book *next;
}book;
book *top=NULL;
book getbookdetails();
book *push(book b);
book *pop();
void peek();
void display(book *top);
int main()
{
 int choice;
 book b;
 clrscr();
 while(1)
 {
      printf("\n\nMenu: 1.Push 2.Pop 3.Peek 4.Display 5.Exit\n");
      printf("Enter your choice:");
      scanf("%d",&choice);
      switch(choice)
      {
	  case 1:b=getbookdetails();
		 top=push(b);break;
	  case 2:top=pop();break;
	  case 3:peek();break;
	  case 4:display(top);break;
	  case 5:exit(0);
      }
 }
}
book getbookdetails()
{
  book b;
  gets(b.book_name);
  printf("\nEnter name of book:");
  gets(b.book_name);
  printf("Enter the price:");
  scanf("%f",&b.price);
  printf("Enter no of pages:");
  scanf("%d",&b.pages);
  return b;

}
book *push(book b)
{
   book *newnode = malloc(sizeof(book));
   strcpy(newnode->book_name, b.book_name);
   newnode->pages=b.pages;
   newnode->price=b.price;
   newnode->next=top;
   top=newnode;
   return top;
}
book *pop()
{
    book *ptr;
    ptr=top;
    if(ptr==NULL)
	printf("\nThe stack is empty");
    else
    {
      printf("\nBook removed is:\n");
      printf("Book Name:");
      puts(ptr->book_name);
      printf("No of Pages: %d\n",ptr->pages);
      printf("Price of book: %f Rs",ptr->price);
      top=top->next;
      free(ptr);
    }
    return top;
}
void peek()
{
   if(top==NULL)
   {
      printf("The stack is empty");
   }
   else
   {
     printf("\nBook at top is:\n");
     printf("Book Name:");
     puts(top->book_name);
     printf("No of Pages: %d\n",top->pages);
     printf("Price of book: %f Rs",top->price);
   }
}
void display(book *top)
{
    book *ptr;
    ptr=top;
    if(top==NULL)
    {
       printf("\nStack Empty");
    }
    else
    {
	while(ptr!=NULL)
	{
		printf("\n\nBook name:");
		puts(ptr->book_name);
		printf("No of Pages: %d\n",ptr->pages);
		printf("Price of Book: %f Rs",ptr->price);
		ptr=ptr->next;
	 }
    }
}