// Name: 2542. Maximum Subsequence Score
// Topics: Array, Greedy, Sorting, Heap (Priority Queue)
// Companies: DE Shaw

import java.util.Comparator;
import java.util.PriorityQueue;

public class ArrayElemTuple
{
    public int index;
    public int value;

    public ArrayElemTuple(int i, int v)
    {
        index = i;
        value = v;
    }
}

public class SortByElem implements Comparator<ArrayElemTuple>
{
    public int compare(ArrayElemTuple aet1, ArrayElemTuple aet2)
    {
        return aet2.value - aet1.value;
    }
}

public class MaximumSubsequenceScore
{
    public static void main(String[] args)
    {
        int[] nums1A = { 1, 3, 3, 2 };
        int[] nums1B = { 2, 1, 3, 4 };

        int[] nums2A = { 4, 2, 3, 1, 1 };
        int[] nums2B = { 7, 5, 10, 9, 6 };

        int[] nums3A = { 2, 1, 14, 12 };
        int[] nums3B = { 11, 7, 13, 6 };

        long result1 = maxScore(nums1A, nums1B, 3);
        long result2 = maxScore(nums2A, nums2B, 1);
        long result3 = maxScore(nums3A, nums3B, 3);

        System.out.println(result1);
        System.out.println(result2);
        System.out.println(result3);
    }

    public static long maxScore(int[] nums1, int[] nums2, int k)
    {
        // Since we need the kth largest number of the second array because
        // multiplying by it would yield the largest value, we use a max heap
        // to store the elements. We will be storing them in tuples with their
        // respective indexes, as to solve the problem, we will need some sort
        // of "mapping" with the elements of the first array.

        PriorityQueue<ArrayElemTuple> nums2Heap =
            new PriorityQueue<>(nums2.length, new SortByElem());

        for (int i = 0; i < nums2.length; i++)
            nums2Heap.offer(new ArrayElemTuple(i, nums2[i]));

        // Next, while we want to maximize the multiplier as much as we can,
        // since that's the most influential operand, we also want to max
        // the sum as much as we can. To achieve this, we will be iterating
        // our max heap of the second array, and store the corresponding element
        // of the first element into a min heap. This way, we'll be able to
        // easily pop the smallest ones while maximizing the sum and product.

        PriorityQueue<Integer> nums1ElemsHeap = new PriorityQueue<>();

        long sum = 0;
        long answer = -1;

        while (!nums2Heap.isEmpty())
        {
            // Get the next largest multiplier and add its counterpart to the
            // current sum.

            ArrayElemTuple nextLargest = nums2Heap.poll();
            int nextSummand = nums1[nextLargest.index];
            sum += nextSummand;
            nums1ElemsHeap.offer(nextSummand);

            // If we have more than k elements, then pop the smallest one and
            // subtract it from the sum, as we won't be needing it.

            if (nums1ElemsHeap.size() > k)
            {
                int toRemove = nums1ElemsHeap.poll();
                sum -= toRemove;
            }

            // If we have exactly k elements, then this is a potential result.
            // Compare it with the one we currently have to keep track of the
            // largest one for the final answer.

            if (nums1ElemsHeap.size() == k)
            {
                answer = Math.max(answer, sum * nextLargest.value);
            }
        }

        return answer;
    }
}
