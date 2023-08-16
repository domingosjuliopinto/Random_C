/* Stack implementation using Array*/
#include<stdlib.h>
#include<stdio.h>
#define size 5
int stack[size];
int top=-1;
void push(int val)
{
	if(top==size-1)
		printf("\nStack Full!!\n");
	else
	{
		top++;
		stack[top]=val;
	}
}

void pop()
{

	if(top==-1)
		printf("\nStack Empty!!\n");
	else
	{
		printf("\nElement removed=%d",stack[top]);
		top--;
	}
}
void peep()
{
	int val;
	if(top==-1)
		printf("\nStack Empty!!\n");
	else
	{
		printf("Element at top=%d",stack[top]);

	}
}
void display()
{	int i;
	if(top==-1)
		printf("\nStack Empty!!\n");
	else
	{	printf("\nStack elements:\n");
		for(i=top;i>=0;i--)
		{
		  printf("%d\n",stack[i]);
		  }

	}
}

void main()
{
	int choice;
	int val;
	clrscr();
	while(1)
	{
	printf("\n1. Push \n2. Pop  \n3. Peep  \n4. Display  \n5. Exit\n Enter your  choice:");
	scanf("%d",&choice);

	switch(choice)
	{
		case 1:	printf("Enter value: ");
			scanf("%d",&val);
			push(val);
			break;
		case 2: pop();
			break;
		case 3: peep();
			break;
		case 4: display();
			break;
		case 5: exit(0);
		default: printf("Enter valid choice!!\n");

	}
	 getch();
	}

}
