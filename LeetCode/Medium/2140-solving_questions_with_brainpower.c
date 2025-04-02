// Name: 2140. Solving Questions With Brainpower
// Topics: Array, Dynamic Programming

#include <stdio.h>
#include <stdlib.h>

long long most_points(int **, size_t, int *);
long long calculate(int **, size_t, long long *, int);
long long llmax(long long, long long);

int main(void)
{
    size_t questions_1_size = 4;
    size_t questions_2_size = 5;

    // Allocate the memory for each 2D test array.

    int **questions_1 = (int **) calloc(questions_1_size, sizeof(int *));
    int **questions_2 = (int **) calloc(questions_2_size, sizeof(int *));

    for (int i = 0; i < questions_1_size; i++)
        *(questions_1 + i) = (int *) calloc(2, sizeof(int));

    for (int j = 0; j < questions_2_size; j++)
        *(questions_2 + j) = (int *) calloc(2, sizeof(int));

    // Add the elements of the 1st array.

    *(*questions_1) = 3;
    *(*(questions_1) + 1) = 2;

    *(*(questions_1 + 1)) = 4;
    *(*(questions_1 + 1) + 1) = 3;

    *(*(questions_1 + 2)) = 4;
    *(*(questions_1 + 2) + 1) = 4;

    *(*(questions_1 + 3)) = 2;
    *(*(questions_1 + 3) + 1) = 5;

    // Add the elements of the 2nd array.

    *(*questions_2) = 1;
    *(*(questions_2) + 1) = 1;

    *(*(questions_2 + 1)) = 2;
    *(*(questions_2 + 1) + 1) = 2;

    *(*(questions_2 + 2)) = 3;
    *(*(questions_2 + 2) + 1) = 3;

    *(*(questions_2 + 3)) = 4;
    *(*(questions_2 + 3) + 1) = 4;

    *(*(questions_2 + 4)) = 5;
    *(*(questions_2 + 4) + 1) = 5;

    // Run our algorithm for the exercise and print the results.

    long long optimal_1 = most_points(questions_1, 4, NULL);
    long long optimal_2 = most_points(questions_2, 5, NULL);

    printf("%lld\n", optimal_1);
    printf("%lld\n", optimal_2);

    // Free the memory from each pair of the arrays.

    for (int i = 0; i < questions_1_size; i++)
        free(*(questions_1 + i));

    for (int j = 0; j < questions_2_size; j++)
        free(*(questions_2 + j));

    // Free the arrays themselves and finish.

    free(questions_1);
    free(questions_2);

    return 0;
}

long long most_points(int **questions, size_t questions_size, int *questions_col_size)
{
    long long *dp = (long long *) calloc(questions_size, sizeof(long long));

    for (int i = 0; i < questions_size; i++)
        *(dp + i) = -1L;

    long long result = calculate(questions, questions_size, dp, 0);
    free(dp);
    return result;
}

long long calculate(int **questions, size_t questions_size, long long *dp, int index)
{
    // If we're past all the questions, then there are no more points to be earned.
    if (index >= questions_size)
        return 0L;

    // If we've already passed by this question, then return the value we calculated
    // for it.
    if (*(dp + index) != -1L)
        return *(dp + index);

    int points = *(*(questions + index));
    int brainpower = *(*(questions + index) + 1);

    // Now, we can either answer the question and skip the next ones, or we can
    // skip it and move on to the next one. Our value is the greater of both options.
    *(dp + index) = llmax(
        points + calculate(questions, questions_size, dp, index + brainpower + 1),
        calculate(questions, questions_size, dp, index + 1));

    return *(dp + index);
}

long long llmax(long long lla, long long llb)
{
    return lla >= llb ? lla : llb;
}
