// Name: Simple Array Sum
// Topics: Algorithms, Warmup

#include <stdio.h>
#include <stdlib.h>
#include <hackerrank.h>

int simple_array_sum(int, int *);

int main(void)
{
    int arr_count = parse_int(ltrim(rtrim(readline())));
    char **arr_temp = split_string(rtrim(readline()));
    int *arr = (int *) malloc(arr_count * sizeof(int));

    for (int i = 0; i < arr_count; i++)
    {
        int arr_item = parse_int(*(arr_temp + i));
        *(arr + i) = arr_item;
    }

    int result = simple_array_sum(arr_count, arr);
    fprintf(stdout, "%d\n", result);

    free(arr_temp);
    free(arr);
    return 0;
}

int simple_array_sum(int arr_count, int *arr)
{
    int result = 0;

    // As its name implies, we have to iterate through all the array and add all
    // of its elements into the final result.

    for (int i = 0; i < arr_count; i++)
    {
        result += *(arr + i);
    }

    return result;
}
