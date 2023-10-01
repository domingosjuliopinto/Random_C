//Program for Linked List
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

typedef struct node
{
    int data;
    struct node *next;
}node;

node * insert_beg(node *);
node * insert_end(node *);
node * insert_before(node *);
node * delete_beg(node *);
node * delete_end(node *);
node * delete_after(node *);
node * search(node *);
node * replace(node *);
void display(node*);

int main()
{
    struct node * start=NULL;
    int ch;
    clrscr();
    while(1)
    {
	printf("\nMenu:\n1.Insert_Beg\n2.Insert_End\n3.Insert_Before");
	printf("\n4.Delete_Beg\n5.Delete_End\n6.Delete_After\n7.Search for a node\n8.Replace the node\n9.Display\n10.Exit\n");
	printf("\nEnter your choice: ");
	scanf("%d",&ch);
	switch(ch)
	{
	    case 1: start=insert_beg(start);
		break;
	    case 2: start=insert_end(start);
		break;
	    case 3: start=insert_before(start);
		break;
	    case 4: start=delete_beg(start);
		break;
	    case 5: start=delete_end(start);
		break;
	    case 6: start=delete_after(start);
		break;
	    case 7: start=search(start);
		break;
	    case 8: start=replace(start);
		break;
	    case 9: display(start);
		break;
	    case 10: exit(0);
	    default : printf("You entered wrong choice");
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


node * delete_beg(node * start)
{
    node *ptr;
	if(start==NULL)
	     printf("List Empty!! Can't Delete");
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
  node *ptr;
  
  if(start==NULL)
  {
     printf("List Empty!!");
  }
  else
  {
     ptr=start;
	 while(ptr->next->next!=NULL)
	 {
	    
		ptr= ptr->next;
	 }
	 free(ptr->next);
	 ptr->next=NULL;
  }
  return start;
}


node * delete_after(node * start)

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
	if(start->data==val)
	{
		free(ptr2);
		start->next=NULL;
	}
	else
	{
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
    }
    return start;
}

node * search(node * start)
{
    node *ptr=start;
    int item;
	printf("\nEnter item which you want to search?\n");
    scanf("%d",&item);
    while (ptr->next!= NULL&&ptr->data!=item)
    {
	 ptr=ptr->next;
    }
    if(ptr->data == item)
    {
	       printf("Element found!!\n");
    }
    else
    {
		printf("Element doesn't exist");
    }
    return start;
}

node * replace(node *start)
{
	node *ptr;
	int pos,count=1,dat;
	printf("Enter position from which to replace : ");
	scanf("%d",&pos);
	printf("Enter data you want to replace with: ");
	scanf("%d",&dat);
	if(start==NULL)
		printf("List empty , Can't replace");
	else if(pos==1)
	{
		start->data=dat;
	}
	else
	{
		ptr=start;
		while(ptr!=NULL&&count<pos)
		{
			count=count++;
			ptr=ptr->next;
		}
		if(count==pos)
		{
			ptr->data=dat;
		}
		else
		{
			printf("Position doesn't exist, can't replace");
		}
	}
	return start;
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