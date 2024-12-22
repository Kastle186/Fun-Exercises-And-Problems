#include <stdio.h>
#include "linked_list.h"

void print_int(void *num_ptr)
{
    printf(" %d", *(int *) num_ptr);
}

int main(int argc, char **argv)
{
    linked_list *ints_list = create_new_linked_list();
    int nums[] = { 1, 2, 3, 4, 5, 6, 7 };
    size_t nums_count = sizeof(nums) / sizeof(nums[0]);

    puts("TESTING OUR LINKED LIST OF INTS!\n");

    for (int i = 0; i < nums_count; i++)
    {
        printf("Appending %d...\n", nums[i]);
        APPEND_TO_LIST(ints_list, nums[i], int)
    }

    printf("\nPrinting Forward: [");
    print_forward(ints_list, print_int);
    printf(" ]\n");

    printf("Printing Backward: [");
    print_backward(ints_list, print_int);
    printf(" ]\n\n");

    for (int j = 0; j < nums_count; j++)
    {
        printf("Prepending %d...\n", nums[j]);
        PREPEND_TO_LIST(ints_list, nums[j], int)
    }

    printf("\nPrinting Forward: [");
    print_forward(ints_list, print_int);
    printf(" ]\n");

    printf("Printing Backward: [");
    print_backward(ints_list, print_int);
    printf(" ]\n");

    printf("\nInserting zeroes at the start, end, and middle of our list...\n");
    INSERT_TO_LIST(ints_list, 0, 0, int)
    INSERT_TO_LIST(ints_list, 15, 0, int)
    INSERT_TO_LIST(ints_list, 8, 0, int)

    printf("\nPrinting Forward: [");
    print_forward(ints_list, print_int);
    printf(" ]\n");

    printf("Printing Backward: [");
    print_backward(ints_list, print_int);
    printf(" ]\n");

    delete_list(ints_list);
    return 0;
}
