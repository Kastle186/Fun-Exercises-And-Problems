#include <iostream>
#include <cmath>
#include "tools/hackerrank.hpp"

std::string counter_game(long);
int get_highest_bit_set(long);

int main(void)
{
    std::string t_temp;
    std::getline(std::cin, t_temp);

    int t = std::stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++)
    {
        std::string n_temp;
        std::getline(std::cin, n_temp);

        long n = std::stol(ltrim(rtrim(n_temp)));
        std::string result = counter_game(n);
        std::cout << result << std::endl;
    }

    return 0;
}

std::string counter_game(long n)
{
    if (n == 1)
        return "Richard";

    // First, we have to define whether the number we have is a power of 2.
    // The best way to go about it is with an '&' operation with n - 1. Since
    // powers of 2 have all bits off minus the highest, and the previous number
    // has one bit less and all are on, then doing an '&' of both should yield 0.

    // If it is not a power of 2, we can get the next smallest power of 2 by
    // truncating the base-2 logarithm of the number to subtract to, as the
    // exercise requires.

    int moves = 0;

    while (n > 1)
    {
        if ((n & (n - 1)) == 0)
            n >>= 1L;
        else
            n -= log2(n);
        moves++;
    }

    // Since Louise and Richard alternate turns, with Louise starting, then we
    // can infer the winner by checking whether the total moves was an even number.

    return moves & 1 ? "Louise" : "Richard";
}
