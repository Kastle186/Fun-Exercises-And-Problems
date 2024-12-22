#ifndef C_DATA_STRUCTURES_HEAP_H
#define C_DATA_STRUCTURES_HEAP_H

/* INCLUDES */

#include <stdlib.h>

/* TYPEDEFS AND STRUCTS */

typedef struct heap_struct heap;

struct heap_struct
{
    void **heap_arr;
    size_t capacity;
    size_t size;
};

/* FUNCTION DECLARATIONS */

// Public Functions

heap *create_new_heap(int);
void *get_max(heap *);
void *extract_max(heap *);

// Private Functions

void heapify(heap *);
void swap(void *, void *);
void insert_to_heap(heap *, void *, size_t);
void delete_from_heap(heap *, void *);

/* FUNCTION MACROS */

#define INSERT_TO_HEAP(heap, value, type)                                 \
    {                                                                     \
        type insert_temp = value;                                         \
        insert_to_heap(heap, (void *) &insert_temp, sizeof(insert_temp)); \
    }

#define DELETE_FROM_HEAP(heap, value)                   \
    {                                                   \
        type delete_temp = value;                       \
        delete_from_heap(heap, (void *) &delete_temp);  \
    }

#endif // C_DATA_STRUCTURES_HEAP_H
