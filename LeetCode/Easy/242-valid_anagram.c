// Name: 242. Valid Anagram
// Topics: Hash Table, String, Sorting
// Companies:
// - Yelp
// - EPAM Systems
// - ConsultAdd
// - Disney
// - Siemens
// - Spotify
// - Cognizant
// - Accenture
// - Autodesk
// - Infosys
// - American Express
// - Tesla
// - tcs
// - Google
// - BlackRock
// - Walmart Labs
// - Yandex
// - PayPal
// - J.P. Morgan
// - Atlassian
// - Goldman Sachs

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define ENGLISH_LETTERS 26

bool is_anagram(const char *, const char *);

int main(void)
{
    const char *s1 = (const char *) "anagram";
    const char *t1 = (const char *) "nagaram";

    const char *s2 = (const char *) "rat";
    const char *t2 = (const char *) "car";

    printf("%s\n", is_anagram(s1, t1) ? "true" : "false");
    printf("%s\n", is_anagram(s2, t2) ? "true" : "false");
    return 0;
}

bool is_anagram(const char *s, const char *t)
{
    // Different length strings cannot be anagrams by definition.

    if (strlen(s) != strlen(t))
        return false;

    // To find out whether string t is an anagram of string s, we'll be using
    // a variant of a hash table with an array and a counter. Each position in
    // the array will correspond to a letter count. We'll add up the ones that
    // appear in the first string, and then subtract the occurrences from the
    // second one. If our array has only zeroes at the end, then the strings
    // were an anagram of each other. Otherwise, they weren't.
    //
    // NOTE: The problem's description guarantees we will only find lowercase
    //       English letters.

    int *letter_occurrences = (int *) calloc(ENGLISH_LETTERS, sizeof(int));
    int letters_found = 0;

    const char *s_ptr = s;
    const char *t_ptr = t;

    while (*s_ptr != '\0')
    {
        int s_index = (*s_ptr) - 'a';

        if (letter_occurrences[s_index] == 0)
            letters_found++;

        letter_occurrences[s_index]++;
        s_ptr++;
    }

    while (*t_ptr != '\0')
    {
        int t_index = (*t_ptr) - 'a';
        letter_occurrences[t_index]--;

        if (letter_occurrences[t_index] == 0)
            letters_found--;

        t_ptr++;
    }

    free(letter_occurrences);
    return letters_found == 0;
}
