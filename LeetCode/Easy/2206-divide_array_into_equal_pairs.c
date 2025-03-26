// Name: 2206. Divide Array Into Equal Pairs
// Topics: Array, Hash Table, Bit Manipulation, Counting

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define NUM_SLOTS 16
#define SLOT_SIZE 32 // Each slot is a 32-bit unsigned integer.

bool divide_array(int *, size_t);

int main(void)
{
    int nums1[] = { 3, 2, 3, 2, 2, 2 };
    int nums2[] = { 1, 2, 3, 4 };

    bool divisible1 = divide_array(&nums1[0], 6);
    bool divisible2 = divide_array(&nums2[0], 4);

    printf("%s\n", divisible1 ? "true" : "false");
    printf("%s\n", divisible2 ? "true" : "false");
    return 0;
}

bool divide_array(int *nums, size_t nums_size)
{
    // If the array has an uneven amount of elements, then we already know it is
    // not possible to divide it in pairs.

    if (nums_size & 1)
        return false;

    // To make this more interesting and efficient, we will be using an int array
    // that will function like a bit array to keep track of whether we have an even
    // or uneven amount of occurrences of each number.
    //
    // The problem specifies that the highest number we can find is 500. Since we are
    // using 32-bit ints for each slot of the bit array, then that means we'll need
    // to allocate 16 slots.
    //
    // NOTE: It has to be unsigned int, otherwise some C compilers will complain
    //       about using the sign bit with multiples of 31.

    unsigned int *slotted_bit_array =
        (unsigned int *) calloc(NUM_SLOTS, sizeof(unsigned int));

    // For each number in the array, we'll toggle its corresponding bit in the
    // slotted bit array to keep track of its even/uneven count.

    for (int i = 0; i < nums_size; i++)
    {
        int bit_index = *(nums + i);
        int slot = bit_index / SLOT_SIZE;
        int bit_in_slot = bit_index - (slot * SLOT_SIZE);
        slotted_bit_array[slot] ^= ((unsigned int) 1 << bit_in_slot);
    }

    // If we could form all of the pairs, then our slotted bit array should be
    // comprised of only zeroes.

    for (int j = 0; j < NUM_SLOTS; j++)
    {
        if (*(slotted_bit_array + j) != 0)
        {
            free(slotted_bit_array);
            return false;
        }
    }

    free(slotted_bit_array);
    return true;
}
