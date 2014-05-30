#include <stdio.h>
#define SIZE 25
int num[SIZE];
void mergesort(int low,int high)
void merge(int low,int mid,int high)
main()
{
    int i,n;
    printf("enter number of elements\n");
    scanf("%d",&n);
    printf("enter %d elements",n);
    for(i=1;i<=n;i++)
      scanf("%d",&num[i]);
    mergesort(1,n);
    printf("After sorting\n");
    for(i=1;i<=n;i++)
    printf("%d\n",num[i]);
}
void mergesort(int low,int high)
{
  int mid;
  if(low<high)
  {
    mid=(low+high)/2;
    mergesort(low,mid);
    mergesort(low+1,high);
    merge(low,mid,high);
  }
}
void merge(int low,int mid,int high)
{
  int temp[SIZE],la,ta,k,ha;
  ta=low,la=low,ha=mid+1;
  while(la<=mid&&ha<=high)
  {
    if(mun[la]<num[ha])
      temp[ta]=num[la++];
    else
      temp[ta]=num[ha++];
    ta++;
  }
  if(la<=mid)
  {
    for(k=la;k<=mid;k++)
    {
      temp[ta++]=num[k];
    }
  }
  if(ha<=high)
  {
    for(k=ha;k<=high;k++,ta++)
      temp[ta]=num[k];
  }
    for(k=low;k<=high;k++)
      num[k]=temp[k];
}
