// Name: 2874. Maximum Value of Ordered Triplet II
// Topics: Array
// Companies: Media.net

#include <stdio.h>

#define MAX(a, b) ((a) >= (b) ? (a) : (b))

long long maximum_triplet_value(int *, size_t);

int main(void)
{
    int nums_1[] = { 12, 6, 1, 2, 7 };
    int nums_2[] = { 1, 10, 3, 4, 19 };
    int nums_3[] = { 1, 2, 3 };

    long long triplet_1 = maximum_triplet_value(&nums_1[0], (size_t) 5);
    long long triplet_2 = maximum_triplet_value(&nums_2[0], (size_t) 5);
    long long triplet_3 = maximum_triplet_value(&nums_3[0], (size_t) 3);

    printf("%lld\n", triplet_1);
    printf("%lld\n", triplet_2);
    printf("%lld\n", triplet_3);
    return 0;
}

long long maximum_triplet_value(int *nums, size_t nums_size)
{
    // To solve this problem in linear time rather than cubic time, we will be
    // keeping track of the biggest element, biggest difference, and biggest
    // triplet results so far, in a greedy-algorithm-esque fashion. However,
    // it is important to note that the order matters.
    //
    // First, update the biggest triplet, then the element, and lastly the
    // difference. This is because since we are updating the three values with
    // each number, we can potentially end up using the same number twice or
    // thrice in our triplets operations, violating the i < j < k constraints
    // in the last element. If we follow this order, we can make sure that the
    // last element is only used to update the max triplet if fitting, and that
    // the max diff uses always the latest max element throughout the algorithm.

    long long max_elem = 0L;
    long long max_diff = 0L;
    long long max_triplet = 0L;

    for (int i = 0; i < nums_size; i++)
    {
        long long next_elem = (long long) *(nums + i);
        max_triplet = MAX(max_triplet, max_diff * next_elem);
        max_elem = MAX(max_elem, next_elem);
        max_diff = MAX(max_diff, max_elem - next_elem);
    }

    return max_triplet;
}
