// Name: Diagonal Difference
// Topics: Algorithms, Warmup

#include <stdio.h>
#include <stdlib.h>
#include <hackerrank.h>

int diagonal_difference(int, int, int **);

int main(void)
{
    int n = parse_int(ltrim(rtrim(readline())));
    int **arr = malloc(n * sizeof(int *));

    for (int i = 0; i < n; i++)
    {
        *(arr + i) = malloc(n * (sizeof(int)));
        char **arr_item_temp = split_string(rtrim(readline()));

        for (int j = 0; j < n; j++)
        {
            int arr_item = parse_int(*(arr_item_temp + j));
            *(*(arr + i) + j) = arr_item;
        }

        free(arr_item_temp);
    }

    int result = diagonal_difference(n, n, arr);
    printf("%d\n", result);

    for (int i = 0; i < n; i++)
    {
        free(*(arr + i));
    }

    free(arr);
    return 0;
}

int diagonal_difference(int arr_rows, int arr_columns, int **arr)
{
    int diff = 0;

    // The difference between the diagonals is also equivalent to sum of the
    // differences between each of their elements. Note that we have to make sure
    // to always start each subtraction with the same diagonal. In other words, if
    // visually speaking, we begin by subtracting left - right, then after we cross
    // the middle row of the matrix, we will be doing right - left.

    for (int i = 0; i < arr_rows; i++)
    {
        diff += *(*(arr + i) + i) - *(*(arr + i) + (arr_columns - i - 1));
    }

    return abs(diff);
}
