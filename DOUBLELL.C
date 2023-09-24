//Double Link List
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<malloc.h>
struct node
{
	int data;
	struct node *next;
	struct node *prev;
};
struct node *start=NULL;
void create();
void insert_beg();
int insert_end();
void  insert_before();
void insert_after();
void delete_beg();
void delete_end();
void delete_after();
void delete_before();
void display();
int main()
{
	int ch,a;
	clrscr();
	while(1)
	{
       printf("\n---------------MAIN MENU------------\n");
       printf("\n1.CREATE\n2.INSERTBEG\n3.INSERT_END\n4.INSERT_BEFORE\n5.INSERT_AFTER\n6.DELETEBEG\n7.DELETE_END\n8.DELETE_AFTER\n9.DELETE_BEFORE\n10.DISPLAY\n11.EXIT");
       printf("\nEnter your choice:");
       scanf("%d",&ch);
       switch(ch)
       {
	case 1:create();
	       printf("\nLinked list created successfully:");
	       break;
	case 2:insert_beg();
	       break;
	case 3:a=insert_end();
	       printf("\n Element %d entered:",a);
	       break;
	case 4:insert_before();
	       break;
	case 5:insert_after();
	       break;
	case 6:delete_beg();
	       break;
	case 7:delete_end();
	       break;
	case 8:delete_after();
	       break;
	case 9:delete_before();
	       break;
	case 10:display();
		break;
	case 11:exit(0);
	default:printf("\nINVALID  CHOICE!!!!!!!");
       }
	}
}
void create()
{
	int n,i;
	printf("Enter the elements to be inserted:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		insert_end();
	}
}
void insert_beg()
{
	  struct node *ptr,*new_node;
	  int val;
    new_node=(struct  node *)malloc(sizeof(struct node));
    printf("\nEnter the value to be inserted: ");
		scanf("%d",&val);
		new_node->data=val;
		new_node->prev=NULL;
		if(start!=NULL)
		{
			start->prev=new_node;
		}
		new_node->next=start;
		start=new_node;
}
int  insert_end()
{
	struct node *ptr,*new_node;
	int val;
	printf("Enter the value to be entered:");
	scanf("%d",&val);
	new_node=(struct node *)malloc(sizeof(struct node));
	ptr=start;
	if(start==NULL)
	{
		new_node->prev=NULL;
		new_node->data=val;
		new_node->next=NULL;
		start=new_node;
	}
	else
	{
		new_node->data=val;
		new_node->next=NULL;
		while(ptr->next!=NULL)
		{
			ptr=ptr->next;
		}
		ptr->next=new_node;
		new_node->prev=ptr;
	}
	return val;
}
void insert_before()
{
	struct node *new_node,*ptr;
	int val,num;
	printf("\nEnter the data of the node before which the new node is  to be inserted:");
	scanf("%d",&num);
	new_node=(struct node *)malloc(sizeof(struct node));
	ptr=start;
	if(ptr->data==num)
	{
		insertbeg();
	}
	else
	{
		printf("\nEnter the data of the node:");
		scanf("%d",&val);
		new_node->data=val;
		while(ptr!=NULL&&ptr->data!=num)
		{
			ptr=ptr->next;
		}
		if(ptr==NULL)
		{
			printf("Value not found, can't insert\n");
		}
		else
		{
			if(ptr==start)
			{
				new_node->next=start;
				new_node->prev=NULL;
				start->prev=new_node;
				start=new_node;
			}
			else
			{
				new_node->next=ptr;
				new_node->prev=ptr->prev;
				ptr->prev->next=new_node;
				ptr->prev=new_node;
			}
		}
	}
}
void insert_after()
{
	struct node *ptr,*new_node;
	int val,num;
	printf("\n Enter the data of the node after which the new node is to be entered:");
	scanf("%d",&num);
	new_node=(struct node *)malloc(sizeof(struct node));
	printf("\nEnter the data of the node:");
	scanf("%d",&val);
	new_node->data=val;
	ptr=start;
	while(ptr!=NULL&&ptr->data!=num)
	{
		ptr=ptr->next;
	}
	if(ptr==NULL)
	{
		printf("Value not found, can't insert\n");
	}
	else
	{
		new_node->next=ptr->next;
		new_node->prev=ptr;
		ptr->next=new_node;
		if(ptr->next!=NULL)
			ptr->next->prev=new_node;
	}
}
void display()
{
	struct node *ptr;
	ptr=start;
	if(start==NULL)
	{
		printf("\n Nothing to display::::");
	}
	else
	{
		while(ptr!=NULL)
		{
			printf("\t %d",ptr->data);
			ptr=ptr->next;
		}
	}
}
void delete_beg()
{
	struct node *ptr;
  ptr=start;
	if(start==NULL)
	{
		printf("UNDERFLOW!!!!!!!!!!!!");
	}
	else
	{
		if(start->next==NULL)
		{
			start=NULL;
		}
		else
		{
			start=start->next;
			start->prev=NULL;
		}
		free(ptr);		
	}
}
void delete_end()
{
	struct node *ptr;
	ptr=start;
	if(start==NULL)
	{
		printf("UNDERFLOW!!!!!!");
	}
	else
	{
		while(ptr->next!=NULL)
		{
			ptr=ptr->next;
		}
		if(ptr==start)
		{
				start=NULL;
		}
		else
		{
			ptr->prev->next=NULL;
		}
		free(ptr);
	}
}
void delete_after()
{
	struct node *ptr,*temp;
	int num;
	printf("Enter the data of the node after which the next node is to be deleted:");
	scanf("%d",&num);
		ptr=start;
	if(start==NULL)
	{
		printf("UNDERFLOW!!!!!!!!");
	}
	else
	{
		while(ptr->next!=NULL&&ptr->data!=num)
		{
			ptr=ptr->next;
		}
		if(ptr->next==NULL)
		{
			printf("Value not found can't delete\n");
		}
		else
		{
			if(ptr->next==NULL)
			{
				printf("This is the last node. Nothing to delete\n");
			}
			else
			{
				temp=ptr->next;
				ptr->next=temp->next;
				if(temp->next!=NULL)
					temp->next->prev=ptr;
			}
		}
	}
	free(temp);
}
void delete_before()
{
	struct node *ptr,*temp;
	int num;
	printf("Enter the data of the node :");
	scanf("%d",&num);
	ptr=start;
	if(start==NULL)
	{
		printf("UNDERFLOW!!!!!!");
	}
	else
	{
		while(ptr->data!=num&&ptr->next!=NULL)
		{
			ptr=ptr->next;
		}
		if(ptr->next==NULL)
		{
			printf("Value not found can't delete\n");
		}
		else
		{
			temp=ptr->prev;
			if(temp==start)
			{
				start=ptr;
				ptr->prev=NULL;
			}
			else
			{
				temp->prev->next=ptr;
				ptr->prev=temp->prev;
			}
		}
	}
	free(temp);
}
