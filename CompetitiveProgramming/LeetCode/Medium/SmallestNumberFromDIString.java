// Name: Construct Smallest Number From DI String
// Topics: String, Backtracking, Stack, Greedy
// Companies:
// - Josh Technology
// - Goldman Sachs

import java.util.Stack;

public class Solution
{
    public static void main(String[] args)
    {
        String diPattern_1 = "IIIDIDDD";
        String diPattern_2 = "DDD";
        String diPattern_3 = "IIDDDIDD";

        String smolNum_1 = smallestNumber(diPattern_1);
        String smolNum_2 = smallestNumber(diPattern_2);
        String smolNum_3 = smallestNumber(diPattern_3);

        System.out.println(smolNum_1);
        System.out.println(smolNum_2);
        System.out.println(smolNum_3);
    }

    private static String smallestNumber(String diPattern)
    {
        // Adding a +1 here because the resulting number will always have one more
        // digit than characters in the di pattern.

        int patternLen = diPattern.length();
        StringBuilder numSb = new StringBuilder("0".repeat(patternLen + 1));
        Stack<Character> decreasingNums = new Stack<>();

        char digit = 48; // 48 is the Ascii Code value for '0'.
        int numIter = 0;

        for (int i = 0; i <= patternLen; i++)
        {
            // Each streak of I's means an ascending sequence of numbers, and each
            // streak of D's means a descending sequence.
            digit++;

            // Since the number string has one more character than the pattern
            // string, we just push the last remaining digit to the stack and
            // then break. Otherwise, we would get an error when trying to access
            // a string position that doesn't exist.

            if (i == patternLen)
            {
                decreasingNums.push(digit);
                break;
            }

            switch (diPattern.charAt(i))
            {
            case 'I':
                // If the next letter is an 'I', that means we are back to the
                // increasing sequence, so we add that digit, and then get the whole
                // descending sequence from the stack.
                numSb.setCharAt(numIter, digit);
                numIter++;

                while (!decreasingNums.isEmpty())
                {
                    numSb.setCharAt(numIter, decreasingNums.pop());
                    numIter++;
                }
                break;

            case 'D':
                // If the next letter is a 'D', then we add the digit to the stack,
                // ready to be used when we bump into an 'I' or reach the end of
                // the pattern string.
                decreasingNums.push(digit);
                break;
            }
        }

        // If we still have some numbers from a pending descending sequence and/or
        // the last of the pattern, then add them by emptying the stack.

        while (!decreasingNums.isEmpty())
        {
            numSb.setCharAt(numIter, decreasingNums.pop());
            numIter++;
        }

        return numSb.toString();
    }
}
