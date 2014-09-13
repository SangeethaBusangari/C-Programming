#include<stdio.h>
#include<stdlib.h>
#define MAX 10
typedef struct Bfsnode
{
	int vertex;
	struct Bfsnode *next;
}node;
node *head[MAX];
typedef struct que
{
	int queue[MAX];
	int front;
	int rear;
}Q;
Q q;
int n=5,visited[MAX]={0}; //initializing all visited values to false

void initialize()
{
	int i;
	for(i=0;i<n;i++)
	{
		head[i]=(node *)malloc(sizeof(node));
		head[i]->vertex=i;
		head[i]->next=NULL;
	}
}
void addToList(int v1,int v2)
{
	node *new,*p;
	new=(node *)malloc(sizeof(node));
	new->vertex=v2;
	new->next=NULL;
	p=head[v1];
	if(p->next==NULL) //if 'new' is the first adjacent node
	p->next=new;
	else
	{
		while(p->next!=NULL)
		p=p->next;
		p->next=new;
	}
}
void ListTraversal()
{
	node *t;
	int i;
	printf("\n--Printing the adjacency list--\n");
	for(i=0;i<n;i++)
	{
		printf("\n%d",head[i]->vertex);
		t=head[i]->next;
		while(t->next!=NULL)
		{
			printf("-->%d",t->vertex);
			t=t->next;
		}
		printf("-->%d",t->vertex); //printing the last adjacent node of a particular node
	}
}
void bfs(int v)
{
	int i;
	node *temp;
	q.front=-1;
	q.rear=-1;
	q.queue[++q.rear]=v; //inserting starting vertex into the queue
	while(q.front!=q.rear)
	{
		i=q.queue[++q.front]; //popping the first element from the queue and storing it in 'i'
		if(i<n && i>=0)
		{
			if(visited[i]==0) //if node not yet visited
			{
				printf("%d\n",i);
				visited[i]=1;
			}
			temp=head[i];
			while(temp!=NULL)
			{
				if(visited[temp->vertex]==0 && (!qcontains(temp->vertex))) //if node not yet visited and not present in queue
				q.queue[++q.rear]=temp->vertex; //insert the node value into queue
				temp=temp->next;
			}
		
		}
	}
}
int qcontains(int data) //checks if a particular element is already in the queue
{
	int i;
	for(i=q.front;i<=q.rear;i++) //'i' varies from front to rear
	{
		if(q.queue[i]==data) //if element found
			return 1;
		else //if not found
			return 0;
	}
}

int main(int argc, char *argv[])
{
	int i,v1,v2,v;
	FILE *fin;
	char ans;
	if(argc!=2) //if argument is not given
	{
		printf("\nImproper no of arguments. Please specify a file containing edges information as argument.");
		printf("\nNodes to be numbered starting from 0.\n\n");
		exit(0);
	}
	fin=fopen(argv[1],"r"); //opening file for reading
	initialize(); //initializes the head nodes of adjacency list
	if(fin==NULL)
	{
		printf("\nFile does not exist! Try again.\n\n");
		exit(0);
	}
	printf("\n--Reading edges information from file--\n");
	while((fscanf(fin,"%d %d\n",&v1,&v2))!=EOF) //reading each line until end of file
	{
		addToList(v1,v2); //adds edge v1-v2 to the adjacency list
	}
	ListTraversal(); //prints the adjacency list
	label: printf("\nEnter the starting vertex for BFS traversal: ");
		scanf("%d",&v);
		if(v>=0 && v<n) //if vertex given is within the proper range
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
