//To Implement  bezier curve
#include <stdio.h>
#include <graphics.h>
#include <math.h>

void bezier ()
{
int i , x[4],y[4];
double t,xt,yt;

printf("Enter the x and y coordinates:\n") ;
for (i=0; i<4; i++)
{
 scanf("%d%d",&x[i],&y[i]);
 putpixel (x[i], y[i], RED);

}

for (t = 0.0; t < 1.0; t += 0.0005)
{
xt = pow(1-t,3)*x[0]+3*t*pow(1-t,2)*x[1]+3*pow(t,2)*(1-t)*x[2]+pow(t,3)*x[3];
yt = pow(1-t,3)*y[0]+3*t*pow(1-t,2)*y[1]+3*pow(t,2)*(1-t)*y[2]+pow(t,3)*y[3];
putpixel (xt, yt,WHITE);
	}
}



void main()
{
int gdriver=DETECT,gmode;
initgraph (&gdriver,&gmode,"C:\\TC\\BGI");
printf("Domingos J Pinto\nSE CMPN B \nRoll No 16 \n192093\n");
bezier ();
getch();
closegraph();
}