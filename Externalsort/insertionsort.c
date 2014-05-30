#include<stdio.h>
#define SIZE 25
int num[SIZE];
void insertionsort(int n)
main()
{
  int i,n;
  printf("enter no of elements\n");
  scanf(%d",&n);
  printf("enter %d elements\n",n);
  for(i=0;i<n;i++)
    scanf("%d",&num[i]);
  insertionsort(n);
  printf("After sorting \n");
  for(i=0;i<n;i++)
    printf("%d",&num[i]);
}
void insertionsort(int n)
{
  int i,j,temp;
  for(i=1;i<n;i++)
  {
    temp=num[i];
    j=i;
    while(j>0 && temp<num[j-1])
    {
      num[j]=num[j-1];
      j--;
    }
    num[j]=temp;
  }
}
