#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
	int pid,pid1;
	char command[100];
	pid=fork();
	int p=getpid();
	if (pid>0)//parent process
	{
		sleep(1);
		waitpid(pid,NULL);
		pid1=system("pidof -s /opt/google/chrome/chrome");
		//sprintf(command,"cat /proc/%d/comm",pid1);
		//system(command);
	}
        else if(pid==0)
	{
		printf("(Child) process pid is %d and name is \n",p);
		sprintf(command,"cat /proc/%d/comm",p);
		system(command);

	}
	else
	printf("error in creating process\n");
		
}
