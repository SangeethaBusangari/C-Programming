/*
Name:Sangeetha Busangari
Date:22-05-2015
Description: program to find the missing element between 0 to n integers in an array
program no:2
Version:1*/

#include<stdio.h>
int cmp(const void *a, const void *b)
{
	return ( *(int *)a- *(int *)b );
}

void Findmissing(int a[], int n)
{
	int i;
	for(i=0;i<n;i++)
	{	
		if(a[i]==i)
			continue;
		else
		{
			printf("missing element is %d\n",i);
			break;
		}
	}
	
}

int main()
{
	int i=0,n=0;
	printf("Enter array size \n");
	scanf("%d",&n);

	int *a=(int*)malloc(n*sizeof(int));

	printf("Array %d elements:\n",n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	qsort(a,n,sizeof(int),cmp);
	printf("After sorting the Array\n");
	for(i=0;i<n;i++)
		printf("%d\t",a[i]);
	printf("\n");
	Findmissing(a,n);
	return 0;
}

/*
Time complexity: nlogn+n=O(nlogn);
Space complexity:constant

output:

mc14mt40@linux-biod:~/Desktop/c> gcc -o Findmissing Findmissing.c
mc14mt40@linux-biod:~/Desktop/c> ./Findmissing 
Enter array size 
5
Array 5 elements:
1
2
3
4
5
After sorting the Array
1	2	3	4	5	
missing element is 0
mc14mt40@linux-biod:~/Desktop/c> 


*/
