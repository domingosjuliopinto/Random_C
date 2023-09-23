//To Implement 2D Transformations: Translation, Scaling, Rotation, Reflection, Shear
#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<math.h>
void translation()
{
    int x[50], y[50], tx, ty, n, i;
    printf("Enter the no. of sides:");
    scanf("%d",&n);
    printf("Enter co-ordinates\n ");
    for(i=0;i<n;i++) 
    {
	printf("X%d Y%d:",i+1,i+1);
        scanf("%d%d",&x[i],&y[i]);
    }
    printf("Enter tx and ty:");
    scanf("%d%d",&tx,&ty);
    setcolor(BLUE);
    for(i=0;i<n;i++)
    {
        line(x[i],y[i],x[(i+1)%n],y[(i+1)%n]);
    }
    for(i=0;i<n;i++)
    {
        x[i]=x[i]+tx;
        y[i]=y[i]+ty;
    }
    setcolor(GREEN);
    for(i=0;i<n;i++)
    {
        line(x[i],y[i],x[(i+1)%n],y[(i+1)%n]);
    }
    getch();
    closegraph();
}

void rotation()
{
  int n,i, x[10],y[10],an,a[10],b[10];
  printf("Enter the number of co-ordinate:");
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
       printf("X%d Y%d: ",i+1,i+1);
       scanf("%d%d",&x[i],&y[i]);
  }
  for(i=0;i<n;i++)
  {
       line(x[i],y[i],x[(i+1)%n],y[(i+1)%n]);
  }
  printf("Enter angle:");
  scanf("%d",&an);
  for(i=0;i<n;i++)
  {
       if(i==0)
       {
            a[i] = x[i];
            b[i] = y[i];
       }
       else
       {
            a[i] = x[i]*cos(an*3.14/180)-y[i]*sin(an*3.14/180);
            b[i] = x[i]*sin(an*3.14/180)+y[i]*cos(an*3.14/180);
       }
  } 
  setcolor(GREEN);
  for(i=0;i<n;i++)
  {
       line(a[i],b[i],a[(i+1)%n],b[(i+1)%n]);
  }
  getch();
  closegraph();
 }
 
 void scaling()
{
   int n, x[50], y[50], i, sx ,sy;
   printf("Enter no. of edges:");
   scanf("%d",&n);
   printf("Enter co-ordinates\n ");
   for(i=0;i<n;i++)
   {
      printf("X%d Y%d ",i+1,i+1);
      scanf("%d%d",&x[i],&y[i]);
   }
   printf("Enter sx and sy:");
   scanf("%d%d",&sx,&sy);
   setcolor(BLUE);
   for(i=0;i<n;i++)
   {
      line(x[i],y[i],x[(i+1)%n],y[(i+1)%n]);
   }
   for(i=0;i<n;i++)
   {
       x[i] = x[i]*sx;
       y[i] = y[i]*sy;
   }
   setcolor(GREEN);
   for(i=0;i<n;i++)
   {
      line(x[i],y[i],x[(i+1)%n],y[(i+1)%n]);
   }
   getch();
   closegraph();
}

void reflection()
{
   int n,i, x[10],y[10],a;
   char r;
    printf("Enter the number of edges:");
   scanf("%d",&n);
   printf("Enter co-ordinates\n");
   for(i=0;i<n;i++)
   {
        printf("X%d Y%d:",i+1,i+1);
	scanf("%d%d",&x[i],&y[i]);
   }
   line(320,0,320,430);
   line(0,240,640,240);
   printf("Enter the axis of reflection:\n");
   printf("Enter 1 to reflect along X \nEnter 2 to reflect along y:\n");
   scanf("%d",&a);
   setcolor(BLUE);
   for(i=0;i<n;i++)
   {
       line(x[i],y[i],x[(i+1)%n],y[(i+1)%n]);
   }
   if(a==1)
   {
      for(i=0;i<n;i++)
      {
	   x[i]=x[i]+320;
      }
      setcolor(GREEN);
      for(i=0;i<n;i++)
      {
	  line(x[i],y[i],x[(i+1)%n],y[(i+1)%n]);
      }
   }
  if(a==2);
   {
      for(i=0;i<n;i++)
      {
	   y[i]=y[i]+240;
      }
      setcolor(GREEN);
      for(i=0;i<n;i++)
      {
	  line(x[i],y[i],x[(i+1)%n],y[(i+1)%n]);
      }
   }
   getch();
   getch();
   closegraph();
}

void shearing()
{
   int n, x[50], y[50], i, s;
   int a;
   printf("Enter no. of edges:");
   scanf("%d",&n);
   printf("Enter co-ordinates\n");
   for(i=0;i<n;i++)
   {
      printf("X%d Y%d ",i+1,i+1);
      scanf("%d%d",&x[i],&y[i]);
   }
   for(i=0;i<n;i++)
   {
        line(x[i],y[i],x[(i+1)%n],y[(i+1)%n]);
   }
   printf("Enter shearing factor:");
   scanf("%d",&s);
   printf("Axis of shearing:\nEnter 1 for for shear along x\nEnter 2 for shear along y\n");
   scanf("%d",&a);
   if(a==1)
   {
       for(i=0;i<n;i++)
       {
            x[i]=x[i]+y[i]*s;
            y[i]=y[i];
       }
   }
   if(a==2)
   {
       for(i=0;i<n;i++)
       {
	    y[i]=y[i]+x[i]*s;
	    x[i]=x[i];
       }
   }
   getch();
   setcolor(GREEN);
   for(i=0;i<n;i++)
   {
        line(x[i],y[i],x[(i+1)%n],y[(i+1)%n]);
   }
   getch();
   closegraph();
}

void main()
{
	int gdriver=DETECT,gmode;
	int choice;
	initgraph(&gdriver,&gmode,"C:\\TC\\BGI"); //set your path to BGI
	printf("Domingos J Pinto\nSE CMPN B \nRoll No 16 \n192093\n");
	printf("Menu\n1-translation\t2-rotation\t3-scaling\n4-reflection\t5-shearing\n");
	printf("Enter your choice : ");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1: translation();
				break;
		case 2: rotation();
				break;
		case 3: scaling();
				break;
		case 4: reflection();
				break;
		case 5: shearing();
				break;
		default:printf("You enter wrong number");
	}
}




