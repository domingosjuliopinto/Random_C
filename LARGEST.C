// Largest Element from array
#include<stdio.h>
#include<conio.h>
void main()
{
 int a[10],n,i,large;
 clrscr();
 printf("number of elements in a array : ");
 scanf("%d",&n);
 printf("Enter the elements :\n");
 for(i=0;i<n;i++)
 {
  scanf("%d",&a[i]);
		     }
 large=a[0];
 for(i=1;i<n;i++)
 {
  if(large<a[i])
  {
   large=a[i];
	      }
	       }
 printf("Largest element=%d",large);
 getch();
	}