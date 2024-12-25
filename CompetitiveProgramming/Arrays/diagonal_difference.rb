#!/usr/bin/env ruby

def diagonal_difference(matrix)
  # We are guaranteed the matrix is a square one.
  dimension = matrix.length
  diff = 0

  # We add to our result the difference of each element in order, of each of the
  # matrix's diagonals. Then, the absolute value of the total subtractions is the
  # result we are looking for.
  (0...dimension).each do |i|
    diag1_value = matrix[i][i]
    diag2_value = matrix[i][dimension - i - 1]
    diff += (diag1_value - diag2_value)
  end

  diff.abs
end

# Available Test Cases:

# Input: [[11, 2, 4]
#         [4, 5, 6]
#         [10, 8, -12]
# Output: 15

# Input: [[1, 2, 3]
#         [4, 5, 6]
#         [9, 8, 9]
# Output: 2

