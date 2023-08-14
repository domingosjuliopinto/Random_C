//matrices multiplication
#include<stdio.h>
#include<conio.h>
void main()
{
 int a[15][15],b[15][15],pro[15][15];
 int i,j,k,r1,r2,c1,c2,s=0;
 clrscr();
 printf("Enter number of rows in first matrix : ");
 scanf("%d",&r1);
 printf("Enter number of columns in first matrix : ");
 scanf("%d",&c1);
 printf("Enter elements in the first matrix : \n");
 for(i=0;i<r1;i++)
 {
  for(j=0;j<c1;j++)
  {
   scanf("%d",&a[i][j]);
			}
			 }
 printf("\nEnter number of rows in second matrix : ");
 scanf("%d",&r2);
 printf("Enter number of columns in second matrix : ");
 scanf("%d",&c2);
 if(c1!=r2)
 {
  printf(" Multiplication cannot be done");
					   }
 else
 {
  printf("Enter elements in the second matrix : \n");
  for(i=0;i<r2;i++)
  {
   for(j=0;j<c2;j++)
  {
   scanf("%d",&b[i][j]);
			}
			 }
 printf("Elements in the first matrix are: \n");
 for(i=0;i<r1;i++)
 {
  for(j=0;j<c1;j++)
  {
   printf("%d\t",a[i][j]);
			}
   printf("\n");
			 }
 printf("\nElements in the second matrix are : \n");
 for(i=0;i<r2;i++)
 {
  for(j=0;j<c2;j++)
  {
   printf("%d\t",b[i][j]);
			}
   printf("\n");
			 }
 printf("The product of the two matrices are : \n");
 for(i=0;i<r1;i++)
 {
  for(j=0;j<c2;j++)
  {
   for(k=0;k<c1;k++)
   {
    s=s+(a[i][k]*b[k][j]);
		      }
   pro[i][j]=s;
   s=0;
   printf("%d\t",pro[i][j]);
			    }
   printf("\n");
		}
		}
 getch();
	 }