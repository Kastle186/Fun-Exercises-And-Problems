#include <stdio.h>
#include <stdlib.h>
#include "tools/hackerrank.h"

int birthday(int, int *, int, int);

int main(void)
{
    int n = parse_int(ltrim(rtrim(readline())));
    char **s_temp = split_string(rtrim(readline()));
    int *s = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        int s_item = parse_int(*(s_temp + i));
        *(s + i) = s_item;
    }

    char **first_multiple_input = split_string(rtrim(readline()));
    int d = parse_int(*(first_multiple_input + 0));
    int m = parse_int(*(first_multiple_input + 1));

    int result = birthday(n, s, d, m);
    printf("%d\n", result);

    free(s);
    free(s_temp);
    free(first_multiple_input);

    return 0;
}

int birthday(int s_count, int *s, int d, int m)
{
    // First, if the chocolate bar has less segments than the birthday month, then
    // we know it is not possible to divide it, so we end early.

    if (s_count < m)
        return 0;

    // Now, we know that there is at least one potential solution. So we go about
    // measuring the sum of the digits of each subarray, and count those that match
    // the day of the birthday.

    int div_ways = 0;

    for (int i = 0; i < s_count - (m - 1); i++)
    {
        int *start_sub = s + i;
        int sub_sum = 0;

        for (int j = 0; j < m; j++)
            sub_sum += *(start_sub + j);

        if (sub_sum == d)
            div_ways++;
    }

    return div_ways;
}
