#include<stdio.h>
#include<stdlib.h>
#include<semaphore.h>
#include<sys/types.h>
#include<pthread.h>
#define CUSTOMERS 15
#define MACHINES 3
#define COUNTERS 8
int produced[CUSTOMERS]={0};
int i=1;
typedef struct bank
{
	sem_t sem;
	pthread_mutex_t mutex;
}Bank;
Bank shared;
int serviced[CUSTOMERS]={0};
void *Token_machine(void *),*counter(void *);
void main()
{
	int i;
	pthread_t tid_machine[3],tid_counter[8];
	for(i=0;i<MACHINES;i++)
	{
		pthread_create(&tid_machine[i],NULL,Token_machine,NULL);
		printf("token machine %d is ON to generate tokens\n",i);
	}
	for(i=0;i<COUNTERS;i++)
	{
		pthread_create(&tid_counter[i],NULL,counter,NULL);
		printf("counter machine %d is ON to process generated tokens\n",i);
	}
	for(i=0;i<MACHINES;i++)
		pthread_join(tid_machine[i],NULL);
	for(i=0;i<COUNTERS;i++)
		pthread_join(tid_counter[i],NULL);
}
void *Token_machine(void *arg)
{
	int j;
	for(j=0;j<CUSTOMERS;j++)
	{
		pthread_mutex_lock(&shared.mutex);
		if(i>CUSTOMERS)
		{
			pthread_mutex_unlock(&shared.mutex);
			return;
		}
		else
		{
			if(i==1)
			{
				if(produced[i]!=1)//token not at generated
				{
					produced[i]=1;
					printf("token generated=%d\n",i);
					i=i+1;
					pthread_mutex_unlock(&shared.mutex);
					sem_post(&shared.sem);
					return;
				}
				else
				{
					sem_post(&shared.sem);
					pthread_mutex_unlock(&shared.mutex);
					return;
				}
			}
			else
			{
				
				if((produced[i-1]==1)&&(produced[i]!=1))//previous token generated and next token not yet generated
				{
					produced[i]=1;
					printf("token generated=%d\n",i);
					i=i+1;
					pthread_mutex_unlock(&shared.mutex);
				}
				else
				{
					 pthread_mutex_unlock(&shared.mutex);

				}
			}
		}
  		}
}
void *counter(void *arg)
{
	static int j=1;
	for(;;)
	{
		pthread_mutex_lock(&shared.mutex);
		if(j>i-1)
		{
			pthread_mutex_unlock(&shared.mutex);
			return;
		}
		else
		{
			if(j==1)
			{
				if(serviced[j]!=1) //token not at serviced
				{
					serviced[j]=1;
					printf("token serviced=%d\n",j);
					j=j+1;
					pthread_mutex_unlock(&shared.mutex);
				}
				else
				{
					pthread_mutex_unlock(&shared.mutex);
					return;
				}
			}
			else
			{
				if((serviced[j-1]==1)&&(serviced[j]!=1))//previous token serviced and next token not yet serviced
				{
					serviced[j]=1;
					printf("token serviced=%d\n",j);
					j=j+1;
					pthread_mutex_unlock(&shared.mutex);
				}
				else
				{
					pthread_mutex_unlock(&shared.mutex);
				}
			}
		}
	}
}
