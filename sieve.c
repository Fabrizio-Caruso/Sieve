#include <stdio.h>
#include <time.h>
 
#define SIEVE_SIZE 500
 
typedef unsigned char uint_8;
 
uint_8 sieve[SIEVE_SIZE];
 
int main(void)
{
    clock_t Ticks, TicksDelta;
    unsigned int Sec;
    unsigned int Milli;	
	
    unsigned int i = 2;
    unsigned int j = 0;

	for(j=0;j<SIEVE_SIZE;++j)
	{
		sieve[j]=0;
	}
	
    printf("\nPress enter to start\n");
    getchar();
    printf("\nComputing...\n"); 
	Ticks = clock();
    while(i<SIEVE_SIZE)
    {
        for(j=i*2;j<SIEVE_SIZE;j+=i)
        {
            sieve[j]=1;
        }
		++i;
        while(sieve[i])
        {
			++i;
        }
    }
    TicksDelta = clock() - Ticks;
    Sec = (unsigned short) (TicksDelta / CLOCKS_PER_SEC);
    Milli = ((TicksDelta % CLOCKS_PER_SEC) * 1000) / CLOCKS_PER_SEC;
    printf ("Time used: %u.%03u seconds = %u ticks\n", Sec, Milli, (unsigned short) TicksDelta);    
     	
    printf("Press enter to print the triples\n");
    getchar(); 
    printf("\n");
	printf(" 2 ");
    for(i=3;i<SIEVE_SIZE;i+=2)
    {
        if(!sieve[i])
        {
             printf(" %u ", i);
        }
    }
    printf("\n");
 
    return 0;
}