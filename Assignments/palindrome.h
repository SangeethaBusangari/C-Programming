#include <stdio.h>

int palindrome(int number)
{
	int rem=0,sum=0;
	int result=number;
	while(number!=0)
	{
		rem=number%10;
		sum=sum*10+rem;
		number=number/10;
	}
	return sum;
}

