// Name: 27. Remove Element
// Topics: Array, Two Pointers
// Companies:
// - Adobe
// - Bloomberg
// - Yahoo
// - Uber
// - Apple
// - Microsoft
// - Amazon
// - Yandex
// - Meta
// - Accenture

#include <stdio.h>

int remove_element_slider(int *, size_t, int);
int remove_element_two_pointers(int *, size_t, int);
void print_array(int *, size_t);

int main(void)
{
    int nums_1[] = { 3, 2, 2, 3 };
    int nums_2[] = { 0, 1, 2, 2, 3, 0, 4, 2 };

    int new_size_1 = remove_element_slider(&nums_1[0], 4, 3);
    int new_size_2 = remove_element_slider(&nums_2[0], 8, 2);

    printf("%d: ", new_size_1);
    print_array(&nums_1[0], new_size_1);
    printf("%d: ", new_size_2);
    print_array(&nums_2[0], new_size_2);

    int nums_3[] = { 3, 2, 2, 3 };
    int nums_4[] = { 0, 1, 2, 2, 3, 0, 4, 2 };

    int new_size_3 = remove_element_two_pointers(&nums_3[0], 4, 3);
    int new_size_4 = remove_element_two_pointers(&nums_4[0], 8, 2);

    printf("%d: ", new_size_3);
    print_array(&nums_3[0], new_size_3);
    printf("%d: ", new_size_4);
    print_array(&nums_4[0], new_size_4);

    return 0;
}

int remove_element_slider(int *nums, size_t nums_size, int val)
{
    int removed = 0;
    int i = 0;

    // To solve this problem, we'll use a sliding-back approach to move and keep
    // the elements that don't match the requested value to remove.

    while (i < nums_size)
    {
        int next_elem = *(nums + i);

        if (next_elem == val)
        {
            // If the next element matches, then we increment the counter fo removed
            // elements and continue.
            removed++;
        }
        else
        {
            // Otherwise, we slide back the element to keep the amount of slots
            // we've "cleared" so far from removed elements.
            *(nums + i - removed) = next_elem;
        }

        i++;
    }

    // The new size is the old size minus the amount of removed elements.
    return (int) (nums_size - removed);
}

int remove_element_two_pointers(int *nums, size_t nums_size, int val)
{
    int new_size = nums_size;
    int *keep_ptr = nums;
    int *discard_ptr = nums + nums_size - 1;

    // Another approach to solve this problem is to use two pointers. We can use
    // this one when the resulting order doesn't matter. Basically, we'll send
    // to the end the elements we are removing. Since we return the new size,
    // then they won't be counted anymore.

    while (keep_ptr < discard_ptr)
    {
        // If the next element is a keep, then we just move our keep pointer forward.
        if (*keep_ptr != val)
        {
            keep_ptr++;
            continue;
        }

        // If the next element has to be discarded, we move the "discard_ptr"
        // element to "keep_ptr", and move our discard pointer backwards. We don't
        // move the keep forward to account for the case when the new element is
        // also one that ought to be removed.

        *keep_ptr = *discard_ptr;
        discard_ptr--;
        new_size--;
    }

    return new_size;
}

void print_array(int *arr, size_t size)
{
    printf("[ %d", *arr);
    for (int i = 1; i < size; i++)
        printf(", %d", *(arr + i));
    printf(" ]\n");
}
