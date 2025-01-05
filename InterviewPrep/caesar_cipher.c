#include <stdio.h>
#include <ctype.h>
#include "tools/hackerrank.h"

#define NUM_ALPHABET_LETTERS 26

char *caesar_cipher(char *, int, int);

int main(void)
{
    int n = parse_int(ltrim(rtrim(readline())));
    char *s = readline();
    int k = parse_int(ltrim(rtrim(readline())));

    char *result = caesar_cipher(s, n, k);
    printf("%s\n", result);

    free(s);
    return 0;
}

char *caesar_cipher(char *msg, int msg_len, int k)
{
    // In order to rotate each letter of the message, first we need to get
    // its "index in the alphabet" so to speak (i.e. 0-26). This is so we can
    // easily do the full rotation using a modulo operation. Then, we substitute
    // the original letter with the rotated one by converting it back to its
    // ASCII Code.

    for (int i = 0; i < msg_len; i++)
    {
        char nextch = *(msg + i);

        // Non-letters are left as is.
        if (!isalpha(nextch))
            continue;

        if (isupper(nextch))
        {
            nextch -= 'A';
            nextch = (nextch + k) % NUM_ALPHABET_LETTERS;
            nextch += 'A';
        }
        else if (islower(nextch))
        {
            nextch -= 'a';
            nextch = (nextch + k) % NUM_ALPHABET_LETTERS;
            nextch += 'a';
        }

        *(msg + i) = nextch;
    }

    return msg;
}
