
#define RANGE 20000u

#if defined(COMPRESSED)
    #define SIEVE_SIZE (RANGE/2)
#else
    #define SIEVE_SIZE RANGE
#endif

#define ARRAY_SIZE (SIEVE_SIZE+2)
