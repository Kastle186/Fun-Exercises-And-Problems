#ifndef C_DATA_STRUCTURES_LINKED_LIST_H
#define C_DATA_STRUCTURES_LINKED_LIST_H

/* INCLUDES */

#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/* TYPEDEFS AND STRUCTS */

typedef struct list_node_struct list_node;
typedef struct linked_list_struct linked_list;

struct list_node_struct
{
    void *data;
    list_node *next;
    list_node *prev;
};

struct linked_list_struct
{
    list_node *head;
    list_node *tail;
    size_t size;
};

/* FUNCTION DECLARATIONS */

linked_list *create_new_linked_list(void);
list_node *create_new_node(void *, size_t);
void append_to_list(linked_list *, void *, size_t);
void prepend_to_list(linked_list *, void *, size_t);
bool insert_to_list(linked_list *, int, void *, size_t);
void print_forward(linked_list *, void (*)(void *));
void print_backward(linked_list *, void (*)(void *));
void delete_list(linked_list *);

/* FUNCTION MACROS */

#define APPEND_TO_LIST(list, value, type)                                 \
    {                                                                     \
        type append_temp = value;                                         \
        append_to_list(list, (void *) &append_temp, sizeof(append_temp)); \
    }

#define PREPEND_TO_LIST(list, value, type)                                   \
    {                                                                        \
        type prepend_temp = value;                                           \
        prepend_to_list(list, (void *) &prepend_temp, sizeof(prepend_temp)); \
    }

#define INSERT_TO_LIST(list, index, value, type)    \
    {                                               \
        type insert_temp = value;                   \
        insert_to_list(list,                        \
                       index,                       \
                       (void *) &insert_temp,       \
                       sizeof(insert_temp));        \
    }

#endif // C_DATA_STRUCTURES_LINKED_LIST_H
