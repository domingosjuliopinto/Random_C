// draw and fill polygon
#include<stdio.h>
#include<conio.h>
#include<graphics.h>
void main()
{
	int gdriver=DETECT,gmode;
	int n,i,j,k,dy,dx;
	int x,y,temp;
	int p[20][2],in[20];
	float slope[20];
	clrscr();
	initgraph(&gdriver,&gmode,"C:\\TC\\BGI"); //set your path to BGI
	printf("Note to user 500>x>190,400>y>200");
	printf("\nEnter number of edges: ");
	scanf("%d",&n);
	printf("\nEnter the co-ordinates of the polygon");
	for(i=0;i<n;i++)
	{
		printf("\nX%d Y%d : ",i,i);
		scanf("%d%d",&p[i][0],&p[i][1]);
	}
	p[n][0]=p[0][0];
	p[n][1]=p[0][1];
	for(i=0;i<n;i++) //to draw the shape
	{
		line(p[i][0],p[i][1],p[i+1][0],p[i+1][1]);
		delay(450);
	}
	for(i=0;i<n;i++)
	{
		dy=p[i+1][1]-p[i][1];
		dx=p[i+1][0]-p[i][0];
		if(dy==0)
		{
			slope[i]=1.0;
		}
		if(dx==0)
		{
			slope[i]=0.0;
		}
		if(dy!=0&&dx!=0)
		{
			slope[i]=(float)dx/dy;
		}
	}
	for(y=0;y<800;y++)
	{
		k=0;
		for(i=0;i<n;i++)
		{
			if(((p[i][1]<=y)&&(p[i+1][1]>y))||((p[i][1]>y)&&(p[i+1][1]<=y)))
			{
				in[k]=(int)(p[i][0]+slope[i]*(y-p[i][1]));
				k++;
			}
		}
		for(j=0;j<k-1;j++)
		{
			for(i=0;i<k-1;i++)
			{
				if(in[i]>in[i+1])
				{
					temp=in[i];
					in[i]=in[i+1];
					in[i+1]=temp;
				}
			}
			setcolor(4);
			for(i=0;i<k;i=i+2)  //to fill the shape
			{
				line(in[i],y,in[i+1]+1,y);
				delay(30);
			}
		}
	}
	getch();
	closegraph();
}

