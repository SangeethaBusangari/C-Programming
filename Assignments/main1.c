/*DESCRIPTION:(palindrome Tester)palindrome reads a text are phrase and finds whether it sounds same as like forward and backward. This program is to testwhether entered 5-digit number is a palindrome or not.
 * NAME   :Busangari Sangeetha
 * Roll no:14mcmt40
 * version:1.1*/

#include<stdio.h>
#include"scan.c"
#include"palindrome.h"
#include "print.h"
int main()
{
	int input=scan();
	int result=palindrome(input);
	print(input,result);
}
