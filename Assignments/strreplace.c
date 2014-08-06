/*Description:Read a text file containing several occurances of student and replace the word student with graduate
 * NAME:BUSANGARI SANGEETHA
 * ROLL NO:14MCMT40
 * */
#include<stdio.h>
#include<string.h>
#define MAXSIZE 2096
int main()
{
	char buffer[MAXSIZE];
	char inputfile[20];
	char *tempfile="temp.txt";
	char search[20];
	char replace[20];
	int line=0;
	FILE *input,*output;
	printf("Enter the file name\n");
	gets(inputfile);
	input=fopen(inputfile,"r");
	output=fopen(tempfile,"w");
	printf("Enter the searching string\n");
	gets(search);
	printf("Enter the string to replace\n");
	gets(replace);
	if(input==NULL)
	{
		printf("\n file not found");
		return -1;
	}
	while(fgets(buffer,2096,input)!=NULL)
	{
		char *str;
		char *start=buffer;
		while(1)
		{
			str=strstr(start,search);
			if(str==NULL)
			{
				fwrite(start,1,strlen(start),output);
				break;
			}
			fwrite(start,1,str-start,output);
			fwrite(replace,1,strlen(replace),output);
			start=str+strlen(search);
		}
		line++;
	}
	fclose(input);
	fclose(output);
	printf("open input file and see the changes\n");
	remove(inputfile);
	rename(tempfile,inputfile);
	return 0;
}

