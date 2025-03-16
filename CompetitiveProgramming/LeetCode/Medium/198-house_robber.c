// Name: 198. House Robber
// Topics: Array, Dynamic Programming
// Companies:
// - Cisco
// - Databricks
// - Arcesium
// - Airbnb
// - Agoda
// - PhonePe
// - ByteDance
// - LinkedIn
// - EPAM Systems
// - Infosys
// - Walmart Labs
// - Intuit
// - DE Shaw
// - Expedia
// - Tesla
// - Flipkart
// - Morgan Stanley
// - Accenture
// - Zoho
// - Citadel
// - Turing
// - Salesforce
// - Goldman Sachs
// - Nvidia
// - PayPal

#include <stdio.h>
#include <stdlib.h>

#define MAX(a, b) (((a) > (b)) ? (a) : (b))

int rob(int *, size_t);

int main(void)
{
    int houses_1[] = { 1, 2, 3, 1 };
    int houses_2[] = { 2, 7, 9, 3, 1 };
    int houses_3[] = { 2, 1, 1, 2 };

    int loot_1 = rob(&houses_1[0], 4);
    int loot_2 = rob(&houses_2[0], 5);
    int loot_3 = rob(&houses_3[0], 4);

    printf("%d\n", loot_1);
    printf("%d\n", loot_2);
    printf("%d\n", loot_3);
    return 0;
}

int rob(int *money_stashes, size_t num_houses)
{
    // If there is only one house, then we just rob that one for the maximum gain.

    if (num_houses == 1)
        return *money_stashes;

    // If there are two houses, we can only rob one of them, so we pick the one
    // with the highest loot.

    if (num_houses == 2)
        return MAX(*money_stashes, *(money_stashes + 1));

    // For more than two houses, we need to keep track of the gains of robbing
    // each house vs not, so as to respect the constraint of not robbing adjacent
    // houses, as that would get us busted.

    int *best_loots_dp = (int *) calloc(num_houses, sizeof(int));
    *best_loots_dp = *money_stashes;
    *(best_loots_dp + 1) = MAX(*money_stashes, *(money_stashes + 1));

    for (int i = 2; i < num_houses; i++)
    {
        // Iterate over each house. To decide whether or not to rob it, we compare
        // the outcomes of both choices. For this, we leverage the outcomes of
        // the previous 1 and 2 houses, so we can decide whether robbing it or
        // skipping it is better.

        int loot_if_rob = *(money_stashes + i) + *(best_loots_dp + i - 2);
        int loot_if_not_rob = *(best_loots_dp + i - 1);
        *(best_loots_dp + i) = MAX(loot_if_rob, loot_if_not_rob);
    }

    int result = *(best_loots_dp + num_houses - 1);
    free(best_loots_dp);
    return result;
}
