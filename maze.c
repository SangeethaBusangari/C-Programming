
/*
MAZE game
*
* void init_M() 
* void show_M() 
* void walker() 
* void walking() 

*
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LEN 10
#define MAX_STEP LEN*LEN

int M[LEN][LEN];
struct POINT {
int x,y;
} S = { 0, 0 }, E = {LEN-1,LEN-1}, G[MAX_STEP];

int G_index = 0;

void init_M()
{
	int x,y;
	time_t now = time(NULL);
	srand(now);
	for(x=0;x<LEN;x++)
	{
		for(y=0;y<LEN;y++)
		{
		
			if( (rand()%10) % 2 )
			{
				M[x][y]=0;
			}
			else
			{
				M[x][y]=1;
			}

			if(x>0 && y>0 && M[x][y]==0)
			{
	
				if( (rand()%100) >50 )
				{
					M[x][y-1]=0;	
					M[x][y+1]=0;
				}
	
				else
				{
					M[x-1][y]=0;
					M[x+1][y]=0;
				}
	
				if( M[x][y]==0 && M[x][y-1]==0 && M[x][y+1]==0 && M[x-1][y]==0 && M[x+1][y] ==0)
				{
				
					if( (rand()%100) >=75 )
					{
						M[x][y-1]=1;
					}
					
					else if ( (rand()%100) >=50 )
					{
						M[x][y+1]=1;
					}
				
					else if ( (rand()%100) >=25 )
					{
						M[x+1][y]=1;
					}
				
					else
					{
						M[x-1][y]=1;
					}
				}
			}
		}
	}
	
	S.x = rand() % (LEN/2);
	S.y = rand() % (LEN/2);
	E.x = rand() % (LEN/2)+LEN/2;
	E.y = rand() % (LEN/2)+LEN/2;
	
	M[S.x][S.y]=0;
	M[E.x][E.y]=0;
	
	M[S.x][S.y+1]=0;
	M[S.x][S.y-1]=0;
	M[S.x+1][S.y]=0;
	M[S.x-1][S.y]=0;
	M[E.x][E.y+1]=0;
	M[E.x][E.y-1]=0;
	M[E.x+1][E.y]=0;
	M[E.x-1][E.y]=0;
}

void show_M()
{
	int x,y;
	for(x=0; x<LEN; x++)
	{
		printf("---");
	}
	printf("\n");
	for(x=0;x<LEN;x++)
	{
		for(y=0;y<LEN;y++)
		{
			if( x==S.x && y==S.y)
			{
				printf(" S ");
			}
			else if( x==E.x && y==E.y)
			{
				printf(" E ");
			}
			else if(M[x][y] == 0 )
			{
				printf(" . ");
			}
			else
			{
				printf(" # ");
			}
		}
		printf("\n");
	}
}
/*
void walking()
{
	int x,y;
	for(x=0; x<LEN; x++)
	{
		printf("---");
	}
	printf("\n");
	
	for(x=0; x<LEN; x++)
	{
		for(y=0;y<LEN;y++)
		{
	
			if ( x==S.x && y==S.y )
			{
				printf(" o ");
			}
			else if ( x==E.x && y==E.y )
			{
				printf(" x ");
			}
			else if ( M[x][y] == 0 )
			{
				printf(" - ");
			}
			else if ( M[x][y] == 1 )
			{
				printf(" ");
			}
			else
			{
				printf(" > ");
			}
		}	
		printf("\n");
	}	
}
*/
void walker()
{
	struct POINT ThisStep;
	int x;
	for(x=0; x<LEN; x++)
	{
		printf("---");
	}
	printf("\n");
	printf(" Walk Direction: Right / Down / Left / Up\n");
	for(x=0; x<LEN; x++)
	{
		printf("---");
	}
	printf("\n");
	
	ThisStep = S;	
	G[G_index] = ThisStep; 
	G_index++; 
	while(G_index>=0)
	{
	
		//walking();
		G_index--;
		ThisStep = G[G_index];
		
		
		if( ThisStep.x == E.x && ThisStep.y == E.y)
		{
			break;
		}
		if( (E.x-S.x)>(LEN/2) && (E.y-S.y)<(LEN/2) )
		{
		
			if ( (ThisStep.x+1)<LEN && M[ThisStep.x+1][ThisStep.y]==0)
			{
				printf("%d: \t(%d, %d)\t\\/\t", G_index+1, ThisStep.x, ThisStep.y);
		
				ThisStep.x = ThisStep.x +1;
		
				M[ThisStep.x][ThisStep.y]--;
		
				G_index++;
				G[G_index] = ThisStep;
				printf("\t(%d, %d)\n",ThisStep.x,ThisStep.y);
		
				G_index++;
				continue;
			}
	
			if ( (ThisStep.y+1)<LEN && M[ThisStep.x][ThisStep.y+1]==0)
			{
				printf("%d: \t(%d, %d)\t->\t", G_index+1, ThisStep.x, ThisStep.y);
	
				ThisStep.y = ThisStep.y+1;
	
				M[ThisStep.x][ThisStep.y]--;
	
				G_index++;
				G[G_index] = ThisStep;
				printf("\t(%d, %d)\n",ThisStep.x,ThisStep.y);
	
				G_index++;
				continue;
			}
		}
		else
		{
		
			if ( (ThisStep.y+1)<LEN && M[ThisStep.x][ThisStep.y+1]==0)
			{
				printf("%d: \t(%d, %d)\t->\t", G_index+1, ThisStep.x, ThisStep.y);
			
				ThisStep.y = ThisStep.y+1;
			
				M[ThisStep.x][ThisStep.y]--;
			
				G_index++;
				G[G_index] = ThisStep;
				printf("\t(%d, %d)\n",ThisStep.x,ThisStep.y);
			
				G_index++;
				continue;
			}
			
			if ( (ThisStep.x+1)<LEN && M[ThisStep.x+1][ThisStep.y]==0)
			{
				printf("%d: \t(%d, %d)\t\\/\t", G_index+1, ThisStep.x, ThisStep.y);
			
				ThisStep.x = ThisStep.x +1;
				
				M[ThisStep.x][ThisStep.y]--;
			
				G_index++;
				G[G_index] = ThisStep;
				printf("\t(%d, %d)\n",ThisStep.x,ThisStep.y);
			
				G_index++;
				continue;
			}
		}
	
		if ( (ThisStep.x-1)>=0 && M[ThisStep.x-1][ThisStep.y]==0)
		{
			printf("%d: \t(%d, %d)\t<-\t", G_index+1, ThisStep.x, ThisStep.y);

			ThisStep.x = ThisStep.x-1;

			M[ThisStep.x][ThisStep.y]--;
		
			G_index++;
			G[G_index] = ThisStep;
			printf("\t(%d, %d)\n",ThisStep.x,ThisStep.y);
		
			G_index++;
			continue;
		}
	
		if( (ThisStep.y-1)>=0 && M[ThisStep.x][ThisStep.y-1]==0)
		{
			printf("%d: \t(%d, %d)\t/\\\t", G_index+1, ThisStep.x, ThisStep.y);
			
			ThisStep.y = ThisStep.y-1;
			
			M[ThisStep.x][ThisStep.y]--;
			
			G_index++;
			G[G_index] = ThisStep;
			printf("\t(%d, %d)\n",ThisStep.x,ThisStep.y);
			
			G_index++;
			continue;
		}
	}
	if(G_index==-1)
	{
		for(x=0; x<LEN; x++)
		{
			printf("---");
		}
		printf("\n");
		printf("\tNO WAY!!!\n");
	}
//	walking();
}

int main(void)
{
	init_M();
	show_M();
	walker();
}
