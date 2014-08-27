/*Description: Program for implementation of Doubly linked list
Name:Busangari sangeetha
Date:22-08-2014*/
#include<stdio.h>
#include<stdlib.h>
struct dnode
{
	struct dlist *prev;
	int data;
	struct dlist *next;
}
//typedef struct Queuedlist dnode;
struct dnode * head=NULL;
struct dnode * tail=NULL;
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
	tmp=(dnode*)malloc(sizeof(dnode));
	tmp->data=ele;
	tmp->prev=NULL;
	tmp->next=head;
	if(isempty())
		tail=tmp;
	else
		head->prev=tmp;
		head=tmp;
		count++;
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
			head=head->next;
			head->prev=NULL;
		}
		count--;
		printf("The node deleted is %d",tmp->data);
		free(tmp);
}
void insEnd(int ele)
{
	struct dnode *tmp;
	tmp=(dnode*)malloc9sizeof(dnode));
	tmp->data=ele;
	tmp->prev=tail;
	if(isempty())
		head=tmp;
	else
		tail->next=tmp;
		tail=tmp;
		count++;	
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
		head=tail->prev;
		tail->next=NULL;
	}	
	count--;
	printf("\n The node deleted is %d",tmp->data);
	free(tmp);
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
	if(pos>count)
	{
		printf("\n invalid position\n");
		return;
	)
	else if(pos==1)
		delBeg();
	else if(pos==count)
		delEnd();
	else
		{
			trav=head;
			for(i=1;i<pos-1;i++)
			{
				trav=tav->next;
			}
			tmp=trav->next;
			tmp->next->prev=tmp->prev;
			trav->next=tmp->next;
			count--;
			printf("\n The deleted ele at pos %d is %d\n",tmp->data,pos);
			free(tmp);
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
		insbeg(ele);
	else if(pos==count+1)
		insEnd(ele);
	else
	{
		trav=head;
		for(i=1;i<pos-1;i++)
		{
			trav=trav->next;
		}
		tmp=(dnode *)malloc(sizeof(dnode));
		tmp->data=ele;
		tmp->next=trav->next;
		tmp->prev=trav;
		tmp->next=tmp;
		tmp->next->prev=tmp;
		count++;
	}
	
}
int main(void)
{
	int ch,ele,pos;
	while(1)
	{
		printf("\n 1.INSBEG\n2.DISPLAY\n3.DELETE at Beg 4.del pos\n 5.ins pos\n 6.ins at END\n7.delete at End \n 8.exit\n");
		scanf("%d",ch);
		switch(ch)
		{
			case 1:printf("\n Enter number \n");
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
			case 5: printf("enter ele position\n");
					scanf("%d %d",&ele,&pos);
					inspos(ele,pos);
					break;
			case 6: printf("\n Enter number\n");
					scanf("%d",&ele);
					insEnd(ele);
					break;
			case 7:delEnd();
					break;
			case 8:exit(0);
					break;
		}
	}
}
