#!/usr/bin/env python3

# Name: 1922. Count Good Numbers
# Topics: Math, Recursion

import math

def modular_exp(base: int, exp: int, mod: int) -> int:
    # This is an algorithm to calculate a number's power faster, and already
    # accounting for the modulo. Instead of the usual O(N), it runs on O(log N).

    result = 1

    while exp > 0:
        if exp & 1:
            result = (result * base) % mod

        base = (base * base) % mod
        exp >>= 1

    return result


def count_good_numbers(n: int) -> int:
    # The problem specifies two important things:
    # - Even indices can only have even numbers.
    # - Odd indices can only have prime numbers.
    #
    # This leaves us with the following facts:
    # - Even indices can only have 5 numbers: 0, 2, 4, 6, 8
    # - Odd indices can only have 4 numbers: 2, 3, 5, 7
    #
    # Also, we have to remember that every string will have the same amount of
    # even and odd indices, with the exception of odd-length strings, which have
    # one more even index.
    #
    # Therefore, if we're looking for all the possible combinations of length n,
    # that satisfy these requirements, then by mathematical definition the magic
    # formula would be possibilities ^ (length / 2) for even sized numbers, and
    # possibilities ^ ((length + 1) / 2) for odd sized numbers. Consequently,
    # for our case the result we're looking for would be:
    #
    #    (5 ^ (n / 2)) * (4 ^ (n / 2))       -> For even sized numbers
    #    (5 ^ ((n + 1) / 2)) * (4 ^ (n / 2)) -> for odd sized numbers

    evens = n // 2
    odds = evens
    answer_modulo = (10 ** 9) + 7

    if n & 1:
        evens += 1

    return (modular_exp(5, evens, answer_modulo) * modular_exp(4, odds, answer_modulo)) \
        % answer_modulo


def main():
    goodies_1 = count_good_numbers(1)
    goodies_2 = count_good_numbers(4)
    goodies_3 = count_good_numbers(50)

    print(goodies_1)
    print(goodies_2)
    print(goodies_3)


if __name__ == '__main__':
    main()
