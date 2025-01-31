#ifndef C_DATA_STRUCTURES_RED_BLACK_TREE_H
#define C_DATA_STRUCTURES_RED_BLACK_TREE_H

/* INCLUDES */

#include <stdlib.h>

/* TYPEDEFS, STRUCTS, AND ENUMS */

enum rb_color_enum
{
    RED,
    BLACK
};

enum tree_order_enum
{
    PREORDER,
    INORDER,
    POSTORDER
}

typedef enum rb_color_enum rb_color;
typedef enum tree_order_enum tree_order;
typedef struct rb_tree_node_struct rb_tree_node;
typedef struct red_black_tree_struct red_black_tree;

struct rb_tree_node_struct
{
    void *data;
    rb_tree_node *parent;
    rb_tree_node *left;
    rb_tree_node *right;
    rb_color color;
    size_t type_size;
    int (*comp_fun)(void *, void *);
};

struct red_black_tree_struct
{
    rb_tree_node *root;
    size_t size;
};

/* FUNCTION DECLARATIONS */

// Public Functions

red_black_tree *create_new_red_black_tree(size_t, int (*)(void *, void *));
void delete_tree(red_black_tree *);
void print_tree(red_black_tree *, tree_order, void (*)(void *));

void *get_minimum(red_black_tree *);
void *get_maximum(red_black_tree *);

// Private Functions

void insert_to_tree(red_black_tree *, void *);
void delete_from_tree(red_black_tree *, void *);
void *search_tree(red_black_tree *, void *);

void rb_preorder_helper(red_black_tree *, void (*)(void *));
void rb_inorder_helper(red_black_tree *, void (*)(void *));
void rb_postorder_helper(red_black_tree *, void (*)(void *));

/* FUNCTION MACROS */

#define INSERT_TO_TREE(tree, value, type)               \
    {                                                   \
        type insert_temp = value;                       \
        insert_to_tree(tree, (void *) &insert_temp);    \
    }

#define DELETE_FROM_TREE(tree, value, type)             \
    {                                                   \
        type delete_temp = value;                       \
        delete_from_tree(tree, (void *) &delete_temp);  \
    }

#define SEARCH_TREE(tree, value, result, type)              \
    {                                                       \
        type search_temp = value;                           \
        result = search_tree(tree, (void *) &search_temp);  \
    }

#endif // C_DATA_STRUCTURES_RED_BLACK_TREE_H
