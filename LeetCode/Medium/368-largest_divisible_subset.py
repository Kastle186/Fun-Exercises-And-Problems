#!/usr/bin/env python3

# Name: 368. Largest Divisible Subset
# Topics: Array, Math, Dynamic Programming, Sorting

def largest_divisible_subset(nums: list[int]) -> list[int]:
    # First, sort the array. Ensuring the next number to check will always be
    # greater than the previous one will make things easier to find divisibility.

    nums.sort()
    num_nums = len(nums)

    # Then, we'll be using two arrays to keep track of our progress. The main
    # dynamic programming one (dp[]), will keep the size of the largest divisible
    # subset possible up to that index. The prev[] array will keep the indices of
    # the previous element in the largest subset so far. We will later use this
    # to rebuild the final largest subset.

    dp = [1] * num_nums
    prev = [-1] * num_nums

    # Main loop: Find the largest subset size at each index.

    max_subset_size = 1
    max_subset_indx = 0

    for i in range(1, num_nums):
        for j in range(i):
            # Try the divisibility of every number with each of its predecessors.
            # Here is where dynamic programming comes into play.

            if nums[i] % nums[j] == 0 and dp[j] + 1 > dp[i]:
                # If this would make the current subset larger, then update the
                # respective dp and prev values too.
                dp[i] = dp[j] + 1
                prev[i] = j

                # Update the max values if this subset turns out to be a candidate
                # for the final answer.
                if dp[i] > max_subset_size:
                    max_subset_size = dp[i]
                    max_subset_indx = i

    # Now that we know the indices and size of the largest divisible subset, we
    # reconstruct it and return it.
    result = []

    # -1 is the value we initialized our prev[] array, so it will tell us when
    # we're done reconstructing.
    while max_subset_indx != -1:
        result.append(nums[max_subset_indx])
        max_subset_indx = prev[max_subset_indx]

    return result


def main():
    nums_1 = [1, 2, 3]
    nums_2 = [1, 2, 4, 8]

    div_subset_1 = largest_divisible_subset(nums_1)
    div_subset_2 = largest_divisible_subset(nums_2)

    print(div_subset_1)
    print(div_subset_2)


if __name__ == '__main__':
    main()
