// Name: Counting Bits
// Topics: Dynamic Programming, Bit Manipulation
// Companies:
// - Nvidia

#include <stdio.h>
#include <stdlib.h>

int *count_bits(int, size_t *);
void print_array(int *, size_t);

int main(void)
{
    size_t bits_size_1;
    size_t bits_size_2;
    size_t bits_size_3;

    int *bits_1 = count_bits(2, &bits_size_1);
    int *bits_2 = count_bits(5, &bits_size_2);
    int *bits_3 = count_bits(32, &bits_size_3);

    print_array(bits_1, bits_size_1);
    print_array(bits_2, bits_size_2);
    print_array(bits_3, bits_size_3);

    free(bits_1);
    free(bits_2);
    free(bits_3);
    return 0;
}

int *count_bits(int n, size_t *result_size)
{
    *result_size = n + 1;
    int *bit_counts = (int *) calloc(*result_size, sizeof(int));

    // Base cases to get our algorithm's foundation to work on.

    if (n == 0)
    {
        *bit_counts = 0;
        return bit_counts;
    }

    if (n == 1)
    {
        *bit_counts = 0;
        *(bit_counts + 1) = 1;
        return bit_counts;
    }

    *bit_counts = 0;
    *(bit_counts + 1) = 1;
    *(bit_counts + 2) = 1;

    if (n == 2)
    {
        return bit_counts;
    }

    int curr_pow_2 = 2;

    for (int i = 3; i <= n; i++)
    {
        // Powers of 2 have only one bit set. So, if we & them with their -1,
        // we get 0. The reason we are treating powers of 2 as a special case
        // is because they are the base of our algorithm.

        if ((i & (i - 1)) == 0)
        {
            curr_pow_2 = i;
            *(bit_counts + i) = 1;
            continue;
        }

        // At the end of the day, increasing sequences are just additions. So,
        // we fetch the amount of bits we calculated from the number we would
        // have to add to the closest power of 2, to get the current number i.
        //
        // For example, number 11:
        //
        // Closest power of 2: 8
        // Remainder: 3 -> 8 + 3 = 11
        //
        // Therefore, the number of set bits of 11 is 1 + set bits of 3, the +1
        // representing the closest power of 2, being 8 in this example.

        *(bit_counts + i) = 1 + *(bit_counts + i - curr_pow_2);
    }

    return bit_counts;
}

void print_array(int *arr, size_t len)
{
    printf("[ %d", *arr);

    for (int i = 1; i < len; i++)
    {
        printf(", %d", *(arr + i));
    }

    printf(" ]\n");
}
