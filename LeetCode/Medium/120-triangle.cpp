// Name: 120. Triangle
// Topics: Array, Dynamic Programming
// Companies:
// - Agoda
// - DE Shaw
// - Salesforce

#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>

int minimum_total(std::vector<std::vector<int>>&);
int minimum_total_top_bottom(std::vector<std::vector<int>>&);
void trace_path(std::vector<std::vector<int>>&, int *, int *, int, int, int);

int main(void)
{
    std::vector<std::vector<int>> triangle1 =
    {
        { 2 },
        { 3, 4 },
        { 6, 5, 7 },
        { 4, 1, 8, 3 }
    };

    std::vector<std::vector<int>> triangle2 =
    {
        { -10 }
    };

    std::vector<std::vector<int>> triangle3 =
    {
        { -1 },
        { 2, 3 },
        { 1, -1, -3 }
    };

    int tri1 = minimum_total(triangle1);
    int tri2 = minimum_total(triangle2);
    int tri3 = minimum_total(triangle3);

    std::cout << tri1 << std::endl;
    std::cout << tri2 << std::endl;
    std::cout << tri3 << std::endl;

    return 0;
}

int minimum_total(std::vector<std::vector<int>>& triangle)
{
    // We tried the top-bottom approach in the below functions, and while that
    // works very nicely, it gives TLE in a certain edge case :(
    // So, here we try a bottom-top approach instead, as it requires a bit less
    // calculations to reach the answer.

    int levels = triangle.size();

    // If there's only one level, then that's the answer.

    if (levels == 1)
        return triangle[0][0];

    // Adding a +1 here to avoid an index out of bounds when processing the
    // bottom level.

    int totals_dp[levels + 1];
    std::fill(totals_dp, totals_dp + levels + 1, 0);

    // For triangles larger than 1 level, we begin at the second to last level.
    // Each index of totals_dp will contain the minimum sum so far at that level,
    // following the path that arrives at that index. Since the levels get smaller
    // as we ascend, when we finish, the first element of our dp array will contain
    // the answer.

    for (int lv = levels - 1; lv >= 0; lv--)
    {
        for (int index = 0; index <= lv; index++)
        {
            int curr_value = triangle[lv][index];
            totals_dp[index] =
                std::min(totals_dp[index], totals_dp[index + 1]) + curr_value;
        }
    }

    return totals_dp[0];
}

int minimum_total_top_bottom(std::vector<std::vector<int>>& triangle)
{
    int levels = triangle.size();
    int totals_dp[levels];
    int min_total = INT_MAX;

    // To solve this problem, we will be keeping track of the current minimum
    // of all possible path additions so far at each level. The first level,
    // Level 0, only has one element, so we can initialize that one directly.
    // Then, we start recursing on each level, keeping track of the current minimum.

    std::fill(totals_dp, totals_dp + levels, INT_MAX);
    totals_dp[0] = triangle[0][0];
    trace_path(triangle, &totals_dp[0], &min_total, 1, 0, levels);
    return min_total;
}

void trace_path(std::vector<std::vector<int>>& triangle,
                int *dp,
                int *current_min,
                int num_level,
                int level_index,
                int total_levels)
{
    // If we've reached the bottom of the triangle, then we compare the result
    // we got from this path with the minimum overall, and keep the smallest.

    if (num_level >= total_levels)
    {
        *current_min = std::min(*current_min, dp[num_level - 1]);
        return ;
    }

    // Add each element to the current result from the previous level, and update
    // if this path yields a smaller sum. Then, recurse to the next level. It is
    // important to mention that the triangle follows a tree-like structure, so
    // each recursive call checks only two more values, those being the child nodes,
    // if we represented the triangle as a tree.

    for (int i = level_index; i <= level_index + 1; i++)
    {
        int lv_value = triangle[num_level][i];
        dp[num_level] = std::min(dp[num_level], dp[num_level-1] + lv_value);
        trace_path(triangle, dp, current_min, num_level + 1, i, total_levels);

        // Reset this level's DP value as we'll now be processing a different
        // subtree.
        dp[num_level] = INT_MAX;
    }
}
