//To Implement Character Generation Method
#include <stdio.h>
#include <conio.h>
#include <graphics.h>
void main()
{
    int i,j,k,x,y;
    int gdriver=DETECT,gmode;//DETECT is macro defined in graphics.h
    /* ch1 ch2 ch3 ch4 are character arrays that display alphabets/number */
    int ch1[][10]={ {1,1,0,0,0,0,0,0,1,1},
                    {0,1,1,0,0,0,0,1,1,0},
                    {0,0,1,1,0,0,1,1,0,0},
                    {0,0,0,1,1,1,1,0,0,0},
					{0,0,0,0,1,1,0,0,0,0},
					{0,0,0,0,1,1,0,0,0,0},
					{0,0,0,0,1,1,0,0,0,0},
					{0,0,0,0,1,1,0,0,0,0},
					{0,0,0,0,1,1,0,0,0,0},
					{0,0,0,0,1,1,0,0,0,0}};
    int ch2[][10]={ {0,0,1,1,1,1,1,1,0,0},
					{0,1,1,1,0,0,1,1,1,0},
					{1,0,0,0,0,0,0,0,0,1},
					{1,0,0,0,0,0,0,0,0,1},
					{1,0,0,0,0,0,0,1,1,0},
					{0,0,0,0,0,0,1,1,0,0},
					{0,0,0,0,0,1,1,0,0,0},
					{0,0,0,1,1,0,0,0,0,0},
					{0,1,1,0,0,0,0,0,0,0},
					{0,1,1,1,1,1,1,1,1,1}};
    int ch3[][10]={ {1,1,1,1,1,1,1,1,1,1},
					{1,1,1,1,1,1,1,1,1,1},
					{0,0,0,0,1,1,0,0,0,0},
					{0,0,0,0,1,1,0,0,0,0},
					{0,0,0,0,1,1,0,0,0,0},
					{0,0,0,0,1,1,0,0,0,0},
					{0,0,0,0,1,1,0,0,0,0},
					{0,1,1,0,1,1,0,0,0,0},
					{0,1,1,0,1,1,0,0,0,0},
					{0,0,1,1,1,0,0,0,0,0}};
    initgraph(&gdriver,&gmode,"C:\\TC\\BGI"); //set your path to BGI
	printf("Domingos J Pinto\nSE CMPN B \nRoll No 16 \n192093\n");
    for(k=0;k<4;k++)
    {
	for(i=0;i<10;i++)
	{
	    for(j=0;j<10;j++)
	    {
		if(k==0)
		{
		    if(ch1[i][j]==1)
		    putpixel(j+250,i+230,RED);
		}
		if(k==1)
		{
		    if(ch2[i][j]==1)
                    putpixel(j+300,i+230,RED);
                }
                if(k==2)
                { 
                    if(ch3[i][j]==1)
                    putpixel(j+350,i+230,RED);
		}

            }
            delay(200);
        }
    }
    getch();
    closegraph();
}