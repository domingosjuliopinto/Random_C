/* Stack header for stack using array*/
#define size 50

char stack[size];

int top=-1;

void push(char val)
{
   if(top==size-1)
     printf("\n Stack Full\n");
   else
   {
     top++;
     stack[top]=val;
   }
}

char pop()
{
  char val;
  if(top==-1)
    {
    printf("\n Stack underflow");
    }
  else
  {
   val=(stack[top--]);
   }
   return val;
}

char peep()
{
	if (top==-1)
		return -1;
	else
	{
	       return stack[top];
	}
}

void display()
{
	int i;
	if (top==-1)
		printf("\n Stack empty");
	else
	{
		printf("Stack Elements are : \n");
		for(i=top;i>=0;i--)
		{
			printf("%c\n",stack[i]);
		}
	}
}

int is_stack_empty()
{
	if(top==-1)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}