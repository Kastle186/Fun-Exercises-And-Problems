#include <stdio.h>
#include "tools/hackerrank.h"

long sumXor(long);

int main(void)
{
    long n = parse_long(ltrim(rtrim(readline())));
    long result = sumXor(n);
    printf("%ld\n", result);
    return 0;
}

long sumXor(long n)
{
    // We can solve this exercise by counting the number of zero-bits in the number.
    // The reasoning for this is that to get the same result from the addition and
    // the xor, we have to alter the same amount of bits in each operation. If we
    // try to alter one of the set bits, the xor will just revert it to zero, while
    // the addition would also alter the following bit, and thus giving a different
    // result. With unset bits, we are guaranteed that 0 ^ 1 = 0 + 1 = 1.

    long mask = 1L;
    int unset_bits = 0;

    while (mask < n)
    {
        if ((mask & n) == 0)
            unset_bits++;

        mask <<= 1L;
    }

    // We can then calculate the total number of combinations by calculating 2 ** zeroes.
    return (1L << unset_bits);
}
