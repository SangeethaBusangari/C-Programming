#include<stdio.h>
#define SIZE 25
int num[SIZE];
void quicksort(int,int);
int partition(int,int);
int random_number(int min,int max);
int main(void)
{
	int r,n,i,pivot,temp;
	printf("Enter the no of elements \n");
  	scanf("%d",&n);
	printf("enter %d elements\n",n);
  	for(i=0;i<n;i++)
   	scanf("%d",&num[i]);
	r=random_number(0,n-1);
	printf("pivot element position is %d \n",r);
	temp=num[r];
	num[r]=num[0];
	num[0]=temp;
	/*printf("after pivot selection:\n");
	for(i=0;i<n;i++)
	printf("%d\n",num[i]);*/
	quicksort(0,n-1);
 	printf("After sorting \n");
 	for(i=0;i<n;i++)
 	printf("%d\n",num[i]);
}
void quicksort(int low,int high)
{
 	 int p;
 	 if(low<high)
 	 {
   		 p=partition(low,high+1);
   		 quicksort(low,p-1);
   		 quicksort(p+1,high);
 	 }
}
int partition(int low,int high)
{
 	 int pivot,l,r,temp;
	 pivot=num[low];
	 l=low+1;
	 r=high-1;
 	 while(l<r)
 	 {
   		 while(num[l]<pivot && l<r)
   			 l++;
  		 while(num[r]>pivot)
   			 r--;
   		 if(l<r)
   		 {
     			 temp=num[l];
     			 num[l]=num[r];
     			 num[r]=temp;
   		 }
 	 }
 	 num[low]=num[r];
 	 num[r]=pivot;
 	 return r;
}

int random_number(int min,int max)
{
	int result=0,low=0,hi=0;
	if(min<max)
	{
		low=min;
		hi=max;
	}
	else
	{
		low=max;
		hi=min;
	}
	srand(time(NULL));
	result=(rand()%(hi-low))+1;
	return result;
}
