#include <stdio.h>
#include "trie.h"

int main(int argc, char **argv)
{
    // List of cute words we will be using to test our trie!
    char *words[] = { "honkai", "star", "rail", "trails", "kiseki" };
    size_t num_words = sizeof(words) / sizeof(words[0]);

    // Create and initialize our trie
    trie *games_trie = create_new_trie();
    for (int i = 0; i < num_words; i++)
    {
        printf("Inserting %s...\n", words[i]);
        insert_word(games_trie, (const char *) words[i]);
    }

    puts("\nTESTING OUR TRIE!\n");
    print_trie(games_trie); // Print all of the contents!

    // List of cute words we'll try to search in our trie!
    char *to_search[] = { "hello", "trails", "star" };
    size_t num_search_words = sizeof(to_search) / sizeof(to_search[0]);

    // Search the words!
    for (int j = 0; j < num_search_words; j++)
    {
        char *next_word = to_search[j];
        printf("\nSearching '%s'...\n", next_word);
        printf("'%s' was %s.\n",
               next_word,
               search_word(games_trie, next_word) ? "present" : "not present");
    }

    delete_trie(games_trie);
    return 0;
}
