#!/usr/bin/env python3

# Name: 2537. Count the Number of Good Subarrays
# Topics: Array, Hash Table, Sliding Window

from collections import defaultdict

def count_good(nums: list[int], k: int) -> int:
    n = len(nums)
    elem_counts = defaultdict(int)
    pairs = 0
    goodies = 0
    boundary = 0

    # To find the "good subarrays", we'll be using a sliding window approach.
    # We start of course at the beginning of the array, and go extending and
    # shrinking the sliding window as we need and go counting.

    for i in range(n):
        # Keep expanding the segment until we find enough pairs. To know when
        # we find a pair, we leverage an element counting dict.
        while boundary < n and pairs < k:
            elem = nums[boundary]
            elem_counts[elem] += 1
            boundary += 1

            if elem_counts[elem] >= 2:
                pairs += elem_counts[elem] - 1

        # If we broke from the previous loop because of enough pairs, we update
        # the subarray count. We increase it by the remaining elements plus 1.
        # Why? Because we have one subarray that is good (the one we found), and
        # since we'd be just adding new elements, by definition all subarrays formed
        # by adding new elements will also be good.

        if pairs >= k:
            goodies += (n - boundary + 1)
        elif boundary >= n:
            # Small optimization: If we broke from the previous loop by going
            # out of bounds, then by definition there can't be any more good
            # subarrays, so we finish early.
            break

        # Then, to check further subarrays in subsequent calls of this loop,
        # we shrink the window from its current starting position.

        start = nums[i]
        elem_counts[start] -= 1

        if elem_counts[start] > 0:
            pairs -= elem_counts[start]

    return goodies


def main():
    nums_1 = [1, 1, 1, 1, 1]
    nums_2 = [3, 1, 4, 3, 2, 2, 4]

    goodies_1 = count_good(nums_1, 10)
    goodies_2 = count_good(nums_2, 2)

    print(goodies_1)
    print(goodies_2)


if __name__ == '__main__':
    main()
