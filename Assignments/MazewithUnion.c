/*description:finding the path in maze puzzle
Name:Sangeetha Busangari
Roll no:14MCMT40*/
#include<stdio.h>
#include<stdlib.h>
int row=4,col=5;
int i,j,start,end,cell1,cell2,left,right,up,down,count=1;
int parent[19],result,unionresult=0,u,v,visited[20];
int find(int u,int v)
{
	if(u==v)
	{
		printf("No wall in between the cells. both are in same set\n");
		return 1;
	}
	else
			return 0;
	
}
int Union(int cell1,int cell2)
{
	int max;
	if(cell1<cell2)
		max=cell2;
	else
		max=cell1;
	if(cell1!=cell2&&cell1!=end&&cell2!=start)
	{
		if((cell2==left)||(cell2==right)||(cell2==up)||(cell2==down))
		{
			printf("entered valid adjacent cell number\n");
			parent[cell2]=cell1;
		}
			visited[count++]=cell1;
			visited[count++]=cell2;
			return max;
	}
	else
	{
		printf("Invalid adjacent cell number\n");
		exit(0);
	}
}
int main()
{
	int sets[4][5]={{0,1,2,3,4},
					{5,6,7,8,9},
					{10,11,12,13,14},
					{15,16,17,18,19}}; //disjoint sets
	printf("Maze Game for 4*5 table:\n");
	for(i=0;i<4;i++)
	{
		for(j=0;j<5;j++)
		{
			printf("%d \t",sets[i][j]);
		}
		printf("\n");
	}
	for(i=0;i<=15;i++)//parent initialization
	{
		parent[i]=-1;
	}
	parent[1]=sets[0][0];
	printf("Enter starting and ending point\n");
	scanf("%d %d",&start,&end);
	do
	{
		printf("enter cell number\n ");
		scanf("%d",&cell1);
	/*	if(unionresult!=cell1)
		{
			printf("invalid cell number\n");
		}*/
		u=parent[cell1];
		left=cell1-1;
		right=cell1+1;
		up=cell1-col;
		down=cell1+col;
		printf("Enter adjacent cell number\n");
		scanf("%d",&cell2);
		v=parent[cell2];
		result=find(u,v);
		if(result==1)
		{
			visited[count++]=cell1;
			visited[count++]=cell2;
		}
		else
		{
			unionresult=Union(cell1,cell2);
		}	
	}while(unionresult!=end);
	printf("visited boxes are\n");
	for(i=1;i<count;i++)
	{
		printf("%d\t",visited[i]);
	}
	printf("\nThank you...run again...\n");
}
