/*
Name:Busangari Sangeetha
Roll no:14MCMT40
Description: Set operations
****************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define SIZE 20
int uni[SIZE]={0},intersection[SIZE]={0},complement[SIZE]={0},Diff[SIZE]={0};
int universe[SIZE]={1,2,3,4,5,6,7,8,9,10};
int isDuplicate(int arr[],int number,int x);
int main()
{
	int setA[SIZE]={0},setB[SIZE]={0},num=0,flag=false;
	int i,j,number,k=0,l=0,s1,s2,check=false;
	printf("Enter SETA size\n"); 
	scanf("%d",&s1);
	
	for(i=0;i<s1;i++)
	{
		scanf("%d",&setA[i]);
		uni[l++]=setA[i];
	}

	printf("Enter SETB size\n"); 
	scanf("%d",&s2);
	for(i=0;i<s2;i++)
	{
		scanf("%d",&number);
		setB[i]=number;
		flag=isDuplicate(setA,number,s1);
		if(flag==true)
		{
			intersection[k++]=number;
		}
		else
			uni[l++]=number;
	}
	printf(" setA ={ ");
	for(i=0;i<s1;++i)
		printf("%d, ",setA[i]);
	printf("}\n");
	printf("\n setB ={ ");
	for(i=0;i<s2;++i)
		printf("%d, ",setB[i]);
	printf("}\n");
	printf("\n A intersection B ={ ");
	for(i=0;i<k;++i)
		printf("%d, ",intersection[i]);
	printf("}\n");
	printf("\n A union B ={ ");
	for(i=0;i<l;++i)
		printf("%d, ",uni[i]);
	printf("}\n");
	printf("\n A-B ={ ");
	for(i=0;i<s1;++i)
	{
		for(j=0;j<k;++j)
		{
			if(intersection[j]!=setA[i])
				printf("%d, ",setA[i]);
		}
	}
	printf("}\n");
	printf("\n A compliment ={ ");
	for(i=0;i<10;++i)
	{
		for(j=0;j<s1;++j)
		{
			if(setA[j]==universe[i])
			{
				check=true;
				break;	
			}
					
		}
		if(check==false)
			printf("%d, ",universe[i]);
		check=false;
	}
	printf("}\n");
	printf("\ndone\n");
	return 0;
}
int isDuplicate(int arr[],int number,int x)
{
	int j,k=0;
	for(j=0;j<x;++j)
	{
		if(arr[j]==number)
			return true;
	}
}
/*
mc14mt40@linux-galz:~/Desktop/semister-2/ITLAB> gcc -o setoper setoper.c 
mc14mt40@linux-galz:~/Desktop/semister-2/ITLAB> ./setoper
Enter SETA size
4
2 3 5 6
Enter SETB size
4
1 3 4 7
 setA ={ 2, 3, 5, 6, }

 setB ={ 1, 3, 4, 7, }

 A intersection B ={ 3, }

 A union B ={ 2, 3, 5, 6, 1, 4, 7, }

 A-B ={ 2, 5, 6, }

 A compliment ={ 1, 4, 7, 8, 9, 10, }

done
mc14mt40@linux-galz:~/Desktop/semister-2/ITLAB> 
*/

