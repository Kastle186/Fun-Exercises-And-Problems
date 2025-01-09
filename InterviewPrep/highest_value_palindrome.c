#include <stdio.h>
#include "tools/hackerrank.h"

char *highest_value_palindrome(char *, int, int);
int num_palindrome_diffs(char *, int);

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

    return 0;
}

char *highest_value_palindrome(char *numstr, int len, int changes)
{
    // First, we have to know how many differences we have. If that number exceeds
    // our available number of changes, then we can infer since now that this case
    // is not possible to solve.

    int diffs = num_palindrome_diffs(numstr, len);

    if (diffs > changes)
        return (char *)"-1";

    int low = 0;
    int high = len - 1;

    while (high >= low)
    {
        // If we have no more changes left allowed, then we're done here.
        if (changes <= 0)
            break;

        char c_low = *(numstr + low);
        char c_high = *(numstr + high);

        // If our goal was to simply make it a palindrome, then we would be able
        // to just pass by the numbers that are already equal. However, since we
        // want the highest possible palindrome then, if we can afford it, we ought
        // to make this pair a pair of 9's. If they are already 9's then we just
        // move on to the next pair.

        if (c_low == c_high)
        {
            // Both 9's, they are already perfect.
            if (c_low == '9')
                continue;

            // If we can afford making them 9's, then do so.
            if ((changes - 2) >= diffs)
            {                
                *(numstr + low) = '9';
                *(numstr + high) = '9';
                changes -= 2;
            }
        }
        else
        {
            // Since we are already using our change tickets, then might as well
            // optimize them! If we can afford it, then let's make both of these
            // numbers 9's!

            if ((changes - 2) >= (diffs - 1))
            {
                // We check both separately, as there is a chance that one of them
                // might be 9 already.

                if (c_low != '9')
                {
                    *(numstr + low) = '9';
                    changes--;
                }

                if (c_high != '9')
                {
                    *(numstr + high) = '9';
                    changes--;
                }
            }
            else
            {
                // Convert the lowest of the two numbers to the highest one to
                // acquire the palindrome property, while maximizing the gain.

                if (c_low > c_high)
                    *(numstr + high) = c_low;
                else
                    *(numstr + low) = c_high;

                changes--;
            }

            diffs--;
        }

        // Odd-length number case! Since this would be the sole digit of the
        // entire string, leaving it alone wouldn't invalidate the palindrome.
        // But if we can afford it, let's make it a 9 to maximize the gain,
        // it is not already a 9.

        if (low == high && changes > 0 && c_low != '9')
        {
            *(numstr + low) = '9';
            changes--;
        }

        low++;
        high--;
    }

    return num_palindrome_diffs(numstr, len) == 0 ? numstr : (char *)"-1";
}

int num_palindrome_diffs(char *numstr, int len)
{
    int diffs = 0;

    for (int i = 0, j = len - 1; j > i; i++, j--)
    {
        if (*(numstr + i) != *(numstr + j))
            diffs++;
    }

    return diffs;
}
