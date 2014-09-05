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
		head=tail=tmp;
		head->prev=tail->prev=tmp;
		head->next=tail->next=tmp;
	}
	else
	{
		tmp->prev=tail;
		tmp->next=head;
		head->prev=tmp;
		tail->next=tmp;
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
		free(tmp);
		head=head->next;
		head->prev=tail;
		tail->next=head;
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
		head=tail=tmp;
		head->prev=tail->prev=tmp;
		head->next=tail->next=tmp;
	}
	else
	{
		tmp->prev=tail;
		tail->next=tmp;
		tmp->next=head;
		tail=tail->next;
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
		free(tmp);
		tmp->next=head;
		head->prev=tail;
	}			
	count--;
	//free(tmp);
	printf("count is %d \t",count);
}
void traversal()
{
	struct dnode *trav;
	printf("\n");
	trav=head;
	int i;
	if(isempty())
		printf("\n cdllist is empty\n");
	else
		for(i=1;i<=count;i++)
		{
			printf("%d<==>",trav->data);
			trav=trav->next;
		}
}
void delpos(int pos)
{
	 printf("<count=%d>\n",count);
        struct dnode *trav=head,*p1,*p2;
        int i;
        if(head==NULL)
        {
                printf("\nQueue is underflow...");
        }
        else
        {
                if(pos==1)
                        delBeg();
                else if(pos>count)
                {
                        printf("\nInvalid entry. Exceeds the total no. of nodes in the queue");
                }
                else if(pos==count)
                        delEnd();
                else
                {
                        
                        for(i=1;i<pos;i++)
                        {
                                if(i==pos-1)
                                {
                                        p1=trav;
                                        trav=trav->next;
                                        p2=trav->next;
                                        free(trav);
                                        p1->next=p2;
                                        p2->prev=p1;
                                }
                                trav=trav->next;
                        }
                }
        }
	count--;
	printf("count is %d \t",count);
}
void inspos(int ele,int pos)
{
        printf("<count=%d>\n",count);
        int i=1;
        struct dnode *trav,*tmp,*prev;
        trav=head;
        tmp=(struct dnode *)malloc(sizeof(struct dnode));
        if(pos>count+1)
        {
                printf("\n Insertion is not possible here. Position exceeds the total no. of nodes\n");
        }
        else if(pos==count+1)
                insEnd(ele);
        else if(pos==1)
                insBeg(ele);
        else
        {
                for(i=1;i<=pos;i++)
                {
                        if(i==pos-1)
                        {
                                prev=trav->next;
                                trav->next=tmp;
                                tmp->prev=trav;
                        }
                        trav=trav->next;
                }        
                tmp->next=prev;
                prev->prev=tmp;
        }
	count++;
	printf("count is %d \t",count);
}
int main(void)
{
	int ch,ele,pos;
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
