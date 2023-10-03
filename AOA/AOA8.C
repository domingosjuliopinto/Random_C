// a program to find Longest Common Subsequence for two sequences using Dynamic Programming
#include<stdio.h>
#include<string.h>
#define MAX 20
char X[MAX], Y[MAX];
int b[MAX][MAX], c[MAX][MAX];
void LCS();
void PRINT_LCS(int i, int j);
void PRINT_LCS_ALL(int i, int j);
int m,n;
int longestlength=0;
void printC();

void main()
{
	int i;
	clrscr();
	printf("Enter the first text X: ");
	gets(X);
	printf("Enter the second text Y: ");
	gets(Y);
	n=strlen(Y);
	m=strlen(X);
	printf("\n Length of X= %d", m);
	printf("\n Length of Y= %d", n);
	printf("\n X= %s \n", X);

	for(i=0;i<m;i++)
	{
		printf("%c ",X[i]);
	}
	printf("\n Y - %s \n",Y);
	for(i=0;i<n;i++)
	{
		printf("%c ",Y[i]);
	}
	LCS();
	printC();
	printf("\n The Longest Common Sunsequence is: ");
	PRINT_LCS(m,n);
	getch();
}

void LCS()
{
	int i,j;
	for(i=0; i<=m+1 ; i++) c[i][0]=0;
	for(j=0; j<=n ; j++) c[0][j]=0;
	for(i=1; i<=m+1; i++)
	{
		for(j=1; j<=n; j++)
		{
			if(X[i-1] ==Y[j-1])
			{
				c[i][j]=c[i-1][j-1]+1;
				b[i][j]=1;
			}
			else if(c[i-1][j] >= c[i][j-1])
			{
				c[i][j]=c[i-1][j];
				b[i][j]=2;
			}
			else
			{
				c[i][j]=c[i][j-1];
				b[i][j]=3;
			}
		}
	}
	longestlength=c[i-1][j-1];
}

void PRINT_LCS(int i, int j)
{
	if(i==0 || j==0)
	{
		return;
	}
	if(b[i][j]==1)
	{
		PRINT_LCS(i-1, j-1);
		printf("%c",X[i-1]);
	}
	else if(b[i][j]==2)
	{
		PRINT_LCS(i-1,j);
	}
	else
	{
		PRINT_LCS(i,j-1);
	}
}

void printC()
{
	int i,j;
	printf("\n Table C: \n    Yi   ");
	for(i=0; i<n; i++)
	{
		printf("%c   ", Y[i]);
	}
	printf("\n Xi");
	for(i=0; i<m+1;i++)
	{
		printf("\n %c", X[i]);
		for(j=0; j<=n; j++)
		{
			printf("  %d ", c[i][j]);
		}
		printf("\n");
	}
	printf("\n Table b: \n");
	for(i=1; i<=m; i++)
	{
		for(j=1;j<=n;j++)
		{
			printf("%d ", b[i][j]);
		}
		printf("\n");
	}
}







