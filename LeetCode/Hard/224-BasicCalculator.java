// Name: 224. Basic Calculator
// Topics: Math, String, Stack, Recursion
// Companies:
// - Snowflake
// - Anduril
// - Coupang
// - DoorDash
// - DE Shaw
// - Snap
// - Citadel
// - Oracle
// - Atlassian

import java.util.Stack;

class BasicCalculator
{
    public static void main(String[] args)
    {
        String mathExpr1 = "1 + 1";
        String mathExpr2 = " 2-1 + 2 ";
        String mathExpr3 = "(1+(4+5+2)-3)+(6+8)";
        String mathExpr4 = "2-4-(8+2-6+(8+4-(1)+8-10))";

        int result1 = calculate(mathExpr1);
        int result2 = calculate(mathExpr2);
        int result3 = calculate(mathExpr3);
        int result4 = calculate(mathExpr4);

        System.out.println("224. Basic Calculator");
        System.out.println(result1);
        System.out.println(result2);
        System.out.println(result3);
        System.out.println(result4);
    }

    public static int calculate(String operation)
    {
        // First, clean the string so that we only have valid characters.
        operation.replaceAll("\\s+", "");

        int result = 0;
        int sign = 1;
        int opLen = operation.length();

        // Iterate over the expression:
        // - Numbers get resolved normally and then added to the result. We multiply
        //   by 1 or -1 to consider the sign.
        // - Plus and minus signs flip the variable 1/-1.
        // - Parenthesis are different. We capture the entire subexpression, and
        //   then recurse with that as the string argument. Then, we add its result
        //   to the result of the original function call.

        for (int i = 0; i < opLen; )
        {
            char c = operation.charAt(i);

            if (Character.isDigit(c))
            {
                int num = Character.getNumericValue(c);

                while (++i < opLen && Character.isDigit((c = operation.charAt(i))))
                    num = (num * 10) + Character.getNumericValue(c);

                result += sign * num;
            }
            else
            {
                switch (c)
                {
                case '+':
                    sign = 1;
                    break;

                case '-':
                    sign = -1;
                    break;

                case '(':
                    int exprStart = i + 1;
                    int unclosedPars = 1;

                    while (++i < opLen)
                    {
                        c = operation.charAt(i);

                        // We count parenthesis instead of using a Stack to enclose
                        // the subexpressions properly because why not :)

                        if (c == '(')
                            unclosedPars++;

                        if (c == ')')
                            unclosedPars--;

                        if (unclosedPars == 0)
                            break;
                    }

                    int exprEnd = i;
                    result += sign * calculate(operation.substring(exprStart, exprEnd));
                    break;

                default:
                    break;
                }
                i++;
            }
        }

        return result;
    }
}
