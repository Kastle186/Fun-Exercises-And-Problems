#!/usr/bin/env python3

# Name: 1415. The k-th Lexicographical String of All Happy Strings of Length n
# Topics: String, Backtracking

def get_happy_string(n: int, k: int) -> str:
    # According to the characteristics of happy strings, there are a maximum
    # of 2^(n-1) * 3 possibilities. So, if n is greater than this result, there
    # is no point in even starting because we already know there is none.

    if k > (2 ** (n - 1)) * 3:
        return ''

    # Starting with each letter, there are a total of 2^(n-1) strings. So, by
    # finding in which of the 3 groups the k fits, we can reduce the scope of
    # the problem.

    group_size = 2 ** (n - 1)
    group_num = 3 if k > group_size * 2 else 2 if k > group_size else 1
    kth_lex_chars = [chr(group_num + 96)] # 97 is the Ascii Code for letter 'a'.

    # Next, we will go doing a variant of divide and conquer to construct the
    # string we are looking for. We will be dividing the group containing the
    # answer and selecting the appropriate letter, until we get to the end
    # result we are looking for.

    # High boundary of the previous group = Low boundary of this group - 1.
    group_low = group_size * (group_num - 1)

    # While we are not done building the string, we keep reducing the possible
    # ramifications as we go picking the letters, until we get to the leaves and
    # finish forming the happy string.

    while len(kth_lex_chars) < n:
        # Check which subgroup our answer will be in.

        group_mid = group_low + int(group_size / 2)
        next_subgroup = 1 if k <= group_mid else 2
        next_letter = None

        # Pick the appropriate letter according to the last one.

        match kth_lex_chars[-1]:
            case 'a':
                next_letter = 'b' if next_subgroup == 1 else 'c'
            case 'b':
                next_letter = 'a' if next_subgroup == 1 else 'c'
            case 'c':
                next_letter = 'a' if next_subgroup == 1 else 'b'

        kth_lex_chars.append(next_letter)

        # Update the subgroup parameters.

        if next_subgroup == 2:
            group_low = group_mid

        group_size /= 2

    return ''.join(kth_lex_chars)


def main():
    kth_happy_1 = get_happy_string(1, 3)
    kth_happy_2 = get_happy_string(1, 4)
    kth_happy_3 = get_happy_string(3, 9)

    print('<empty>' if not kth_happy_1 else kth_happy_1)
    print('<empty>' if not kth_happy_2 else kth_happy_2)
    print('<empty>' if not kth_happy_3 else kth_happy_3)


if __name__ == '__main__':
    main()
