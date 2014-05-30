#include<stdio.h>
#define SIZE 25
int num[SIZE];
void bubblesort(int n);
main()
{
  int i,n;
  printf("enter no of elements to sort");
  scanf("%d",&n);
  printf("Enter %d elements",n);
  for(i=0;i<n;i++)
  scanf("%d",&num[i]);
  bubblesort(n);
  printf("After sorting \n");
  for(i=0;i<n;i++)
    printf("%d\n",num[i]);
}
void bubblesort(int n)
{
  int np,nx,i,temp;
  for(np=i;np<=n-1;np++)
  {
    for(nx=0;nx<n-np;nx++)
    {
      temp=num[nx];
      num[nx]=num[nx+1];
      num[nx+1]=temp;
    }
  }
}
