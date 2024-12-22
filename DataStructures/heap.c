#include "heap.h"

/********************/
/* PUBLIC FUNCTIONS */
/********************/

heap *create_new_heap(int capacity)
{
    heap *new_heap_obj = (heap *) malloc(sizeof(heap));

    new_heap_obj->heap_arr = (void **) calloc(capacity, sizeof(void *));
    new_heap_obj->capacity = capacity;
    new_heap_obj->size = 0;

    for (int i = 0; i < capacity; i++)
        *(new_heap_obj->heap_arr + i) = NULL;

    return new_heap_obj;
}

void *get_max(heap *heap_obj)
{
    return NULL;
}

void *extract_max(heap *heap_obj)
{
    return NULL;
}

/*********************/
/* PRIVATE FUNCTIONS */
/*********************/

void heapify(heap *heap_obj)
{
    return ;
}

void swap(void *ptr1, void *ptr2)
{
    return ;
}

void insert_to_heap(heap *heap_obj, void *data, size_t type_size)
{
    return ;
}

void delete_from_heap(heap *heap_obj, void *data)
{
    return ;
}
