#include<stdio.h>
#define MAX_SIZE 100
int main()
{
	int Array[MAX_SIZE]={-1};
	int n,temp,i,j,num_of_elements=0,ch,pri;
	
	while(1)
	{
	
		printf("enter your choice\n \
			1.Submit the  process \n \ 
			2 select a process to schedule\n \
			3 display the processess prioritys\n \
		      	4.exit	\n");
		scanf("%d",&ch);
		switch(ch)
		{
			 case 1 :
			 	 printf("enter priority value \n");
		       		 scanf("%d",&pri);
		       		 if(pri<0)
		       		 {
			       		printf("priority value is not proper one ");
		       		 }
		       		 else
		       		 {
			       		insert(Array,&num_of_elements,pri);
		       		 }
		       		 break;
			 case 2 : 
				 n=delete(Array,&num_of_elements);
				 if(n>=0)
				 printf("process submitted to scheduler is %d\n",n);
		       		 break;

			case 3 :
				 display(Array,&num_of_elements);
		       		 break;

			case 4 :
				 exit(0);
		 }


	}
}

int insert(int Array[],int *n,int pri)
{
	*n=*n+1;
	Array[(*n)]=pri;
	int i=*n;
	int temp=Array[(*n)];
	while((i>1) && (Array[(i/2)]<temp))
	{
		Array[i]=Array[(i/2)];
		i=i/2;
	}
	Array[i]=temp;
	return 0;
}
	




int delete(int Array[],int *n)
{
	if(*n==0)
	{
		printf("heap is empty \n");
		return -1;
	}
	else
	{
		int temp=Array[1];
		Array[1]=Array[(*n)];
		*n=*n-1;
		Adjust(Array,1,n);
		return temp;
	}
	
}


int Adjust(int Array[],int i,int *n)
{
	int j=2*i;
	int temp=Array[i];
	while(j<=(*n))
	{
		if(j<(*n) && Array[j]<Array[j+1])
			j++;
		if(temp>=Array[j])
		break;
		Array[(j/2)]=Array[j];
		j=2*j;
	}
	Array[(j/2)]=temp;
	return 0;
}


int display(int Array[],int *n)
{
	int i;
	if(*n==0)
	{
		printf("the heap is empty \n");
		return 0;
	}
	else
	{
		for(i=1;i<=(*n);i++)
			printf("%5d",Array[i]);
			printf("\n");
	}
}
