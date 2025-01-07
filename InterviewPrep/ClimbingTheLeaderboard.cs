using System;
using System.Collections.Generic;
using System.Linq;

class Result
{
    public static List<int> ClimbingLeaderboard(List<int> ranked, List<int> player)
    {
        // Firstly, since the rankings do not skip numbers and just give the same
        // one to all those who tie, then we can make our life easier by working
        // with a simplified ranked list with only the unique values. The exercise
        // specifies that the existing rankings are already sorted in natural or
        // descending order.

        List<int> uniqRanks = ranked.Distinct().ToList();
        List<int> newRanks = new List<int>();
        // Console.WriteLine($"\nUNIQUE: [{string.Join(", ", uniqRanks)}]");

        // Next, we will do a small variant of Binary Search to find the index
        // where this score would go in the rankings.

        foreach (int score in player)
        {
            if (uniqRanks.Count == 0)
            {
                newRanks.Add(1);
                continue;
            }

            int scoreRank = BinarySearchIndex(uniqRanks, score, 0, uniqRanks.Count - 1);
            // Console.WriteLine($"{scoreRank} - {score}");
            newRanks.Add(scoreRank);
        }

        return newRanks;
    }

    private static int BinarySearchIndex(
        List<int> rankedScores,
        int playerScore,
        int chunkStart,
        int chunkEnd)
    {
        // Console.WriteLine($"\nSCORE: {playerScore}");
        // Console.WriteLine($"START: {chunkStart}");
        // Console.WriteLine($"END: {chunkEnd}");

        int chunkSize = chunkEnd - chunkStart + 1;
        // Console.WriteLine($"SIZE: {chunkSize}");

        if (chunkSize == 1)
        {
            // Console.WriteLine("SIZE WAS 1! RETURNING!");
            return playerScore >= rankedScores[chunkStart]
                ? chunkStart + 1
                : chunkStart + 2;
        }

        // This thing insists on behaving like an edge-case, so let's treat it
        // separately as such.

        if (chunkSize == 2)
        {
            // Console.WriteLine("SIZE WAS 2!");

            int first = rankedScores[chunkStart];
            int second = rankedScores[chunkEnd];

            // Console.WriteLine($"FIRST: {first}");
            // Console.WriteLine($"SECOND: {second}");

            if (playerScore >= first)
            {
                // Console.WriteLine($"SCORE GREATER OR EQUAL!");
                return chunkStart + 1;
            }
            else if (playerScore < first && playerScore >= second)
            {
                // Console.WriteLine($"SCORE IN THE MIDDLE!");
                return chunkStart + 2;
            }
            else
            {
                // Console.WriteLine($"SCORE LESS THAN!");
                return chunkStart + 3;
            }
        }

        int chunkMid = chunkStart + (chunkSize / 2);
        int testScore = rankedScores[chunkMid];

        // Console.WriteLine($"MID: {chunkMid}");
        // Console.WriteLine($"TEST: {testScore}");

        if (playerScore == testScore)
        {
            // Console.WriteLine($"FOUND MATCH! RETURNING {chunkMid + 1}");
            return chunkMid + 1;
        }

        if (playerScore > testScore)
        {
            // Console.WriteLine("RECURSING INTO FIRST HALF!");
            return BinarySearchIndex(rankedScores, playerScore, chunkStart, chunkMid);
        }

        // Console.WriteLine("RECURSING INTO SECOND HALF!");
        return BinarySearchIndex(rankedScores, playerScore, chunkMid, chunkEnd);
    }
}

class Solution
{
    static int Main(string[] args)
    {
        int rankedCount = Convert.ToInt32(Console.ReadLine().Trim());

        List<int> ranked = Console.ReadLine()
                                  .TrimEnd()
                                  .Split(' ')
                                  .ToList()
                                  .Select(rankedTemp => Convert.ToInt32(rankedTemp))
                                  .ToList();

        int playerCount = Convert.ToInt32(Console.ReadLine().Trim());

        List<int> player = Console.ReadLine()
                                  .TrimEnd()
                                  .Split(' ')
                                  .ToList()
                                  .Select(playerTemp => Convert.ToInt32(playerTemp))
                                  .ToList();

        List<int> result = Result.ClimbingLeaderboard(ranked, player);
        Console.WriteLine(String.Join("\n", result));

        return 0;
    }
}
