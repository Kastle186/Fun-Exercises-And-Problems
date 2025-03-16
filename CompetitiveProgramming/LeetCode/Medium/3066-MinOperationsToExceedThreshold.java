// Name: 3066. Minimum Operations to Exceed Threshold Value II
// Topics: Array, Heap/Priority Queue, Simulation

import java.util.PriorityQueue;

public class MinOperationsToExceedThreshold
{
    public static void main(String[] args)
    {
        int[] arr1 = { 2, 11, 10, 1, 3 };
        int[] arr2 = { 1, 1, 2, 4, 9 };

        int result1 = minOperations(arr1, 10);
        int result2 = minOperations(arr2, 20);

        System.out.println(result1);
        System.out.println(result2);
    }

    public static int minOperations(int[] nums, int k)
    {
        PriorityQueue<Long> numsQueue = new PriorityQueue<>();
        int operations = 0;

        // First we need to create a priority queue or min heap with the elements
        // of the array. We need to use Long because while the largest number we
        // can receive in the array is 10^9, which fits in an Integer, when
        // multiplying and/or adding them, we can go past the 32-bit limit of
        // the Integer and consequently get erroneous results.

        for (int i : nums)
        {
            numsQueue.offer((long) i);
        }

        // Next, we run the sequence of steps described in the exercise until
        // the first element of the priority queue is equal or greater than k.

        while (numsQueue.size() >= 2 && numsQueue.peek() < k)
        {
            long x = numsQueue.poll();
            long y = numsQueue.poll();
            long transformed = (Math.min(x, y) * 2) + Math.max(x, y);

            numsQueue.offer(transformed);
            operations++;
        }

        return operations;
    }
}
