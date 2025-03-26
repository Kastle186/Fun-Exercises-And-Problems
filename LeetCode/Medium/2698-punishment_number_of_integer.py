#!/usr/bin/env python3

# Name: 2698. Find the Punishment Number of an Integer
# Topics: Math, Backtracking

def is_punishment_summand(sq_str: str, partition_index: int, tgt_num: int) -> bool:
    # If we've reached the end of the square string, then we should have reached
    # the target 0, if it is a summand of the punishment number.

    if partition_index >= len(sq_str):
        return tgt_num == 0

    partial_sum = 0

    # Begin iterating to test the partitions that can be formed starting from
    # the current index.

    for i in range(partition_index, len(sq_str)):
        # Gradually build the number of the next partition by multiplying the
        # current result by 10 and "appending" the next digit.

        partial_sum = partial_sum * 10 + int(sq_str[i])

        # If we exceed the target remainder, then this attempt at partitioning
        # is not a working one.

        if partial_sum > tgt_num:
            break

        # Recurse to check more partitions, and if at least one is valid, then
        # we can conclude this is a valid punishment summand.

        if (is_punishment_summand(sq_str, i + 1, tgt_num - partial_sum)):
            return True

    return False


def punishment_number(num: int) -> int:
    result = 0

    for i in range(1, num+1):
        square = i * i

        # If the square of this number satisfies the condition, then it is a summand
        # of the original number's punishment number.

        if is_punishment_summand(str(square), 0, i):
            result += square

    return result


def main():
    result1 = punishment_number(10)
    result2 = punishment_number(37)
    print(result1)
    print(result2)


if __name__ == '__main__':
    main()
