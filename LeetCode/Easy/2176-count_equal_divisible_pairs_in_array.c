// Name: 2176. Count Equal and Divisible Pairs in an Array
// Topics: Array

#include <stdio.h>

int count_pairs(int *, size_t, int);

int main(void)
{
    int nums_1[] = { 3, 1, 2, 2, 2, 1, 3 };
    int nums_2[] = { 1, 2, 3, 4 };

    int goodies_1 = count_pairs(&nums_1[0], (size_t) 7, 2);
    int goodies_2 = count_pairs(&nums_2[0], (size_t) 4, 1);

    printf("%d\n", goodies_1);
    printf("%d\n", goodies_2);
    return 0;
}

int count_pairs(int *nums, size_t nums_size, int div)
{
    int eq_div_pairs = 0;

    for (int i = 0; i < nums_size - 1; i++)
    {
        for (int j = i + 1; j < nums_size; j++)
        {
            if ((*(nums + i) == *(nums + j)) && ((i * j) % div == 0))
                eq_div_pairs++;
        }
    }

    return eq_div_pairs;
}
