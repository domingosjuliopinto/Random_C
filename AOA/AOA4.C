// program to perform String Matching using Knutt Morris Pratt Algorithm
#include<stdio.h>
#include<conio.h>
#include<string.h>
char txt[100], pat[100];
int M, N, pi[100], j = 0, i = 0;
int count = 0, a = 0;
void compute_prefix()
{
	int len = 0, i;
	pi[0] = 0;
	i = 1;
	while (i < M)
	{
		if (pat[i] == pat[len])
		{
			len++;
			pi[i] = len;
			i++;
		}
		else
		{
			if (len != 0)
				len = pi[len - 1];
			else
			{
				pi[i] = 0;
				i++;
			}
		}
	}
	printf("\nThe prefix array:\n");
	printf("|");
	for (i = 0; i < M; i++)
	printf(" %d |", pi[i]);
	printf("\n\n");
}
void kmp_matcher()
{
	int j = 0, i = 0;
	M = strlen(pat);
	N = strlen(txt);
	compute_prefix();
	while (i < N)
	{
		if (pat[j] == txt[i])
		{
			j++;
			i++;
		}
		if (j == M)
		{
			printf("Pattern is found at index: %d\n", i - j);
			j = pi[j - 1];
			count = count + 1;
			a = count;
		}
		else if (pat[j] != txt[i])
		{
			if (j != 0)
				j = pi[j - 1];
			else
				i = i + 1;
		}
	}
	printf("Total number of valid shifts: %d", a);
}
void main()
{
	clrscr();
	printf("\nEnter the string: \n");
	gets(txt);
	printf("Enter the pattern: \n");
	gets(pat);
	kmp_matcher();
	getch();
}