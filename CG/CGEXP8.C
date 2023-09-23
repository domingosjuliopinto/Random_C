//To Implement Line Clipping Algorithm
#include<stdio.h>
#include<graphics.h>
#include<math.h>

void main()
{
  int gdriver=DETECT,gmode;
  int xmin, ymin, xmax, ymax;
  int x1,y1,x2,y2,i;
  int m;
  float a[4], b[4], c[4];
  initgraph(&gdriver,&gmode,"C:\\TC\\BGI");//set your path to BGI
  printf("Domingos J Pinto\nSE CMPN B \nRoll No 16 \n192093\n");
  printf("Enter the values of X-min and Y-min:");
  scanf("%d%d",&xmin,&ymin);
  printf("Enter the values of X-max and Y-max:");
  scanf("%d%d",&xmax,&ymax);
  printf("Enter the co-ordinates of line\n");
  printf("X1 Y1:");
  scanf("%d%d",&x1,&y1);
  printf("X2 Y2:");
  scanf("%d%d",&x2,&y2);
  for(i=0;i<4;i++)
  {
      a[i]=0;
      b[i]=0;
  }
  m=(y2-y1)/(x2-x1);
  if(x1<xmin)
  {
      a[0]=1;
  }
  if(x1>xmax)
  {
      a[1]=1;
  }
  if(y1<ymin)
  {
      a[2]=1;
  }
  if(y1>ymax)
  {
      a[3]=1; 
  }
  if(x2<xmin)
  {
      b[0]=1;
  }
  if(x2>xmax)
  {
      b[1]=1;
  }
  if(y2<ymin)
  {
      b[2]=1;
  }
  if(y2>ymax)
  {
      b[3]=1;
  }
  for(i=0;i<4;i++)
  {
       c[i] = a[i] && b[i];
  }
  if((c[0]==0)&&(c[1]==0)&&(c[2]==0)&&(c[3]==0))
  {
	if((a[0]==0)&&(a[1]==0)&&(a[2]==0)&&(a[3]==0)&&(b[0]==0)&&(b[1]==0)&&(b[2]==0)&&(b[3]==0))
	{
	       printf("Clipping is not required");
	       rectangle(xmin,ymin,xmax,ymax);
	       line(x1,y1,x2,y2);
	       getch();
	}
	else
	{
	       printf("Clipping is required\n");
	       rectangle(xmin,ymin,xmax,ymax);
	       setcolor(BLUE);
	       line(x1,y1,x2,y2);
	       getch();
	}
	if((a[2]==0)&&(a[3]==1))
	{
	       x1=x1+(ymin-y1)/m;
	       y1=ymin;
	}
	if((b[2]==0)&&(b[3]==1))
	{
	       x2=x2+(ymin-y2)/m;
	       y2=ymin;
	}
	if((a[2]==1)&&(a[3]==0))
	{
	       x1=x1+(ymax-y1)/m;
	       y1=ymax;
	}
	if((b[2]==1)&&(b[3]==0))
	{
	       x2=x2+(ymax-y2)/m;
	       y2=ymax;
	}
	if((a[1]==0)&&(a[0]==1))
	{
	       y1=y1+m*(xmin-x1);
	       x1=xmin;
	}
	if((b[1]==0)&&(b[0]==1))
	{
	       y2=y1+m*(xmin-x2);
	       x2=xmin;
	}
	if((a[1]==1)&&(a[0]==0))
	{
	       y1=y1+m*(xmax-x1);
	       x1=xmax;
	}
	if((b[1]==1)&&(b[0]==0))
	{
	       y2=y2+m*(xmax-x2);
	       x2=xmax;
	}
	printf("\nAfter cliping(line in green)");
	setcolor(GREEN);
	line(x1,y1,x2,y2);
  }
  else
  {
	printf("\nLine is invisible");
  }
  getch();
  closegraph();
}
