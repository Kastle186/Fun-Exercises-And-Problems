// Name: 82. Remove Duplicates from Sorted List II
// Topics: Linked List, Two Pointers
// Companies:
// - Tencent
// - Bloomberg
// - Microsoft
// - Uber
// - Amazon
// - Apple
// - Google
// - Adobe

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct ListNode
{
    int val;
    struct ListNode *next;
} ListNode;

ListNode *delete_duplicates(ListNode *);
ListNode *array_to_list(int *, size_t);
void add_to_list(ListNode *, int);
void free_list(ListNode *);
void print_list(ListNode *);

int main(void)
{
    int arr_1[] = { 1, 2, 3, 3, 4, 4, 5 };
    int arr_2[] = { 1, 1, 1, 2, 3 };

    ListNode *lst_1 = array_to_list(&arr_1[0], (size_t) 7);
    ListNode *lst_2 = array_to_list(&arr_2[0], (size_t) 5);

    lst_1 = delete_duplicates(lst_1);
    lst_2 = delete_duplicates(lst_2);

    puts("82. Remove Duplicates from Sorted List II");
    print_list(lst_1);
    print_list(lst_2);

    free_list(lst_1);
    free_list(lst_2);
    return 0;
}

ListNode *delete_duplicates(ListNode *list)
{
    // Empty lists or lists with one element cannot have duplicates :)
    if (list == NULL || list->next == NULL)
        return list;

    // Dummy node mainly to handle the case where the first element is duplicated.
    ListNode prelist;
    prelist.next = list;

    ListNode *uniq_boundary = &prelist;
    ListNode *iter = list;

    // The main idea of this algorithm is to iterate through our linked list, and
    // keep track of each "range" of duplicated elements we find. Then, adjust the
    // pointers to remove them.

    while (iter != NULL)
    {
        bool found_dup = false;

        // Advance the iterator pointer until we're out of the duplicates range.
        while (iter->next != NULL && iter->val == iter->next->val)
        {
            iter = iter->next;
            found_dup = true;
        }

        // If we were in a duplicates range, then adjust the pointer from the last
        // non-repeated element to after the range to "discard" that range of nodes.
        // FIXME: Add the appropriate memory management to avoid leaks.
        if (found_dup)
            uniq_boundary->next = iter->next;
        else
            uniq_boundary = iter;

        // Move to the next node.
        iter = iter->next;
    }

    return prelist.next;
}

ListNode *array_to_list(int *arr, size_t len)
{
    ListNode *head = (ListNode *) malloc(sizeof(ListNode));
    head->val = *arr;
    head->next = NULL;

    for (int i = 1; i < len; i++)
        add_to_list(head, *(arr + i));

    return head;
}

void add_to_list(ListNode *list, int value)
{
    ListNode *list_ptr = list;

    while (list_ptr->next != NULL)
        list_ptr = list_ptr->next;

    ListNode *new_node = (ListNode *) malloc(sizeof(ListNode));
    new_node->val = value;
    new_node->next = NULL;

    list_ptr->next = new_node;
}

void free_list(ListNode *head)
{
    while (head != NULL)
    {
        ListNode *next = head->next;
        free(head);
        head = next;
    }
}

void print_list(ListNode *list)
{
    ListNode *ptr = list;

    while (ptr != NULL)
    {
        printf("(%d)", ptr->val);
        ptr = ptr->next;
    }

    printf("\n");
}
