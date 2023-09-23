// a Program for Boundary Fill and Flood Fill Algorithm
#include<stdio.h>
#include<conio.h>
#include<graphics.h>

void boundaryFill4(int x,int y, int fill_color, int boundary_color)
{
	if(getpixel(x,y)!=boundary_color&&getpixel(x,y)!=fill_color)
	{
		putpixel(x,y,fill_color);
		boundaryFill4(x+1,y, fill_color,boundary_color);
		boundaryFill4(x,y+1, fill_color,boundary_color);
		boundaryFill4(x-1,y, fill_color,boundary_color);
		boundaryFill4(x,y-1, fill_color,boundary_color);
	}
}

void floodFill4(int x,int y, int fill_color, int old_color)
{
	if(getpixel(x,y)==old_color)
	{
		putpixel(x,y,fill_color);
		floodFill4(x+1,y, fill_color,old_color);
		floodFill4(x,y+1, fill_color,old_color);
		floodFill4(x-1,y, fill_color,old_color);
		floodFill4(x,y-1, fill_color,old_color);
	    }
}

void main()
{
	int gdriver=DETECT,gmode;
	int x,y,r,ch;
	clrscr();
	initgraph(&gdriver,&gmode,"C:\\TC\\BGI"); //set your path to BGI
	printf("Note to user 550>x>250,30>r>10,400>y>250");
	printf("\nEnter x and y coordinates of circle\n");
	scanf("%d%d",&x,&y);
	printf("Enter radius of  circle\n");
	scanf("%d",&r);
	circle(x,y,r);
	boundaryFill4(x,y,4,15);
	delay(500);
	printf("Which colour do you want to change it to?\n 1-Black,2-Blue,3-Green,4-Yellow,\n5-White, Other numbers -no change \n Your Choice : ");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:floodFill4(x,y,0,4);
			break;
		case 2:floodFill4(x,y,1,4);
			break;
		case 3:floodFill4(x,y,2,4);
			break;
		case 4:floodFill4(x,y,14,4);
			break;
		case 5:floodFill4(x,y,15,4);
			break;
		default : printf("No color change");
	}
	getch();
	closegraph();
}