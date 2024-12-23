#include "heap.h"

/********************/
/* PUBLIC FUNCTIONS */
/********************/

heap *create_new_heap(int capacity, size_t type_size, int (*comparer)(void *, void *))
{
    heap *new_heap_obj = (heap *) malloc(sizeof(heap));

    new_heap_obj->heap_arr = (void **) calloc(capacity, sizeof(void *));
    new_heap_obj->capacity = capacity;
    new_heap_obj->size = 0;
    new_heap_obj->type_size = type_size;

    // Since we are simulating generics here, we need a way to know which object
    // is greater than another. So, we need the user to give us a comparing function
    // that will tell us just that.
    new_heap_obj->comp_fun = comparer;

    // Initialize our heap to NULL pointers, rather than random garbage.
    for (int i = 0; i < capacity; i++)
        *(new_heap_obj->heap_arr + i) = NULL;

    return new_heap_obj;
}

void *get_max(heap *heap_obj)
{
    return heap_obj->size > 0 ? heap_obj->heap_arr[0] : NULL;
}

void *extract_max(heap *heap_obj)
{
    if (heap_obj->size == 0)
    {
        printf("Can't extract from an empty heap.\n");
        return NULL;
    }

    if (heap_obj->size == 1)
    {
        void *elem = heap_obj->heap_arr[0];
        free(heap_obj->heap_arr[0]);
        return elem;
    }

    void *elem = malloc(heap_obj->type_size);
    memcpy(elem, heap_obj->heap_arr[0], heap_obj->type_size);

    memcpy(heap_obj->heap_arr[0],
           heap_obj->heap_arr[heap_obj->size - 1],
           heap_obj->type_size);

    heap_obj->size--;
    free(heap_obj->heap_arr[heap_obj->size]);
    heapify(heap_obj, 0);

    return elem;
}

void print_heap(heap *heap_obj, void (*printfn)(void *))
{
    printf("HEAP CONTENTS: [");
    for (int i = 0; i < heap_obj->size; i++)
    {
        void *item = heap_obj->heap_arr[i];
        (*printfn)(item);
    }
    printf(" ]\n");
}

void delete_heap(heap *heap_obj)
{
    for (int i = 0; i < heap_obj->size; i++)
        free(heap_obj->heap_arr[i]);

    free(heap_obj->heap_arr);
    free(heap_obj);
}

/*********************/
/* PRIVATE FUNCTIONS */
/*********************/

void heapify(heap *heap_obj, int index)
{
    int left = LEFT_CHILD(index);
    int right = RIGHT_CHILD(index);
    int largest = index;
    void **heap_array = heap_obj->heap_arr;

    if (left < heap_obj->size)
    {
        int compare_left = (heap_obj->comp_fun)(heap_array[left],
                                                heap_array[index]);

        if (compare_left == 1)
            largest = left;
    }

    if (right < heap_obj->size)
    {
        int compare_right = (heap_obj->comp_fun)(heap_array[right],
                                                 heap_array[largest]);

        if (compare_right == 1)
            largest = right;
    }

    if (largest != index)
    {
        swap(&heap_array[index], &heap_array[largest]);
        heapify(heap_obj, largest);
    }
}

void swap(void **ptr1, void **ptr2)
{
    // Good old pointer swap!
    void *temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}

void insert_to_heap(heap *heap_obj, void *data)
{
    if (heap_obj->size == heap_obj->capacity)
    {
        printf("The heap is now full.\n");
        return ;
    }

    int index = heap_obj->size;
    heap_obj->heap_arr[index] = malloc(heap_obj->type_size);
    memcpy(heap_obj->heap_arr[index], data, heap_obj->type_size);
    heap_obj->size++;

    // Adding the new node to the heap might not be enough. We need to ensure that
    // the heap's property was not violated by this addition. And if it was, then
    // fix our heap so that it fulfills its property again.

    while (index != 0)
    {
        int compare = (heap_obj->comp_fun)(heap_obj->heap_arr[PARENT(index)],
                                           heap_obj->heap_arr[index]);

        // The compare function returns 1 if the first operand is greater than
        // the second operand. So, in this case, if the parent is greater than
        // the child, then the heap's property either was not disrupted or has
        // been restored, and we can exit this self-management loop.

        if (compare == 1)
            break;

        swap(&heap_obj->heap_arr[PARENT(index)], &heap_obj->heap_arr[index]);
        index = PARENT(index);
    }
}

void delete_from_heap(heap *heap_obj, void *data)
{
    // Leaving this for a later exercise because I'm tired right now :)
    puts("Under Construction!");
    return ;
}
