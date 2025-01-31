#include "trie.h"

/********************/
/* PUBLIC FUNCTIONS */
/********************/

trie *create_new_trie()
{
    trie *trie_obj = (trie *) malloc(sizeof(trie));
    trie_obj->root = create_new_node();
    trie_obj->word_count = 0;
    return trie_obj;
}

void insert_word(trie *trie_obj, const char *word)
{
    trie_node *curr = trie_obj->root;
    const char *ptr_word = word;

    // For each letter in the word, we follow our trie "constructing" it. If we
    // get to a new branch, then allocate a new node for the next letter.

    while (*ptr_word != '\0')
    {
        int index = LETTER_TO_INDEX(*ptr_word);

        if (!curr->children[index])
            curr->children[index] = create_new_node();

        curr = curr->children[index];
        ptr_word++;
    }

    // Mark the final letter node as a leaf, and update the word count bookkeeping
    // that our trie object keeps.
    curr->is_word_end = true;
    trie_obj->word_count++;
}

bool search_word(const trie *trie_obj, const char *word)
{
    trie_node *curr = trie_obj->root;
    const char *ptr_word = word;

    // Same as with the insertion process, we follow our trie "constructing" the
    // word we received. The difference here is that if we get to what would be
    // a new branch, then that means this word is not part of our trie, and so we
    // return false early.

    while (*ptr_word != '\0')
    {
        int index = LETTER_TO_INDEX(*ptr_word);

        if (!curr->children[index])
            return false;

        curr = curr->children[index];
        ptr_word++;
    }

    return curr->is_word_end;
}

void print_trie(const trie *trie_obj)
{
    printf("******************\n");
    printf("TRIE DESCRIPTION!\n");
    printf("SIZE: %zu WORDS\n", trie_obj->word_count);
    printf("******************\n");

    trie_node *root = trie_obj->root;
    print_node(root);
}

void delete_trie(trie *trie_obj)
{
    delete_node(trie_obj->root);
    free(trie_obj);
}

/*********************/
/* PRIVATE FUNCTIONS */
/*********************/

trie_node *create_new_node()
{
    trie_node *node = (trie_node *) malloc(sizeof(trie_node));
    node->is_word_end = false;

    // Set all of the letter pointers of this node to NULL for additional safety.
    for (int i = 0; i < NUM_ENGLISH_LETTERS; i++)
        node->children[i] = NULL;

    return node;
}

void print_node(const trie_node *node)
{
    printf("\n*****************\n");
    printf("NODE DESCRIPTION!\n");
    printf("IS LEAF: %s\n", node->is_word_end ? "true" : "false");
    printf("*****************\n");

    if (node->is_word_end)
        return ;

    printf("\n[");
    for (int i = 0; i < NUM_ENGLISH_LETTERS; i++)
    {
        if (node->children[i] != NULL)
            printf(" %c", INDEX_TO_LETTER(i));
    }
    printf(" ]\n");

    for (int j = 0; j < NUM_ENGLISH_LETTERS; j++)
    {
        trie_node *child_node = node->children[j];
        if (child_node != NULL)
            print_node(child_node);
    }
}

void delete_node(trie_node *node)
{
    // If this node is a word ending or leaf, then we can be sure all of its
    // children are NULL, so we can deallocate it safely.

    if (node->is_word_end)
    {
        free(node);
        return ;
    }

    // Check all of the children of this node, and apply the same deletion
    // process to all those that are not NULL.

    for (int i = 0; i < NUM_ENGLISH_LETTERS; i++)
    {
        trie_node *letter_node = node->children[i];

        if (letter_node != NULL)
            delete_node(node);
    }
    free(node);
}
