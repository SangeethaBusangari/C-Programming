/*program no:02
Descrption:Doubly linked list insertion, deletion and traversal.
version no:01
Author:Busangari Sangeetha
Date:10-06-2015*/

#include<stdio.h>
#include<stdlib.h>

struct node
{
	struct node *prev;	
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
	struct node *temp,*new;
	new=(struct node *)malloc(sizeof(struct node));
	if(!new)
	{
		printf("No memory\n");
		return;
	}
	new->data=data;
	new->next = NULL;
	new->prev = NULL;

	printf("Data inserted\n");
	if(position==1)
	{
		new->next=*head;
		//new->prev=NULL;
		printf("hi\n");
		if(*head ){
			printf("hii");
			(*head)->prev=new;
			*head=new;
			return;
		} else {
			*head = new;
			return;	
		}
	}
	temp=*head;
	while((k<position) && (temp->next!=NULL))
	{
		temp=temp->next;
		k++;
	}
	if(k!=position)
	{
		printf("no matching position exist\n");
	}
	new->next=temp->next;
	new->prev=temp;
	if(temp->next)
		temp->next->prev=new;
		temp->next=new;
	return;
}
void delete(struct node **head,int position)
{
	int k=1;
	struct node *temp,*temp1;temp=*head;
	if(*head==NULL)
	{
		printf("List is empty\n");
		return;
	}
	if(position==1)
	{
		*head=(*head)->next;
		if(*head!=NULL)
			(*head)->prev=NULL;
		free(temp);
		return;
	}
	while((k<position-1)&& temp->next!=NULL)
	{
		temp=temp->next;
		k++;
	}
	if(k!=position)
	{
		printf("no matching position exist\n");
		return;
	}
	temp1=temp->prev;
	temp1->next=temp->next;
	if(temp->next)
		temp->next->prev=temp1;
	free(temp);
	return;

}

int main(void)
{
	int ch,ele,pos,count;
	struct node *head=NULL;
	while(1)
	{
		printf("welcome to doubly linked list. do following operations:\n");
		printf("\n1.Insert \n2. Display \n3.delete \n4.exit\n");
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
			case 2:count=traversal(head);
				printf("list length is %d\n",count);	
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
