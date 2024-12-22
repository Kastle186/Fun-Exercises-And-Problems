#ifndef C_DATA_STRUCTURES_TRIE_H
#define C_DATA_STRUCTURES_TRIE_H

/* INCLUDES */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* MACROS */

#define NUM_ENGLISH_LETTERS 26
#define LETTER_TO_INDEX(letter) (unsigned) (letter - 'a')
#define INDEX_TO_LETTER(index) (char) (index + 'a')

/* TYPEDEFS AND STRUCTS */

typedef struct trie_node_struct trie_node;
typedef struct trie_struct trie;

struct trie_node_struct
{
    trie_node *children[NUM_ENGLISH_LETTERS];
    bool is_word_end;
};

struct trie_struct
{
    trie_node *root;
    size_t word_count;
};

/* FUNCTION DECLARATIONS */

trie *create_new_trie(void);
trie_node *create_new_node(void);
void insert_word(trie *, const char *);
bool search_word(const trie *, const char *);
void print_trie(const trie *);
void print_node(const trie_node *);
void delete_trie(trie *);
void delete_node(trie_node *);

#endif // C_DATA_STRUCTURES_TRIE_H
