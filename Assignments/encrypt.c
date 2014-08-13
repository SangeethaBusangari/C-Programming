//*program: to read text and produces encoded text by replacing each character with the character that occurs five positions later in the character set.
 * NAME: BUSANGARI SANGEETHA
 * ROLL NO:14MCMT40
 * DATE:26-07-2014*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define MAXSIZE 30
int main()
{
	char string[MAXSIZE];
	int n,count=0,key=5,array[MAXSIZE];
	printf("Enter string\n");
	scanf("%s",string);
	n=strlen(string);
	while(count<n)
	{
	   if(isalpha(string[count]))
           {
		switch(string[count])
		{

			case 'v':array[count]='a';
				 printf("%c",array[count]);
				 break;
			case 'w':array[count]='b';
				 printf("%c",array[count]);
				 break;
			case 'x':array[count]='c';
				 printf("%c",array[count]);
				 break;
			case 'y':array[count]='d';
				 printf("%c",array[count]);
				 break;
			case 'z':array[count]='e';
				 printf("%c",array[count]);
				 break;
			case 'V':array[count]='A';
				 printf("%c",array[count]);
				 break;
			case 'W':array[count]='B';
				 printf("%c",array[count]);
				 break;
			case 'X':array[count]='C';
				 printf("%c",array[count]);
				 break;
			case 'Y':array[count]='D';
				 printf("%c",array[count]);
				 break;
			case 'Z':array[count]='E';
				 printf("%c",array[count]);
				 break;
			default:array[count]=string[count]+key;		
				printf("%c",array[count]);
		}
		++count;
	   }
	   else
           {
		 printf("\nenter only charecters\n");
		 return -1;
	   }
	}
	
}
