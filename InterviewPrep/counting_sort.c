#include <stdio.h>
#include <stdlib.h>
#include "tools/competitiveinput.h"

int *counting_sort(int, int *, int *);

int main(void)
{
    int n = parse_int(ltrim(rtrim(readline())));
    char **arr_temp = split_string(rtrim(readline()));
    int *arr = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        int arr_item = parse_int(*(arr_temp + i));
        *(arr + i) = arr_item;
    }

    int result_count;
    int *result = counting_sort(n, arr, &result_count);

    for (int i = 0; i < result_count; i++)
    {
        printf("%d", *(result + i));

        if (i != result_count - 1)
            printf(" ");
    }

    printf("\n");
    free(arr_temp);
    free(arr);
    free(result);

    return 0;
}

int *counting_sort(int arr_count, int *arr, int *result_count)
{
    *result_count = 100;
    int *occurrences = calloc(*result_count, sizeof(int));

    for (int i = 0; i < arr_count; i++)
    {
        int elem = *(arr + i);
        occurrences[elem]++;
    }

    return occurrences;
}
