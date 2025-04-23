// Name: 295. Find Median from Data Stream
// Topics: Two Pointers, Design, Sorting, Heap/Priority Queue, Data Stream
// Companies:
// - Splunk
// - IXL
// - Anduril
// - Docusign
// - Pinterest
// - Spotify
// - Nvidia
// - Citadel
// - Google
// - Agoda
// - Salesforce
// - Snowflake
// - Samsung
// - Goldman Sachs
// - PayPal

#include <iostream>
#include <functional>
#include <queue>
#include <vector>

// This class is basically a median-heap. We'll be using two heaps to keep track
// of each half of elements: A max-heap for the lesser half, and a min-heap for
// the greater half. This way, we can easily get the median values right away.

class MedianFinder
{
private:
    std::priority_queue<int> less_than_median;
    std::priority_queue<int, std::vector<int>, std::greater<>> more_than_median;

public:
    MedianFinder() { }

    void add_num(int num)
    {
        // Add to lesser half, and then more the largest from lesser half to the
        // greater half. This way, we can maintain the sorting/ordering property.

        less_than_median.push(num);
        more_than_median.push(less_than_median.top());
        less_than_median.pop();

        // Rebalance if one of our halves is 2 or more elements larger than the
        // other to preserve the halves principle.

        if ((more_than_median.size() - less_than_median.size()) > 1)
        {
            less_than_median.push(more_than_median.top());
            more_than_median.pop();
        }
    }

    double find_median()
    {
        std::priority_queue<int>::size_type ltm_size = less_than_median.size();
        std::priority_queue<int>::size_type mtm_size = more_than_median.size();

        // Same size: Median is the average of the two middle values.

        if (ltm_size == mtm_size)
        {
            double med_low = (double) less_than_median.top();
            double med_high = (double) more_than_median.top();
            return (med_low + med_high) / 2.0;
        }

        // Else, median is the exact middle element, which is at the top of the
        // larger heap.

        return ltm_size > mtm_size
            ? (double) less_than_median.top()
            : (double) more_than_median.top();
    }
};

int main(void)
{
    std::cout << "295. Find Median from Data Stream" << std::endl;

    MedianFinder med_heap;
    med_heap.add_num(1);
    med_heap.add_num(2);

    std::cout << med_heap.find_median() << std::endl;

    med_heap.add_num(3);
    std::cout << med_heap.find_median() << std::endl;

    return 0;
}
