#include<stdio.h>
#define SIZE 25
int num[SIZE];
void quicksort(int,int);
void partition(int,int);
main()
{
  int n,i,pivot;
  printf("Enter the no of elements \n");
  scanf("%d",&n);
  printf("enter %d elements",n);
  for(i=0;i<n;i++)
    scanf("%d",&num[i]);
  quicksort(0,n-1);
  printf("After sorting \n");
  for(i=0;i<n;i++)
  printf("%d",num[i]);
}
void quicksort(int low,int high)
{
  int p;
  if(low<high)
  {
    p=partition(low,high);
    quicksort(low,p-1);
    quicksort(p+1,high);
  }
}
int partition(int low,int high)
{
  int pivot,l,r,temp;
  pivot=num[low];l=low+1;r=high;
  while(l<r)
  {
    while(num[l]<pivot)
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
