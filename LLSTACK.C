// linked list stack
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

typedef struct node
{
	int data;
	struct node *next;
}node;

void display(node*);
node * push(node*);
node * pop(node*);
void peep(node*);

int main()
{
	struct node * top=NULL;
	int ch;
	clrscr();
	while(1)
	{
		printf("\nMenu:\n1.Push \t2.Pop\n3.Peep\t4.Display\n5.Exit");
		printf("\nEnter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:top=push(top);
				break;
			case 2:top=pop(top);
				break;
			case 3:peep(top);
				break;
			case 4:display(top);
				break;
			case 5:exit(0);
			default: printf("\n Wrong choice, enter again\n");
		}
	}
}

void display (node* start)
{
	node * ptr;
	ptr=start;
	if(ptr==NULL)
	{
		printf("Empty stack");
	}
	else
	{
		printf("\nElements of the stack:\n");
		while(ptr!=NULL)
		{
			printf("%d\n",ptr->data);
			ptr=ptr->next;
		}
	}
}

node * push(node * start)
{
	node *newnode=malloc(sizeof(node));
	printf("Enter data : ");
	scanf("%d",&newnode->data);
	newnode->next=start;
	start=newnode;
	return start;
}

node * pop(node * top)
{
	node * ptr;
	if(top==NULL)
		printf("Stack empty , Can't delete\n");
	else
	{
		ptr=top;
		top=top->next;
		printf("Element popped %d\n",ptr->data);
		free(ptr);
	}
	return top;
}

void peep(node * top)
{
	node * ptr;
	if(top==NULL)
		printf("Stack Empty\n");
	else
	{
		printf("Element at top %d\n",top->data);
	}
}