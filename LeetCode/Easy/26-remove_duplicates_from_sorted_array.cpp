// Name: 26. Remove Duplicates from Sorted Array
// Topics: Array, Two Pointers
// Companies:
// - Wipro
// - Bloomberg
// - Yahoo
// - Capgemini
// - Ozon
// - SAP
// - Adobe
// - Apple
// - Infosys
// - Microsoft
// - Amazon
// - Accenture
// - Qualcomm
// - ZScaler
// - EPAM Systems
// - Meta
// - Uber
// - Zoho
// - Flipkart
// - tcs
// - Oracle
// - Cisco

#include <iostream>
#include <vector>

int remove_duplicates(std::vector<int>&);
void print_resized_vector(std::vector<int>&, int);

int main(void)
{
    std::vector<int> nums_1 = { 1, 1, 2 };
    std::vector<int> nums_2 = { 0, 0, 1, 1, 1, 2, 2, 3, 3, 4 };

    int new_size_1 = remove_duplicates(nums_1);
    int new_size_2 = remove_duplicates(nums_2);

    print_resized_vector(nums_1, new_size_1);
    print_resized_vector(nums_2, new_size_2);
    return 0;
}

int remove_duplicates(std::vector<int>& nums)
{
    std::vector<int>::size_type nums_size = nums.size();

    // Can't have duplicates if we don't have at least 2 elements :)
    if (nums_size < 2)
        return (int) nums_size;

    int removed = 0;

    // To eliminate the duplicates, we'll iterate through the array to find them.
    // As we do this, we'll be keeping an "offset" of how many elements we have
    // removed so far, so we can "slide" the unique ones to their new corresponding
    // position in the array.

    for (int i = 1; i < nums_size; i++)
    {
        int current = nums[i];
        int actual = nums[i - removed - 1];

        if (current == actual)
        {
            removed++;
        }
        else
        {
            nums[i - removed] = current;
        }
    }

    return (int) nums_size - removed;
}

void print_resized_vector(std::vector<int>& vec, int new_size)
{
    std::cout << "[ " << vec[0];
    for (int i = 1; i < new_size; i++)
        std::cout << ", " << vec[i];
    std::cout << " ]" << std::endl;
}
