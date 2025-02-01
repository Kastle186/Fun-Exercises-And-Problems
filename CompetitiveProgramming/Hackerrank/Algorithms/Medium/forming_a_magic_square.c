#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <hackerrank.h>

int forming_magic_square(int, int, int **);

int main(void)
{
    int **s = (int **) malloc(3 * sizeof(int *));

    for (int i = 0; i < 3; i++)
    {
        *(s + i) = (int *) malloc(3 * (sizeof(int)));
        char **s_item_temp = split_string(rtrim(readline()));

        for (int j = 0; j < 3; j++)
        {
            int s_item = parse_int(*(s_item_temp + j));
            *(*(s + i) + j) = s_item;
        }

        free(s_item_temp);
    }

    int result = forming_magic_square(3, 3, s);
    fprintf(stdout, "%d\n", result);

    for (int k = 0; k < 3; k++)
    {
        free(*(s + k));
    }

    free(s);
    return 0;
}

int forming_magic_square(int s_rows, int s_columns, int **magic_square)
{
    // We know by mathematical definition that only 8 magic squares exist when
    // our dimension is 3x3.

    int possible_squares[8][3][3] = {
        {{4, 3, 8}, {9, 5, 1}, {2, 7, 6}},
        {{8, 3, 4}, {1, 5, 9}, {6, 7, 2}},
        {{8, 1, 6}, {3, 5, 7}, {4, 9, 2}},
        {{4, 9, 2}, {3, 5, 7}, {8, 1, 6}},
        {{2, 7, 6}, {9, 5, 1}, {4, 3, 8}},
        {{6, 7, 2}, {1, 5, 9}, {8, 3, 4}},
        {{6, 1, 8}, {7, 5, 3}, {2, 9, 4}},
        {{2, 9, 4}, {7, 5, 3}, {6, 1, 8}},
    };

    int min_cost = INT_MAX;

    // Check the cost of converting the square we were given to each of the magic
    // squares that we have.
    for (int i = 0; i < 8; i++)
    {
        int cur_cost = 0;

        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                int cost_of_change = abs(magic_square[j][k] - possible_squares[i][j][k]);
                cur_cost += cost_of_change;
            }
        }

        // Keep the lowest cost so far.
        if (cur_cost < min_cost)
            min_cost = cur_cost;
    }

    return min_cost;
}
