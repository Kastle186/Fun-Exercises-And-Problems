using System;
using System.Numerics;

static class Result
{
    public static int SuperDigit(string n, int k)
    {
        long start = 0;

        // First, we can iterate each character directly and add up their numeric
        // values directly. This allows us to not need the BigInteger class and
        // be a bit more efficient.

        foreach (char c in n)
        {
            start += (long) Char.GetNumericValue(c);
        }

        // Since multiplying the string 'k' times only means we will get the same
        // pattern again, we can just take the calculation of one iteration, and
        // multiply it 'k' times instead.

        long result = SuperDigitHelper(start * k);
        return (int) result;
    }

    private static long SuperDigitHelper(long num)
    {
        // If we only have one digit, then we're done.
        if (num < 10)
            return num;

        // If we still have more than one digit, then we have to calculate the
        // sum of its digits, and then iterate, or better said, recurse, on that
        // result. To do this, we calculate the % 10 of the number to get the
        // next digit, and then divide by 10 to "shift" to the next digit.

        long nextSuper = 0;

        while (num > 0)
        {
            nextSuper += num % 10;
            num /= 10;
        }

        return SuperDigitHelper(nextSuper);
    }
}

class Solution
{
    static int Main(string[] args)
    {
        string[] firstMultipleInput = Console.ReadLine().TrimEnd().Split(' ');
        string n = firstMultipleInput[0];

        int k = Convert.ToInt32(firstMultipleInput[1]);
        int result = Result.SuperDigit(n, k);

        Console.WriteLine(result);
        return 0;
    }
}
