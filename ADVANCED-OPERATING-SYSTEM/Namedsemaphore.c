#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include<fcntl.h>
#include<errno.h>

#define MAXNITEMS	2000000
#define MAXNTHREADS	50
 char mutexname[] = "Mymutex1";
 char nstoredname[] = "Myname1";
int nitems;
int buff[MAXNITEMS];
struct {
  sem_t *mutex, *nstored;
  int nput;
  int nval;
} shared;

void *prod(void *), *cons(void *);

int main (int argc, char *argv[])
{
     int i, nthreads, count[MAXNTHREADS], totalsum = 0;
     pthread_t tid_prod[MAXNTHREADS], tid_cons;

     if (argc != 3) {
	  fprintf(stderr, "Usage: mutexes #items #threads\n");
	  exit(1);
     }

     if ((nitems = atoi (argv[1])) > MAXNITEMS)
	  nitems = MAXNITEMS;

     if ((nthreads = atoi (argv[2])) > MAXNTHREADS)
	  nthreads = MAXNTHREADS;

    // sem_init (&shared.mutex, 0, 1);
    // sem_init (&shared.nstored, 0, 0);
	shared.mutex=sem_open(mutexname,O_CREAT,0644,1);
	shared.nstored=sem_open(nstoredname,O_CREAT,0644,0);
	printf("\nsem_open is working correctly\n");

     for (i=0; i<nthreads; i++) {
	  count[i] = 0;
	  pthread_create(&tid_prod[i], NULL, prod, &count[i]);
		//printf("\nproducer %d created \n",i);
     }
     pthread_create(&tid_cons, NULL, cons, NULL);
	//printf("\nconsumer %d created \n",i);

     for (i=0; i<nthreads; i++) {
	  pthread_join(tid_prod[i], NULL);
	  printf("count[%d] = %d\n", i, count[i]);
	  totalsum += count[i];
     }
     printf("TOTAL: %d\n", totalsum);

     pthread_join(tid_cons, NULL);

     //sem_destroy (&shared.mutex);
    // sem_destroy (&shared.nstored);
	sem_close(shared.mutex);
	sem_close(shared.nstored);
	printf("\nsem_close working correctly\n");
	sem_unlink(mutexname);
	sem_unlink(nstoredname);
	printf("\nsem_unlink working correctly\n");
     exit(0);
}

void *prod(void *arg)
{
	int sts,spts;
     for ( ; ; ) {
	  sts=sem_trywait(shared.mutex);
	/*if (sts == 0)
	printf("\nsem_wait working correctly\n");
	else
  		perror("sem_wait() failure");*/

	  if (shared.nput >= nitems) {
	       sem_post (shared.mutex);
	       return (NULL);
	  }

	  buff[shared.nput] = shared.nval;
	  shared.nput++;
	  shared.nval++;
	  sem_post (shared.mutex); 
	  sem_post (shared.nstored);
	spts=sem_trywait(shared.mutex);
	/*if (spts == 0)
	printf("\nsem_post working correctly\n");
	else
  		perror("sem_post() failure");*/

	  *((int *) arg) += 1;
     }
}

void *cons(void *arg)
{
     int i,swt;
     
     for (i=0; i<nitems; i++) {
	  swt=sem_trywait (shared.nstored);
	/*if (swt == 0)
	printf("\nsem_wait() working correctly\n");
	else
  		perror("sem_wait() failure");*/
	  if (buff[i] != i)
	       printf("buff[%d] = %d\n", i, buff[i]);
	  
     }
     
     return(NULL);
}
