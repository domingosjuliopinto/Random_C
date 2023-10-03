/*
Implement Prims and Kruskal’s algorithm for finding Minimum cost spanning tree using Greedy Method. 
*/
#include<stdio.h>
#include <limits.h>
#include<stdbool.h>

#define MAX 30

int V;

typedef struct edge
{
    int u,v,w;
}edge;

typedef struct edgelist
{
    edge data[MAX];
    int n;
}edgelist;

edgelist elist;
edgelist spanlist;

int minKey(int key[], int mstSet[])
{
	int v;
    // Initialize min value
    int min = INT_MAX, min_index;

    for (v = 0; v < V; v++)
	if (mstSet[v] == false && key[v] < min)
	    min = key[v], min_index = v;

    return min_index;
}

int printMST(int parent[], int graph[10][10])
{
	int sum = 0,i;
    printf("Edge \tCost\n");
    for (i = 1; i < V; i++)
    {
	printf("%d - %d \t%d \n", parent[i] + 1, i + 1, graph[i][parent[i]]);
	sum = sum + graph[i][parent[i]];
    }
    printf("Minimum Cost: %d", sum);
    return 0;
}

void prims(int graph[10][10])
{
    int parent[10];
    int key[10],count;
    int mstSet[10],i;

    for (i = 0; i < V; i++)
	key[i] = INT_MAX, mstSet[i] = false;

    key[0] = 0;
    parent[0] = -1;

    for (count = 0; count < V - 1; count++) {
	int u = minKey(key, mstSet),v;
	mstSet[u] = true;
	for (v = 0; v < V; v++)
	    if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
		parent[v] = u, key[v] = graph[u][v];
    }
    printMST(parent, graph);
}

int find(int belongs[],int vertexno)
{
    return(belongs[vertexno]);
}

void union1(int belongs[],int c1,int c2)
{
    int i;

    for(i=0;i<V;i++)
	if(belongs[i]==c2)
	    belongs[i]=c1;
}

void sort()
{
    int i,j;
    edge temp;

    for(i=1;i<elist.n;i++)
	for(j=0;j<elist.n-1;j++)
	    if(elist.data[j].w>elist.data[j+1].w)
	    {
		temp=elist.data[j];
		elist.data[j]=elist.data[j+1];
		elist.data[j+1]=temp;
	    }
}

void print()
{
    int i,cost=0;
    printf("Edge \tCost");
    for(i=0;i<spanlist.n;i++)
    {
	printf("\n%d - %d\t%d",spanlist.data[i].u+1,spanlist.data[i].v+1,spanlist.data[i].w);
	cost=cost+spanlist.data[i].w;
    }

    printf("\nCost of the spanning tree=%d",cost);
}

void kruskals(int G[10][10])
{
    int belongs[MAX],i,j,cno1,cno2;
    elist.n=0;

    for(i=1;i<V;i++)
	for(j=0;j<i;j++)
	{
	    if(G[i][j]!=0)
	    {
		elist.data[elist.n].u=i;
		elist.data[elist.n].v=j;
		elist.data[elist.n].w=G[i][j];
		elist.n++;
	    }
	}

    sort();

    for(i=0;i<V;i++)
	belongs[i]=i;

    spanlist.n=0;

    for(i=0;i<elist.n;i++)
    {
	cno1=find(belongs,elist.data[i].u);
	cno2=find(belongs,elist.data[i].v);

	if(cno1!=cno2)
	{
	    spanlist.data[spanlist.n]=elist.data[i];
	    spanlist.n=spanlist.n+1;
	    union1(belongs,cno1,cno2);
	}
    }
}

void main()
{
    int i,j,choice, graph[10][10];
    clrscr();
    printf("Enter the number of nodes: ");
    scanf("%d", &V);
    printf("Enter the adjacency matrix: ");
    for(i = 0 ; i < V ; i++)
    {
	for(j = 0 ; j < V ; j++)
	{
	    scanf("%d",  &graph[i][j]);
	}
    }
    printf("Menu:\n1.Prims\n2.Kruskals\nEnter Your choice: ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
	prims(graph);
	break;
    case 2:
	kruskals(graph);
	print();
	break;
    default:
	printf("Enter correct choice!!");
    }
    getch();

}
