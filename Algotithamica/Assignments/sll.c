/*program no:01
Descrption:Single linked list insertion, deletion and traversal.
version no:01
Author:Busangari Sangeetha
Date:09-06-2015*/

#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};

int traversal(struct node *head)
{
	struct node *current=head;
	int count=0;
	if(head==NULL)
		printf("List is empty\n");
	while(current!=NULL)
	{
		++count;
		printf("%d--> ",current->data);
		current=current->next;
	}
	return count;
}

void insert(struct node **head,int data,int position)
{
	int k=1;	
	struct node *p,*q,*newNode;
	newNode=(struct node *)malloc(sizeof(struct node));
	if(!newNode)
	{
		printf("insufficient memory\n");
		return;
	}
	newNode->data=data;
	p=*head;
	if(position==1)
	{
		newNode->next=p;
		*head=newNode;
	}
	else
	{
		while(p!=NULL && k<position)
		{
			k++;
			q=p;
			p=p->next;
		}
		q->next=newNode;
		newNode->next=p;
	}
}
void delete(struct node **head,int position)
{
	int k=1;
	struct node *p,*q;
	if(*head== NULL)
	{
		printf("List is empty\n");
			return;
	}
	p=*head;
	if(position==1)
	{
		*head=(*head)->next;
		free(p);
		return;
	}
	else
	{
		while((p!=NULL) && (k<position))
		{
			k++;
			q=p;
			p=p->next;
		}
		if(p==NULL)
		{
			printf("position does not exist\n");
			return;
		}
		q->next=p->next;
		free(p);
		return;
	}
}
int main(void)
{
	int ch,ele,pos;
	struct node *head=NULL;
	while(1)
	{
		printf("\n 1.Insert \n 2. Display \n 3.delete \n 4.exit\n");
		printf("Enter choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("enter element");
				scanf("%d",&ele);
				printf("enter position to insert\n");
				scanf("%d",&pos);
				insert(&head,ele,pos);
				break;
			case 2:traversal(head);	
				break;
			case 3: printf("enter position to delete\n");
				scanf("%d",&pos);
				delete(&head,pos);
				break;
			default: printf("Thank you\n");
					exit(0);
		}
	}
		
}
		
