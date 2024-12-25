#!/usr/bin/env ruby

def min_max_sum(arr)
  # To get the lowest sum, we have to add the smallest 4 elements, and for the
  # highest, the largest 4 elements. By sorting the array, we get easy access
  # to them :)
  arr.sort!
  min_sum = arr[...4].reduce(:+)
  max_sum = arr[-4..-1].reduce(:+)
  puts "#{min_sum} #{max_sum}"
end

# Available Test Cases:
#
# Input: [1, 2, 3, 4, 5]
# Output: 10 14
#
# Input: [7, 69, 2, 221, 8974]
# Output: 299 9271
