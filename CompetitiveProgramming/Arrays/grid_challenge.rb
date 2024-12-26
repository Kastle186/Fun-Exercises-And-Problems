#!/usr/bin/env ruby

def grid_challenge(grid)
  # First, sort each of the strings we get.
  grid.map! do |str|
    str.chars.sort
  end

  # Then, we could iterate the columns with indices, or transpose the matrix
  # to form "new strings" with the columns rather than the rows. And from there
  # simply check whether they are sorted, and return the "YES" or the "NO" accordingly.

  grid.transpose.each do |column|
    0.upto(column.length - 2) do |i|
      if column[i] >= column[i + 1] then return "NO" end
    end
  end

  "YES"
end

# Available Test Cases:
#
# Input: ["eabcd", "fghij", "olkmn", "trpqs", "xywuv"]
# Output "YES"
