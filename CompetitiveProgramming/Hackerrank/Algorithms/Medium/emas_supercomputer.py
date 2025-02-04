#!/usr/bin/env python3

from typing import Self

class PlusCross:
    area: int
    tiles: set[tuple[int, int]]

    def __init__(self: Self, area_val: int, tiles_set: set[tuple[int, int]]):
        self.area = area_val
        self.tiles = tiles_set

    def overlaps_with(self: Self, other: Self) -> bool:
        for pt in other.tiles:
            if pt in self.tiles:
                return True
        return False


def is_shape_in_grid(x: int, y: int, delta: int, num_rows: int, num_cols) -> bool:
    return x + delta < num_rows \
        and x - delta >= 0 \
        and y + delta < num_cols \
        and y - delta >= 0


def is_a_cross(grid: list[str], x: int, y: int, delta: int) -> bool:
    return grid[x+delta][y] == 'G' \
        and grid[x-delta][y] == 'G' \
        and grid[x][y+delta] == 'G' \
        and grid[x][y-delta] == 'G'


def find_pluses_crosses_from_src(grid: list[str], row: int, col: int) -> list[PlusCross]:
    tile_coords = set()
    pluses_crosses = []
    total_area = 1
    delta = 1

    # Adding it here because we need the tuple to be a single element and the
    # constructor takes it as two.
    tile_coords.add((row, col))
    pluses_crosses.append(PlusCross(total_area, tile_coords.copy()))

    # Next, we grow each side of the shape by one. If it is still a plus/cross
    # within the grid, then we record it as another option. Otherwise, we're
    # done with this tile as a center/origin.

    while is_shape_in_grid(row, col, delta, len(grid), len(grid[row])) \
          and is_a_cross(grid, row, col, delta):
        tile_coords.add((row + delta, col))
        tile_coords.add((row - delta, col))
        tile_coords.add((row, col + delta))
        tile_coords.add((row, col - delta))

        total_area += 4
        delta += 1
        pluses_crosses.append(PlusCross(total_area, tile_coords.copy()))

    return pluses_crosses


def two_pluses(grid: list[str]) -> int:
    product_area = 0
    plus_crosses = []

    # First, we have to find all the pluses/crosses in the grid we were given.

    for i in range(len(grid)):
        for j in range(len(grid[i])):
            if grid[i][j] != 'G':
                continue
            plus_crosses += (find_pluses_crosses_from_src(grid, i, j))

    # Next, we have to find the two largest pluses/crosses that do not overlap
    # with each other, and the product of their areas is our result.

    for i in range(len(plus_crosses)):
        for j in range(i+1, len(plus_crosses)):
            if plus_crosses[i].overlaps_with(plus_crosses[j]):
                continue
            product_area = max(product_area,
                               plus_crosses[i].area * plus_crosses[j].area)

    return product_area


def main():
    first_multiple_input = input().rstrip().split()
    n = int(first_multiple_input[0])
    m = int(first_multiple_input[1])

    grid = []

    for _ in range(n):
        grid_item = input()
        grid.append(grid_item)

    result = two_pluses(grid)
    print(str(result))


if __name__ == '__main__':
    main()
