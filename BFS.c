#include<stdio.h>
#include<stdlib.h>
#define N 10

typedef struct node
{
	int vertex;
	struct node *link;
}NODE;

NODE *head[N];

typedef struct que
{
	int queue[N];
	int front;
	int rear;
}Q;
Q q;

int n,visited[N]={0};   //initializing all visited values to false

void init();
void add(int,int);
void bfs(int);
void print();
int qcontains(int);

int main(int argc, char *argv[])
{
	int i,v1,v2,v;
	FILE *in;
	char ans;
	if(argc!=2)  //if argument is not given
	{
		printf("\nInvalid no. of arguments. Please specify a file containing edges information as argument.");
		printf("\nNodes to be numbered starting from 0.\n\n");
		exit(0);
	}
	in=fopen(argv[1],"r");   //opening file for reading
        printf("\nEnter the no. of nodes in the graph (nodes are numbered starting from 0): ");
        scanf("%d",&n);
        init();    //initializes the head nodes of adjacency list
	if(in==NULL)
	{
		printf("\nFile does not exist! Try again.\n\n");
		exit(0);
	}
	printf("\n--Reading edges information from file--\n");
	while((fscanf(in,"%d %d\n",&v1,&v2))!=EOF)    //reading each line until end of file
	{
		add(v1,v2);     //adds edge v1-v2 to the adjacency list
	}
	print();       //prints the adjacency list
	label: printf("\nEnter the starting vertex for BFS traversal: ");
	scanf("%d",&v);
	if(v>=0 && v<n)    //if vertex given is within the proper range
	{
		printf("\nBFS of the graph is:\n");
		bfs(v);
	}
	else
	{
		printf("\nWrong input. Node does not exist!\n");
		goto label;
	}
	return 0;
}
	
void init()
{
	int i;
	for(i=0;i<n;i++)
	{
		head[i]=(NODE *)malloc(sizeof(NODE));
		head[i]->vertex=i;    
		head[i]->link=NULL;
	}
}

void add(int v1,int v2)
{
	NODE *new,*p;
	new=(NODE *)malloc(sizeof(NODE));
	new->vertex=v2;
	new->link=NULL;
	p=head[v1];
	if(p->link==NULL)   //if 'new' is the first adjacent node
		head[v1]->link=new;
	else
	{
		while(p->link!=NULL)
			p=p->link;
		p->link=new;
	}
}

void print()
{
	NODE *t;
	int i;
	printf("\n--Printing the adjacency list--\n");
        for(i=0;i<n;i++)
        {
		printf("\n%d",head[i]->vertex);
		t=head[i]->link;
                while(t->link!=NULL)
                {
	                printf("  %d",t->vertex);
	                t=t->link;
	        }
		printf("  %d",t->vertex);   //printing the last adjacent node of a particular node
	}
}

void bfs(int v)
{
	int i;
	NODE *temp;
	q.front=-1;
	q.rear=-1;
	q.queue[++q.rear]=v;    //inserting starting vertex into the queue
	while(q.front!=q.rear)
	{
		i=q.queue[++q.front];  //popping the first element from the queue and storing it in 'i'
		if(i<n && i>=0)
		{
			if(visited[i]==0)  //if node not yet visited
			{
				printf("%d\n",i);
				visited[i]=1;
			}
			temp=head[i];
			while(temp!=NULL)  
			{
				if(visited[temp->vertex]==0 && (!qcontains(temp->vertex)))  //if node not yet visited and not present in queue
					q.queue[++q.rear]=temp->vertex;    //insert the node value into queue
				temp=temp->link;
			}
		}
	}
}

int qcontains(int data)    //checks if a particular element is already in the queue
{
	int i;
	for(i=q.front;i<=q.rear;i++)  //'i' varies from front to rear
	{
		if(q.queue[i]==data)  //if element found
			return 1;
		else                 //if not found
			return 0;
	}
}
