// Exponentiation Math Lesson With Programming!

#include <iostream>

long long exponentiation_by_squaring(long long, long long);
long long modular_exponentiation(long long, long long, long long);

int main(void)
{
    return 0;
}

// Example:
// 3 ^ 13
//
// Step-by-step:
//
// Binary representation of 13 is 1101. That’s:
//
// 13 = 1×8 + 1×4 + 0×2 + 1×1
//    = 2^3 + 2^2 + 0 + 2^0
//
// So:
//
// 3^13 = 3^(8 + 4 + 0 + 1) = 3^8 * 3^4 * 3^1
// Instead of doing 3 * 3 * 3 ... thirteen times, we compute:
//
// 3^1 = 3
// 3^2 = (3^1)^2 = 9
// 3^4 = (3^2)^2 = 81
// 3^8 = (3^4)^2 = 6561
//
// Then we multiply the powers we actually need (based on the binary of 13):
//
// result = 3^8 * 3^4 * 3^1 = 6561 * 81 * 3 = 1594323

long long exponentiation_by_squaring(long long base, long long exp)
{
    long long result = 1L;

    while (exp > 0)
    {
        if (exp & 1)
            result *= base;

        base *= base;
        exp >>= 1;
    }

    return result;
}

long long modular_exponentiation(long long base, long long exp, long long mod)
{
    long long result = 1L;
    base %= mod;

    while (exp > 0)
    {
        if (exp & 1)
            result = (result * base) % mod;

        base = (base * base) % mod;
        base >>= 1;
    }

    return result;
}
