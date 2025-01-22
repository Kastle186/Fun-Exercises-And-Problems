#!/usr/bin/env python3

from collections import deque

def main():
    n = int(input().strip())
    grid = []

    for _ in range(n):
        grid_item = input()
        grid.append(grid_item)

    first_multiple_input = input().rstrip().split()

    start_x = int(first_multiple_input[0])
    start_y = int(first_multiple_input[1])
    goal_x = int(first_multiple_input[2])
    goal_y = int(first_multiple_input[3])

    result = minimum_moves(grid, start_x, start_y, goal_x, goal_y)
    print(str(result))


def minimum_moves(grid: list[str],
                  start_x: int,
                  start_y: int,
                  goal_x: int,
                  goal_y: int) -> int:

    bfs_queue = deque()
    visited = set()
    moves = 0

    # If we start at the end goal, then there's nothing else for us to do
    # or traverse here.

    if start_x == goal_x and start_y == goal_y:
        return moves

    # Set up and begin our breadth-first search with the starting point and 0 moves.

    grid_size_x, grid_size_y = len(grid), len(grid[0])
    directions = [[1, 0], [-1, 0], [0, 1], [0, -1]]
    bfs_queue.append([start_x, start_y, moves])

    while bfs_queue:
        x_iter, y_iter, moves = bfs_queue.popleft()
        moves += 1

        # Run through all the reachable unvisited points from the current point.
        # The reason we are not incrementing the total number of moves on each one
        # of these loops, is that each move can be of any length, as long as the
        # direction remains the same. For example, if we start at (0,0), then all
        # of (0,1), (0,2) ... (0,n) are reachable with one move, assuming there
        # are no obstacles.

        for xi, yi in directions:
            x, y = x_iter + xi, y_iter + yi

            while is_within_boundaries(x, y, grid_size_x, grid_size_y) \
                  and grid[x][y] == '.':

                if x == goal_x and y == goal_y:
                    return moves

                if (x, y) not in visited:
                    visited.add((x, y))
                    bfs_queue.append([x, y, moves])

                x += xi
                y += yi

    return -1


def is_within_boundaries(x: int, y: int, x_len: int,  y_len: int) -> bool:
    return 0 <= x < x_len and 0 <= y < y_len


if __name__ == '__main__':
    main()
