/*
 * Name:BUSANGARI SANGEETHA
 * ROLL NO:14MCMT40
 * DESCRIPTION: Randomized Quicksort
 * */
#include<stdio.h>
#define SIZE 25
int num[SIZE];
int n;
void quicksort(int num[n],int low,int high)
{
 	 int p;
 	 if(low<high)
 	 {
		r=random_number(num,0,n-1);
		printf("pivot element position is %d \n",r);
		temp=num[r];
		num[r]=num[0];
		num[0]=temp;
   		p=partition(num,low,high);
   		quicksort(num,low,p-1);//left part of pivot
   		quicksort(num,p+1,high);//right part of pivot
 	 }
}
int partition(int num[n],int low,int high)
{
 	 int pivot,l,r,temp;
	 pivot=num[low];
	 l=low+1;
	 r=high;
 	 while(l<r)
 	 {
   		 while(num[l]<pivot && l<r)//finding right place fro left side for pivot
   			 l++;
  		 while(num[r]>pivot) //finding right place of pivot from right side
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
	 pivot=num[low];
 	 return r;
}

int random_number(int num[n],int min,int max)
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
	//srand(time(NULL));
	result=(rand()%(hi-low))+1;
	return result;
}

int main(void)
{
	int r,i,pivot,temp;
	printf("Enter the no of elements \n");
  	scanf("%d",&n);
	printf("enter %d elements\n",n);
  	for(i=0;i<n;i++)
   	scanf("%d",&num[i]);
	
	/*printf("after pivot selection:\n");
	for(i=0;i<n;i++)
	printf("%d\n",num[i]);*/
	quicksort(num,0,n-1);
 	printf("After sorting \n");
 	for(i=0;i<n;i++)
 	printf("%d\n",num[i]);
}
