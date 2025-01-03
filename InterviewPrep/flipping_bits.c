#include <stdio.h>
#include "tools/hackerrank.h"

#define NUM_BITS 32

long flipping_bits(long);

int main(void)
{
    int q = parse_int(ltrim(rtrim(readline())));

    for (int q_itr = 0; q_itr < q; q_itr++)
    {
        long n = parse_long(ltrim(rtrim(readline())));
        long result = flipping_bits(n);
        printf("%ld\n", result);
    }

    return 0;
}

long flipping_bits(long n)
{
    long result = 0;
    long mask = 1;

    // We start with an empty result set to 0. We also have a mask which will only
    // have one bit set at a time. By and'ing the mask and n, we can get each one
    // of its individual bits. So, we not them one by one, and then or each result
    // into our result to set its own bits.

    for (int i = 0; i < NUM_BITS; i++)
    {
        long next = n & mask;
        result |= (~next) & mask;
        mask <<= 1;
    }

    return result;
}
