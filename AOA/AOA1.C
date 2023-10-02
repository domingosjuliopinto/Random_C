// Program for Insertion sort and Selection sort
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void main()
{
	int n,i,ch;
	int a[100];
	clrscr();
	/*Initializes random number generator*/
	srand(time(NULL));
	printf("Enter the number of array elements: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		a[i]=rand()%100; /*Inputs random numbers in array*/
	}
	printf("1.Insertion sort \n2.Selection sort \nEnter any number to Exit \nEnter your choice : ");
	scanf("%d",&ch) ;
	switch(ch)
	{
		case 1 : insertion(a,n);
			 break;
		case 2 : selection(a,n);
			 break;
		default :break;
	}
	printf("\nThe sorted array is \n");
	for(i=0;i<n;i++)
	{
		printf("%d\t",a[i]);
	}
	getch();
}

int insertion (int a[],int n)
{
	int i,j,key;
	for(i=1;i<n;i++)
	{
		key=a[i];
		j=i-1;
		while(key<a[j]&&j>=0)
		{
			a[j+1]=a[j];
			j=j-1;
		}
		a[j+1]=key;
		disp(a,n);
	}
	return;
}

int disp(int a[],int n)
{
	int i;
	printf("\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t",a[i]);
	}
	return;
}

int selection(int a[],int n)
{
	int i,j;
	int large,pos;
	for(i=n-1;i>=0;i--)
	{
		large=a[0];
		pos=0;
		for(j=1;j<=i;j++)
		{
			if(a[j]>large)
			{
				large=a[j];
				pos=j;
			}
		}
		a[pos]=a[i];
		a[i]=large;
		disp(a,n);
	}
	return;
}