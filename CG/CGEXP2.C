// program to draw line
#include<stdio.h>
#include<conio.h>
#include<graphics.h>
void main()
{
 int gdriver=DETECT,gmode;
 int x1,xn,y1,yn;
 int dx,dy,p;
 clrscr();

 initgraph(&gdriver,&gmode,"C:\\TC\\BGI"); //Set path to BGI
 printf("Enter value of starting point (x1,y1) :\n");
 scanf("%d%d",&x1,&y1);
 printf("Enter value of starting point (x2,y2) :\n");
 scanf("%d%d",&xn,&yn);
 dx=xn-x1;
 dy=yn-y1;
 p=2*dy-dx;
 while (x1<=xn)
 {
  putpixel(x1,y1,RED);
  x1++;
  if(p<0)
  {
   p=p+2*dy;
   }
  else
  {
   p=p+2*dy-2*dx;
   y1++;
   }
  }
  getch();
 }
