#include <stdio.h>
#include <time.h>
 
#include "definitions.h"
 
typedef unsigned char uint_8;
 
uint_8 composite[SIEVE_SIZE+2] = { 0 };
uint_8 *primePtr;
uint_8 *compositePtr;
uint_8 *boundPtr;
uint_8 *endPtr;

unsigned int babylonian(unsigned int n);

void display_primes(void);
 
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
    boundPtr = &composite[bound];
    endPtr = &composite[SIEVE_SIZE];
    
    printf("\nrange: %u\n", SIEVE_SIZE);
    printf("bound: %u\n", bound);
	
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
        i = primePtr - composite;
    }
    TicksDelta = clock() - Ticks;
    Sec = (unsigned short) (TicksDelta / CLOCKS_PER_SEC);
    Milli = ((TicksDelta % CLOCKS_PER_SEC) * 1000) / CLOCKS_PER_SEC;
    printf ("Time used: %u.%03u seconds = %u ticks\n", Sec, Milli, (unsigned short) TicksDelta);    
     	
    display_primes();
 
    return 0;
}