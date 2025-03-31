// Name: 2551. Put Marbles in Bags
// Topics: Array, Greedy, Sorting, Heap/Priority Queue
// Companies:
// - DE Shaw
// - Flipkart

#include <stdio.h>
#include <stdlib.h>

long long put_marbles(int *, size_t, int);
int llcompare(const void *, const void *);

int main(void)
{
    int weights_1[] = { 1, 3, 5, 1 };
    int weights_2[] = { 1, 3 };

    long long costs_1 = put_marbles(&weights_1[0], (size_t) 4, 2);
    long long costs_2 = put_marbles(&weights_2[0], (size_t) 2, 2);

    printf("%lld\n", costs_1);
    printf("%lld\n", costs_2);
    return 0;
}

long long put_marbles(int *weights, size_t weights_size, int bags)
{
    // If we are asked this number of bags, then the only solution would be to put
    // one marble in each bag, and therefore the min and max would be the same.

    if (bags == weights_size)
        return 0;

    // First, we need to compute the costs (sums) of each adjacent pair in the
    // weights array. Then, we'll sort them to find easily the mins and maxs.
    // I'll explain why later.

    int num_pairs = weights_size - 1;
    long long *adj_pairs_costs = (long long *) calloc(num_pairs,
                                                      sizeof(long long));

    for (int i = 0; i < num_pairs; i++)
        *(adj_pairs_costs + i) = *(weights + i) + *(weights + i + 1);

    qsort((void *) &adj_pairs_costs[0],
          (size_t) num_pairs,
          sizeof(long long),
          llcompare);

    // Now, to find the minimum and maximum costs of the bags, we will sum up
    // the first k costs and the last k costs, and get the difference between
    // these two results.
    //
    // Why does this work?
    //
    // Since all elements must end up in one bag, then by definition, both,
    // the minimum and maximum, will have the first plus the last. And therefore,
    // will cancel themselves out when we effectuate the difference. Consequently,
    // the only sums we have left are those of the "splits" for each bag. And what
    // are these? Yes, they are adjacent pairs indeed!

    long long min_cost = 0L;
    long long max_cost = 0L;

    for (int j = 0; j < bags - 1; j++)
    {
        min_cost += *(adj_pairs_costs + j);
        max_cost += *(adj_pairs_costs + num_pairs - j - 1);
    }

    free(adj_pairs_costs);
    return max_cost - min_cost;
}

int llcompare(const void *a, const void *b)
{
    long long a_unwrap = *(long long *) a;
    long long b_unwrap = *(long long *) b;

    if (a_unwrap < b_unwrap) return -1;
    if (a_unwrap > b_unwrap) return 1;
    return 0;
}
