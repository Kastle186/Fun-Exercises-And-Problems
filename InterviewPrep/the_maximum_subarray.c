#include <stdio.h>
#include <stdlib.h>
#include "tools/hackerrank.h"

#ifndef MAX
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#endif // MAX

int *max_subarray(int, int *, int *);

int main(void)
{
    int t = parse_int(ltrim(rtrim(readline())));

    for (int t_itr = 0; t_itr < t; t_itr++)
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
        int *result = max_subarray(n, arr, &result_count);

        for (int i = 0; i < result_count; i++)
        {
            printf("%d", *(result + i));

            if (i != result_count - 1)
            {
                printf(" ");
            }
        }

        printf("\n");
        free(arr_temp);
        free(arr);
        free(result);
    }

    return 0;
}

int *max_subarray(int arr_count, int *arr, int *result_count)
{
    *result_count = 2;
    int *subarrseq = calloc(*result_count, sizeof(int));

    // To find the maximum subarray, we will be applying Kadane's Algorithm.
    // This consists in using the sum ending of the previous element to define
    // whether we continue with this subarray, or start a new one. We also keep
    // track of the highest sum so far, as that will be our final result.

    int max_sum = *arr;
    int this_sum = *arr;

    for (int i = 1; i < arr_count; i++)
    {
        // Calling our MAX macro here is a shorthand way of telling the program
        // to continue adding to the current subarray or start a new one.
        this_sum = MAX(this_sum + *(arr + i), *(arr + i));

        // Keep track of the highest sum we've encountered so far.
        max_sum = MAX(max_sum, this_sum);
    }

    *subarrseq = max_sum;

    // To find the maximum subsequence, we simply must add all positive numbers in
    // our array.

    int max_seq = 0;

    for (int j = 0; j < arr_count; j++)
    {
        int elem = *(arr + j);

        if (elem > 0)
            max_seq += elem;
    }

    // If we didn't find a single positive number, then we have to search for the
    // smallest (or technically largest) negative number, and that's the maximum
    // subsequence result we are looking for.

    if (max_seq <= 0)
    {
        max_seq = *arr;

        for (int k = 1; k < arr_count; k++)
            max_seq = MAX(max_seq, *(arr + k));
    }

    *(subarrseq + 1) = max_seq;
    return subarrseq;
}
