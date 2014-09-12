/*program to implement queue using single linked list*/
#include<stdio.h>
#include<stdlib.h>
struct queueNode
{
	int data;
	struct queueNode *next;
};
typedef struct queueNode node;
node *p,*q=NULL;
node *head,*ptr,*new;
node *front=NULL;
node *rear=NULL;
int isEmpty()
{
	return (front==NULL);
}
void Enque(int ele)
{	
	if(q==NULL)
	{	
		q=(node *)malloc(sizeof(node));
		q->data=ele;
		q->next=NULL;
		front=q;
	}
	else
	{
		q=front;
		p=(node *)malloc(sizeof(node));
		p->data=ele;
		p->next=NULL;
		if(p->data<q->data)
		{
			p->next=q;
			front=p;
		}
		else if(q->data<p->data)
		{
			while(q->next!=NULL && q->next->data<p->data)
				q=q->next;
			p->next=q->next;
			q->next=p;
		}
	}
}
void Deque()
{
	node *temp;
	if(isEmpty())
	{
		printf("\n Queue is empty\n");
	}
	else
	{
		temp=front;/*saving node to be deleted*/
		front=front->next;/*deleting*/
		if(front==NULL)
			rear=NULL;
		printf("\n deleted %d\n",temp->data);
		free(temp);
	}
}
void Traversal()
{
	node *trav;
	trav=front;
	while(trav!=NULL)
	{
		printf("\n %d",trav->data);
		trav=trav->next;
	}
}

int main()
{
	int num,ch;
	while(1)
	{
		printf("1.Enque process Ids\n2.Deque\n3.Traversal\n4.isEmpty\n");
		printf(" enter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf(" enter process id into queue\n");
			       scanf("%d",&num);
			       Enque(num);
			       break;
			case 2:Deque();
			       break;
			case 3:Traversal();
			       break;
			case 4:if(isEmpty())
				       printf("\nQueue is empty\n");
			       else
				       printf("Queue is not empty\n");
					break;
			default:exit(0);
		}
	}
}
