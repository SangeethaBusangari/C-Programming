/*DescrIption: The program takes three command line arguments. argv[1] is the name of a standard Linux command and argv[2] is a single argument to argv[1].
	       The child process executes the command with its argument. The parent outputs the time taken by the child process.
Name:	       BUSANGARI SANGEETHA
ROLL NO:       14MCMT40
PROGRAM NO:    03*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/time.h>
void main (int argc,char *argv[])
{
	pid_t pid;
	struct timeval start,end;
	double s;
	char command[50],options[10];
	if(argc!=3)//expecting command with options
	{
		printf("\nImproper number of arguements\n");
		exit(0);
	}
	if((pid=vfork())==-1)
		printf("\nerror in creating a child \n");
	else if (pid>0)//parent process
	{
		sleep(1);
		waitpid(pid,NULL);
		printf(" \ntime to run the command is %f \n", s);
	}
	else
	{  
		strcpy(command,argv[1]);//copying first argument into command
		strcat(command," ");//appending space
		strcpy(options,argv[2]);//storing options from argument2
		strcat(command,options);//combining argument with options
		gettimeofday(&start, NULL);  
		system(command);//executing complete comaand with argument
		gettimeofday(&end, NULL);
		s = end.tv_usec  - start.tv_usec; //calculating required time to execute given command	 
	}
	exit(0);
}
