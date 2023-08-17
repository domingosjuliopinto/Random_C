// Linked list queue
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

typedef struct node
{
	int data;
	struct node *next;
}node;

void display();
void insert(int val);
void delete();
void peep();
struct node * front=NULL;
struct node * rear=NULL;

int main()
{
	int ch,val;
	clrscr();
	while(1)
	{
		printf("\nMenu:\n1.Insert\t2.Delete\n3.Peep\t\t4.Display\n5.Exit");
		printf("\nEnter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("\nEnter data: ");
				scanf("%d",&val);
				insert(val);
				break;
			case 2: delete();
				break;
			case 3: peep();
				break;
			case 4: display();
				break;
			case 5: exit(0);
		}
	}
}

void display ()
{
	struct node * ptr;
	ptr=front;
	if(ptr==NULL)
	{
		printf("Empty Queue");
	}
	else
	{
		printf("\nElements of the queue are:\n");
		while(ptr!=NULL)
		{
			printf("%d\n",ptr->data);
			ptr=ptr->next;
		}
	}
}

void peep()
{
	if(front==NULL)
		printf("Queue is Empty\n");
	else
	{
		printf("Front element of the queue %d\n",front->data);
	}
}

void delete()
{
	struct node * ptr;
	ptr=front;
	if(front==NULL)
		printf("Queue empty , Can't delete\n");
	else
	{
		printf("Value deleted from queue=%d",front->data);
		if(front==rear)
		{
			front=rear=NULL;
		}
		else
		{
			front=front->next;
		}
		free(ptr);
	}
}

void insert(int val)
{
		struct node * newnode;
		newnode=(struct node *)malloc(sizeof(struct node*));
		newnode->data=val;
		newnode->next=NULL;
		if(rear!=NULL)
		{
			rear->next=newnode;
			rear=newnode;
		}
		else
		{
			rear=front=newnode;
		}
}