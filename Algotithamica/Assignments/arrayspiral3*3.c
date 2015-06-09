#include<stdio.h>
int main(void)
{
	int arr[10][10];
	int r,c,i,j,k,l;
	printf("enter no of rows\n");
	scanf("%d",&r);
	printf("enter no of cols\n");
	scanf("%d",&c);
	printf("enter %d elements\n",r*c);
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			scanf("%d",&arr[i][j]);
		}
	}
	printf("Array elements are\n");
	for(i=0;i<r;i++)
	{
		printf("%d\t ",arr[0][i]);
	}
	for(j=1;j<r;j++)
		printf("%d\t",arr[j][c-1]);
	for(k=c-2;k>=0;k--)
		printf("%d \t",arr[r-1][k]);
	for(l=0;l<c-1;l++)
		printf("%d\t",arr[r-2][l]);
}
