#!/usr/bin/env python3

# Name: 221. Maximal Square
# Topics: Array, Dynamic Programming, Matrix
# Companies:
# - Airbnb
# - ServiceNow
# - SAP
# - Booking.com
# - Myntra
# - ByteDance
# - Walmart Labs
# - Karat
# - PhonePe
# - DE Shaw
# - Citadel
# - eBay
# - Salesforce
# - Nvidia
# - PayPal
# - Oracle
# - Goldman Sachs
# - IBM

def maximal_square(matrix: list[list[chr]]) -> int:
    rows = len(matrix)
    cols = len(matrix[0])
    sq_dp = [[0] * (cols + 1) for _ in range(rows + 1)] # Extra row/col for borders.
    max_square_dim = 0

    # To solve this problem, we'll be using dynamic programming to keep track
    # the size of the largest square we can make with the current tile as the
    # bottom-right one.

    for i in range(rows):
        for j in range(cols):
            # If it's not a '1', then we can't make any square here.
            if matrix[i][j] != '1':
                continue

            # The result for each tile is the smallest square we can build with
            # its previous neighbors + 1 (the tile itself).

            dp_top = sq_dp[i][j + 1]
            dp_left = sq_dp[i + 1][j]
            dp_topleft = sq_dp[i][j]

            sq_dp[i + 1][j + 1] = min(dp_top, dp_left, dp_topleft) + 1
            max_square_dim = max(max_square_dim, sq_dp[i + 1][j + 1])

    # Return the area of the largest square.
    return max_square_dim ** 2


def main():
    matrix_1 = [
        ["1","0","1","0","0"],
        ["1","0","1","1","1"],
        ["1","1","1","1","1"],
        ["1","0","0","1","0"]
    ]

    matrix_2 = [
        ["0","1"],
        ["1","0"]
    ]

    matrix_3 = [["0"]]

    area_1 = maximal_square(matrix_1)
    area_2 = maximal_square(matrix_2)
    area_3 = maximal_square(matrix_3)

    print('221. Maximal Square')
    print(area_1)
    print(area_2)
    print(area_3)


if __name__ == '__main__':
    main()
