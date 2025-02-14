// Name: 1768. Merge Strings Alternatively
// Topics: Two Pointers, String
// Companies: Wells Fargo, Zoho

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *merge_alternatively(char *, char *);

int main(void)
{
    char *word1 = (char *) "abc";
    char *word2 = (char *) "pqr";
    char *word3 = (char *) "ab";
    char *word4 = (char *) "pqrs";
    char *word5 = (char *) "abcd";
    char *word6 = (char *) "pq";

    char *result12 = merge_alternatively(word1, word2);
    char *result34 = merge_alternatively(word3, word4);
    char *result56 = merge_alternatively(word5, word6);

    printf("%s\n", result12);
    printf("%s\n", result34);
    printf("%s\n", result56);

    free(result12);
    free(result34);
    free(result56);
    return 0;
}

char *merge_alternatively(char *word1, char *word2)
{
    // We don't have to check for null or empty strings because the problem
    // description guarantees they will always have at least 1 letter.

    // We are allocating +1 because we need to add the null terminator character
    // at the end.
    char *merged = (char *) calloc(strlen(word1) + strlen(word2) + 1, sizeof(char));

    char *word1_ptr = word1;
    char *word2_ptr = word2;
    char *merged_ptr = merged;

    // Add each character of each string alternatively by moving the three
    // pointers accordingly.

    while (*word1_ptr != '\0' && *word2_ptr != '\0')
    {
        *merged_ptr = *word1_ptr;
        word1_ptr++;
        merged_ptr++;

        *merged_ptr = *word2_ptr;
        word2_ptr++;
        merged_ptr++;
    }

    // At this point, at least one of the two words has been fully added. So,
    // we chack and add the remanining letters of the non-exhausted word.

    while (*word1_ptr != '\0')
    {
        *merged_ptr = *word1_ptr;
        word1_ptr++;
        merged_ptr++;
    }

    while (*word2_ptr != '\0')
    {
        *merged_ptr = *word2_ptr;
        word2_ptr++;
        merged_ptr++;
    }

    // Add null-terminator at the end of our new string.
    *merged_ptr = '\0';

    return merged;
}
