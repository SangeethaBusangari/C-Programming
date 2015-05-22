/*
Name:Sangeetha Busangari, MTech(CS),HCU
Date:22-05-2015
Description: program to count no of consecutive zeros at beginning of an array
program no:1
Version:1*/

#include<stdio.h>
void countzeros(int a[],int n)
{
	int i,count=1;
	for(i=1;i<n;i++)
	{
		if(a[i]==0)
			++count;
		else
		{
			printf("No of consequtive zeros in the given array are: %d\n",count);
			break;
		}
	}
	
}

int main(void)
{
	int a[100],n,i,flag=0;
	printf("Enter size of array\n");
	scanf("%d",&n);
	printf("Enter array elements\n"); 
	for(i=0;i<n;i++)
	{
		printf("enter %d element :\n",i+1);
		scanf("%d",&a[i]);

		if(a[i]!=0 && flag==0)
		{
			printf("please enter consequtive zeros followed by other numbers\n");
			--i;
			continue;
		}
		flag++;
	}
	countzeros(a,n);
}
/*
mc14mt40@linux-biod:~/Desktop/c> gcc -o countzeros countZeros.c
mc14mt40@linux-biod:~/Desktop/c> ./countzeros 
Enter size of array
5
Enter array elements
enter 1 element :
7
please enter consequtive zeros followed by other numbers
enter 1 element :
0
enter 2 element :
0
enter 3 element :
0
enter 4 element :
3
enter 5 element :
4
No of consequtive zeros in the given array are: 3
mc14mt40@linux-biod:~/Desktop/c> 
*/
