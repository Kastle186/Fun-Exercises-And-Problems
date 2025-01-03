#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "tools/hackerrank.h"

#define ENGLISH_ALPHABET 26
#define BIT_ARRAY_FULL 67108863

char *pangrams(char *);

int main(void)
{
    char *s = readline();
    char *result = pangrams(s);
    printf("%s\n", result);
    return 0;
}

char *pangrams(char *str)
{
    size_t len = strlen(str);

    // If the string is less than 26 chars long, then it is not possible for it
    // to contain every letter of the alphabet, so we don't even have to process.

    if (len < ENGLISH_ALPHABET)
        return (char *) "not pangram";

    // We iterate letter by letter, and then mark it as found in our bit array.
    // Once all smallest 26 bits have been lit up, we know the string is a pangram.
    // If we reach the end of the string, and didn't light up all bits, then it
    // was not a pangram.

    int found_letters = 0;

    for (int i = 0; i < len; i++)
    {
        char c = tolower(*(str + i));

        // We can also find non-letter characters like spaces. Those, we only need
        // to skip.
        if (!isalpha(c))
            continue;

        int letter_idx = (int) (c - 'a');
        int mask = 1 << letter_idx;

        // Set this letter as found.
        found_letters |= mask;

        // If we've found all letters at least once, then there is no need to
        // continue processing, as we know the string is a pangram.
        if (found_letters == BIT_ARRAY_FULL)
            return (char *) "pangram";
    }

    return (char *) "not pangram";
}
