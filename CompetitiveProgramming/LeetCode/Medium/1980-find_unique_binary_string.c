// Name: 1980. Find Unique Binary String
// Topics: Array, Hash Table, String, Backtracking

#include <stdio.h>
#include <stdlib.h>

char *find_different_binary_string(char **, size_t);

int main(void)
{
    char *binset_1[] = { "01", "10" };
    char *binset_2[] = { "00", "01" };
    char *binset_3[] = { "111", "011", "001" };

    char *new_bin_1 = find_different_binary_string(&binset_1[0], 2);
    char *new_bin_2 = find_different_binary_string(&binset_2[0], 2);
    char *new_bin_3 = find_different_binary_string(&binset_3[0], 3);

    printf("%s\n", new_bin_1);
    printf("%s\n", new_bin_2);
    printf("%s\n", new_bin_3);

    free(new_bin_1);
    free(new_bin_2);
    free(new_bin_3);
    return 0;
}

char *find_different_binary_string(char **bins, size_t num_bins)
{
    // Adding a +1 here for the null terminator character.
    char *diff_bin = (char *) calloc(num_bins + 1, sizeof(char));

    // To solve this problem, we will be using Cantor's Diagonalization.
    // In summary, this mathematical proof demonstrates that given a set of
    // numbers, if we tweak one digit from each one in a diagonal form (i.e. the
    // first digit of the first number, the second digit of the second number,
    // and so on), that diagonal will have a new number that is guaranteed to
    // not be already in the set we were given.

    for (int i = 0; i < num_bins; i++)
    {
        char *next_num = *(bins + i);
        char new_bit = *(next_num + i) == '0' ? '1' : '0';
        *(diff_bin + i) = new_bit;
    }

    *(diff_bin + num_bins) = '\0';
    return diff_bin;
}
