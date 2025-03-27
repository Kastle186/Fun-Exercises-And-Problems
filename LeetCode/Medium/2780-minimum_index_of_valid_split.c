// Name: 2780. Minimum Index of a Valid Split
// Topics: Array, Hash Table, Sorting?

#include <stdio.h>
#include <stdlib.h>

int minimum_index(int *, size_t);
int *find_dominant(int *, size_t);

int main(void)
{
    int nums_1[] = { 1, 2, 2, 2 };
    int nums_2[] = { 2, 1, 3, 1, 1, 1, 7, 1, 2, 1 };
    int nums_3[] = { 3, 3, 3, 3, 7, 2, 2 };

    int slice_1 = minimum_index(&nums_1[0], 4);
    int slice_2 = minimum_index(&nums_2[0], 10);
    int slice_3 = minimum_index(&nums_3[0], 7);

    printf("%d\n", slice_1);
    printf("%d\n", slice_2);
    printf("%d\n", slice_3);
    return 0;
}

int minimum_index(int *nums, size_t nums_size)
{
    // First of all, we have to find whether the array has a dominant element,
    // and which one it is, if yes. If there isn't then, we can finish here.

    int *dom_elem_and_count = find_dominant(nums, nums_size);

    if (*dom_elem_and_count == -1)
    {
        free(dom_elem_and_count);
        return -1;
    }

    // If there is a dominant, we now have to check whether it is possible to split
    // the array in such a way, that both subarrays have said element as their own
    // dominant. To do this, we'll be using a variant of the prefix count algorithm.
    // We'll be counting the occurrences of the dominant in the full array. We can
    // know it will appear on both subarrays when split at a given index, if and
    // only if the following conditions are fulfilled:
    //
    // - So Far * 2 > Current Index + 1
    // - (Total - So Far) * 2 > Size - Current Index - 1

    int element = *dom_elem_and_count;
    int total = *(dom_elem_and_count + 1);
    int so_far = 0;
    int index = 0;

    for (; index < nums_size; index++)
    {
        if (*(nums + index) != element)
            continue;

        so_far++;

        if ((so_far * 2) > (index + 1)
            && ((total - so_far) * 2) > (nums_size - index - 1))
            break;
    }

    // If we got to the very end of the previous loop, then we could not find
    // a viable split.

    free(dom_elem_and_count);
    return index < nums_size ? index : -1;
}

int *find_dominant(int *nums, size_t nums_size)
{
    // We name "dominant" that one element that appears more than half the total
    // elements in an array. To find it, we'll use the Boyer-Moore Majority Voting
    // algorithm. If we can't find any, then we'll return -1.

    int votes = 0;
    int candidate = -1;

    for (int i = 0; i < nums_size; i++)
    {
        // If we have no votes, then that means we are in the search of a new
        // candidate for dominant. So, we select the next element in the array.

        if (votes == 0)
        {
            candidate = *(nums + i);
            votes = 1;
            continue;
        }

        // Otherwise, we check for the next element. If it is equal to the candidate,
        // then it gains a vote. Otherwise, it loses one. If it reaches zero, then
        // we'll have to start searching again.

        if (*(nums + i) == candidate)
            votes++;
        else
            votes--;
    }

    // We've now got the element that appears most often. Now, we have to see if
    // it fulfills the characteristic of a dominant (appear more than half elements).

    int count = 0;
    int *dominant_with_count = (int *) calloc(2, sizeof(int));

    for (int j = 0; j < nums_size; j++)
    {
        if (*(nums + j) == candidate)
            count++;
    }


    if (count > (nums_size / 2))
    {
        *dominant_with_count = candidate;
        *(dominant_with_count + 1) = count;
    }
    else
    {
        *dominant_with_count = -1;
        *(dominant_with_count + 1) = -1;
    }

    return dominant_with_count;
}
