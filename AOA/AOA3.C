//Program to perform String matching using Rabin Karp Algorithm
#include<stdio.h>
#include<conio.h>
#include<string.h>
int count = 0, a = 0;
void rabin_karp(char pat[], char txt[], int d, int q)
{
	int m = strlen(pat);
	int n = strlen(txt);
	int i, j;
	int p = 0;
	int t = 0;
	int h = 1;
	for (i = 0; i < m - 1; i++)
	{
		h = (h * d) % q;
	}
	for (i = 0; i < m; i++)
	{
		p = (d * p + pat[i]) % q;
		t = (d * t + txt[i]) % q;
	}
	for (i = 0; i <= n - m; i++)
	{
		if (p == t)
		{
			for (j = 0; j < m; j++)
			{
				if (txt[i + j] != pat[j])
				break;
			}
			if (j == m)
			{
				printf("Pattern found at index: %d \n", i);
				count = count + 1;
				a = count;
			}
		}
		if (i < n - m)
		{
			t = (d * (t - txt[i] * h) + txt[i + m]) % q;
			if (t < 0)
			t = (t + q);
		}
	}
	printf("\nTotal valid shifts: %d", a);
}

void main()
{
	char txt[80], pat[80], tmp[2];
	int d, q;
	clrscr();
	printf("Note:\nFor ASCII string d = 256\nFor Text String d = 26\nFor Binary text d = 2\nFor Hexadecimal string d = 16\nFor Numeric string d = 10");
	printf("\nEnter the string:\n");
	gets(txt);
	printf("Enter a pattern:\n");
	gets(pat);
	printf("\nEnter the base or radix for the input string (d) :\n");
	scanf("%d", &d);
	printf("\nEnter an appropriate prime no. :\n");
	scanf("%d", &q);
	printf("Input String : %s\n", txt);
	printf("Input Pattern : %s\n", pat);
	rabin_karp(pat, txt, d, q);
	getch();
}