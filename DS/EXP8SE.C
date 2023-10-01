//Another linked list program
#include<stdio.h>
#include<conio.h>
#include <stdlib.h>
 
typedef struct node
{
    int data;
    struct node *next;
}node;
 
void display(node *start)
{
    node *ptr;
    if(start == NULL)
    {
        printf("No element present to display!");
    }
    else
    {
        ptr = start;
        while(ptr->next != start)
        {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        }
        printf("%d ", ptr->data);
    }  
}
 
node * insert_beg(int val, node *start)
{
    node *ptr = start;
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = val;
    if(start==NULL)
    {
        newnode->next = newnode;
        start = newnode;
    }
    else
    {
        while (ptr->next!=start)
        {
            ptr = ptr->next;
        }
        ptr->next = newnode;
        newnode->next = start;
        start = newnode;
    }
    return start;
}

node * insert_end(int val, node *start)
{
    node *ptr = start;
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = val;
    if(start == NULL)
    {
	newnode->next = newnode;
	start = newnode;
    }
    else
    {
	while (ptr->next!=start)
	{
	    ptr = ptr->next;
	}
	ptr->next = newnode;
	newnode->next = start;
    }
    return start;
}

node * delete_beg(node *start)
{
    node *ptr, *temp;
    if(start == NULL)
    {
	printf("No element present! Cant delete.");
    }
    else
    {
	ptr = start;
	temp = start;
	while(ptr->next != start)
	{
	    ptr=ptr->next;
	}
	start = temp->next;
	ptr->next = start;
	if(start == temp)
	{
	    start = NULL;
	}
	free(temp);
    }
    return start;
}

node * delete_end(node *start)
{
    node *temp, *ptr = start;
    if(start == NULL)
    {
	printf("No element present! Cant delete.");
    }
    else
    {
	while(ptr->next->next!=start)
	{
	    ptr = ptr->next;
	}
	temp = ptr;
	ptr = ptr->next;
	temp->next = start;
	if(temp == ptr)
	{
	    start = NULL;
	}
	free(ptr);
    }
    return start;
}

void main()
{
    int choice, val;
    node *start = NULL;
	clrscr();
    while (1)
    {
	printf("\n\n1.Insert Beginning 2.Insert End 3.Delete Beginning\n 4.Delete End 5.Display 6.Quit\nEnter Choice: ");
	scanf("%d", &choice);
	switch(choice)
	{
	    case 1: printf("Enter element to insert at beginning: ");
		    scanf("%d", &val);
		    start = insert_beg(val, start);
		    break;
	    case 2: printf("Enter element to insert at end: ");
		    scanf("%d", &val);
		    start = insert_end(val, start);
		    break;
	    case 3: start = delete_beg(start);
		    break;
	    case 4: start = delete_end(start);
		    break;
	    case 5: display(start);
		    break;
	    case 6: exit(0);
		    break;
	    default: printf("Enter correct choice!");
	}
    }
}