// Program for bfs dfs
#include<stdio.h>
#include<conio.h>

void bfs(int adjb[10][10], int visitedb[10],int n,int startb)
{

	int queue[10],rear=-1,front=-1,i;
	queue[++rear]=startb;
	visitedb[startb]=1;
	while(rear!=front)
	{
		startb=queue[++front];
		printf("%c\t",startb+65);
		for(i=0;i<n;i++)
		{
			if(adjb[startb][i]==1&&visitedb[i]==0)
			{
				queue[++rear]=i;
				visitedb[i]=1;
			}
		}
	}
	printf("\n");
}

void dfs(int adjd[10][10], int visitedd[10],int n,int startd)
{
	int stack[10];
	int top=-1,i;
	printf("%c\t",startd+65);
	stack[++top]=startd;
	visitedd[startd]=1;
	while(top!=-1)
	{
		startd=stack[top];
		for(i=0;i<n;i++)
		{
			if(adjd[startd][i]==1&&visitedd[i]==0)
			{
				stack[++top]=i;
				printf("%c\t",i+65);
				visitedd[i]=1;
				break;
			}
		}
		if(i==n)
			top--;
	}
}

void main()
{
	int n;
	int visitedb[10]={0};
	int adj[10][10],i,j,s;
	int visitedd[10]={0};
	clrscr();
	printf("Enter number of nodes : ");
	scanf("%d",&n);
	printf("Enter the adjacency matrix:\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&adj[i][j]);
		}
	}
	printf("Enter starting node number : ");
	scanf("%d",&s);
	printf("BFS is \n");
	bfs(adj,visitedb,n,s);
	printf("DFS is \n");
	dfs(adj,visitedd,n,s);
	getch();
}