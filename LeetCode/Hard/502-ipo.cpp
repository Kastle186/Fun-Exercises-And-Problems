// Name: 502. IPO
// Topics: Array, Greedy, Sorting, Heap/Priority Queue
// Companies:
// - Zeta
// - Docusign
// - PhonePe
// - Salesforce

#include <iostream>
#include <functional>
#include <queue>
#include <utility>
#include <vector>

int find_maximized_capital(int, int, std::vector<int>&, std::vector<int>&);

int main(void)
{
    std::vector<int> profits_1 = { 1, 2, 3 };
    std::vector<int> capitals_1 = { 0, 1, 1 };

    std::vector<int> profits_2 = { 1, 2, 3 };
    std::vector<int> capitals_2 = { 0, 1, 2 };

    int max_gain_1 = find_maximized_capital(2, 0, profits_1, capitals_1);
    int max_gain_2 = find_maximized_capital(3, 0, profits_2, capitals_2);

    std::cout << max_gain_1 << std::endl;
    std::cout << max_gain_2 << std::endl;

    return 0;
}

int find_maximized_capital(int projects,
                           int capital,
                           std::vector<int>& proj_profits,
                           std::vector<int>& proj_capitals)
{
    // First, we'll zip the project profits and capitals into a priority queue
    // or min heap using the capital as criteria. This is so we can always select
    // the cheapest project, AND also make sure we can afford it.

    std::priority_queue<
        std::pair<int, int>,
        std::vector<std::pair<int, int>>,
        std::greater<>
    > by_capital;

    // We are guaranteed that both, proj_profits and proj_capitals, are the
    // same size.
    for (int i = 0; i < proj_capitals.size(); i++)
    {
        std::pair<int, int> proj_info = {proj_capitals[i], proj_profits[i]};
        by_capital.push(proj_info);
    }

    // Next, we'll also need a helper priority queue where we will be "sorting" the
    // projects by profit. By using both queues together, we'll be able to select
    // the projects that yield the best profit, while also ensuring they are part
    // of the affordable budget group.

    // Comparator for the max heap to work with the second element of the pairs.
    auto cmp = [](const std::pair<int, int>& a, const std::pair<int, int>& b)
    {
        return a.second < b.second;
    };

    std::priority_queue<
        std::pair<int, int>,
        std::vector<std::pair<int, int>>,
        decltype(cmp)
    > by_profit(cmp);

    // And here is the main core of this problem's solution.
    for (int j = 0; j < projects; j++)
    {
        // First, we move as many projects as we can from the by_capital queue to
        // the by_profit one. All the ones that we can currently afford, to be
        // more precise.

        while (!by_capital.empty() && by_capital.top().first <= capital)
        {
            by_profit.push(by_capital.top());
            by_capital.pop();
        }

        // There are no more projects we can do.
        if (by_profit.empty())
            break;

        // Once we have all the projects we can currently afford, we'll "do" them
        // one by one, and add their profit to our current capital/budget. It is
        // worth noting that we are only doing one per loop iteration, because of
        // the potential possibility of "unlocking" a new more profitable project
        // with the gains of the last current one.

        capital += by_profit.top().second;
        by_profit.pop();
    }

    return capital;
}

// ******** //
// ZIPPING! //
// ******** //

// #include <iostream>
// #include <vector>
// #include <utility>

// int main() {
//     std::vector<int> a = {1, 2, 3};
//     std::vector<std::string> b = {"one", "two", "three"};

//     for (size_t i = 0; i < std::min(a.size(), b.size()); ++i) {
//         std::pair<int, std::string> zipped = {a[i], b[i]};
//         std::cout << zipped.first << " -> " << zipped.second << '\n';
//     }

//     return 0;
// }

// ******** //
// MAX HEAP //
// ******** //

// #include <iostream>
// #include <queue>

// int main() {
//     std::priority_queue<int> pq;

//     pq.push(10);
//     pq.push(30);
//     pq.push(20);
//     pq.push(5);

//     while (!pq.empty()) {
//         std::cout << pq.top() << " ";
//         pq.pop();
//     }

//     return 0;
// }

// ******** //
// MIN HEAP //
// ******** //

// #include <iostream>
// #include <queue>
// #include <vector>
// #include <functional>

// int main() {
//     std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

//     minHeap.push(10);
//     minHeap.push(30);
//     minHeap.push(20);
//     minHeap.push(5);

//     while (!minHeap.empty()) {
//         std::cout << minHeap.top() << " ";
//         minHeap.pop();
//     }

//     return 0;
// }

// ********** //
// WITH PAIRS //
// ********** //

// std::priority_queue<
//     std::pair<int, int>,
//     std::vector<std::pair<int, int>>,
//     std::greater<std::pair<int, int>>
// > pq;

// ******************************* //
// WITH PAIRS USING SECOND ELEMENT //
// ******************************* //

// struct CompareSecond {
//     bool operator()(const std::pair<int, int>& a, const std::pair<int, int>& b) {
//         return a.second > b.second; // Min-heap based on second
//     }
// };

// std::priority_queue<
//     std::pair<int, int>,
//     std::vector<std::pair<int, int>>,
//     CompareSecond
// > pq;

// ***************** //
// CUSTOM COMPARATOR //
// ***************** //

// #include <iostream>
// #include <queue>
// #include <vector>
// #include <functional>

// int main() {
//     auto cmp = [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
//         return a.second > b.second;  // min-heap by second value
//     };

//     std::priority_queue<
//         std::pair<int, int>,
//         std::vector<std::pair<int, int>>,
//         decltype(cmp)
//     > pq(cmp);  // Pass lambda as constructor arg

//     pq.push({1, 50});
//     pq.push({2, 30});
//     pq.push({3, 40});

//     while (!pq.empty()) {
//         auto p = pq.top();
//         pq.pop();
//         std::cout << "{" << p.first << ", " << p.second << "}\n";
//     }

//     return 0;
// }
