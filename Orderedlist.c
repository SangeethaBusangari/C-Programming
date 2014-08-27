#include<stdio.h>
#include<stdlib.h>
#define MAX 50
struct node
{
	int data;
	struct node *next;
};
struct node *head,*ptr,*p,*q=NULL;
void sort(int);
int main(int argc,char *argv[])
{
	int n;
	char s[MAX];
	FILE *fsrc,*fdst;
	if(argc!=3)
	{
		printf("\n improper no of arguments\n");
		return -1;
	}
	fsrc=fopen(argv[1],"r");
	while(fgets(s,5,fsrc)!=NULL)
	{
		n=atoi(s);
		sort(n);
	}
	printf("\nPriorities: \n");
	fdst=fopen(argv[2],"w");
	p=head;
	while(p->next!=NULL)
	{
		fprintf(fdst,"%d\n",p->data);
                printf("%d\n",p->data);
		p=p->next;
	}
	fprintf(fdst,"%d\n",p->data);
        printf("%d\n",p->data);
	return 0;
}
void sort(int n)
{	
	if(q==NULL)
	{	
		q=(struct node *)malloc(sizeof(struct node));
		q->data=n;
		q->next=NULL;
		head=q;
	}
	else
	{
		q=head;
		p=(struct node *)malloc(sizeof(struct node));
		p->data=n;
		p->next=NULL;
		if(p->data<q->data)
		{
			p->next=q;
			head=p;
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
