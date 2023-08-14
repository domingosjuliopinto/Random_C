// Matrices addition
#include<stdio.h>
#include<conio.h>
void main()
{
 int a[15][15],b[15][15],sum[15][15],i,j,r,c;
 clrscr();
 printf("Enter number of rows in both matrices : ");
 scanf("%d",&r);
 printf("Enter number of columns in both matrices: ");
 scanf("%d",&c);
 printf("Enter elements in the first matrix : \n");
 for(i=0;i<r;i++)
 {
  for(j=0;j<c;j++)
  {
   scanf("%d",&a[i][j]);
		       }
			}
 printf("Enter elements in second matrix : \n");
 for(i=0;i<r;i++)
 {
  for(j=0;j<c;j++)
  {
   scanf("%d",&b[i][j]);
		       }
			}
 printf("\n the first matrix is : \n");
 for(i=0;i<r;i++)
 {
  for(j=0;j<c;j++)
  {
   printf("%d\t",a[i][j]);
		       }
   printf("\n");
			}
 printf("\n The second matrix is : \n");
 for(i=0;i<r;i++)
 {
  for(j=0;j<c;j++)
  {
   printf("%d\t",b[i][j]);
		       }
   printf("\n");
			}
  printf("\n The sum of the two matrices are : \n");
  for(i=0;i<r;i++)
  {
   for(j=0;j<c;j++)
   {
    sum[i][j]=a[i][j]+b[i][j];
    printf("%d\t",sum[i][j]);
			     }
   printf("\n");
    }
  getch();
  }
