#include <stdio.h>
#include "heap.h"

void print_int(void *num_ptr)
{
    printf(" %d", *(int *) num_ptr);
}

int compare_ints(void *a_ptr, void *b_ptr)
{
    int a = *(int *) a_ptr;
    int b = *(int *) b_ptr;

    if (a > b) return 1;
    if (a == b) return 0;
    return -1;
}

int main(int argc, char **argv)
{
    heap *ints_max_heap = create_new_heap(10, sizeof(int), &compare_ints);
    int nums[] = { 1, 2, 3, 4, 5, 6, 7 };
    size_t nums_count = sizeof(nums) / sizeof(nums[0]);

    puts("TESTING OUR HEAP OF INTS!\n");

    for (int i = 0; i < nums_count; i++)
    {
        printf("Inserting %d...\n", nums[i]);
        INSERT_TO_HEAP(ints_max_heap, nums[i], int)
    }

    putchar('\n');
    print_heap(ints_max_heap, &print_int);
    putchar('\n');

    printf("CURRENT MAX: %d\n", *(int *) get_max(ints_max_heap));
    printf("EXTRACTED MAX: %d\n", *(int *) extract_max(ints_max_heap));
    printf("UPDATED MAX: %d\n\n", *(int *) get_max(ints_max_heap));

    print_heap(ints_max_heap, &print_int);
    putchar('\n');

    delete_heap(ints_max_heap);
    return 0;
}
