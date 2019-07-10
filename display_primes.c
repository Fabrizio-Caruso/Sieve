#include <stdio.h>

#include "definitions.h"

typedef unsigned char uint_8;

extern uint_8 composite[];

void display_primes(void)
{
    unsigned int i,j;
    
    printf("Press enter to print the prime numbers\n");
    getchar(); 
    printf("\n");
	printf(" 2 ");
    j = 1;
    #if defined(COMPRESSED)
        #define STEP 1
        #define START 1
    #else
        #define STEP 2
        #define START 3
    #endif
    for(i=START;i<SIEVE_SIZE;i+=STEP)
    {
        if(!composite[i])
        {
            #if defined(COMPRESSED)
                printf(" %u ", 1+(i<<1));
            #else
                printf(" %u ", i);
            #endif
            ++j;
        }
    }
    printf("\n");
    printf("\n Primes found: %u\n", j);  
    
}    
 