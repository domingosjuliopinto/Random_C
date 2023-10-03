/*
    Program to find Optimal Binary Search Tree using Dynamic Method in C
*/
#include<stdio.h>
#define MAX 10
#define IN 999
void OBST(float p[],float q[],int n);
int display(int i,int j);
float w[MAX][MAX], e[MAX][MAX];
int root[MAX][MAX];

int n;
int display(int i,int j)
{   int left,right,k;
    if((i>j)||(j==0))
	return 0;
    k=root[i][j];

    if(i<=(k-1))
    {   left=root[i][k-1];
	printf("\nLeft child of k%d=k%d",k,left);
    }
    else    printf("\nLeft child of k%d=d%d",k,k-1);
    if((k+1)<=j)
    {           right=root[k+1][j];
		printf("\nRight child of k%d=k%d",k,right);
    }
    else
	printf("\nRight child of k%d=d%d",k,j);

    display(i,k-1);
    display(k+1,j);
    return 0;
}
void main()
{

    float p[MAX], q[MAX];
    int i,j;
    clrscr();
    printf("Enter the number of keys:");
    scanf("%d",&n);
    printf("\n");
    printf("Enter the probability of keys:\n");
    for(i=1; i <= n; i++)
    {
        printf("K%d=",i);
        scanf("%f",&p[i]);
    }
    printf("\n");
    printf("Enter the Probability of dummy keys:\n");
    for(i=0; i <= n; i++)
    {
        printf("D%d=",i);
        scanf("%f",&q[i]);
    }
    OBST(p,q,n);
    printf("The estimated search cost table:for n=%d\n",n);
    for(j=n;j>=0;j--)
    {   for(i=1;i<=(n+1);i++)
        {
            if(i<=j)
                printf(" %0.2f ",e[i][j]);
        }
        printf("\n");
    }
    printf("The table w (sum of probabilities)\n");
    for(j=n;j>=0;j--)
    {   for(i=1;i<=(n+1);i++)
        {
            if(i<=j)
                printf(" %0.2f ",w[i][j]);
        }
        printf("\n");
    }
    printf("The root table\n");
    for(j=n;j>=0;j--)
    {   for(i=1;i<=(n+1);i++)
        {
            if(i<=j)
                printf(" %d ",root[i][j]);
        }
        printf("\n");
    }
    printf("\nRoot=k%d",root[1][n]);
    display (1,n);    
    getch();
        
}

void OBST(float p[MAX],float q[MAX],int n)
{
int i,j,r,l;
float t;

for(i=1;i<=(n+1);i++) 
{
    e[i][(i-1)]=q[(i-1)];
    w[i][(i-1)]=q[(i-1)];
}

for(l=1;l<=n;l++)
    for(i=1;i<=(n-l+1);i++)
    {
        j=(i+l)-1;
        e[i][j]=IN;
        w[i][j]=w[i][j-1]+p[j]+q[j];
        for(r=i;r<=j;r++)
        {
            t=e[i][(r-1)]+e[(r+1)][j]+w[i][j];
            if(t<e[i][j])
            {      
                e[i][j]=t;
                root[i][j]=r;
            }
        }
    }
    printf("Minimum estimated search cost of OBST = %0.2f\n",e[1][n]);

}
