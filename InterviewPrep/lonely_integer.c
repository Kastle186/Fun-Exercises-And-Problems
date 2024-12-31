#include <stdio.h>
#include "tools/competitiveinput.h"

int lonely_integer(int, int *);

int main(void)
{
    int n = parse_int(ltrim(rtrim(readline())));
    char **a_temp = split_string(rtrim(readline()));
    int *a = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        int a_item = parse_int(*(a_temp + i));
        *(a + i) = a_item;
    }

    int result = lonely_integer(n, a);
    printf("%d\n", result);

    free(a_temp);
    free(a);
    return 0;
}

int lonely_integer(int arr_count, int *arr)
{
    // We can solve this one with some bit magic!
    //
    // If we xor any number with itself, then the result is 0. In other words,
    // if we xor the entire input, all the pairs will end up cancelling themselves,
    // leaving us with only the lonely integer!

    int lonely = 0;

    for (int i = 0; i < arr_count; i++)
    {
        lonely ^= *(arr + i);
    }

    return lonely;
}
