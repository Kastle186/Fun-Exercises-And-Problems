// Name: 2. Add Two Numbers
// Topics: Linked List, Math, Recursion
// Companies:
// - josh technology
// - Wix
// - Bloomberg
// - Microsoft
// - Amazon
// - Adobe
// - Airbnb
// - Apple
// - Google
// - Oracle
// - Uber
// - Yahoo
// - Nvidia
// - Meta
// - Intel
// - Accenture
// - Arista Networks
// - Wipro
// - EPAM Systems
// - Capgemini
// - Infosys
// - Nutanix
// - Samsung
// - Zopsmart
// - Expedia
// - Visa
// - Capital One
// - Morgan Stanley
// - TikTok
// - tcs
// - Yandex
// - Cisco
// - Walmart Labs
// - IBM
// - Salesforce
// - Goldman Sachs

#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode
{
    int val;
    struct ListNode *next;
} ListNode;

ListNode *add_two_numbers(ListNode *, ListNode *);
ListNode *number_to_linked_list(int);
void free_linked_list_memory(ListNode *);
void print_linked_list(ListNode *);

int main(void)
{
    ListNode *num_as_list_1 = number_to_linked_list(342);
    ListNode *num_as_list_2 = number_to_linked_list(465);
    ListNode *num_as_list_3 = number_to_linked_list(0);
    ListNode *num_as_list_4 = number_to_linked_list(0);
    ListNode *num_as_list_5 = number_to_linked_list(9999999);
    ListNode *num_as_list_6 = number_to_linked_list(9999);

    ListNode *sum_12 = add_two_numbers(num_as_list_1, num_as_list_2);
    ListNode *sum_34 = add_two_numbers(num_as_list_3, num_as_list_4);
    ListNode *sum_56 = add_two_numbers(num_as_list_5, num_as_list_6);

    puts("2. Add Two Numbers");
    print_linked_list(sum_12);
    print_linked_list(sum_34);
    print_linked_list(sum_56);

    free_linked_list_memory(num_as_list_1);
    free_linked_list_memory(num_as_list_2);
    free_linked_list_memory(num_as_list_3);
    free_linked_list_memory(num_as_list_4);
    free_linked_list_memory(num_as_list_5);
    free_linked_list_memory(num_as_list_6);

    free_linked_list_memory(sum_12);
    free_linked_list_memory(sum_34);
    free_linked_list_memory(sum_56);
    return 0;
}

ListNode *add_two_numbers(ListNode *lst1, ListNode *lst2)
{
    ListNode result;
    ListNode *res_ptr = &result;
    result.next = NULL;

    // Using extra pointers here to avoid losing the original references to
    // the numbers.
    ListNode *lst1_ptr = lst1;
    ListNode *lst2_ptr = lst2;
    short carry = 0;

    // To solve this problem, we basically have to explicitly do the addition
    // process as we were taught as kids, using the linked lists as our numbers.

    while (lst1_ptr != NULL || lst2_ptr != NULL || carry > 0)
    {
        int val1 = (lst1_ptr != NULL) ? lst1_ptr->val : 0;
        int val2 = (lst2_ptr != NULL) ? lst2_ptr->val : 0;
        int digit_sum = val1 + val2 + carry;

        res_ptr->next = (ListNode *) malloc(sizeof(ListNode));
        res_ptr = res_ptr->next;
        res_ptr->val = digit_sum % 10;
        res_ptr->next = NULL;

        carry = digit_sum / 10;

        if (lst1_ptr) lst1_ptr = lst1_ptr->next;
        if (lst2_ptr) lst2_ptr = lst2_ptr->next;
    }

    // Return the "next" node, as the first one is the sentinel node we were using
    // for ease of use.
    return result.next;
}

ListNode *number_to_linked_list(int num)
{
    ListNode *num_lst = NULL;
    ListNode *ptr = NULL;

    do
    {
        int digit = num % 10;
        num /= 10;

        ListNode *new_digit_node = (ListNode *) malloc(sizeof(ListNode));
        new_digit_node->val = digit;
        new_digit_node->next = NULL;

        if (num_lst == NULL)
        {
            num_lst = new_digit_node;
            ptr = new_digit_node;
        }
        else
        {
            ptr->next = new_digit_node;
            ptr = ptr->next;
        }
    } while (num > 0);

    return num_lst;
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
