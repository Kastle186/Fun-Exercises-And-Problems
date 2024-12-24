#include "red_black_tree.h"

/********************/
/* PUBLIC FUNCTIONS */
/********************/

red_black_tree *create_new_red_black_tree(size_t type_size,
                                          int (*comparer)(void *, void *))
{
    red_black_tree *rbtree_obj = (red_black_tree *) malloc(sizeof(red_black_tree));
    rbtree_obj->root = NULL;
    rbtree_obj->size = 0;
    rbtree_obj->type_size = type_size;
    rbtree_obj->comp_fun = comparer;
    return rbtree_obj;
}

void delete_tree(red_black_tree *rbtree)
{
    return ;
}

void print_tree(red_black_tree *rbtree, tree_order order, void (*printfn)(void *))
{
    return ;
}

void *get_minimum(red_black_tree *rbtree)
{
    return NULL;
}

void *get_maximum(red_black_tree *rbtree)
{
    return NULL;
}

/*********************/
/* PRIVATE FUNCTIONS */
/*********************/

rb_tree_node *create_new_rbnode(void *data, size_t type_size)
{
    rb_tree_node *new_node = (rb_tree_node *) malloc(sizeof(rb_tree_node));

    // Allocate memory for the data's pointer and initialize its parent and children
    // pointers to NULL, and set its color to RED.

    new_node->data = malloc(type_size);
    new_node->parent = NULL;
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->color = RED;

    // Copy the value of data into our new node.
    memcpy(new_node->data, data, type_size);

    return new_node;
}

void insert_to_tree(red_black_tree *rbtree, void *data)
{
    rb_tree_node *new_node = create_new_rbnode(data, rbtree->type_size);
    rbtree->size++;

    // If our tree is empty, then the new node will be its root and we have to
    // also color it black instead.

    if (!rbtree->root)
    {
        new_node->color = BLACK;
        rbtree->root = new_node;
        return ;
    }

    rb_tree_node *iter = rbtree->root;
    rb_tree_node *parent = NULL;

    while (iter != NULL)
    {
        parent = iter;
        int compare = (rbtree->comp_fun)(iter->data, new_node->data);

        if (compare >= 0)
            iter = iter->left;
        else
            iter = iter->right;
    }

    new_node->parent = parent;
    int l_or_r_comp = (rbtree->comp_fun)(parent->data, new_node->data);

    if (l_or_r_comp >= 0)
        parent->left = new_node;
    else
        parent->right = new_node;
}

void delete_from_tree(red_black_tree *rbtree, void *data)
{
    return ;
}

void *search_tree(red_black_tree *rbtree, void *data)
{
    return NULL;
}

void rb_preorder_helper(red_black_tree *rbtree, void (*printfn)(void *))
{
    return ;
}

void rb_inorder_helper(red_black_tree *rbtree, void (*printfn)(void *))
{
    return ;
}

void rb_postorder_helper(red_black_tree *rbtree, void (*printfn)(void *))
{
    return ;
}
