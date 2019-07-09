#include <stdio.h>
#include <time.h>
 
#define RANGE 50000u
#define SIEVE_SIZE (RANGE/2)
 
typedef unsigned char uint_8;
 
uint_8 composite[SIEVE_SIZE+1];
 
int main(void)
{
    clock_t Ticks, TicksDelta;
    unsigned int Sec;
    unsigned int Milli;	
	
    unsigned int i = 3;
    unsigned int j = 0;

	for(j=0;j<SIEVE_SIZE;++j)
	{
		composite[j]=0;
	}
	
    printf("\nPress enter to start\n");
    getchar();
    printf("\nComputing...\n"); 
	Ticks = clock();
    while(i<2*SIEVE_SIZE)
    {
		// getchar();
		// printf("i : %u is prime; index at %u\n", i, i>>1);
        for(j=i*2;j<2*SIEVE_SIZE;j+=i)
        {
            if(j&1)
			{
				// printf("j: %u is composite; index at %u\n", j, j>>1);
				composite[j>>1]=1;
			}
        }
		i+=1;
        while(composite[i>>1])
        {
			i+=1;
        }
		if(!(i&1))
		{
			++i;
		}
    }
    TicksDelta = clock() - Ticks;
    Sec = (unsigned short) (TicksDelta / CLOCKS_PER_SEC);
    Milli = ((TicksDelta % CLOCKS_PER_SEC) * 1000) / CLOCKS_PER_SEC;
    printf ("Time used: %u.%03u seconds = %u ticks\n", Sec, Milli, (unsigned short) TicksDelta);    
     	
    printf("Press enter to print the prime numbers\n");
    getchar(); 
    printf("\n");
	printf(" 2 ");
    for(i=1;i<SIEVE_SIZE;++i)
    {
        if(!composite[i])
        {
             printf(" %u ", 1+(i<<1));
        }
    }
    printf("\n");
 
    return 0;
}