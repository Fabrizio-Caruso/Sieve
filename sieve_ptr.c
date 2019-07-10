#include <stdio.h>
#include <time.h>
 
#define SIEVE_SIZE 20000
 
typedef unsigned char uint_8;
 
uint_8 composite[SIEVE_SIZE+1];
uint_8 *primePtr;
uint_8 *compositePtr;
uint_8 *beginPtr;
uint_8 *boundPtr;
uint_8 *endPtr;

unsigned int babylonian(unsigned int n)
{
    unsigned int x,y;
    
    x = n;
    y = 1;
    while(x>y)
    {
        x = (x+y)>>1;
        y = n/x;
    }
    return x;
}
 
int main(void)
{
    clock_t Ticks, TicksDelta;
    unsigned int Sec;
    unsigned int Milli;	
	
    unsigned int bound;
    unsigned int i = 3;
    unsigned int j = 0;
    
    primePtr = composite;
    ++primePtr;
    ++primePtr;
    ++primePtr;
    compositePtr = composite;


    bound = 1+babylonian(SIEVE_SIZE);
    beginPtr = composite;
    boundPtr = &composite[bound];
    endPtr = &composite[SIEVE_SIZE];
    
    printf("\nrange: %u\n", SIEVE_SIZE);
    printf("bound: %u\n", bound);

	for(j=0;j<SIEVE_SIZE;++j)
	{
		composite[j]=0;
	}
	
    printf("\nPress enter to start\n");
    getchar();
    printf("\nComputing...\n"); 
	Ticks = clock();

    while(primePtr<boundPtr)
    {
        compositePtr = primePtr + i;
        while(compositePtr<endPtr)
        {
            *compositePtr=1;
            compositePtr+=i;
        }
		i+=2;
        primePtr = composite + i;
        while(*primePtr)
        {
			++primePtr;
            ++primePtr;
        }
        i = primePtr - beginPtr;
    }
    TicksDelta = clock() - Ticks;
    Sec = (unsigned short) (TicksDelta / CLOCKS_PER_SEC);
    Milli = ((TicksDelta % CLOCKS_PER_SEC) * 1000) / CLOCKS_PER_SEC;
    printf ("Time used: %u.%03u seconds = %u ticks\n", Sec, Milli, (unsigned short) TicksDelta);    
     	
    printf("Press enter to print the prime numbers\n");
    getchar(); 
    printf("\n");
	printf(" 2 ");
    j = 1;
    for(i=3;i<SIEVE_SIZE;i+=2)
    {
        if(!composite[i])
        {
             printf(" %u ", i);
             ++j;
        }
    }
    printf("\n");
    printf("\n Primes found: %u\n", j);
 
    return 0;
}