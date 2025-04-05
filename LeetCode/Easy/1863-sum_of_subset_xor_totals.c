// Name: 1863. Sum of All Subset XOR Totals
// Topics: Array, Math, Backtracking, Bit Manipulation, Combinatorics, Enumeration

#include <stdio.h>

int subset_xor_sum(int *, size_t);
void gen_xor_sums(int *, size_t, int, int, int *);

int main(void)
{
    int nums_1[] = { 1, 3 };
    int nums_2[] = { 5, 1, 6 };
    int nums_3[] = { 3, 4, 5, 6, 7, 8 };

    int xors_1 = subset_xor_sum(&nums_1[0], (size_t) 2);
    int xors_2 = subset_xor_sum(&nums_2[0], (size_t) 3);
    int xors_3 = subset_xor_sum(&nums_3[0], (size_t) 6);

    printf("%d\n", xors_1);
    printf("%d\n", xors_2);
    printf("%d\n", xors_3);

    return 0;
}

int subset_xor_sum(int *nums, size_t nums_size)
{
    int xors_sum = 0;
    gen_xor_sums(nums, nums_size, 0, 0, &xors_sum);
    return xors_sum;
}

void gen_xor_sums(int *nums,
                  size_t nums_size,
                  int curr_indx,
                  int curr_xor,
                  int *result)
{
    // Add the calculated XOR of the previous subset.
    *result = *result + curr_xor;

    // Here is the core of the solution. Iterate from the current index to the
    // end of the array. The recursive calls will magically take care of "appending"
    // and "popping" the elements accordingly with the backtracking, and updating
    // the result sum in an efficient way.

    for (int i = curr_indx; i < nums_size; i++)
    {
        int next_xor = curr_xor ^ *(nums + i);
        gen_xor_sums(nums, nums_size, i + 1, next_xor, result);
    }
}
