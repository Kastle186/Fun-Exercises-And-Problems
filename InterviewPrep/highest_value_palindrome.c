#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "tools/hackerrank.h"

char *highest_value_palindrome(char *, int, int);

int main(void)
{
    char **first_multiple_input = split_string(rtrim(readline()));
    int n = parse_int(*(first_multiple_input + 0));
    int k = parse_int(*(first_multiple_input + 1));

    char *s = readline();
    char *result = highest_value_palindrome(s, n, k);

    printf("%s\n", result);

    free(first_multiple_input);
    free(s);
    free(result);

    return 0;
}

char *highest_value_palindrome(char *numstr, int len, int changes)
{
    char *result = calloc(len, sizeof(char));

    // Iterate the string with two pointers, one from the beginning, and one from
    // the end. In a palindrome, these two values will always be the same. So, when
    // they differ, then we know there is something we can fix here.

    for (int i = 0, j = len - 1; i <= j; i++, j--)
    {
        char c_low = *(numstr + i);
        char c_high = *(numstr + j);

        // They follow the palindrome property, so if we leave them alone, we're
        // good. We'll later do another pass to see if we can convert them to 9's
        // to maximize the value, if they are not already 9's.
        if (c_low >= c_high)
        {
            *(result + i) = c_low;
            *(result + j) = c_low;

            // If they are equal, then no changes were made, so we skip the rest
            // of the remaining processing for this pair.
            if (c_low == c_high)
                continue;
        }
        else
        {
            *(result + i) = c_high;
            *(result + j) = c_high;
        }

        changes--;

        // We exceeded our possible changes, so we know this is not a palindromic
        // fixable number.
        if (changes < 0)
            return (char *)"-1";
    }

    // At this point, our number string should be a palindrome. However, since we
    // want it to be the highest possible, then let's try to get as many 9's as we
    // can before returning it.

    for (int i = 0, j = len - 1; i <= j; i++, j--)
    {
        if (changes <= 0)
            break;

        // Odd-length number case! Since this would be the sole digit of the
        // entire string, leaving it alone wouldn't invalidate the palindrome.
        // But if we can afford it, let's make it a 9 to maximize the gain.

        if (i == j && changes > 0)
        {
            *(result + i) = '9';
            break;
        }

        // Next, we need to know whether this pair was already there, or we made
        // a change to make it. If we made it, then we can make them both 9's with
        // only one more change, since theoretically, we would've made them 9's
        // since the beginning on paper. In other words, one change has already
        // been done, and hence we only need one more.

        if ((*(result + i) != *(numstr + i)) || (*(result + j) != *(numstr + j)))
        {
            *(result + i) = '9';
            *(result + j) = '9';
            changes--;
        }

        // If the pair was already there, then we need the two changes to make
        // them 9's.
        else if (changes >= 2 && *(result + i) != '9')
        {
            *(result + i) = '9';
            *(result + j) = '9';
            changes -= 2;
        }
    }

    return result;
}
