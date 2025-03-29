// Name: 88. Merge Sorted Array
// Topics: Array, Two Pointers, Sorting
// Companies:
// - Meta
// - Infosys
// - Microsoft
// - Amazon
// - Bloomberg
// - EPAM Systems
// - Swiggy
// - Apple
// - Adobe
// - Accenture
// - Uber
// - Yahoo
// - Zoho
// - Ozon
// - IBM
// - PayPal
// - Palo Alto Networks
// - Yandex
// - Barclays
// - Wipro
// - tcs
// - TikTok
// - Tinkoff
// - Agoda
// - Netflix
// - ServiceNow
// - Nvidia
// - Intuit
// - LinkedIn
// - Oracle
// - Walmart Labs
// - Atlassian
// - Cisco
// - Goldman Sachs

#include <stdio.h>

void merge(int *, size_t, int, int *, size_t, int);
void print_array(int *, size_t);

int main(void)
{
    int nums_1A[] = { 1, 2, 3, 0, 0, 0 };
    int nums_1B[] = { 2, 5, 6 };

    int nums_2A[] = { 1 };
    int nums_2B[] = { };

    int nums_3A[] = { 0 };
    int nums_3B[] = { 1 };

    int nums_4A[] = { 2, 0 };
    int nums_4B[] = { 1 };

    merge(&nums_1A[0], 6, 3, &nums_1B[0], 3, 3);
    merge(&nums_2A[0], 1, 1, &nums_2B[0], 0, 0);
    merge(&nums_3A[0], 1, 0, &nums_3B[0], 1, 1);
    merge(&nums_4A[0], 2, 1, &nums_3B[0], 1, 1);

    print_array(&nums_1A[0], 6);
    print_array(&nums_2A[0], 1);
    print_array(&nums_3A[0], 1);
    print_array(&nums_4A[0], 2);

    return 0;
}

void merge(int *nums_1,
           size_t nums_1_size,
           int m,
           int *nums_2,
           size_t nums_2_size,
           int n)
{
    // If the second array is empty, then we have nothing to merge, so we can
    // finish early.

    if (n == 0)
        return ;

    // To avoid using a temp variable to solve this problem, we'll be occupying
    // three pointers. One for nums_1 elements, one for nums_2 elements, and one
    // for the extra slots in nums_1. The problem's description guarantees that
    // the first array will always have enough slots to merge with the second one.

    // If the first array only has one element, then we must not adjust for the
    // 0-based index, as that would yield an index of -1.
    int *ptr_1 = nums_1 + m - 1;
    int *ptr_2 = nums_2 + n - 1;
    int *ptr_merge = nums_1 + nums_1_size - 1;

    while (ptr_1 >= nums_1 && ptr_2 >= nums_2)
    {
        // If the second array's current element is greater than the first one's,
        // then we add it to the next empty slot. If it is less than or equal to,
        // then we do the shift with the first element. Then, we slide the pointers
        // accordingly to evaluate the next pair. We repeat until we reach the end
        // of either of the arrays.

        if (*ptr_2 > *ptr_1)
        {
            *ptr_merge = *ptr_2;
            ptr_2--;
        }
        else
        {
            *ptr_merge = *ptr_1;
            ptr_1--;
        }

        ptr_merge--;
    }

    // If we exited the previous loop because we ran out of elements of the first
    // array, but still missed some of the second, then that means those elements
    // are smaller than all of the original ones of the first array, and all of
    // the first array have already been shifted. So, we prepend them for the
    // final answer.

    while (ptr_2 >= nums_2)
    {
        *ptr_merge = *ptr_2;
        ptr_2--;
        ptr_merge--;
    }
}

void print_array(int *arr, size_t arr_size)
{
    printf("[ %d", *arr);
    for (int i = 1; i < arr_size; i++)
        printf(", %d", *(arr + i));
    printf(" ]\n");
}
