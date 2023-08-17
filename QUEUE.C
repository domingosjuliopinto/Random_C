// Queue
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#define size 50

int queue[size];
int front=-1;
int rear=-1;

void insert(int val)
{
	if(rear==-1)
	{
		front=rear=0;
		queue[rear]=val;
	}
	else
	{
		if(rear==size-1)
		{
			printf("Queue is full. Item can't be inserted");
		}
		else
		{
			rear=rear+1;
			queue[rear]=val;
		}
	}
}

void delete()
{
	if(front==-1)
	{
		printf("Queue is empty");
	}
	else
	{
		printf("Item deleted is %d",queue[front]);
		if(front==rear)
		{
			front=-1;
			rear=-1;
		}
		else
			front=front+1;
	}
}

void peep()
{
	int val;
	if(front==-1)
		printf("\nQueue Empty\n");
	else
		printf("Element at the front is %d",queue[front]);
}

void display()
{
	int i;
	if(front==-1)
	{
		printf("Queue Empty\n");
	}
	else
	{
		printf("\n Queue Elements are :\n");
		{
			for(i=front;i<=rear;i++)
			{
				printf("%d\n",queue[i]);
			}
		}
	}
}

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