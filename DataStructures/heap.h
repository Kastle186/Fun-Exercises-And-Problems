#ifndef C_DATA_STRUCTURES_HEAP_H
#define C_DATA_STRUCTURES_HEAP_H

/* INCLUDES */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* MACROS */

#define PARENT(i) (int) (i-1)/2
#define LEFT_CHILD(i) (int) (2*i)+1
#define RIGHT_CHILD(i) (int) (2*i)+2

/* TYPEDEFS AND STRUCTS */

typedef struct heap_struct heap;

struct heap_struct
{
    void **heap_arr;
    size_t capacity;
    size_t size;
    size_t type_size;
    int (*comp_fun)(void *, void *);
};

/* FUNCTION DECLARATIONS */

// Public Functions

heap *create_new_heap(int, size_t, int (*)(void *, void *));
void *get_max(heap *);
void *extract_max(heap *);
void print_heap(heap *, void (*)(void *));
void delete_heap(heap *);

// Private Functions

void heapify(heap *, int);
void swap(void **, void **);
void insert_to_heap(heap *, void *);
void delete_from_heap(heap *, void *);

/* FUNCTION MACROS */

#define INSERT_TO_HEAP(heap, value, type)                                 \
    {                                                                     \
        type insert_temp = value;                                         \
        insert_to_heap(heap, (void *) &insert_temp); \
    }

#define DELETE_FROM_HEAP(heap, value)                   \
    {                                                   \
        type delete_temp = value;                       \
        delete_from_heap(heap, (void *) &delete_temp);  \
    }

#endif // C_DATA_STRUCTURES_HEAP_H
