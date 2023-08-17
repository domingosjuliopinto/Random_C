// infix to postfix
#include<stdio.h>
#include<conio.h>
#include"CHARSTAC.H"

void infixtopostfix(char *, char *);
int getprecedence(char c);

void main()
{
  char infix[50];
  char postfix[50];
  clrscr();
  printf("Enter the infix expression :\n");
  gets(infix);
  infixtopostfix(infix,postfix);
  printf("The postfix expression = %s",postfix);
  getch();
}

void infixtopostfix(char infix[50], char postfix[50])
{
  int i=0,j=0,len=0,x;
  len=strlen(infix);
  infix[len]=')';
  infix[len+1]='\0';
  push('(');

  while(infix[i]!='\0')
  {
    if(infix[i]=='(')
     push(infix[i]);
    else if(isalpha(infix[i])||isdigit(infix[i]))
     {
      postfix[j++]=infix[i];
      }
    else if(infix[i]==')')
     {
       while(peep()!='(')
       {
	x=pop();
	postfix[j++]=x;
       }
       pop();
     }
    else
    {
      while(getprecedence(peep())>=getprecedence(infix[i]))
      {
       x=pop();
       postfix[j++]=x;
       }
       push(infix[i]);
    }
    i++;
   }
   postfix[j]='\0';
}

int getprecedence(char c)
{
  if(c=='%'||c=='*'||c=='/')
  {
   return 2;
   }
  if(c=='+'||c=='-')
  {
   return 1;
   }
  else return 0;
}