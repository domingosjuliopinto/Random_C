// Linked List
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

typedef struct node
{
	int data;
	struct node *next;
}node;

void display(node*);
node * create_list(node *);
node * insert_beg(node *);
node * insert_end(node *);
node * insert_at(node *);
node * insert_before(node *);
node * insert_after(node *);
node * delete_beg(node *);
node * delete_end(node *);
node * delete_at(node *);
node * delete_before(node *);
node * delete_after(node *);
node * delete_value(node *);
int main()
{
	struct node * start=NULL;
	int ch;
	clrscr();
	while(1)
	{
		printf("\nMenu:\n1.Create list\t2.Insert_beg\n3.Insert_end");
		printf("\t4.Insert_at\n5.Insert_before\t6.Insert_after");
		printf("\n7.Delete_beg\t8.Delete_end\n9.Delete_at");
		printf("\t10.Delete_before\n11.Delete_after\t12.Delete_value");
		printf("\n13.Display\t14.Exit");
		printf("\nEnter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: start=create_list(start);
				break;
			case 2: start=insert_beg(start);
				break;
			case 3: start=insert_end(start);
				break;
			case 4: start=insert_at(start);
				break;
			case 5: start=insert_before(start);
				break;
			case 6: start=insert_after(start);
				break;
			case 7: start=delete_beg(start);
				break;
			case 8: start=delete_end(start);
				break;
			case 9: start=delete_at(start);
				break;
			case 10: start=delete_before(start);
				break;
			case 11: start=delete_after(start);
				break;
			case 12: start=delete_value(start);
				break;
			case 13: display(start);
				break;
			case 14: exit(0);
			default : printf("You entered wrong choice");
		}
	}
}

void display (node* start)
{
	node * ptr;
	ptr=start;
	if(ptr==NULL)
	{
		printf("Empty list");
	}
	else
	{
		printf("\nElements of the list:\n");
		while(ptr!=NULL)
		{
			printf("%d\n",ptr->data);
			ptr=ptr->next;
		}
	}
}

node * insert_beg(node * start)
{
	node *newnode=malloc(sizeof(node));
	printf("Enter data : ");
	scanf("%d",&newnode->data);
	newnode->next=start;
	start=newnode;
	return start;
}

node * insert_end(node * start)
{
    node *newnode=malloc(sizeof(node));
    node * ptr;
    printf("Enter data: ");
    scanf("%d",&newnode->data);
    ptr=start;
    if(start==NULL)
    {
	newnode->next=start;
	start=newnode;
	return start;
    }
    else
    {
	while (ptr->next!=NULL)
	{
		ptr=ptr->next;
	}
	ptr->next=newnode;
	newnode->next=NULL;
    }
    return start;
};

node * insert_after(node * start)
{
	node *ptr;
	int val;
	node *newnode=malloc(sizeof(node));
	printf("Enter data: ");
	scanf("%d",&newnode->data);
	newnode->next=NULL;
	printf("Enter value of node after which to insert data : ");
	scanf("%d",&val);
	if(start==NULL)
	{
		printf("List is empty cannot insert\n");
	}
	else
	{
		ptr=start;
		while(ptr!=NULL&&ptr->data!=val)
		{
			ptr=ptr->next;
		}
		if(ptr!=NULL)
		{
			newnode->next=ptr->next;
			ptr->next=newnode;
		}
		else
		{
			printf("Value not found. Can't insert");
		}
	}
	return start;
}

node * insert_before(node *start)
{
	node *ptr1, *ptr2;
	int val;
	node *newnode=malloc(sizeof(node));
	printf("Enter data: ");
	scanf("%d",&newnode->data);
	newnode->next=NULL;
	printf("Enter value of node before which to insert data : ");
	scanf("%d",&val);
	if(start==NULL)
	{
		printf("List is empty cannot insert\n");
	}
	else
	{
		ptr1=ptr2=start;
		while(ptr2!=NULL&&ptr2->data!=val)
		{
			ptr1=ptr2;
			ptr2=ptr2->next;
		}
		if(ptr2==NULL)
		{
			printf("Value not found ! Can't insert");
		}
		else
		{
			newnode->next=ptr2;
			if(ptr1==ptr2)
			{
				start=newnode;
			}
			else
			{
				ptr1->next=newnode;
			}
		}
	}
	return start;
}

node * insert_at(node *start)
{
	node *ptr1, *ptr2;
	int pos,count=0;
	node *newnode=malloc(sizeof(node));
	printf("Enter data: ");
	scanf("%d",&newnode->data);
	newnode->next=NULL;
	printf("Enter position to insert data : ");
	scanf("%d",&pos);
	if(start==NULL)
	{
		printf("List is empty cannot insert\n");
	}
	else
	{
		ptr1=ptr2=start;
		while(ptr2!=NULL&&count<pos-1)
		{
			count=count++;
			ptr1=ptr2;
			ptr2=ptr2->next;
		}
		if(count==pos-1)
		{
			newnode->next=ptr2;
			ptr1->next=newnode;
		}
		else
		{
		       printf("Cant insert at position %d",pos);
		}
	}
	return start;
}

node * delete_beg(node * start)
{
	node * ptr;
	if(start==NULL)
		printf("List empty , Can't delete");
	else
	{
		ptr=start;
		start=start->next;
		free(ptr);
	}
	return start;
}

node * delete_end(node * start)
{
	node * ptr;
	if(start==NULL)
		printf("List empty , Can't delete");
	else
	{
		ptr=start;
		while(ptr->next->next!=NULL)
		{
			ptr=ptr->next;
		}
		free(ptr->next);
		ptr->next=NULL;
	}
	return start;
}

node * delete_at(node *start)
{
	node * ptr1,*ptr2;
	int pos,count=1;
	printf("Enter position from which to delete : ");
	scanf("%d",&pos);
	if(start==NULL)
		printf("List empty , Can't delete");
	else if(pos==1)
	{
		ptr1=start;
		start=start->next;
		free(ptr1);
	}
	else
	{
		ptr1=start;
		ptr2=start;
		while(ptr2!=NULL&&count<pos)
		{
			count=count++;
			ptr1=ptr2;
			ptr2=ptr2->next;
		}
		if(count==pos)
		{
			ptr1->next=ptr2->next;
			free(ptr2);
		}
		else
		{
			printf("Position doesn't exist, can't delete");
		}
	}
	return start;
}

node * delete_before(node *start)
{
	node *ptr1,*ptr2;
	int val;
	printf("Enter value of node before which to delete : ");
	scanf("%d",&val);
	if(start==NULL)
		printf("\nList empty , Can't delete\n");
	else
	{
		ptr1=start;
		ptr2=start->next;
		if(ptr1->data==val)
		{
			printf("\nThis is the first node. Nothing to delete\n");
			return start;
		}
		if(ptr2->data==val)
		{
			ptr1=start;
			start=start->next;
			free(ptr1);
			return start;
		}
		while(ptr2->next!=NULL&&ptr2->next->data!=val)
		{
			ptr1=ptr2;
			ptr2=ptr2->next;
		}
		if(ptr2->next==NULL)
		{
			printf("\nValue not found, Can't delete\n");
		}
		else
		{
			ptr1->next=ptr2->next;
			free(ptr2);
		}
	}
	return start;
}

node * delete_after(node *start)
{
    if (start==NULL)
    {
	printf("\nList empty!\n");
    }
    else
    {
	node *ptr1,*ptr2;
	int val;

	printf("Enter the node value after which you want to delete node: ");
	scanf("%d",&val);

	ptr1=start;
	ptr2=start->next;

	while (ptr2->next!=NULL&&ptr1->data!=val)
	{
	    ptr1=ptr2;
	    ptr2=ptr2->next;
	}
	if(ptr2->next==NULL)
		{
			printf("\nValue not found, Can't delete\n");
		}
	else
	{
		ptr1->next=ptr2->next;
	}
	free(ptr2);
    }
    return start;
};

node * delete_value(node *start)
{
	node *ptr1,*ptr2;
	int val;
	printf("Enter value of node to delete : ");
	scanf("%d",&val);
	if(start==NULL)
		printf("\nList empty , Can't delete\n");
	else
	{
		ptr1=start;
		ptr2=start->next;
		if(ptr1->data==val)
		{
			ptr1=start;
			start=start->next;
			free(ptr1);
			return start;
		}
		while(ptr2->next!=NULL&&ptr2->data!=val)
		{
			ptr1=ptr2;
			ptr2=ptr2->next;
		}
		if(ptr2->next==NULL)
		{
			printf("\nValue not found, Can't delete\n");
		}
		else
		{
			ptr1->next=ptr2->next;
			free(ptr2);
		}
	}
	return start;
}

node * create_list(node * start)
{
	if (start==NULL)
	{
		int n,i;
		clrscr();
		printf("Enter number of nodes : ");
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			start=insert_end(start);
		}
	}
	else
    {
        printf("\nList already exists!\n");
    }
    return start;
}