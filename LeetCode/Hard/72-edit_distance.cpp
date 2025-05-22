// Name: 77. Edit Distance
// Topics: String, Dynamic Programming
// Companies:
// - Instacart
// - Zoho
// - EPAM Systems
// - Arcesium
// - TikTok
// - Rubrik
// - Snap
// - Flipkart
// - Microsoft
// - Accenture
// - Infosys
// - DE Shaw
// - Amazon
// - LinkedIn
// - Meta
// - Uber
// - Salesforce
// - Adobe
// - Bloomberg
// - Apple
// - Yahoo
// - tcs
// - Yandex

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

int min_distance(std::string, std::string);
void init_empty_string_dp(std::vector<std::vector<int>>&, size_t, size_t);

int main(void)
{
    int levenshtein_1 = min_distance("horse", "ros");
    int levenshtein_2 = min_distance("intention", "execution");

    std::cout << "72. Edit Distance" << std::endl;
    std::cout << levenshtein_1 << std::endl;
    std::cout << levenshtein_2 << std::endl;

    return 0;
}

int min_distance(std::string word1, std::string word2)
{
    size_t word1_len = word1.length();
    size_t word2_len = word2.length();

    if (word1_len == 0)
        return word2_len;

    if (word2_len == 0)
        return word1_len;

    // We use an extra row and column because empty strings are base cases we
    // need to consider to derive the calculations of the other string fragments.

    std::vector<std::vector<int>> levenshtein_dp(
        word1_len + 1,
        std::vector<int>(word2_len + 1, 8));

    init_empty_string_dp(levenshtein_dp, word1_len, word2_len);

    // Calculate the Levenshtein Distance between the two given words. Basically,
    // we need to find the fewest number of modification of operations to turn
    // word1 into word2. If we brute force it, we can observe that depending on
    // the operation we make, one or both string pointers move forward. That's
    // what we are simulating here, but more efficiently with dynamic programming:
    //
    // - Delete: i + 1
    // - Insert: j + 1
    // - Replace: i + 1 & j + 1

    for (int i = static_cast<int>(word1_len - 1); i >= 0; i--)
    {
        for (int j = static_cast<int>(word2_len - 1); j >= 0; j--)
        {
            if (word1[i] == word2[j])
            {
                // Equal letters, no change in number of operations so far.
                levenshtein_dp[i][j] = levenshtein_dp[i+1][j+1];
            }
            else
            {
                // Different letters, select the operation with the least amount
                // of moves to continue.
                levenshtein_dp[i][j] = 1 + std::min(
                    {levenshtein_dp[i+1][j],
                     levenshtein_dp[i][j+1],
                     levenshtein_dp[i+1][j+1]});
            }
        }
    }

    // The first tile will include the solution at the end.
    return levenshtein_dp[0][0];
}

void init_empty_string_dp(std::vector<std::vector<int>>& dp, size_t rows, size_t cols)
{
    // Empty to empty requires zero changes.
    dp[rows][cols] = 0;

    // Initialize the empty to non-empty row and column.
    size_t i;

    // Using i-- > 0 to avoid the pitfall of size_t not having negatives.
    for (i = rows; i-- > 0; )
        dp[i][cols] = rows - i;

    for (i = cols; i-- > 0; )
        dp[rows][i] = cols - i;
}
