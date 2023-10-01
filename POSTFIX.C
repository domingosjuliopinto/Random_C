// postfix evaluation
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>

char exp1[10];
float stack[20];
int len=0,TOP=-1;
void push(float element);
void pop(void);
float peek(void);
void main()
{
	int i=0;
	float op1,op2,val = 0.0,valf;
	clrscr();
	printf("Enter The Postfix Expression To Evaluate It: ");
	scanf("%s",exp1);
	len=strlen(exp1);
	for(i=0;i<len;i++)
	{
		if(isalpha(exp1[i]))
		{
			float v;
			printf("Enter value of the variable %c : ",exp1[i]);
			scanf("%f",&v);
			push((float)(v));
		}
		else if(isdigit(exp1[i]))
		{
			push((float)(exp1[i]-'0'));
		}
		else
		{
			op1=peek();
			pop();
			op2=peek();
			pop();
			if(exp1[i]=='+')
			{
				val=op2+op1;
			}
			else if(exp1[i]=='-')
			{
				val=op2-op1;
			}
			else if(exp1[i]=='*')
			{
				val=op2*op1;
			}
			else if(exp1[i]=='/')
			{
				val=op2/op1;
			}
			else if(exp1[i]=='%')
			{
				val=(int)(op2)%(int)(op1);
			}
			push(val);
		}
	}
	valf=peek();
	pop();
	printf("\n\n result of evaluation is %f",valf);
	getch();
}
void push(float element)
{
	    TOP++;
	    stack[TOP]=element;
}
float peek()
{
	return(stack[TOP]);
}
void pop()
{
      TOP--;
}