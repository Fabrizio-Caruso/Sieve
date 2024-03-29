#include <stdio.h>
#include <time.h>
 
#include "definitions.h"
 
typedef unsigned char uint_8;
 
uint_8 composite[ARRAY_SIZE] = { 0 };

unsigned int babylonian(unsigned int n);
 
void display_primes(void);

clock_t Ticks, TicksDelta;
unsigned int Sec;
unsigned int Milli; 

#if defined(EXTERN_VARS)
    #include "extern_vars.h"
#else 
    unsigned int bound;
    unsigned int i;
    unsigned int j;
#endif

 
int main(void)
{
    i = 3;

    bound = 1+babylonian(RANGE);
    
    printf("\nrange: %u\n", RANGE);
    printf("bound: %u\n", bound);
    
    printf("\nPress enter to start\n");
    getchar();
    printf("\nComputing...\n"); 
    Ticks = clock();
    while(i<bound)
    {
        for(j=i*2;j<RANGE;j+=i)
        {
            if(j&1)
            {
                composite[j>>1]=1;
            }
        }
        i+=2;
        while(composite[i>>1])
        {
            i+=2;
        }
    }
    TicksDelta = clock() - Ticks;
    Sec = (unsigned short) (TicksDelta / CLOCKS_PER_SEC);
    Milli = ((TicksDelta % CLOCKS_PER_SEC) * 1000) / CLOCKS_PER_SEC;
    printf ("Time used: %u.%03u seconds = %u ticks\n", Sec, Milli, (unsigned short) TicksDelta);    
        
    display_primes();
 
    return 0;
}