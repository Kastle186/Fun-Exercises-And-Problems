// Name: 77. Combinations
// Topics: Backtracking
// Companies:
// - Adobe
// - Microsoft
// - Apple
// - Amazon
// - Bloomberg
// - Meta
// - Google
// - Uber

import Foundation

func Main()
{
    let combinations1: [[Int]] = combine(n: 4, k: 2)
    let combinations2: [[Int]] = combine(n: 1, k: 1)

    print(combinations1)
    print(combinations2)
}

func combine(n: Int, k: Int) -> [[Int]]
{
    // To generate all the possible combinations of k numbers from 1 to n, we will
    // be using a backtracking approach.

    var combinations: [[Int]] = []
    var current: [Int] = []
    generate(combinations: &combinations, current: &current, index: 1, n: n, k: k)
    return combinations
}

func generate(combinations: inout [[Int]],
              current: inout [Int],
              index: Int,
              n: Int,
              k: Int) -> Void
{
    // Base case: Our current combination has reached the expected size. We append
    //            it to the final result and continue to the next.

    if current.count == k
    {
        combinations.append(current)
        return
    }

    // Finish case: We've finished processing the numbers range in this path.

    if index > n
    {
        return
    }

    // If we got here, then we are still adding numbers to this combination. So,
    // add the current one, and then recurse for the next one.

    current.append(index)
    generate(combinations: &combinations,
             current: &current,
             index: index + 1,
             n: n,
             k: k)

    // Then, backtrack so we can begin generating the combination(s) with the
    // next number(s).

    current.removeLast()
    generate(combinations: &combinations,
             current: &current,
             index: index + 1,
             n: n,
             k: k)
}
