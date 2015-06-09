#include<stdio.h>
#include<string.h>

int main(void)
{
	int T[]={15,20,22,25,30},S[]={10,19,20,23,24,30};
	int k,l;
	for(k=4,l=5;k>=0 && l>=0;k--,l--)
	{
		if(T[k]<=S[l])
		{
			printf("[%d %d]",T[k],S[l]);
			continue;
		}
		else
		{
			k++;
			l+=2;
		}
	}
}
