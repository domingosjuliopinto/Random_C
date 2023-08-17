// Parenthesis Checker
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include"CHARSTAC.H"

void main()
{
	int choice,i=0;
	char val,expr[50];
	clrscr();
	printf("Enter an algebraic expression with parenthesis:\n");
	gets(expr);
	printf("\nExp=%s",expr);
	while(expr[i]!='\0')
	{
		if(expr[i]=='('||expr[i]=='{'||expr[i]=='[')
		{
			push(expr[i]);
		}
		if(expr[i]==')'||expr[i]=='}'||expr[i]==']')
		{
			val=pop();
			if(expr[i]==')'&&val!='(')
			{
				printf("\nNot Well Formed");
				exit(0);
			}
			if(expr[i]=='}'&&val!='{')
			{
				printf("\nNot Well Formed");
				exit(0);
			}
			if(expr[i]==']'&&val!='[')
			{
				printf("\nNot Well Formed");
				exit(0);
			}
		}
		i++;
	}
	if(is_stack_empty()!=-1)
	{
		printf("\nNot Well Formed");
	}
	else
	{
		printf("\nExpression is Well Formed");
	}
	getch();
}