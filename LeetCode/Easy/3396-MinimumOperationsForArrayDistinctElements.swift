// Name: 3396. Minimum Number of Operations to Make Elements in Array Distinct
// Topics: Array, Hash Table

import Foundation

func Main()
{
    var ops1: Int = minimumOperationsHashMap(nums: [1, 2, 3, 4, 2, 3, 3, 5, 7])
    var ops2: Int = minimumOperationsHashMap(nums: [4, 5, 6, 4, 4])
    var ops3: Int = minimumOperationsHashMap(nums: [6, 7, 8, 9])

    print(ops1)
    print(ops2)
    print(ops3)

    ops1 = minimumOperationsBackwards(nums: [1, 2, 3, 4, 2, 3, 3, 5, 7])
    ops2 = minimumOperationsBackwards(nums: [4, 5, 6, 4, 4])
    ops3 = minimumOperationsBackwards(nums: [6, 7, 8, 9])

    print(ops1)
    print(ops2)
    print(ops3)
}

func minimumOperationsHashMap(nums: [Int]) -> Int
{
    // To solve this problem, we will be using a hash table to keep track of the
    // times each number occurrs in the array. Also, count of how many are repeated
    // so far. This will help us be more efficient when removing the duplicates.

    var ops = 0
    var repeats = 0
    var elemOccurrences = [Int: Int]()

    for n in nums
    {
        // Simpler way of doing an if contains() then add else update.
        elemOccurrences[n, default: 0] += 1

        // If we've found the second occurrence of a number, then we have a repeat
        // we have to remove later.
        if elemOccurrences[n] == 2
        {
            repeats += 1
        }
    }

    var indexBoundary = 2

    // Next, we'll go "removing" elements in chunks of three until we finish
    // removing all repeated elements. The repeats variable comes in handy here.
    // We only have to iterate while it is greater than zero, rather than having
    // to check the hash map entirely every time to see if any value is greater
    // than 1.

    while repeats > 0
    {
        // If we got here, we have less than 3 remaining elements and they are
        // still repeated, so we add the last operation.
        if indexBoundary >= nums.count
        {
            ops += 1
            break
        }

        // For each triplet, decrease the count in the hash map. Then, update
        // the repeats count for each one that got trimmed to 1 or 0.
        for i in (indexBoundary - 2)...indexBoundary
        {
            let num = nums[i]
            elemOccurrences[num]! -= 1

            if elemOccurrences[num] == 1
            {
                repeats -= 1
            }
        }

        // Update vars.
        ops += 1
        indexBoundary += 3
    }

    return ops
}

func minimumOperationsBackwards(nums: [Int]) -> Int
{
    // A more efficient way to solve this problem is by iterating backwards.
    // When we find the first duplicate this way, we know that by definition,
    // the rest of the array from the beginning will be removed. Since removals
    // can only be done by triplets, we can calculate that to remove said slice,
    // we will need (i / 3) + 1 operations.

    var elemOccurrences = [Int: Int]()

    for i in stride(from: nums.count - 1, through: 0, by: -1)
    {
        let num = nums[i]

        // Found a duplicate, so calculate the slices that would have to be
        // discarded to remove it.
        if elemOccurrences.keys.contains(num)
        {
            return (i / 3) + 1;
        }

        // Else, add to our list of found numbers.
        elemOccurrences[num] = 1;
    }

    return 0
}
