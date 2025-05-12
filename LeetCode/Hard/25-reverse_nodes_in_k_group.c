// Name: 25. Reverse Nodes in k-Group
// Topics: Linked List, Recursion
// Companies:
// - Arista Networks
// - Snowflake
// - Commvault
// - josh technology
// - Tesla
// - Microsoft
// - Zeta
// - Capital One
// - MakeMyTrip
// - VMware
// - Qualcomm
// - Zomato
// - Autodesk
// - Infosys
// - Nutanix
// - Amazon
// - TikTok
// - Visa
// - MathWorks
// - Walmart Labs
// - Bloomberg
// - Adobe
// - DE Shaw
// - Meta
// - Apple
// - Uber
// - Yahoo

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct ListNode
{
    int val;
    struct ListNode *next;
} ListNode;

ListNode *reverse_k_group(ListNode *, int);
ListNode *array_to_list(int *, size_t);
void print_linked_list(ListNode *);
void free_linked_list_memory(ListNode *);

int main(void)
{
    int arr_1[] = { 1, 2, 3, 4, 5 };
    int arr_2[] = { 1, 2, 3, 4, 5 };

    ListNode *lst_1 = array_to_list(&arr_1[0], (size_t) 5);
    ListNode *lst_2 = array_to_list(&arr_2[0], (size_t) 5);

    ListNode *rev_chunks_1 = reverse_k_group(lst_1, 2);
    ListNode *rev_chunks_2 = reverse_k_group(lst_2, 3);

    puts("25. Reverse Nodes in k-Group");
    print_linked_list(rev_chunks_1);
    print_linked_list(rev_chunks_2);

    free_linked_list_memory(lst_1);
    free_linked_list_memory(lst_2);
    return 0;
}

ListNode *reverse_k_group(ListNode *head, int k)
{
    ListNode dummy = { 0, head };
    ListNode *k_pre = &dummy;
    ListNode *k_start = NULL;
    ListNode *k_end = head;

    while (true)
    {
        // Move forward the next K nodes. If there are less than that remaining,
        // then we are done and we return.
        for (int i = 0; i < k; i++)
        {
            if (k_end == NULL)
                return dummy.next;

            k_end = k_end->next;
        }

        k_start = k_pre->next;

        ListNode *prev = k_end;
        ListNode *curr = k_start;
        ListNode *next;

        // Reverse the segment as one would a regular linked list.
        while (curr != k_end)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        // Update the pre and end pointers for the next segment.
        k_pre->next = prev;
        k_pre = k_start;
        k_end = k_pre->next;
    }

    return dummy.next;
}

ListNode *array_to_list(int *arr, size_t arr_size)
{
    ListNode *lst = (ListNode *) malloc(sizeof(ListNode));
    ListNode *prev = lst;

    lst->val = *arr;
    lst->next = NULL;

    for (int i = 1; i < arr_size; i++)
    {
        ListNode *new_node = (ListNode *) malloc(sizeof(ListNode));
        new_node->val = *(arr + i);
        new_node->next = NULL;

        prev->next = new_node;
        prev = prev->next;
    }

    return lst;
}


void print_linked_list(ListNode *lst)
{
    ListNode *iter = lst;
    while (iter != NULL)
    {
        printf("(%d)", iter->val);
        iter = iter->next;
    }
    printf("\n");
}

void free_linked_list_memory(ListNode *lst)
{
    while (lst != NULL)
    {
        ListNode *next = lst->next;
        free(lst);
        lst = next;
    }
}
