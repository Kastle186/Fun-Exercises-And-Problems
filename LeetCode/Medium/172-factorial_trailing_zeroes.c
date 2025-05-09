// Name: 172. Factorial Trailing Zeroes
// Topics: Math
// Companies: Google

#include <stdio.h>
#include <stdbool.h>

int trailing_zeroes(int);

int main(void)
{
    int z_three = trailing_zeroes(3);
    int z_five = trailing_zeroes(5);
    int z_zero = trailing_zeroes(0);

    puts("172. Factorial Trailing Zeroes");
    printf("%d\n", z_three);
    printf("%d\n", z_five);
    printf("%d\n", z_zero);
    return 0;
}

int trailing_zeroes(int n)
{
    // For a number to have any amount of trailing zeroes, it needs to have at
    // least one 10-factor. 5! is the first factorial with such a component.

    if (n < 5)
        return 0;

    int factor_of_five = 5;
    int the_zeroes = 0;

    // As specified above, for a number to have any number of trailing zeroes,
    // it must be composed of at least one 10-factor. But how can we find this?
    // We notice that 10 = 5 * 2. So, we need to account for all the products
    // of 5 AND 2 in the number's expansion. There are many more factors of 2
    // than factors of 5 however, so if we take all the numbers in the expansion
    // with a factor of 5 instead, we'll find that we have more than enough even
    // numbers (aka factors of 2) to pair up with them to form the factors of 10.

    while (true)
    {
        // Divide n by the current factor of five to find how many numbers composing
        // n have said factor.
        int num_factors = n / factor_of_five;

        if (num_factors <= 0)
            break;

        // We then increase factor_of_five to the next power, because every multiple
        // of 5 will bring an extra factor of 5 to consider (e.g. 25 = 5 * 5).
        the_zeroes += num_factors;
        factor_of_five *= 5;
    }

    return the_zeroes;
}
