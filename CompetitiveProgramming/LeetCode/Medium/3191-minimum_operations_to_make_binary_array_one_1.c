// Name: 3191. Minimum Operations to Make Binary Array Elements Equal to One I
// Topics: Array, Bit Manipulation, Queue, Sliding Window, Prefix Sum

#include <stdio.h>

int min_operations(int *, size_t);

int main(void)
{
    int binarr_1[] = { 0, 1, 1, 1, 0, 0 };
    int binarr_2[] = { 0, 1, 1, 1 };

    int ops_1 = min_operations(binarr_1, (size_t) 6);
    int ops_2 = min_operations(binarr_2, (size_t) 4);

    printf("%d\n", ops_1);
    printf("%d\n", ops_2);
    return 0;
}

int min_operations(int *nums, size_t nums_len)
{
    int op_count = 0;

    // To flip any element in the binary array, we have to flip it alongside the
    // two elements that come after it. So, if we slide one by one, we can ensure
    // that all the previous elements to the current one have been set to 1.

    for (int i = 0; i < nums_len - 2; i++)
    {
        if (*(nums + i) == 1)
            continue;

        nums[i] ^= 1;
        nums[i + 1] ^= 1;
        nums[i + 2] ^= 1;
        op_count++;
    }

    // Then, we check whether the last two elements are now 1's. If they are, it
    // is possible to flip the entire array to 1's. If they aren't then it is not
    // possible, as flipping them would imply reflipping previous ones, since there
    // are not enough afterwards to satisfy the 3-element constraint.

    return (*(nums + nums_len - 1) == 1) && (*(nums + nums_len - 2) == 1)
        ? op_count
        : -1;
}
