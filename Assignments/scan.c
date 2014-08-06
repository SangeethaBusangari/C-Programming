#include <stdio.h>
int scan()
{
	int number;
	printf("enter 5-digit number ex:12321,55555,34567 \n");
	scanf("%d",&number);
	if(number>9999 && number<=99999)
		//printf("vaild input is received"\n");
	return number;
	else
	{
		printf("sorry try again with a valid input\n");
	}
}
