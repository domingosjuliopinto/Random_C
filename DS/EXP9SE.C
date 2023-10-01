//Program of stack using structures
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct
{
	char bname[50];
	int pages;
	float price;
}book;
typedef struct node
{
	book data;
	struct node *next;
}node;

struct node * top=NULL;

void printbook(book b);
void display(node *);
node * push(node *);
node * pop(node *);
void peep(node *);

int main()
{
	int i;
	int ch;
	clrscr();
	while(1)
	{
		printf("\n1. Push \n2. Pop  \n3. Peep  \n4. Display  \n5. Exit\n Enter your  choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: top=push(top);break;
			case 2: top=pop(top);break;
			case 3: peep(top);break;
			case 4: display(top);break;
			case 5: exit(0);
		}
	}
}

void display (node* top)
{
	node * ptr;
	ptr=top;
	if(ptr==NULL)
	{
		printf("\nEmpty stack\n");
	}
	else
	{
		printf("\nElements of the stack:\n");
		while(ptr!=NULL)
		{
			printbook(ptr->data);
			ptr=ptr->next;
		}
	}
}

node * push(node * top)
{
	node *newnode=malloc(sizeof(node));
	printf("Enter book details\n");
	gets(newnode->data.bname);
	printf("Enter name of the book: ");
	gets(newnode->data.bname);
	printf("Enter no.of pages : ");
	scanf("%d",&newnode->data.pages);
	printf("Enter price : ");
	scanf("%f",&newnode->data.price);
	newnode->next=top;
	top=newnode;
	return top;
}

void printbook(book b)
{
	printf("\nBook name = %s, pages=%d, price=%f\n",b.bname,b.pages,b.price);
}

node * pop(node * top)
{
	node * ptr;
	if(top==NULL)
		printf("\nStack empty , Can't delete\n");
	else
	{
		ptr=top;
		top=top->next;
		printf("\nElement popped %d\n");
		printbook(ptr->data);
		free(ptr);
	}
	return top;
}

void peep(node * top)
{
	node * ptr;
	if(top==NULL)
		printf("\nStack Empty\n");
	else
	{
		printf("\nElement at top %d\n");
		printbook(top->data);
	}
}