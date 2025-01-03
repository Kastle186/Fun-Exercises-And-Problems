#include <stdio.h>
#include <stdlib.h>
#include "tools/hackerrank.h"

#define NUM_COLORS 100

int sock_merchant(int, int *);

int main(void)
{
    int n = parse_int(ltrim(rtrim(readline())));
    char **ar_temp = split_string(rtrim(readline()));
    int *ar = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        int ar_item = parse_int(*(ar_temp + i));
        *(ar + i) = ar_item;
    }

    int result = sock_merchant(n, ar);
    printf("%d\n", result);

    free(ar_temp);
    free(ar);
    return 0;
}

int sock_merchant(int n, int *arr)
{
    // To know the number of pairs of socks, we first have to count how many we
    // have of each color. Then, divide those numbers by 2 and add up the results.
    // Since we know there are only 100 potential colors, and that is a reasonable
    // number, we can use an array as the dictionary/hashset.

    int *socks_counts = calloc(NUM_COLORS + 1, sizeof(int));

    for (int i = 0; i < n; i++)
    {
        int sock_num = *(arr + i);
        socks_counts[sock_num]++;
    }

    int pairs = 0;

    for (int j = 0; j <= NUM_COLORS; j++)
    {
        if (*(socks_counts + j) == 0)
            continue;

        int count = *(socks_counts + j);
        pairs += (count / 2);
    }

    free(socks_counts);
    return pairs;
}
