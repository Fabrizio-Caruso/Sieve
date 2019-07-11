#include <stdio.h>
#include <time.h> 
 
#include "definitions.h"

#if defined(EXTERN_VARS)
    #include "extern_vars.h"
#else 
    unsigned int bound;
    unsigned int i;
    unsigned int j;
#endif

 
 
typedef unsigned char uint_8;
 
uint_8 composite[ARRAY_SIZE] = { 0 };
uint_8 *primePtr;
 
unsigned int babylonian(unsigned int n);
 
void display_primes(void);

clock_t Ticks, TicksDelta;
unsigned int Sec;
unsigned int Milli; 

int main(void)
{
    bound = 1+babylonian(SIEVE_SIZE);
    i = 3;
    
    printf("\nrange: %u\n", SIEVE_SIZE);
    printf("bound: %u\n", bound);
    
    printf("\nPress enter to start\n");
    getchar();
    printf("\nComputing...\n"); 
    Ticks = clock();
    while(i<bound)
    {
        for(j=i*2;j<SIEVE_SIZE;j+=i)
        {
            composite[j]=1;
        }
        i+=2;
        primePtr = composite + i;
        while(*primePtr)
        {
			++primePtr;
            ++primePtr;
        }
        i = primePtr - composite;
    }
    TicksDelta = clock() - Ticks;
    Sec = (unsigned short) (TicksDelta / CLOCKS_PER_SEC);
    Milli = ((TicksDelta % CLOCKS_PER_SEC) * 1000) / CLOCKS_PER_SEC;
    printf ("Time used: %u.%03u seconds = %u ticks\n", Sec, Milli, (unsigned short) TicksDelta);    
        
    display_primes();
 
    return 0;
}