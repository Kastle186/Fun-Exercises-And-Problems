// Name: 2563. Count the Number of Fair Pairs
// Topics: Array, Two Pointers, Binary Search, Sorting
// Companies: Salesforce

import java.util.Arrays;

class Solution
{
    public static void main(String[] args)
    {
        int[] nums1 = { 0, 1, 7, 4, 4, 5 };
        int[] nums2 = { 1, 7, 9, 2, 5 };

        long fairness1 = countFairPairs(nums1, 3, 6);
        long fairness2 = countFairPairs(nums2, 11, 11);

        System.out.println("2563. Count Fair Pairs");
        System.out.println(fairness1);
        System.out.println(fairness2);
    }

    private static long countFairPairs(int[] nums, int lower, int upper)
    {
        // To find the number of fair pairs, first we have to sort the array.
        // This is because it will then allow us to use Binary Search, rather
        // than brute-force searching, which will bring our runtime down
        // from O(N^2) to O(N log N).

        long fairPairs = 0;
        Arrays.sort(nums);

        // The main principle is that we are going to find the range of numbers
        // that will fulfill the winning condition written in the problem. For
        // this, we will be applying binary search to find such indices.

        for (int i = 0; i < nums.length; i++)
        {
            // We would have to write two slightly different binary search functions,
            // but we can do it with only one with a clever trick. To get the higher
            // bound, we will search up to one after, so that we get the actual
            // higher. For the lower, we'll search up to it. Why does this work?
            // Because then we'll be subtracting these indices and this way, we will
            // get the correct range size to add. The range size in this case equals
            // the amount of numbers that can be paired up with the current nums[i].

            int rangeHigh = binarySearch(nums, (upper - nums[i]) + 1, i + 1, nums.length - 1);
            int rangeLow = binarySearch(nums, lower - nums[i], i + 1, nums.length - 1);
            fairPairs += (rangeHigh - rangeLow);
        }

        return fairPairs;
    }

    private static int binarySearch(int[] array, int target, int low, int high)
    {
        while (low <= high)
        {
            int mid = (low + high) / 2;

            if (array[mid] >= target)
                high = mid - 1;
            else
                low = mid + 1;
        }

        return high;
    }
}
