#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include "tools/hackerrank.hpp"

int max_min(int, std::vector<int>);

int main(void)
{
    std::string n_temp;
    getline(std::cin, n_temp);

    int n = std::stoi(ltrim(rtrim(n_temp)));

    std::string k_temp;
    getline(std::cin, k_temp);

    int k = stoi(ltrim(rtrim(k_temp)));
    std::vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        std::string arr_item_temp;
        getline(std::cin, arr_item_temp);

        int arr_item = std::stoi(ltrim(rtrim(arr_item_temp)));
        arr[i] = arr_item;
    }

    int result = max_min(k, arr);
    std::cout << result << std::endl;

    return 0;
}

int max_min(int k, std::vector<int> vec)
{
    // If we want to minimize the difference between the smallest and largest
    // elements in the subarrays, then we want to build them with the closest
    // numbers we can get. To make this easier, first we sort our array/vector.

    std::sort(vec.begin(), vec.end());
    int unfairness = std::numeric_limits<int>::max();

    // And now we can iterate the potential chunks by sliding the "subarray ruler"
    // one element at a time.

    for (int i = 0; i < vec.size() - k + 1; i++)
    {
        int lowest = vec[i];
        int highest = vec[i + k - 1];
        int chunk_diff = highest - lowest;

        if (chunk_diff < unfairness)
            unfairness = chunk_diff;
    }

    return unfairness;
}
