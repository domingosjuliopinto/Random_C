//  a program to solve the Sum of Subsets problem using Backtracking
#include<stdio.h>
#define MAX 10
int w[MAX];
int x[MAX];
int m,n;
 void display()
 {
     int i;
     printf("\nSubsets are : \n{");
       for(i=1;i<=n;i++)
       { printf(" %d ",x[i]);}
       printf("}");
 }
 void sum_of_subsets(int s,int k,int r)
 {   int i;int g;
      x[k] = 1;
       if((s+w[k])==m)
       {
	 for(i=k+1;i<=n;i++) {  x[i]=0; }
	 display();
       }

	 else
	 if((s+w[k]+w[k+1])<= m)
	  {
	     sum_of_subsets(s+w[k],k+1,r-w[k]);
	  }
	   if((s+r-w[k]>=m)&&(s+w[k+1]<=m))
	  {
	     x[k] = 0;
	     sum_of_subsets(s,k+1,r-w[k]);
	  }



 }
  void main()
{
    int i,total=0;
	clrscr();
    printf("Enter the value of n: ");
    scanf("%d",&n);
    printf("Enter the sum value for creating subsets: ");
    scanf("%d",&m);
    printf("Enter the number in the set in ascending order:\n");

    for(i=1;i<=n;i++)
    {
     scanf("%d",&w[i]);
     total = total+w[i];
    }

    if(total<m)
    {   printf("Subsets can't be generated"); }

    sum_of_subsets(0,1,total);
    getch();
}