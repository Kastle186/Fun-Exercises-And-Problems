// Name: 334. Increasing Triplet Subsequence
// Topics: Array, Greedy
// Companies:
// - MakeMyTrip
// - Coupang
// - Sprinklr
// - IBM

#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

bool has_increasing_triplet(int *, size_t);

int main(void)
{
    int arr1[] = { 1, 2, 3, 4, 5 };
    int arr2[] = { 5, 4, 3, 2, 1 };
    int arr3[] = { 2, 1, 5, 0, 4, 6 };
    int arr4[] = { 20, 100, 10, 12, 5, 13 };
    int arr5[] = { 0, 4, 2, 1, 0, -1, -3 };
    int arr6[] = { 1 };

    printf("%s\n", has_increasing_triplet(&arr1[0], 5) ? "true" : "false");
    printf("%s\n", has_increasing_triplet(&arr2[0], 5) ? "true" : "false");
    printf("%s\n", has_increasing_triplet(&arr3[0], 6) ? "true" : "false");
    printf("%s\n", has_increasing_triplet(&arr4[0], 6) ? "true" : "false");
    printf("%s\n", has_increasing_triplet(&arr5[0], 7) ? "true" : "false");
    printf("%s\n", has_increasing_triplet(&arr6[0], 1) ? "true" : "false");
    return 0;
}

bool has_increasing_triplet(int *nums, size_t nums_size)
{
    int smallest = INT_MAX;
    int second = INT_MAX;

    // We have to keep track of the smallest and second smallest numbers we've
    // seen so far.

    for (int i = 0; i < nums_size; i++)
    {
        int next = *(nums + i);

        // If the next number is larger than the second-smallest we've encountered
        // in this potential sequence, then we've found an increasing triplet
        // and we return true;

        if (next > second)
            return true;

        // Otherwise, we update the value accordingly and continue searching
        // the array for the triplet.

        if (next <= smallest)
            smallest = next;
        else if (next <= second)
            second = next;
    }

    return false;
}
