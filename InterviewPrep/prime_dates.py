#!/usr/bin/env python3

import re

months = []

def update_leap_year(year):
    if year % 400 == 0:
        months[2] = 29
    elif year % 100 == 0:
        months[2] = 28
    elif year % 4 == 0:
        months[2] = 29
    else:
        months[2] = 28


def store_month():
    months[1] = 31
    months[2] = 28
    months[3] = 31
    months[4] = 30
    months[5] = 31
    months[6] = 30
    months[7] = 31
    months[8] = 31
    months[9] = 30
    months[10] = 31
    months[11] = 30
    months[12] = 31


def find_prime_dates(d1, m1, y1, d2, m2, y2):
    store_month()
    result = 0

    while True:
        x = d1
        x = x * 100 + m1
        x = x * 10000 + y1

        if x % 4 == 0 or x % 7 == 0:
            result += 1

        if d1 == d2 and m1 == m2 and y1 == y2:
            break

        update_leap_year(y1)
        d1 += 1

        if d1 > months[m1]:
            m1 += 1
            d1 = 1

            if m1 > 12:
                y1 += 1
                m1 = 1

    return result


def main():
    for i in range(1, 14):
        months.append(31)

    line = input()
    date = re.split('-| ', line)
    d1 = int(date[0])
    m1 = int(date[1])
    y1 = int(date[2])
    d2 = int(date[3])
    m2 = int(date[4])
    y2 = int(date[5])

    result = find_prime_dates(d1, m1, y1, d2, m2, y2)
    print(result)


if __name__ == '__main__':
    main()
