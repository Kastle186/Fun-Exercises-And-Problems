#include <iostream>
#include <algorithm>
#include <functional>
#include <map>
#include "tools/hackerrank.hpp"

int lilys_homework(std::vector<int>);
int beautifier(std::vector<int>, bool);

int main(void)
{
    std::string n_temp;
    std::getline(std::cin, n_temp);

    int n = std::stoi(ltrim(rtrim(n_temp)));

    std::string arr_temp_temp;
    std::getline(std::cin, arr_temp_temp);

    std::vector<std::string> arr_temp = split(rtrim(arr_temp_temp));
    std::vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        int arr_item = std::stoi(arr_temp[i]);
        arr[i] = arr_item;
    }

    int result = lilys_homework(arr);
    std::cout << result << std::endl;
    return 0;
}

int lilys_homework(std::vector<int> arr)
{
    // The 'beautiful' array property can be summed up as whether the array is
    // sorted. However, we can't know beforehand whether sorting ascendingly
    // or descendingly will yield the least amount of swaps, so we have to try
    // out both options.
    int ascending_swaps = beautifier(arr, false);
    int descending_swaps = beautifier(arr, true);
    return std::min(ascending_swaps, descending_swaps);
}

int beautifier(std::vector<int> raw_arr, bool reverse)
{
    // We don't want to touch the original array, so we create copies for the
    // helper simulation one, and the sorted guiding one.
    std::vector<int> helper_arr = raw_arr;
    std::vector<int> sorted_arr = raw_arr;

    if (reverse)
        std::sort(sorted_arr.begin(), sorted_arr.end(), std::greater<int>());
    else
        std::sort(sorted_arr.begin(), sorted_arr.end(), std::less<int>());

    // First, we need to keep track of which index each element was originally in.
    // This is so that, in the general sense, we can know when to swap and where.
    std::map<int, int> orig_indexes;

    for (int i = 0; i < helper_arr.size(); i++)
    {
        int element = helper_arr[i];
        orig_indexes[element] = i;
    }

    // Next comes the main algorithm. We iterate through the sorted array, checking
    // for the index of each element in the original array by means of the map we
    // built above. If the indexes don't match, then we perform a swap.
    int swaps = 0;

    for (int iter_idx = 0; iter_idx < helper_arr.size(); iter_idx++)
    {
        int actual_val = helper_arr[iter_idx];
        int sorted_val = sorted_arr[iter_idx];
        int orig_idx = orig_indexes[sorted_val];

        // Element is in the right spot, so no swaps are needed.
        if (orig_idx == iter_idx)
            continue;

        // If this value is located at different places in the sorted and the
        // original arrays, then this is a swap we have to perform.
        helper_arr[orig_idx] = actual_val;
        helper_arr[iter_idx] = sorted_val;

        // Update the swaps count, and our map with the updated index of the value.
        orig_indexes[actual_val] = orig_idx;
        swaps++;
    }

    return swaps;
}
