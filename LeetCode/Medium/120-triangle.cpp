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
void trace_path(std::vector<std::vector<int>>&, int *, int, int, int);

int main(void)
{
    return 0;
}

int minimum_total(std::vector<std::vector<int>>& triangle)
{
    int levels = triangle.size();
    int totals_dp[levels];

    std::fill(totals_dp, totals_dp + levels, INT_MAX);
    totals_dp[0] = triangle[0][0];
    trace_path(triangle, &totals_dp[0], 1, 0, levels);

    return totals_dp[levels - 1];
}

void trace_path(std::vector<std::vector<int>>& triangle,
                int *dp,
                int num_level,
                int level_index,
                int total_levels)
{
    if (num_level >= total_levels)
        return ;
}
