// Name: 2342. Max Sum of a Pair With Equal Sum of Digits
// Topics: Array, Hash Table, Sorting, Heap/Priority Queue

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map.Entry;

public class MaxSumEqualSumOfDigits
{
    public static void main(String[] args)
    {
        int[] arr1 = { 18, 43, 36, 13, 7 };
        int[] arr2 = { 10, 12, 19, 14 };

        int result1 = maximumSum(arr1);
        int result2 = maximumSum(arr2);

        System.out.println(result1);
        System.out.println(result2);
    }

    public static int maximumSum(int[] nums)
    {
        HashMap<Integer, ArrayList<Integer>> digitSums = new HashMap<>();

        // First, we will divide the numbers by "buckets" of their digit sums.
        // This will help us optimize by discarding those with only one occurrence.

        for (int n : nums)
        {
            int ds = sumOfDigits(n);

            if (!digitSums.containsKey(ds))
                digitSums.put(ds, new ArrayList<Integer>());

            digitSums.get(ds).add(n);
        }

        // Then, we can check each of the buckets with more than one element, and
        // see which pair(s) yield the highest sum. Then, the highest of all these
        // sums is the result we are looking for.

        int maxSum = -1;

        for (Entry<Integer, ArrayList<Integer>> entry : digitSums.entrySet())
        {
            ArrayList<Integer> digitSumBucket = entry.getValue();

            if (digitSumBucket.size() < 2)
                continue;

            int maxBucketSum = -1;

            for (int i = 0; i < digitSumBucket.size() - 1; i++)
            {
                for (int j = i + 1; j < digitSumBucket.size(); j++)
                {
                    int sum = digitSumBucket.get(i) + digitSumBucket.get(j);

                    if (sum > maxBucketSum)
                        maxBucketSum = sum;
                }
            }

            if (maxBucketSum > maxSum)
                maxSum = maxBucketSum;
        }

        return maxSum;
    }

    private static int sumOfDigits(int num)
    {
        int result = 0;

        while (num > 0)
        {
            result += num % 10;
            num /= 10;
        }

        return result;
    }
}
