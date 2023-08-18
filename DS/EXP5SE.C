// queue of item
#include<stdio.h>
#include<conio.h>
#define size 50

struct item
{
	long int Item_id;
	char Item_name[50];
	int quantity;
	float price;
};

typedef struct item item;

item queue[size];
int front=-1;
int rear=-1;
float total=0.0;

item getitemdetails();
void insert(item b);
item *remov();
void delete();
void peep();
void display();
void show(item b);
void exit_final();

void main()
{
  int choice;
  int temp=1;
  item b;
  item *bp;
  clrscr();
  while(temp==1)
  {
	printf("\n1. Insert\n2. Remove\n3. Peep\n4. Display\n5. Exit");
	printf("\n Enter your  choice: ");
	scanf("%d",&choice);
	switch(choice)
	{
	   case 1: printf("Enter details of the book : \n\n");
		   b=getitemdetails();
		   insert(b);
		   break;
	   case 2: bp=remov();
		   if(bp!=NULL)
		   {
		    show(*bp);
		    }
		   delete();
		   break;
	   case 3: peep();
		   break;
	   case 4: display();
		   break;
	   case 5: temp=0;
		   break;
	   default: printf("\nInvalid Choice.Enter right number\n");
	}
  }
  printf("------BILL------");
  exit_final();
  getch();
}

item getitemdetails()
{
  item b;
  gets(b.Item_name);
  printf("Enter name of the item: ");
  gets(b.Item_name);
  printf("Enter quantity. of item : ");
  scanf("%d",&b.quantity);
  printf("Enter id of item: ");
  scanf("%ld",&b.Item_id);
  printf("Enter price : ");
  scanf("%f",&b.price);
  total=total+(b.price*b.quantity);
  return b;
}

void insert(item b)
{
	if(rear==-1)
	{
		front=rear=0;
		queue[rear]=b;
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
			queue[rear]=b;
		}
	}
}

void show(item b)
{
	printf("\nItem name = %s, Item id = %ld, quantity=%d, price=%f\n",b.Item_name,b.Item_id,b.quantity,b.price);
}

item *remov(item b)
{
	if(front==-1)
	{
		printf("Queue is empty");
		return NULL;
	}
	else
	{
		b=queue[front];
		total=total-((b.price)*(b.quantity));
		b=queue[rear];
		printf("Item deleted is \n");
		return(&queue[front]);

	}
}

void delete()
{
	if(front!=-1)
	{
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
	if(front==-1)
		printf("\nQueue Empty\n");
	else
	{
		printf("Item at the front is \n");
		show(queue[front]);
	}
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
		printf("\n Items in queue are :\n");
		{
			for(i=front;i<=rear;i++)
			{
				printf("Item at %d ",i+1);
				show(queue[i]);
			}
		}
	}
}

void exit_final()
{
	int i;
	char temp;

	display();
	while(front!=-1)
	{
		delete();
	}
	printf("\nThe total of all items is : %f",total);
	printf("\n Press anything to exit");
}

