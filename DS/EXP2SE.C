//stack of book
#include<stdio.h>
#include<conio.h>
#define size 50

struct book
{
  char name[50];
  int pages;
  float price;
};

typedef struct book book;

book stack[size];
int top=-1;

book getbookdetails();
void push(book b);
book *pop();
void peep();
void display();
void show(book b);

void main()
{
  int choice;
  book b;
  book *bp;
  clrscr();
  while(1)
  {
	printf("\n1. Push\n2. Pop\n3. Peep\n4. Display\n5. Exit");
	printf("\n Enter your  choice:");
	scanf("%d",&choice);
	switch(choice)
	{
	   case 1: printf("Enter details of the book : \n");
		   b=getbookdetails();
		   push(b);
		   break;
	   case 2: bp=pop();
		   if(bp!=NULL)
		   {
		    show(*bp);
		    }
		   break;
	   case 3: peep();
		   break;
	   case 4: display();
		   break;
	   case 5: exit(0);
	   default: printf("\nInvalid Choice.Enter right number\n");
	}
  }
}

book getbookdetails()
{
  book b;
  gets(b.name);
  printf("Enter name of the book: ");
  gets(b.name);
  printf("Enter no.of pages : ");
  scanf("%d",&b.pages);
  printf("Enter price : ");
  scanf("%f",&b.price);
  return b;
}

void push(book b)
{
  if(top==size-1)
  {
    printf("\n Stack Full \n");
    }
  else
  {
   top++;
   stack[top]=b;
   }
}

void show(book b)
{
  printf("\nBook name = %s, pages=%d, price=%f\n",b.name,b.pages,b.price);
  }

book *pop()
{
  if(top==-1)
  {
    printf("\n Stack Empty\n");
    return NULL;
    }
  else
  {
    top--;
    printf("\n The Book removed is\n");
    return (&stack[top+1]);
  }
}

void peep()
{
  int val;
  if(top==-1)
  {
    printf("\nStack Empty\n");
    }
  else
  {
   printf("Book at top is\n");
   show(stack[top]);
   }
}

void display()
{
  int i;
  if(top==-1)
  {
    printf("\nStack Empty\n");
  }
  else
  {
    printf("\nStack elements are :\n");
    {
     for(i=top;i>=0;i--)
     {
       printf(" Book at %d ",i+1);
       show(stack[i]);
     }
    }
  }
}


