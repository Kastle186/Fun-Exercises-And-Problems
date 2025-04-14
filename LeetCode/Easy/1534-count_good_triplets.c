// Name: 1534. Count Good Triplets
// Topics: Array, Enumeration

#include <stdio.h>
#include <stdlib.h>

int count_good_triplets(int *, size_t, int, int, int);

int main(void)
{
    int arr_1[] = { 3, 0, 1, 1, 9, 7 };
    int arr_2[] = { 1, 1, 2, 2, 3 };

    int goody_threes_1 = count_good_triplets(&arr_1[0], (size_t) 6, 7, 2, 3);
    int goody_threes_2 = count_good_triplets(&arr_2[0], (size_t) 5, 0, 0, 1);

    printf("%d\n", goody_threes_1);
    printf("%d\n", goody_threes_2);
    return 0;
}

int count_good_triplets(int *arr, size_t arr_size, int a, int b, int c)
{
    // Since in this problem the constraints are small enough, we'll take advantage
    // of that to be funny and practice a literal brute-force solution.

    int goodies = 0;

    for (int i = 0; i < arr_size; i++)
    {
        for (int j = i + 1; j < arr_size; j++)
        {
            // If i - j <= a then we start looking for the k's that fulfill the
            // other two conditions. Otherwise, we can skip these triplets.

            if (abs(*(arr + i) - *(arr + j)) <= a)
            {
                for (int k = j + 1; k < arr_size; k++)
                {
                    if (abs(*(arr + j) - *(arr + k)) <= b
                        && abs(*(arr + i) - *(arr + k)) <= c)
                    {
                        goodies++;
                    }
                }
            }
        }
    }

    return goodies;
}
