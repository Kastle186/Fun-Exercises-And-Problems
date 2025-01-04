#include <stdio.h>
#include "tools/hackerrank.h"

char *balanced_sums(int, int *);

int main(void)
{
    int T = parse_int(ltrim(rtrim(readline())));

    for (int T_itr = 0; T_itr < T; T_itr++)
    {
        int n = parse_int(ltrim(rtrim(readline())));
        char **arr_temp = split_string(rtrim(readline()));
        int *arr = malloc(n * sizeof(int));

        for (int i = 0; i < n; i++)
        {
            int arr_item = parse_int(*(arr_temp + i));
            *(arr + i) = arr_item;
        }

        char *result = balanced_sums(n, arr);
        printf("%s\n", result);

        free(arr_temp);
        free(arr);
    }

    return 0;
}

char *balanced_sums(int arr_count, int *arr)
{
    /*
      To solve this problem, we will be applying some maths.

       We know that for the balanced sums properties to be fulfilled, the array's
       elements must be such that: x + y + x = 2x + y = Sum of all elements.
       Therefore: 2x = Sum - y

       With this information, we start substituting values, such that y is the
       potential pivot element, and x is the sum of the elements before it.
       If we find any such values for x and y that make the equation true, then
       we know the sums of this array can be balanced. Otherwise, it is not
       possible to define such balance.
    */

    // First step is to get the sum of all elements.

    int sum = 0;

    for (int i = 0; i < arr_count; i++)
        sum += *(arr + i);

    // Next, we test one by one of the potential pivots with the equation. We also
    // incrementally add to x to avoid having to repeat sums we've already passed
    // by beforehand.

    int x = 0;
    int y = -1;

    for (int j = 0; j < arr_count; j++)
    {
        y = *(arr + j);

        if (j > 0)
            x += *(arr + j - 1);

        if ((sum - y) == (2 * x))
            return (char *)"YES";
    }

    return (char *)"NO";
}
