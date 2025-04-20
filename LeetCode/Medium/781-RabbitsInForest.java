// Name: 781. Rabbits in Forest
// Topics: Array, Hash Table, Math, Greedy
// Companies: Zepto

import java.util.HashMap;
import java.util.Map;

class Solution
{
    public static void main(String[] args)
    {
        int[] forestInterview1 = { 1, 1, 2 };
        int[] forestInterview2 = { 10, 10, 10 };

        int rabbits1 = numRabbits(forestInterview1);
        int rabbits2 = numRabbits(forestInterview2);

        System.out.println("781. Rabbits in Forest");
        System.out.println(rabbits1);
        System.out.println(rabbits2);
    }

    private static int numRabbits(int[] rabbitAnswers)
    {
        // To solve this problem, we'll go from these premises:
        // For every answer x, we know there is at least one group with at least
        // x+1 rabbits: The x that was answered, plus the rabbit who answered it.
        // However, we must also take into account that multiple groups might be
        // present (i.e. the total amount of x answers is more than x+1). To process
        // all of this, we'll be keeping track of how many times each answer is
        // given in a Hash Map.

        HashMap<Integer, Integer> ansGroups = new HashMap<>();
        int forestRabbits = 0;

        for (int i = 0; i < rabbitAnswers.length; i++)
        {
            int ans = rabbitAnswers[i];
            int ansCount = ansGroups.getOrDefault(ans, 0) + 1;

            // If we've found this answer one more time than it, then we know this
            // group is complete, so we add it to the result and reset the count.

            if (ansCount == ans + 1)
            {
                forestRabbits += ansCount;
                ansCount = 0;
            }

            ansGroups.put(ans, ansCount);
        }

        // Groups that were not reset to zero in the previous loop are incomplete.
        // So, we have to "complete" them by adding their x+1 to the final count.

        for (Map.Entry<Integer, Integer> group : ansGroups.entrySet())
        {
            if (group.getValue() > 0)
                forestRabbits += (group.getKey() + 1);
        }

        return forestRabbits;
    }
}
