#include "linked_list.h"

linked_list *create_new_linked_list()
{
    linked_list *new_list_obj = malloc(sizeof(linked_list));
    new_list_obj->head = NULL;
    new_list_obj->tail = NULL;
    new_list_obj->size = 0;
    return new_list_obj;
}

list_node *create_new_node(void *data, size_t type_size)
{
    list_node *new_node = malloc(sizeof(list_node));

    // Allocate memory for the data's pointer and initialize its next and previous
    // pointers to NULL.

    new_node->data = malloc(type_size);
    new_node->next = NULL;
    new_node->prev = NULL;

    // Copy the value of data into our new node.
    memcpy(new_node->data, data, type_size);

    return new_node;
}

void append_to_list(linked_list *list, void *data, size_t type_size)
{
    list_node *new_node = create_new_node(data, type_size);

    // If we're adding at the end of the list, then the former list tail and the
    // new node point to each other. Thus, the new node effectively becomes the
    // list's new tail.

    if (list->size == 0)
    {
        // If the list is empty, then the new node will become the only node it
        // contains, and therefore its head and its tail both.
        list->head = new_node;
        list->tail = new_node;
    }
    else
    {
        list->tail->next = new_node;
        new_node->prev = list->tail;
        list->tail = list->tail->next;
    }

    list->size++;
}

void prepend_to_list(linked_list *list, void *data, size_t type_size)
{
    list_node *new_node = create_new_node(data, type_size);

    // If we're adding at the beginning of the list, then the former list head
    // and the new node point to each other. Thus, the new node effectively
    // becomes the list's new head.

    if (list->size == 0)
    {
        // Like in append_to_list(), if the list is empty, then the new node will
        // become the only node it contains, and therefore its head and its tail both.
        list->head = new_node;
        list->tail = new_node;
    }
    else
    {
        list->head->prev = new_node;
        new_node->next = list->head;
        list->head = list->head->prev;
    }

    list->size++;
}

bool insert_to_list(linked_list *list, int index, void *data, size_t type_size)
{
    // If the index doesn't exist yet, then we can't add there.
    if (index > list->size)
        return false;

    // If the index is the size of the list, then this insert operation would be
    // synonym with appending at the end of the list.
    else if (index == list->size)
        append_to_list(list, data, type_size);

    // If the index is 0, then this insert operation would be synonym with prepending
    // at the beginning of the list.
    else if (index == 0)
        prepend_to_list(list, data, type_size);

    // And if it's in the middle, we'll do the usual insertion algorithm :)
    else
    {
        list_node *new_node = create_new_node(data, type_size);
        list_node *iter = list->head;

        for (int i = 0; i < index; i++)
            iter = iter->next;

        new_node->next = iter;
        new_node->prev = iter->prev;
        iter->prev = new_node;
    }

    return true;
}

void print_forward(linked_list *list, void (*fptr)(void *))
{
    list_node *iter = list->head;

    while (iter != NULL)
    {
        (*fptr)(iter->data);
        iter = iter->next;
    }
}

void print_backward(linked_list *list, void (*fptr)(void *))
{
    list_node *iter = list->tail;

    while (iter != NULL)
    {
        (*fptr)(iter->data);
        iter = iter->prev;
    }
}

void delete_list(linked_list *list)
{
    list_node *curr = list->head;

    while (curr->next !=  NULL)
    {
        list_node *next = curr->next;
        free(curr);
        curr = next;
    }

    free(curr);
    free(list);
}
