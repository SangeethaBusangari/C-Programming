/*Description: Program for implementation of Doubly linked list
Name:Busangari sangeetha
Date:22-08-2014*/
#include<stdio.h>
#include<stdlib.h>
struct dnode
{
	struct dnode *prev;
	int data;
	struct dnode *next;
};
//typedef struct dnode dnode;
struct dnode *head=NULL;
struct dnode *tail=NULL;
int count=0;

int isempty()
{
	if(head==NULL)
		return 1;
	else
		return 0;
}
void insBeg(int ele)
{
	struct dnode *tmp;
	tmp=(struct dnode*)malloc(sizeof(struct dnode));
	if(!tmp)
		printf("tmp cannot created\n");
	tmp->data=ele;
	if(head==NULL)
	{
		tmp->prev=NULL;
		tmp->next=NULL;
		head=tmp;
		tail=tmp;
	}
	else
	{
		tmp->prev=NULL;
		tmp->next=head;
		head->prev=tmp;
		head=tmp;
	}
	count++;
	printf("Count in the list is %d\n",count);
}
void delBeg()
{
	struct dnode *tmp;
	tmp=head;
	if(isempty())
	{
	printf("\n list is empty\n");
	return;
	}
	if(count==1)
	head=tail=NULL;
	else
	{
		//var=tmp;
		tmp=tmp->next;
		tmp->prev=NULL;
		free(head);
		head=tmp;
	}
	count--;
	printf("\ncount is %d \t",count);
}
void insEnd(int ele)
{
	struct dnode *tmp;
	tmp=(struct dnode*)malloc(sizeof(struct dnode));
	tmp->data=ele;
	if(head==NULL)
	{
		tmp->prev=NULL;
		tmp->next==NULL;
		head=tmp;
		tail=tmp;
	}
	else
	{
		tmp->prev=tail;
		tmp->next=NULL;
		tail->next=tmp;
		tail=tmp;;
	}
	count++;
	printf("Count in the list is %d\n",count);
}	
void delEnd()
{
	struct dnode *tmp;
	tmp=tail;
	if(isempty())
	{
		printf("\n dlist empty");
		return;
	}
	if(count==1)
		head=tail=NULL;
	else
	{
		tmp=tmp->prev;
		tmp->next=NULL;
		free(tail);
		tail=tmp;
	}			
	count--;
	//free(tmp);
	printf("count is %d \t",count);
}
void traversal()
{
	struct dnode *trav;
	printf("\n");
	if(isempty())
		printf("\n dlist is empty\n");
	else
		for(trav=head;trav!=NULL;trav=trav->next)
	printf("%d<==>",trav->data);
}
void delpos(int pos)
{
	int i;
	struct dnode *trav,*tmp;
	if(isempty())
	{
	printf("\nlist is empty");
	return;
	}
	/*if(pos>count)
	{
		printf("count is %d\n",count);
		printf("\n invalid position\n");
		return;
	}*/
	else if(pos==1)
		delBeg();
	else if(pos==count)
		delEnd();
	else
	{
		trav=head;
		for(i=1;i<pos-1;i++)
		{
			trav=trav->next;
		}
		tmp=trav->next;
		tmp->next->prev=tmp->prev;
		trav->next=tmp->next;
		count--;
		printf("\n The deleted ele at pos %d is %d\n",tmp->data,pos);
		free(tmp);
		printf("count is %d \t",count);
	}
}
void inspos(int ele,int pos)
{
	int i;
	struct dnode *trav,*tmp;
	if(pos>count+1)
	{
		printf("\n invalid position \n");
		return;
	}
	else if(pos==1)
		insBeg(ele);
	else if(pos==count+1)
		insEnd(ele);
	else
	{
		trav=head;
		for(i=1;i<pos-1;i++)
		{
			trav=trav->next;
		}
		tmp=(struct dnode *)malloc(sizeof(struct dnode));
		tmp->data=ele;
		tmp->next=trav->next;
		tmp->prev=trav;
		tmp->next=tmp;
		tmp->next->prev=tmp;
		count++;
		printf("count is %d \t",count);
	}
}
int main(void)
{
	int ch,ele,pos=1;
	while(1)
	{
		printf("\n1.INSBEG\n2.DISPLAY\n3.DELETE at Beg\n4.DELETE at  pos\n5.INSERT pos\n6.INSERT at END\n7.DELETE at End\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("\n Enter number \n");
	       			scanf("%d",&ele);
	      			insBeg(ele);
		      		break;
			case 2: traversal();
				break;
			case 3: delBeg();
				break;
			case 4: printf("\n Enter position");
				scanf("%d",&pos);
				delpos(ele);
				break;
			case 5: printf("enter element and its position\n");
				scanf("%d %d",&ele,&pos);
				inspos(ele,pos);
				break;
			case 6: printf("\n Enter number\n");
				scanf("%d",&ele);
				insEnd(ele);
				break;
			case 7: delEnd();
				break;
			default: exit(0);
				break;
			
		}
	}	
}
