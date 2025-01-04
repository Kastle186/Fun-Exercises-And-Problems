using System;
using System.Collections.Generic;

class Result
{
    public static string GridChallenge(List<string> grid)
    {
        // As the first step to solve this exercise, we have to sort each of the
        // strings provided. Since we will also be working with individual characters
        // anyway, we'll convert them to character arrays.

        char[][] charsGrid = new char[grid.Count][];

        for (int i = 0; i < grid.Count; i++)
        {
            string s = grid[i];
            charsGrid[i] = new char[s.Length];

            for (int j = 0; j < s.Length; j++)
                charsGrid[i][j] = s[j];

            Array.Sort(charsGrid[i]);
        }

        // Console.WriteLine($"\nLEN: {charsGrid[0].Length}");
        // Console.WriteLine($"LENFULL: {charsGrid.Length}");

        // Next, we iterate our strings character by character in a top-down
        // fashion, treating them as char arrays for this purpose. If all happen
        // to be sorted, then we can return "YES". Otherwise, "NO" is the answer.

        for (int i = 0; i < charsGrid[0].Length; i++)
        {
            for (int j = 0; j < charsGrid.Length - 1; j++)
            {
                if (charsGrid[j][i] > charsGrid[j+1][i])
                    return "NO";
            }
        }

        return "YES";
    }
}

class Solution
{
    static void Main(string[] args)
    {
        int t = Convert.ToInt32(Console.ReadLine().Trim());

        for (int tItr = 0; tItr < t; tItr++)
        {
            int n = Convert.ToInt32(Console.ReadLine().Trim());
            List<string> grid = new List<string>();

            for (int i = 0; i < n; i++)
            {
                string gridItem = Console.ReadLine();
                grid.Add(gridItem);
            }

            string result = Result.GridChallenge(grid);
            Console.WriteLine(result);
        }
    }
}
