//to Implement a Program for Mid Point Ellipse Algorithm
#include<stdio.h>
#include<conio.h>
#include<graphics.h>
void Reg1(float rx, float ry, float xc, float yc);
void Reg2(float rx, float ry, float xc, float yc, float x, float y);
void main()
{
	int gdriver=DETECT,gmode;
	float xc,yc,ry,rx;
	clrscr();
	initgraph(&gdriver,&gmode,"C:\\TC\\BGI"); //set your path to BGI
	printf("Note to user x>200 y>200\n");
	printf("Enter center x and y of the ellipse:\n");
	scanf("%f%f",&xc,&yc);
	printf("Enter radius on x axis \n");
	scanf("%f",&rx);
	printf("Enter radius on y axis \n");
	scanf("%f",&ry);
	Reg1(rx,ry,xc,yc); //function call for Mid ellipse algorithm
	getch();
}
void Reg1(float rx,float ry,float xc,float yc) //function for Region 1
{
	float x=0,y=ry,p;
	p=(ry*ry)-(rx*rx*ry)+(0.25*rx*rx);
	do
	{
		putpixel(xc+x,yc+y,RED);
		putpixel(xc+x,yc-y,RED);
		putpixel(xc-x,yc+y,RED);
		putpixel(xc-x,yc-y,RED);
		if(p<0)
		{
			x=x+1;
			p=p+2*ry*ry*x+ry*ry;
		}
		else
		{
			x=x+1;
			y=y-1;
			p=p+2*ry*ry*x-2*rx*rx*y+ry*ry;
		}
	}while(2*ry*ry*x<2*rx*rx*y);
	Reg2(rx,ry,xc,yc,x,y); //function call for 2nd region
}
void Reg2(float rx,float ry, float xc,float yc, float x, float y) //function for Region 2
{
	float p;
	p=(ry*ry*(x+0.5)*(x+0.5))+((y-1)*(y-1)*rx*rx-rx*rx*ry*ry);
	do
	{
		putpixel(xc+x,yc+y,RED);
		putpixel(xc+x,yc-y,RED);
		putpixel(xc-x,yc+y,RED);
		putpixel(xc-x,yc-y,RED);
		if(p>0)
		{
			y=y-1;
			p=p-2*rx*rx*y+rx*rx;
		}
		else
		{
			x=x+1;
			y=y-1;
			p=p-2*rx*rx*y+2*ry*ry*x+rx*rx;
		}
	}while(y>0);
}
