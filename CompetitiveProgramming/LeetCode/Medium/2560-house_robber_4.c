// Name: 2560. House Robber IV
// Topics: Array, Binary Search

#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

// Using a macro instead of a function because why not. Let me be funny and practice
// my macros too!
#define MAX(array, length, result)       \
    do                                   \
    {                                    \
        int max_elem = -1;               \
                                         \
        for (int i = 0; i < length; i++) \
        {                                \
            int next = *(array + i);     \
                                         \
            if (next > max_elem)         \
                max_elem = next;         \
        }                                \
        (result) = max_elem;             \
    } while (0)

int min_capability(int *, size_t, int);
bool is_feasible_capability(int *, size_t, int, int);

int main(void)
{
    int houses1[] = { 2, 3, 5, 9 };
    int houses2[] = { 2, 7, 9, 3, 1 };

    int capability1 = min_capability(&houses1[0], (size_t) 4, 2);
    int capability2 = min_capability(&houses2[0], (size_t) 5, 2);

    printf("%d\n", capability1);
    printf("%d\n", capability2);
    return 0;
}

int min_capability(int *houses, size_t num_houses, int to_rob)
{
    int min_loot = 0;

    // Initializing to INT_MIN so we can catch any weird errors with the MAX macro
    // early on.
    int max_loot = INT_MIN;
    MAX(houses, num_houses, max_loot);

    // To find the answer, we will be applying binary search with a slight
    // customization. We will be testing each mid loot number to see whether it is
    // possible to rob any combination of houses yielding that result (or less).
    // And that will be the criteria to recurse/iterate the binary search, until
    // we find the minimum capability we are looking for.

    while (min_loot < max_loot)
    {
        int mid_test = (min_loot + max_loot) >> 1;

        if (is_feasible_capability(houses, num_houses, to_rob, mid_test))
            max_loot = mid_test;
        else
            min_loot = mid_test + 1;
    }

    return min_loot;
}

bool is_feasible_capability(int *houses, size_t num_houses, int to_rob, int target_cap)
{
    int total_houses = 0;
    int j = -2; // Secondary counter to keep track of the houses not being adjacent.

    for (int i = 0; i < num_houses; i++)
    {
        // If this house has a higher loot than our target, or is adjacent to the
        // previous robbed one, then we ought to skip it.

        if (target_cap < *(houses + i) || i == (j + 1))
            continue;

        total_houses++;
        j = i;
    }

    // If we were able to rob at least the required amount of houses, then this is
    // a feasible capability.
    return total_houses >= to_rob;
}
