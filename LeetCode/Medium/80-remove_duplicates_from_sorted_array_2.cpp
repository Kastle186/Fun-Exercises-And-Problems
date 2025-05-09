// Name: 80. Remove Duplicates from Sorted Array II
// Topics: Array, Two Pointers
// Companies:
// - Accolite
// - Adobe
// - Bloomberg
// - Amazon
// - Meta
// - Zoho
// - Microsoft
// - tcs
// - Apple
// - TikTok
// - Yandex
// - Yahoo
// - Uber

#include <iostream>
#include <vector>

int remove_duplicates(std::vector<int>&);
void print_shortened_vector(std::vector<int>&, int);

int main(void)
{
    std::vector<int> dups_1 = { 1, 1, 1, 2, 2, 3 };
    std::vector<int> dups_2 = { 0, 0, 1, 1, 1, 1, 2, 3, 3 };

    int uniq_size_1 = remove_duplicates(dups_1);
    int uniq_size_2 = remove_duplicates(dups_2);

    std::cout << "80. Remove Duplicates from Sorted Array II" << std::endl;

    print_shortened_vector(dups_1, uniq_size_1);
    print_shortened_vector(dups_2, uniq_size_2);

    return 0;
}

int remove_duplicates(std::vector<int>& nums)
{
    // Counter for the new length.
    int uniqs_size = 0;

    // If we have one or zero copies of the current number, then copy it to the
    // current new position and continue advancing. Triples and on are skipped.

    for (int num : nums)
    {
        if (uniqs_size < 2 || num != nums[uniqs_size - 2])
            nums[uniqs_size++] = num;
    }

    return uniqs_size;
}

void print_shortened_vector(std::vector<int>& vec, int new_size)
{
    std::cout << "[ " << vec[0];

    for (int i = 1; i < new_size; i++)
        std::cout << ", " << vec[i];

    std::cout << " ]" << std::endl;
}
