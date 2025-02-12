#!/usr/env/bin python3

def grid_challenge(grid: list[str]) -> str:
    # First we have to sort the rows.

    for i in range(0, len(grid)):
        grid[i] = sorted(grid[i])

    # And here, we are doing an "inversed" double loop so that we can iterate
    # over the columns, rather than the rows, to check whether they are sorted.

    for i in range(0, len(grid[0])):
        for j in range(0, len(grid) - 1):
            if grid[j][i] > grid[j+1][i]:
                return "NO"

    return "YES"


def main():
    t = int(input().strip())

    for _ in range(t):
        n = int(input().strip())
        grid = []

        for _ in range(n):
            grid_item = input()
            grid.append(grid_item)

        result = grid_challenge(grid)
        print(result)


if __name__ == '__main__':
    main()
