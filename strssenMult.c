#include<stdio.h>
#include<stdlib.h>
#define SIZE 10
int main(void)
{
	int a[SIZE][SIZE],b[SIZE][SIZE],c[SIZE][SIZE];
	int p,q,r,s,t,u,v,i,j,row1,col1,row2,col2;
	printf("Enter no of rows for first matrix\n");
	scanf("%d",&row1);
	printf("Enter no of col for second matrix\n");
	scanf("%d",&col1);
	printf("Enter %d elements of first matrix\n",row1*col1);
	for(i=0;i<2;i++)
	 for(j=0;j<2;j++)
		scanf("%d",&a[i][j]);
	printf("Enter no of rows for second matrix\n");
	scanf("%d",&row2);
	printf("Enter no of cols for second matrix\n");
	scanf("%d",&col2);
	printf("Enter %d elements of second matrix\n",row2*col2);
	for(i=0;i<2;i++)
	 for(j=0;j<2;j++)
		scanf("%d",&b[i][j]);
	if(col1!=row2)
	{
		printf("Entered matrix indices are not correct\n");
		return -1;
	}
	printf("The first matrix is\n");
	for(i=0;i<2;i++)
	{
		printf("\n");
		for(j=0;j<2;j++)
		printf("%d\t",a[i][j]);
	}
	printf("\nThe second matrix is ]n");
	for(i=0;i<2;i++)
	{
		printf("\n");
		for(j=0;j<2;j++)
			printf("%d\t",b[i][j]);
	}
	p=(a[0][0]+a[1][1])*(b[0][0]+b[1][1]);
	q=a[1][0]+a[1][1]*b[0][0];
	r=a[0][0]*(b[0][1]-b[1][1]);
	s=a[1][1]*(b[1][0]-b[0][0]);
	t=(a[0][0]+a[0][1])*b[1][1];
	u=(a[1][0]-a[0][0])*(b[0][0]+b[0][1]);
	v=(a[0][1]-a[1][1])*(b[1][0]+b[1][1]);
	c[0][0]=p+s-t+v;
	c[0][1]=r+t;
	c[1][0]=q+s;
	c[1][1]=p+r-q+u;
	printf("\nAfter multiplication\n");
	for(i=0;i<2;i++)
	{
		printf("\n");
		for(j=0;j<2;j++)
			printf("%d\t",c[i][j]);
	}
	printf("\n");
	return 0;
}


