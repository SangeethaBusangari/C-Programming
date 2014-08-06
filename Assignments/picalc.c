/*Description:calulating the value of pi from the infinite seriespi=4-(4/3)+(4/5)-(4/7)+......
 * NAME: B SANGEETHA
 * ROLL NO: 14MCMT40
 * DATE:2-aug-2014*/
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int main()
{
	float pival=0;
	int count=0;
	long int i,x=500000;
	printf("****************************\n");
	printf("Number of terms\t pivalue\n");
	printf("****************************\n");
	for(i=1;i<=x;i++)
	{
		pival=pival+(pow(-1,i+1)*(4.0/(2.0*i-1.0)));
		if((int)(pival*100)==314)
		{
			if(count==0)
			{
				printf("%lu \t\t %f\n",i,pival);
				count=1;
			}
		}
		if((int)(pival*1000)==3141)
		{
			if(count==1)
			{
				printf("%lu \t\t %f\n",i,pival);
				count=2;
			}
		}
		if((int)(pival*10000)==31415)
		{
			if(count==2)
			{
				printf("%lu \t\t %f\n",i,pival);
				count=3;
			}
		}
		if((long int)(pival*100000)==314159)
		{
			if(count==3)
			{
				printf("%lu \t\t %f\n",i,pival);
				break;
			}
		}
	}
	printf("*****************************\n");
	return 0;
}

