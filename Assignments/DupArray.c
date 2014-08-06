/*Description:use a single subscripted array to aolve the following problem read in 20 numbers,each of which in between 10 and 100 inclusive as each number is read,print it only if its not a duplicate of a number already read provide for the worst case in which all 20 numbers are different.use the smallest possible array to solve this problem
 * NAME:BUSANGARI SANGEETHA
 * ROLL NO:14MCMT40
 * */
#include<stdio.h>
#include<stdbool.h>
#define SIZE 20
int isDuplicate(int arr[],int number,int x);
int main()
{
	int a[SIZE]={0},i,num=0,flag=true;
	printf("enter numbers in between 10 to 100\n");
	for(i=0;i<SIZE;++i)
	{
		printf("enter number %d \n",i+1);
		scanf("%d",&num);
		while(num<10||num>100)
		{
			printf("Invalid entry.Try again");
			scanf("%d",&num);
		}
		flag=isDuplicate(a,num,SIZE);
		if(flag!=false)
		{
			a[i]=num;
		}
		else
			--i;
	}
	printf("Array Contents are\n");
		for(i=0;i<SIZE;++i)
			printf("%d\n",a[i]);
}
int isDuplicate(int arr[],int number,int x)
{
	int j;
	for(j=0;j<x;++j)
	{
		if(arr[j]==number)
		{
			printf("entered duplicate value. try again\n");
			return false;
		}
	}
}

