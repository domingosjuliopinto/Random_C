#include<stdio.h>
#include<conio.h>

// Factorial
int fact(int a)
{
 if(a==1)
 {
   return 1;
   }
 else
 {
  return a*fact(a-1);
  }
 }

void factadd()
{
 int b[100];
 int i,n,add=0;
 printf("\nEnter value of n : ");
 scanf("%d",&n);
 printf("\nEnter the values \n");
 for(i=0;i<n;i++)
 {
  scanf("%d",&b[i]);
  }
 printf("\n The array contains \n");
 for(i=0;i<n;i++)
 {
  printf("%d\t",b[i]);
  }
 for(i=0;i<n;i++)
 {
  add=add+fact(b[i]);
  }
 printf("\n\n The sum of the factorial of each element is : %d",add);
}

//sum of elements of 2d array
void demo_2d()
{
 int b[100][100];
 int i,j;
 int m,n;
 int sum=0;
 printf("Enter the size of m and n :\n");
 scanf("%d%d",&m,&n);
 printf("Enter the values :\n");
 for(i=0;i<m;i++)
 {
  for(j=0;j<n;j++)
  {
    scanf("%d",&b[i][j]);
    }
 }
 printf("\n The elements are\n");
 for(i=0;i<m;i++)
 {
  for(j=0;j<n;j++)
  {
    printf("%d\t",b[i][j]);
    }
  printf("\n");
 }
 for(i=0;i<m;i++)
 {
  for(j=0;j<n;j++)
  {
    sum=sum+b[i][j];
    }
 }
 printf("Sum of the elements of 2d array is : %d",sum);
}

// swapping two numbers
void swap(int *x,int *y)
{
 int temp;
 temp=*x;
 *x=*y;
 *y=temp;
	}

void swapping()
{
  int c[100];
  int n,i;
  printf("Enter the value of n : ");
  scanf("%d",&n);
  printf("Enter the numbers :\n");
  for(i=0;i<n;i++)
  {
    scanf("%d",&c[i]);
  }
  printf(" Array contents :\n");
  for(i=0;i<n;i++)
  {
    printf("%d\t",c[i]);
  }
  for(i=0;i<(n/2);i++)
  {
   swap(&c[i],&c[n-i-1]);
  }
  printf("\n Array contents after swapping :\n");
  for(i=0;i<n;i++)
  {
    printf("%d\t",c[i]);
  }
}

void main()
{
 int choice;
 clrscr();
 printf("Menu : \n1.Factorial Add \n2.2D Array Demo \n3.Swapping \n4.Exit");
 printf("\n Enter your choice \n");
 scanf("%d",&choice);
 switch(choice)
 {
  case 1: factadd();
	  break;
  case 2: demo_2d();
	  break;
  case 3: swapping();
	  break;
  case 4: break;
  default : printf("Please Enter correct choice");
  }
 getch();
}