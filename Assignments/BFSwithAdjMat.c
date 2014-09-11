#include<stdio.h>
#include<stdlib.h>
#define MAX 100
#define initial 1
#define waiting 2
#define visited  3
int n; //number of vertices in the graph
int adj[MAX][MAX];
int state[3];
void create_graph();
void BF_Traversal();
void BFS(int v);
int queue[MAX],front=-1,rear=-1;
void insert_queue(int vertex);
int delete_queue();
int isEmpty_queue();
main()
{
	create_graph();
	BF_Traversal();
}
void BF_Traversal()
{
	int v;
	for(v=1;v<=n;v++)
		state[v]=initial;
	printf("Enter starting vertex for Breadth first search:");
	scanf("%d",&v);
	BFS(v);
	for(v=1;v<=n;v++)
		if(state[v]==initial)
			BFS(v);
		printf("\n");
}
void BFS(int v)
{
	int i;
	insert_queue(v);
	state[v]=waiting;
	while(!isEmpty_queue())
	{
		v=delete_queue();
		printf("%d",v);
		state[v]=visited;
		for(i=0;i<=n;i++)
		{
			if(adj[v][i]==1 && state[i]==initial)
			{
				insert_queue(i);
				state[i]=waiting;
			}
		}
	}
	printf("\n");
}
void insert_queue(int vertex)
{
	if(rear==MAX-1)
		printf("Queue overflow\n");
	else
	{
		if(front==-1)
			front=0;
		rear=rear+1;
		queue[rear]=vertex;
	}
}
int isEmpty_queue()
{
	if(front==-1||front>rear)
	{
		return 1;
	}
	else
		return 0;
}
int delete_queue()
{
	int del_item;
	if(front==-1 || front>rear)
	{
		printf("Queue underflow\n");
		exit(1);
	}
	del_item=queue[front];
	front=front+1;
	return del_item;
}
void create_graph()
{
	int i,max_edges,origin,destin;
	printf("Enter number of vertices:");
	scanf("%d",&n);
	max_edges=n*(n-1);
	for(i=1;i<=max_edges;i++)
	{
		printf("Enter edge %d(-1 -1) to quit;",i);
		scanf("%d %d",&origin,&destin);
		if((origin==-1) && (destin==-1))
				break;
		if(origin>n||destin>n||origin<0||destin<0)
		{
			printf("Invalid edge\n");
			i--;
		}
		else
			adj[origin][destin]=1;
	}
	printf("Graph is created\n");
}

