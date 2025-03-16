// Name: 215. Kth Largest Element in an Array
// Topics: Array, Divide and Conquer, Sorting, Heap (Priority Queue), Quickselect
// Companies:
// - Pocket Gems
// - Verily
// - Spotify
// - ByteDance
// - eBay
// - Walmart Labs
// - Wipro
// - ServiceNow
// - LinkedIn
// - Salesforce
// - Grab
// - Morgan Stanley
// - Netflix
// - Oracle
// - EPAM Systems
// - Infosys
// - SAP
// - Nvidia
// - Deutsche Bank
// - Flipkart
// - Intuit
// - Goldman Sachs
// - Samsung
// - Turing
// - PayPal
// - Yandex
// - tcs

#include <iostream>
#include <cstdlib>
#include <queue>
#include <vector>

int find_kth_largest_heap(std::vector<int> &, int);

int main(void)
{
    std::vector<int> vec1 = { 3, 2, 1, 5, 6, 4 };
    std::vector<int> vec2 = { 3, 2, 3, 1, 2, 4, 5, 5, 6};

    int kth_1 = find_kth_largest_heap(vec1, 2);
    int kth_2 = find_kth_largest_heap(vec2, 4);

    std::cout << kth_1 << std::endl;
    std::cout << kth_2 << std::endl;
    return 0;
}

int find_kth_largest_heap(std::vector<int> &nums, int k)
{
    // To solve this problem, we will be using a max heap/priority queue. We'll
    // add all the elements of the list, and then extract k elements to get the
    // kth largest one.

    std::priority_queue<int> queue_heap;

    for (int n : nums)
    {
        queue_heap.push(n);
    }

    for (int i = 0; i < k - 1; i++)
    {
        queue_heap.pop();
    }

    return queue_heap.top();
}
