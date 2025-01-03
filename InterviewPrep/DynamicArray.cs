using System;
using System.Collections.Generic;
using System.Linq;

class Result
{
    public static List<int> DynamicArray(int n, List<List<int>> queries)
    {
        List<int>[] dynamicArray = new List<int>[n];
        List<int> answers = new List<int>();
        int lastAnswer = 0;

        // Initialize our dynamic array to empty lists.

        for (int i = 0; i < n; i++)
            dynamicArray[i] = new List<int>();

        foreach (List<int> query in queries)
        {
            // Extract our query so we can process it.
            // - The first element will be the type of query (1, 2).
            // - The next two elements are the operands.

            int q = query[0];
            int x = query[1];
            int y = query[2];

            int idx = (x ^ lastAnswer) % n;

            // The exercise guarantees that we won't get an invalid query number.
            switch (q)
            {
                case 1:
                    dynamicArray[idx].Add(y);
                    break;

                case 2:
                    // The exercise also guarantees that we won't get an invalid
                    // memory access here.
                    int idxListLen = dynamicArray[idx].Count;
                    lastAnswer = dynamicArray[idx][y % idxListLen];
                    answers.Add(lastAnswer);
                    break;
            }
        }

        return answers;
    }
}

class Solution
{
    public static int Main(string[] args)
    {
        string[] firstMultipleInput = Console.ReadLine().TrimEnd().Split(' ');
        int n = Convert.ToInt32(firstMultipleInput[0]);
        int q = Convert.ToInt32(firstMultipleInput[1]);

        List<List<int>> queries = new List<List<int>>();

        for (int i = 0; i < q; i++)
        {
            queries.Add(Console.ReadLine()
                               .TrimEnd()
                               .Split(' ')
                               .ToList()
                               .Select(queriesTemp => Convert.ToInt32(queriesTemp))
                               .ToList());
        }

        List<int> result = Result.DynamicArray(n, queries);

        Console.WriteLine(String.Join("\n", result));
        return 0;
    }
}
