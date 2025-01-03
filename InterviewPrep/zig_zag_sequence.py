#!/usr/bin/env python3

def find_zig_zag_sequence(a, n):
    a.sort()
    mid = int(n/2)
    a[mid], a[n-1] = a[n-1], a[mid]

    st = mid + 1
    ed = n - 2

    while(st < ed):
        a[st], a[ed] = a[ed], a[st]
        st = st + 1
        ed = ed - 1

    for i in range (n):
        if i == n-1:
            print(a[i])
        else:
            print(a[i], end = ' ')
    return


def main():
    test_cases = int(input())

    for cs in range (test_cases):
        n = int(input())
        a = list(map(int, input().split()))
        find_zig_zag_sequence(a, n)


if __name__ == "__main__":
    main()
