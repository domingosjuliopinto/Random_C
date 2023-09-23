// a program of Midpoint Circle Algorithm
#include<stdio.h>
#include<conio.h>
#include<graphics.h>
void MidCircle(int x,int y,int r) //implementing the Midcircle algorithm
{
	int x0,y0,p;
	x0=0;
	y0=r;
	p=1-r;
	while(x0<y0)
	{
		putpixel(x+x0,y+y0,RED);
		putpixel(x+x0,y-y0,RED);
		putpixel(x-x0,y+y0,RED);
		putpixel(x-x0,y-y0,RED);
		putpixel(y+y0,x+x0,RED);
		putpixel(y+y0,x-x0,RED);
		putpixel(y-y0,x+x0,RED);
		putpixel(y-y0,x-x0,RED);
		if(p<0)
		{
			p=p+(2*x0)+3;
			y0=y0;
			x0=x0+1;
		}
		else
		{
			p=p+(2*(x0-y0))+5;
			y0=y0-1;
			x0=x0+1;
		}
	}
}
void main()
{
	int gdriver=DETECT,gmode;
	int x,y,r;
	clrscr();
	initgraph(&gdriver,&gmode,"C:\\TC\\BGI"); //set your path to BGI
	printf("Note to user : x>199 & y>199\n");
	printf("Enter value of centre point (x,y) :\n");
	scanf("%d%d",&x,&y);
	printf("Enter value of radius :\n");
	scanf("%d",&r);
	MidCircle(x,y,r); //function call
	getch();
}
