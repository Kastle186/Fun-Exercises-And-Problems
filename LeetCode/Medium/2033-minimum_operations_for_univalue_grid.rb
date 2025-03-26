#!/usr/bin/env ruby

# Name: 2033. Minimum Operations to Make a Uni-Value Grid
# Topics: Array, Math, Sorting, Matrix
# Companies: EPAM Systems

def operations_to_number(lst, num, x)
  # To get the number of operations to get any given number to our target, we
  # just have to divide the absolute difference between both, by the operator
  # we'll be using (x). Then, just add all up to get the total for the list.
  lst.reduce(0) { |sum, val| sum + ((val - num).abs / x) }
end


def min_operations(grid, x)
  # First, we have to convert our grid into a single array, for easier processing.
  # After all, the 2D representation was just for visualization.

  grid.flatten!.sort!

  # The next step is to ensure that all the numbers in our list yield the same
  # result modulo x. Otherwise, we are sure it is mathematically not possible
  # to unify them.

  expected_modulo = grid[0] % x
  return -1 if grid.any? { |n| n % x != expected_modulo }

  # Now that we know it's possible, we have the number that is closest to all of
  # the elements. In other words, the median. For even-sized lists, we will check
  # both medians and return the one that takes less operations.
  median_index = grid.length / 2

  if grid.length % 2 == 1
    return operations_to_number(grid, grid[median_index], x)
  end

  [operations_to_number(grid, grid[median_index], x),
   operations_to_number(grid, grid[median_index-1], x)].min
end


def main
  grid_1 = [[2, 4], [6, 8]]
  grid_2 = [[1, 5], [2, 3]]
  grid_3 = [[1, 2], [3, 4]]

  grid_ops_1 = min_operations(grid_1, 2)
  grid_ops_2 = min_operations(grid_2, 1)
  grid_ops_3 = min_operations(grid_3, 2)

  puts grid_ops_1
  puts grid_ops_2
  puts grid_ops_3
end


main()
