#include<stdio.h>
#include<conio.h>
#include <string.h>
char noun[][20]={"dogs","cats","chase","milk","drink"};

void isNoun(char * token)
{
  int i,val;
  for(i=0;i<5;i++)
  {
	val=strcmp(token,noun[i]);
	if(val==0)
	{
		printf("(n,%d) ",i+1);
	}
  }
}

void isVerb(char * token)
{
  int i,val;
  char verb[][5]={"hate","like"};
  for(i=0;i<2;i++)
  {
	val=strcmp(token,verb[i]);
	if(val==0)
	{
		printf("(v) ");
	}
  }
}

void isAction(char * token)
{
	int i,val;
	char action[][5]={"they","They"};
	for(i=0;i<2;i++)
	{
		val=strcmp(token,action[i]);
		if(val==0)
		{
			printf("(a) ");
		}
	}
}

void isLine(char * token)
{
	int i,val;
	char line[][5]={"If","if","then","Then"};
	for(i=0;i<4;i++)
	{
		val=strcmp(token,line[i]);
		if(val==0)
		{
			printf("(k) ");
		}
	}
}

void isOperator(char * token)
{
	int i,val;
	char op[][5]={",","."};
	for(i=0;i<2;i++)
	{
		val=strcmp(token,op[i]);
		if(val==0)
		{
			printf("(op) ");
		}
	}
}

void isEOF(char * token)
{
	int val;
	char eof[1]={"$"};
	val=strcmp(token,eof);
	if(val==0)
	{
		printf("<eof>");
	}
}

void main()
{
	int i,n=5;
	char str[50];
	//char str[] = "If dogs hate cats then they chase , If cats like milk then they drink . $" ;
	char * token;
	clrscr();
	printf("Symbol Table\n");
	for(i=0;i<n;i++)
	{
		printf("%s\t%d\n",noun[i],i+1);
	}
	printf("\nEnter a string:\n");
	gets(str);
	//printf("%s\n",str);
	token = strtok(str," ");
	while( token != NULL ) {
		isNoun(token);
		isVerb(token);
		isAction(token);
		isLine(token);
		isOperator(token);
		isEOF(token);
		token = strtok(NULL," ");
	}
	getch();
}