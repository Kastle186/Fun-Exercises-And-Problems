// Name: 209. Minimum Size Subarray Sum
// Topics: Array, Binary Search, Sliding Window, Prefix Sum
// Companies:
// - Expedia
// - Oracle
// - DE Shaw
// - Nvidia
// - Goldman Sachs
// - Yandex

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

int min_subarray_len(int, int *, size_t);

int main(void)
{ 
    int nums_1[] = { 2, 3, 1, 2, 4, 3 };
    int nums_2[] = { 1, 4, 4 };
    int nums_3[] = { 1, 1, 1, 1, 1, 1, 1, 1 };

    int len_to_tgt_1 = min_subarray_len(7, &nums_1[0], (size_t) 6);
    int len_to_tgt_2 = min_subarray_len(4, &nums_2[0], (size_t) 3);
    int len_to_tgt_3 = min_subarray_len(11, &nums_3[0], (size_t) 8);

    puts("209. Minimum Size Subarray Sum");
    printf("%d\n", len_to_tgt_1);
    printf("%d\n", len_to_tgt_2);
    printf("%d\n", len_to_tgt_3);

    return 0;
}

int min_subarray_len(int target, int *nums, size_t nums_size)
{
    // Base case 1: Empty array can't reach a target by definition.

    if (nums_size == 0)
        return 0;

    // Base case 2: One-element array only depends on whether said element is
    // equal or greater than the target.

    if (nums_size == 1)
        return *nums >= target ? 1 : 0;

    // Base case 3: If the first element already fulfills the target condition,
    // then there's no need to look at the rest, since 1 is the lowest possible
    // result (sans the empty or no-result cases that are 0).

    if (*nums >= target)
        return 1;

    int curr_sum = *nums;
    int curr_sub = 1;
    int smallest_sub = INT_MAX;

    size_t i = 0;
    size_t j = 1;

    // For this problem, we'll be using a sliding window approach. Grow the slice
    // until we reach the target, then shrink it while we are still above the target,
    // rinse and repeat until we reach the end of the array.

    while (j < nums_size)
    {
        // Extend the window.
        int next_sum = curr_sum + *(nums + j);
        curr_sub++;

        // Shrink the window while we still meet the target.
        while (next_sum >= target && i <= j)
        {
            smallest_sub = MIN(smallest_sub, curr_sub);
            next_sum -= *(nums + i);
            curr_sub--;
            i++;
        }

        // Update the current values accordingly.
        curr_sum = next_sum;
        j++;
    }

    return smallest_sub == INT_MAX ? 0 : smallest_sub;
}
