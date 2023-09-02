// program to draw a line
#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<graphics.h>
void main()
{
 int gdriver=DETECT,gmode;
 float x1,x2,y1,y2;
 float xn,yn,dx,dy;
 float xi,yi,steps,i;

 clrscr();

 initgraph(&gdriver,&gmode,"C:\\TC\\BGI"); //set your path to BGI
 printf("Note to user:500>x>25 500>y>200\n");
 printf("Enter value of starting point (x1,y1) :\n");
 scanf("%f%f",&x1,&y1);
 printf("Enter value of starting point (x2,y2) :\n");
 scanf("%f%f",&x2,&y2);
 xn=x1;
 yn=y1;
 dx=x2-x1;
 dy=y2-y1;
 if(dx>=dy)
 {
  steps=abs(dx);
  }
 else
 {
  steps=abs(dy);
  }
 xi=dx/steps;
 yi=dy/steps;
 for(i=0;i<=steps;i++)
 {
  putpixel(xn,yn,RED);
  xn=xn+xi;
  yn=yn+yi;
  }
 getch();
}

