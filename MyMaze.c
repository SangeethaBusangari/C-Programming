/*description:finding the path in maze puzzle
Name:Sangeetha Busangari
Roll no:14MCMT40*/
#include<stdio.h>
#include<stdlib.h>
int row=4,col=5;
int i,j,s,e,start,end,cell1,cell2,left,right,up,down,count=1;
int parent[19],result,unionresult=0,u,v,visited[20];
int sets[4][5]={{0,1,2,3,4},
		{5,6,7,8,9},
		{10,11,12,13,14},
		{15,16,17,18,19}}; //disjoint sets
/*int search(int cell)
{
	for(i=0;i<4;i++)
	{
		for(j=0;j<5;j++)
		{
			if(cell==sets[i][j])
			return 1;
		}
		printf("\n");
	}
	return=0;
}*/
int find(int u,int v)
{
	if(u==v)//in same set
	{
		printf("wall is removed in between the cells. both are in same set now.\n");
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
	if(cell1!=cell2||cell1!=end||cell2!=start)
	{
		if((cell2==left)||(cell2==right)||(cell2==up)||(cell2==down))
		{
			printf("it is valid  adjacent cell number\n");
			parent[cell2]=cell1;//assigning parent as one set to other
			visited[count++]=cell1;
			visited[count++]=cell2;
		}
		else
		{
			printf("entered cell number is not adjacent cell. try again with other cell number\n");
		}
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
	printf("Maze Game for 4*5 table:\n");
	for(i=0;i<4;i++)
	{
		for(j=0;j<5;j++)
		{
			printf("%d \t",sets[i][j]);
		}
		printf("\n");
	}
	for(i=0;i<=19;i++)//parent initialization
	{
		parent[i]=-1;
	}
	parent[1]=sets[0][0];
	printf("Enter starting and ending point\n");
	scanf("%d %d",&start,&end);
	//s=search(start);
	//e=search(end);
	if(start<0 || end>24)
	{
		printf("Given positions are not present in the given set\n");
		exit(0);
	} 
	//else{
	do
	{
		printf("enter cell number\n ");
		scanf("%d",&cell1);
		if(cell1<start)
		{
			printf("Enter cell number is not in a given set\n");
			exit(0);
		} 
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
		if(cell2<start)
		{
			printf("Enter cell number is not in a given set\n");
			exit(0);
		} 
		v=parent[cell2];
		result=find(u,v);
		if(result==1)//both are in same set
		{
			visited[count++]=cell1;
			visited[count++]=cell2;
		}
		else//both are in different sets
		{
			unionresult=Union(cell1,cell2);
			//printf("%d",unionresult);
		}	
	}while(unionresult!=end);
	//}else
	printf("visited boxes are\n");
	for(i=1;i<count-1;i++)
	{
		printf("visited from %d to %d\n",visited[i],visited[i+1]);
		i++;
	}
	printf("\nThank you...run again...\n\n");
}
